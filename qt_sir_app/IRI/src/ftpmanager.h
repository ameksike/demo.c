#ifndef FTPMANAGER_H
#define FTPMANAGER_H

#include <QThread>
#include "servicio.h"
#include <QMutex>
#include "src/clienteservicioftp.h"
#include <QTimer>
#include <QFile>
#include <QCoreApplication>



/**
  SE ENCARGA DE MONITOREAR LOS FTP QUE ESTAN FUERA DE SERVICIO,
  E INDICAR EL FTPManager CUANDO SE ACTIVA  NUEVAMENTE
**/
class QMonFtp: public QObject
{
    Q_OBJECT
  public:
    QMonFtp()
    {
        this->intervaloTiempoMonitoreo = 10000;
        this->logFile = new QFile("/var/IRI/monitorservicios.log");
        this->logFile->open( QIODevice::WriteOnly | QIODevice::Truncate );
        QDebug( this->logFile )<<QDateTime::currentDateTime().toString( "hh:mm:ss" )<<"Iniciando monitor de servicios"<<endl;
        this->posServicioLista = 0;       
    }
    ~QMonFtp()
    {        
        this->logFile->close();
        delete this->logFile;
    }

  public slots:
    void slotNuevoServicioMonitorear(QEvent* e)
    {
       QServicioEvent *_e = new QServicioEvent( *static_cast<QServicioEvent*>(e) );
       Servicio *s        = new Servicio( *_e->getServicio() );
       ClienteFTP *ftp    = new ClienteFTP( s );
       connect(ftp, SIGNAL(connectionTimeout()), this, SLOT(slotFallaConeccionPorTiempo()));
       connect(ftp, SIGNAL(connected(bool))    , this, SLOT(finMonitorearServicio(bool)));
       connect(ftp, SIGNAL(logged(bool))       , this, SLOT(finMonitorearServicio(bool)));
       connect(ftp, SIGNAL(closed(bool))       , this, SLOT(finMonitorearServicio(bool)));
       
       QDebug( this->logFile )<< QDateTime::currentDateTime().toString( "hh:mm:ss" )<<"Nuevo servicio a monitorear [ dirIP:"<<s->getDirIP().toString()<<"puerto:"<<s->getPuerto()<<"]"<<endl;
       if( this->serviciosMonitorear.empty() )
       {
          this->timerMonitoreo.start( this->intervaloTiempoMonitoreo, this );
       }
       this->serviciosMonitorear.insert(s->getId(), ftp );
    }

    void  slotFallaConeccionPorTiempo()
    {
        ClienteFTP *ftp = qobject_cast<ClienteFTP*>( sender() );
        this->serviciosEnMonitoreo.remove( ftp->getDatosServicio()->getId() );
        this->finMonitorearServicio( true );
    }

    void finMonitorearServicio(bool error)
    {
        ClienteFTP *ftp = qobject_cast<ClienteFTP*>( sender() );
        Servicio *s     = ftp->getDatosServicio();
        QFtp::Command cmdEjecutado = ftp->getUltimoComandoEjecutado();
        cout<<"QMonFtp::finMonitorearServicio id: "<<s->getId()<<" cmd:"<<cmdEjecutado<<endl;

        if( cmdEjecutado == QFtp::ConnectToHost )
        {            
            if( !error )
            {
                ftp->login();
            }
            else
            {               
               this->serviciosEnMonitoreo.remove( s->getId() );               
            }
        }

        if( cmdEjecutado == QFtp::Login )
        {
            if( error )
            {
                QDebug( this->logFile )<<QDateTime::currentDateTime().toString( "hh:mm:ss" );
                QDebug( this->logFile )<<" [IP: "<<s->getDirIP().toString()<<" puerto: "<<s->getPuerto()<<"] "<<ftp->errorString()<<endl;
            }
            ftp->close();           
        }

        if( cmdEjecutado == QFtp::Close )
        {
            if( !error )
            {
              QDebug( this->logFile )<<QDateTime::currentDateTime().toString( "hh:mm:ss" );
              QDebug( this->logFile )<<"Nuevo Servicio Activo [IP: "<<s->getDirIP().toString()<<" puerto: "<<s->getPuerto()<<"] "<<ftp->errorString()<<endl;
              emit signalServicioActivo( s->getId() );
              this->serviciosEnMonitoreo.remove( s->getId() );
              this->serviciosMonitorear.take( s->getId() );
              ftp->deleteLater();
            }
        }

        if( this->serviciosEnMonitoreo.empty() && !this->serviciosMonitorear.empty())
        {            
            this->timerMonitoreo.start( this->intervaloTiempoMonitoreo, this );
        }
    }

