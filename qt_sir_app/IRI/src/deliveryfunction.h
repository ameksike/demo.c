#ifndef DELEVERYFUNCTION_H
#define DELEVERYFUNCTION_H

#include <QThread>
#include <iostream>

#include "SERVICE/DataAcces/Query.h"
#include "src/servicio.h"

#include <QSet>
#include "src/qx2event.h"
#include <QMutex>
#include <QWaitCondition>
#include <QMutexLocker>
#include <QFtp>
#include <QQueue>
#include <QFile>
#include <QDebug>
#include <QBasicTimer>
#include <QPair>
#include <QCoreApplication>
#include "src/ftpmanager.h"
// #include "salvapersistente.h"
#include "src/Entity/Fija/CallRelatedEvent.h"
#include "src/Entity/Fija/ChannelControlEvent.h"
#include "src/Entity/Fija/SuplementaryServiceEvent.h"
using namespace std;
class QIRIEvent;

class DeliveryFunctionPrivate : public QObject
{
    Q_OBJECT
  private:

  public:
    typedef enum
    {
       FTP_DELIVERY_MECHANISM ,
       ROSE_DELIVERY_MECHANISM
    } DeliveryMechanism;

    typedef QList<Servicio*> listaServicios;

    DeliveryFunctionPrivate(QObject *parent = 0, DeliveryMechanism dm = FTP_DELIVERY_MECHANISM );

    ~DeliveryFunctionPrivate()
    {
        QDebug( this->logFile )<<QDateTime::currentDateTime().toString( "hh:mm:ss" )<<"Delivery function detenida"<<endl;
        this->query->getConnection().closeConnection();
        delete this->query;
        this->logFile->close();
        delete this->logFile;
    }
//protected:
//    bool event(QEvent *e)
//    {
//        qDebug()<<"DeliveryFunctionPrivate thread: "<<QThread::currentThreadId()<<endl;
//        qDebug()<<"DeliveryFunctionPrivate Event: "<<e->type()<<endl;
//        if( (e->type() > QEvent::User) && ( e->type() < (QEvent::Type)QX2Event::MAX_X2_EVENT ) )
//        {
//            //this->slotNuevoEvento( e );
//            return true;
//        }
//        else
//            return QObject::event( e );
//    }

  private:
    DeliveryMechanism deliveryMechanism;
    Query*            query;
    quint64           numProxTransferencia;
    FTPManager*       ftpManager;
    int cantidadIRIPorTransferencia;
    bool almacenarTodosEventos;

    QHash<quint64, QQueue<QX2Event*> > transferenciasActivas;
    QMultiHash<quint64, quint64>     transferenciasPorCentroMonitoreo;
    QHash<quint64, Servicio*>        centrosMonitoreo;
    QHash<quint64, Servicio*>        centrosMonitoreoEspejos;
    QHash<quint64, QQueue<QX2Event*> > eventosRecibidos;

    Servicio*         getCentroMonitoreo(quint16);
    QIRIEvent*        crearIRIEvent(QQueue<QX2Event*>&);
 //   QUpdateX2Event*   enviarUpdateEvent(QEvent*);
    QByteArray        crearIRIRecord(QQueue<QX2Event*>);
    QFile*            logFile;
   // SalvaPersistente  *sp;

signals:
     void signalsSendQIRIEvent(QIRIEvent*);
  private slots:
    void slotNuevoEvento(QX2Event *);

    void slotCambioEstadoCentroMonitoreo(int estado, quint16 id);

    void slotFinTransferencia(quint16 idServicio, quint64 numTransf, bool errorTransferencia);

  private:
    void activarServiciosEventosPendientes();

    void activarClienteServicio(Servicio*);

    void activarClientesEspejos();

    void iniciarTransferencia( quint16 idServicio = 0 );

    void procesarEventosPendientes( quint16 idServicio = 0 );

    void generarNumeroProximaTransferencia();

    QList<quint16> getCentrosMonitoreoEspejosActivos();

    void procesarEventos(QQueue<QX2Event*> &eventos, bool errorTransferencia = false);

};

class DeliveryFunction: public QThread
{
    Q_OBJECT
  public:
    DeliveryFunction(QObject *parent = 0):QThread(parent){}

  signals:
    /**  SENAL PARA PASAR LOS EVENTOS AL HILO  **/
    void signalNuevoEvento(QX2Event *);

    /** SENAL PARA INDICAR EL LIG QUE EL DELIVERY FUNCTION ESTA LISTA **/
    void signalDeliveryFunctionReady();

  protected:
    bool event(QEvent *e)
    {
//        if( (e->type() > QEvent::User) && (e->type() < QEvent::Type( QX2Event::MAX_X2_EVENT ) ) )
//        {
//            QEvent *x2e = NULL;
//            if( e->type() == QEvent::Type( QX2Event::CALL_RELATED_EVENT ) )
//                x2e = new CallRelatedEvent( *static_cast<CallRelatedEvent*>( e ) );
//
//            if( e->type() == QEvent::Type( QX2Event::CHANNEL_CONTROL_EVENT ) )
//                x2e =  new ChannelControlEvent( *static_cast<ChannelControlEvent*>( e ) );
//
//            if( e->type() == QEvent::Type( QX2Event::SUPLEMENTARY_SERVICE_EVENT ) )
//                x2e = new SuplementaryServiceEvent( *static_cast<SuplementaryServiceEvent*>( e ) );
//
//            if(x2e)
//            {
//                emit signalNuevoEvento( x2e );
//                cout<<"emiting nuevo x2 event"<<endl;
//                return true;
//            }
        //}
        return true;//QThread::event( e );
    }

    void run()
    {
        DeliveryFunctionPrivate df;
        connect(this, SIGNAL(signalNuevoEvento(QX2Event*)), &df, SLOT(slotNuevoEvento(QX2Event*)), Qt::QueuedConnection);
        cout<<"[Delivery function started]"<<endl;
        emit signalDeliveryFunctionReady();
        this->exec();
    }
};


#endif // DELEVERYFUNCTION_H