  signals:
    void signalServicioActivo(quint16);

  private:
    typedef QHash<quint16, ClienteFTP*> hashServicios;
    QFile* logFile;    
    quint16       posServicioLista;
    int           intervaloTiempoMonitoreo;
    hashServicios serviciosMonitorear;
    hashServicios serviciosEnMonitoreo;
    QBasicTimer   timerMonitoreo;
    QString       idServicioMonitoreoActual;
    void timerEvent(QTimerEvent *te)
    {
        if( te->timerId() == this->timerMonitoreo.timerId() )
        {
            te->accept();
            cout<<"[MONITOREANDO SERVICIOS]"<<endl;
            //this->iniciarMonitoreo();
            return;
        }
        QObject::timerEvent(te);
    }
    void iniciarMonitoreo()
    {        
        this->timerMonitoreo.stop();        
        QHashIterator<quint16, ClienteFTP*> i(this->serviciosMonitorear);
        while ( i.hasNext() )
        {
            i.next();
            ClienteFTP *ftp = i.value();
            Servicio *s = ftp->getDatosServicio();
            cout<<"INICIAR-MONITOREO [IP: "<<s->getDirIP().toString().toStdString()<<" PUERTO:"<<s->getPuerto()<<"]"<<endl;
            ftp->start();            
            this->serviciosEnMonitoreo.insert(i.key(), ftp);
        }
    }  
};


/**
   CLASE QUE CREA UNA INSTANCIA DE QMonFtp Y LO EJECUTA EN UNA HILO INDEPEDIENTE
**/
class QMonServicio: public QThread
{
    Q_OBJECT
   public:
    QMonServicio()    {}

   signals:
    void signalServicioActivo(int, quint16);

    void signalMonitorearServicio(QEvent*);

   private slots:
    void slotActivarServicio(quint16 idServicio)
    {
        emit this->signalServicioActivo( Servicio::SERVICIO, idServicio );
    }

   protected:
    void customEvent(QEvent *e)
    {
        cout<<"QMonServicio event"<<endl;
        if( e->type() == QEvent::Type( QEvent::User + 130 ) )
        {
            QServicioEvent *_e = new QServicioEvent( *static_cast<QServicioEvent*>( e ));
            emit this->signalMonitorearServicio( _e );
        }
    }

    void run()
    {
//        cout<<"[QMonServicio started]"<<endl;
//        QMonFtp *monFtp = new QMonFtp;
//        connect(this, SIGNAL(signalMonitorearServicio(QEvent*)), monFtp, SLOT(slotNuevoServicioMonitorear(QEvent*)), Qt::QueuedConnection);
//        connect(monFtp, SIGNAL(signalServicioActivo(quint16)), this, SLOT(slotActivarServicio(quint16)), Qt::QueuedConnection);
//        this->exec();
    }
};

/**
  CONTROLA EL ESTADO DE CADA CLIENTE  FTP QUE ESTA ENVIANDO INFORMACION.
  SI ALGUN SERVIDOR FTP SE PONE FUERA DE SERVICIO POR ALGUN MOTIVO, ESTE SE
  ENCARGA DE PONERLO A MONITOREAR MEDIANTE EL QMonFtp

**/

class FTPManager : public QObject
{
    Q_OBJECT
  private:
     typedef enum  { METODO_A, METODO_B } MetodoNombrarArchivos;
 public slots:
      void slotsNuevoIRI(QIRIEvent *e)
      {
        qDebug()<<"si llego el evento"<<e->getFileName();
        emit this->signalNuevoIRI(e);
      }
  public:
     
    FTPManager(QObject *parent = 0,  MetodoNombrarArchivos _MNArchivos = METODO_B):QObject( parent ), MNArchivos( _MNArchivos )
    {
        this->inicializar();
    }

    ~FTPManager()
    {
        this->monitorServicios->quit();
        this->monitorServicios->wait();
        this->monitorServicios->deleteLater();
    }

    void setMetodoNombrarArchivos(MetodoNombrarArchivos);
    void setLIID(QString);
    void setOperatorID(QString);
    void setIRIServerID(QString);
    void setFileType(QString t = "1");

    QString generateNameIRItemp()
    {
        this->metodoB_DateTimeFormat  = "yyMMddhhmmss";
        this->metodoB_eeee            = "0000";
        this->metodoB_t               = "1";
        this->setIRIServerID("NS");
        this->setOperatorID("HU");
       return this->getNombreArchivoMetodoB();
    }
    void activarCliente(Servicio*s)
    {
        cout<<"*************************************************************"<<endl;
        cout<<"*  FTPManager::activarCliente id: "<<s->getId()<<"          *"<<endl<<endl;
        cout<<"*************************************************************"<<endl;
        quint16 id = s->getId();
        ClienteServicioFTP* clienteFTP = this->clientesActivos.value( id );               
        if( !clienteFTP )
        {
            clienteFTP = new ClienteServicioFTP( s );
            connect(clienteFTP, SIGNAL(cambioEstadoServicio(int,quint16))         , this, SLOT(cambioEstadoFtp(int,quint16)));
            connect(clienteFTP, SIGNAL(coneccionCerrada(quint16,bool))        , this, SLOT(slotCerrarFTPInactivo(quint16, bool)));
            connect(clienteFTP, SIGNAL(finTransferencia(quint16,quint64,bool)), this, SIGNAL(signalFinTransferencia(quint16,quint64,bool)));
            connect(this,SIGNAL(signalNuevoIRI(QIRIEvent*)),clienteFTP,SLOT(procesarEventos(QIRIEvent*)));
            this->clientesActivos.insert(id, clienteFTP);
            clienteFTP->habilitarSalvaConNombreTemporal();
            clienteFTP->start();            
        }

        /**
          EN CASO DE EXISTIR Y ESTAR FUERA DE SERVICIO VERFICAR QUE COINCIDAN LOS
          DATOS. SI NO COINCIDEN, NOTIFICAR EL QMonFtp DE QUE  EL SERVICIO
          HA CAMBIADO SUS DATOS. SE ELIMINA DE LA LISTA Y SE VUELVA A CREAR

        **/
        /*else
        {
            if( s != clienteFTP->getDatosServicio() )
            {
                if( clienteFTP->getDatosServicio()->getEstado() == Servicio::FUERA_SERVICIO )

            }
        }*/


    }

  signals:
    void signalNuevoEvento(QEvent *);
    void signalNuevoIRI(QIRIEvent *);
    void cerrarPorInactividad();

    void cambioEstadoServicio(int, quint16);

    void signalFinTransferencia(quint16, quint64, bool);

  private slots:
    void cambioEstadoFtp( int estadoFtp, quint16 idServicio )
    {
        cout<<"FTPManager::cambioEstadoFtp["<<estadoFtp<<"] id: "<<idServicio <<endl;
        if( estadoFtp == Servicio::FUERA_SERVICIO )
        {            
            ClienteServicioFTP* clienteFTP = this->clientesActivos.take( idServicio );            
           // QCoreApplication::postEvent( this->monitorServicios, new QServicioEvent( clienteFTP->getDatosServicio() ));
            emit this->cambioEstadoServicio( Servicio::FUERA_SERVICIO, idServicio );
            clienteFTP->deleteLater();
            return;
        }

        if( (estadoFtp == Servicio::ACTIVO) || (estadoFtp == Servicio::INACTIVO) )
        {
            Servicio::EstadosServicio estado = Servicio::ACTIVO;
            if( estadoFtp == Servicio::INACTIVO )
                estado = Servicio::INACTIVO;
            this->clientesActivos.value( idServicio )->getDatosServicio()->setEstado( estado );
            emit this->cambioEstadoServicio( estadoFtp, idServicio );
        }
    }

    void slotCerrarFTPInactivo(quint16 idServicio, bool error)
    {
        if(!error)
        {
            cout<<"FTPManager::slotCerrarFTPInactivo. ID: "<<idServicio<<endl;
            ClienteServicioFTP *clienteFTP = this->clientesPorDesactivar.take( idServicio );
            clienteFTP->deleteLater();
        }
    }

  public slots:
   void customEvent(QEvent *e)
   {
       cout<<"FTPManager::customEvent("<<e->type()<<")"<<endl;
       if( e->type() == QEvent::Type( QIRIEvent::IRI_EVENT ) )
       {
           QIRIEvent *irie = static_cast<QIRIEvent*>( e );
           QList<quint16> servicios = irie->getServicios();

           cout<<"IRI_EVENT:"<<servicios.length()<<endl;
           for( int i = 0; i < servicios.length(); i++)
           {
               QIRIEvent *irie = new QIRIEvent( *static_cast<QIRIEvent*>( e ) );
               irie->setFileName( this->getNombreArchivo() );
               quint16 idServicio = servicios.at( i );
               ClienteServicioFTP *clienteFTP = this->clientesActivos.value( idServicio );
               if( clienteFTP )
               {
                  // clienteFTP->getDatosServicio()->setEstado( s->getEstado() );
                   //QCoreApplication::postEvent(clienteFTP, irie);
               }
           }                      
           return ;
       }

       if( e->type() == QEvent::Type( QServicioEvent::SERVICIO_EVENT ) )
       {
           QServicioEvent *se = static_cast<QServicioEvent*>( e );
           quint16 idServicio = se->getServicio()->getId();
           ClienteServicioFTP *clienteFTP = this->clientesActivos.take( idServicio );
           this->clientesPorDesactivar.insert(idServicio, clienteFTP);
           clienteFTP->cerrarPorInactividad();                      
       }
   }

   void timerEvent(QTimerEvent *);

  private:
    /**
      SE EMPLEA PARA GENERAR LA EXTENSION "eeee" CUANDO SE UTILIZA EL METODO_B
      PARA NOMBRAR ARCHIVOS
    **/
    QDateTime dateTime;

    QHash<quint16, ClienteServicioFTP*> clientesActivos;
    QHash<quint16, ClienteServicioFTP*> clientesPorDesactivar;

    QMutex mutex;
    QTimer timerControlInactividad;
    int timerInactividad;
    int tiempoMaximoInactividad;
    QString getNombreArchivoMetodoB();
    //frequency of transfer, based on send timeout
    int tiempoInterTransferencia;
    int idTimerInterTransferencia;
    //frequency of transfer, based on volume trigger
    int tamanoMaximoPorTransferencia;

    MetodoNombrarArchivos MNArchivos;
    QString getNombreArchivoMetodoA();

    QString getNombreArchivo();

    //Metodo A para nombrar los archivos < LIID_seq.ext >
    QString metodoA_LIID;//LIID
    QString metodoA_seq;//0..2^64-1  en formato ASCII. no excede 20 caracteres
    QString metodoA_ext;//1..8  en formato ASCII. 1 => IRI files

    //Metodo B para nombrar los archivos < ABXYyymmddhhmmsseeeet >
    QString metodoB_OperatorID;//AB
    QString metodoB_MFNode;//XY
    QString metodoB_DateTimeFormat;//yyMMddhhmmss
    QString metodoB_eeee;//eeee se utiliza para evitar conflictos en los nombres de archivos
    QString metodoB_t;//1..8  en formato ASCII. 1 => IRI files


    void inicializar()
    {
        this->metodoB_DateTimeFormat  = "yyMMddhhmmss";
        this->metodoB_eeee            = "0000";
        this->metodoB_t               = "1";
        this->setIRIServerID("NS");
        this->setOperatorID("HU");
        this->monitorServicios = new QMonServicio;
        connect(this->monitorServicios, SIGNAL(signalServicioActivo(int,quint16)), this, SIGNAL(cambioEstadoServicio(int,quint16)));
        this->monitorServicios->start();
    }

    void  activarTimerControlInactividad();
    void  detenerTimerControlInactividad();

    //parametro eeee para evitar conflictos en los nombres de los archivos
    void generarExtension_eeee()
    {       
        QDateTime currDT = QDateTime::currentDateTime();
        if( !this->dateTime.isValid() || ( this->dateTime.toString( this->metodoB_DateTimeFormat ) != currDT.toString( this->metodoB_DateTimeFormat ) ) )
       {

           this->dateTime     = currDT;
           this->metodoB_eeee = QByteArray().fill('0', 4);
       }
       else
       {           
          quint32 next_eeee  = this->metodoB_eeee.toInt();
          this->metodoB_eeee = QByteArray().setNum( ++next_eeee ).rightJustified(4, '0');
       }
    }

    QMonServicio*     monitorServicios;
};


#endif // FTPMANAGER_H
