#ifndef CLIENTESERVICIOFTP_H
#define CLIENTESERVICIOFTP_H

#include <QFtp>
#include <QThread>
#include <QEvent>
#include "servicio.h"
#include <QCoreApplication>
#include <QQueue>
#include <QHash>
#include "qsalvaevent.h"
#include "qirievent.h"
#include "SERVICE/DataAcces/dat_callrelatedevent.h"
#include <QMutex>
#include <QMutexLocker>
#include <QBasicTimer>
#include <QFile>
#include <QDir>
#include <QFileInfoList>
//193.4.48.20

class ClienteFTP: public QFtp
{
        Q_OBJECT
    public:
        ClienteFTP(Servicio *s, bool _permiteAccesoAnonimo = false):servicio(s), _permiteAccesoAnonimo(_permiteAccesoAnonimo)
        {
            this->cerradoPorSistema           = false;
            this->errorUltimoComando          = QFtp::NoError;
            this->ultimoComandoEjecutado      = QFtp::None;
            this->execTransferSalva=false;
            this->tiempoMaximoEsperaConeccion = 10000;//ms = 10s
            this->connect(this, SIGNAL(commandStarted(int)), this, SLOT(inicioEjecuacionComando(int)));
            this->connect(this, SIGNAL(stateChanged(int))  , this, SLOT(cambioEstado(int)));
            this->connect(this, SIGNAL(done(bool))         , this, SLOT(finEjecucionUltimoComando(bool)));
        }

        virtual ~ClienteFTP()
        {
             delete this->servicio;
             cout<<"ClienteFTP::~ClienteFTP()"<<endl;
        }

        Servicio * getDatosServicio()
        {
            return this->servicio;
        }

        void start()
        {
            this->connectToHost( this->servicio->getDirIP().toString(), this->servicio->getPuerto() );
        }        

        static QString generarNombreArchivoTemporal()
        {
            return QString("TMP").append(QDateTime::currentDateTime().toString( "hhMMddhhmmsszzz" ));
        }

        QFtp::Command getUltimoComandoEjecutado()
        {
            return this->ultimoComandoEjecutado;
        }

        bool permiteAccesoAnonimo()
        {
            return this->_permiteAccesoAnonimo;
        }


        int login()
        {
            int cmdId = 0;
            if(!this->_permiteAccesoAnonimo)
                {
                 cmdId = QFtp::login( this->servicio->getUsuario(), this->servicio->getClave() );

               }
            else
                cmdId = QFtp::login( "anonymous", "" );
            return cmdId;
        }
       bool executePending()
       {
              bool result=false;

              qDebug()<<"MC activado comprobando IRI backup";

              QDir dir("/var/IRI/pendin/"+QString ().setNum(this->servicio->getId())+"/");



               QFileInfoList list = dir.entryInfoList();

                for (int i = 1; i < list.count(); ++i)
                {
                    QFileInfo fileInfo = list.at(i);
                    QString name=fileInfo.filePath();
                    QFile fileConten(name);
                    if (!fileConten.open(QIODevice::ReadOnly))
                        continue;
                    this->put(QByteArray (fileConten.readAll()),fileInfo.fileName(), QFtp::Binary );
                    fileConten.close();
                    dir.remove(name);
                    sleep(1);

                    if(i==list.count()-1)
                    {
                        dir.rmdir(dir.path());
                        result=true;

                    }
                }

           execTransferSalva=(result==true)?true:false;

         return result;
       }

    signals:
        void connectionTimeout();

        void connected(bool);

        void logged(bool);

        void closed(bool);

        void connectionBroken();

    protected slots:

        void inicioEjecuacionComando(int)
        {
            this->ultimoComandoEjecutado = this->currentCommand();
            this->cerradoPorSistema      = (this->ultimoComandoEjecutado == QFtp::Close);
        }

        void finEjecucionUltimoComando(bool error)
        {

            cout<<"ClienteFTP::finEjecucionUltimoComando id:"<<this->servicio->getId()<<"cmd: "<<this->ultimoComandoEjecutado<<endl;

            if( this->ultimoComandoEjecutado == QFtp::ConnectToHost )
            {
                this->timerIntentoConeccion.stop();
                emit this->connected( error );
                return;
            }

            if( this->ultimoComandoEjecutado == QFtp::Login )
            {
                emit this->logged( error );
                return;
            }


            if( this->ultimoComandoEjecutado == QFtp::Close )
            {               
                emit this->closed(error);
            }

           if(this->execTransferSalva)
                {
                  this->execTransferSalva=false;
                 // this->close();
                  this->cambioEstado(QFtp::Unconnected);



                }

        }

        void cambioEstado(int estado)
        {
            cout<<"ClienteFTP::cambioEstado("<<estado<<")"<<endl;
            if( estado == QFtp::Connecting )
            {
                cout<<"intentando conectar"<<endl;
                this->timerIntentoConeccion.start( this->tiempoMaximoEsperaConeccion, this );
                return;
            }

            if( (estado == QFtp::Unconnected) && (this->ultimoComandoEjecutado != QFtp::ConnectToHost) && !this->cerradoPorSistema )
            {
                cout<<"ClienteFTP::cambioEstado, cmd:"<<this->ultimoComandoEjecutado<<endl;
                emit connectionBroken();
                return;
            }
        }

    protected:
        Servicio*     servicio;
        QFtp::Error   errorUltimoComando;
        QFtp::Command ultimoComandoEjecutado;
        bool          cerradoPorSistema;
        bool          _permiteAccesoAnonimo;
        QFtp::State   estadoFTP;
        QBasicTimer   timerIntentoConeccion;
        int           tiempoMaximoEsperaConeccion;
        bool execTransferSalva;
    protected:
        void timerEvent(QTimerEvent *te)
        {
            if( te->timerId() == this->timerIntentoConeccion.timerId() )
            {
                this->timerIntentoConeccion.stop();
                cout<<"falla de coneccion por tiempo id:"<<this->servicio->getId()<<endl;
                emit this->connectionTimeout();                
                return;
            }            
            QFtp::timerEvent(te);
        }

};



/**
  CLIENTE DEL SERVICIO FTP  PARA ENVIAR IRIs AL CENTRO DE MONITOREO
**/
class ClienteServicioFTP: public ClienteFTP
{
  Q_OBJECT
 public:
    ClienteServicioFTP(Servicio *s, bool _permiteAccesoAnonimo = false):ClienteFTP( new Servicio( *s ), _permiteAccesoAnonimo  )
    {
        this->tiempoMaximoInactividad        = 15000;//en ms=/1000
        this->salvarArchivoConNombreTemporal = false;               
        this->connect(this, SIGNAL(commandFinished(int,bool)), this, SLOT(finEjecucionComando(int, bool)));
        this->connect(this, SIGNAL(connectionTimeout())      , this, SLOT(coneccionFallidaPorTiempo()));        
        this->connect(this, SIGNAL(connected(bool))          , this, SLOT(finEjecucionUltimoComando(bool)));
        this->connect(this, SIGNAL(logged(bool))             , this, SLOT(finEjecucionUltimoComando(bool)));
        this->connect(this, SIGNAL(closed(bool))             , this, SLOT(finEjecucionUltimoComando(bool)));
        this->connect(this, SIGNAL(connectionBroken())       , this, SLOT(desconeccionInesperada()));
    }

    ~ClienteServicioFTP()
    {        
       // cout<<"ClienteServicioFTP::~ClienteServicioFTP(), id:"<<this->servicio->getId()<<endl;
    }
    
    void cerrarPorInactividad()
    {
        if( this->transferenciasActivas.empty() )
        {
           this->cerradoPorSistema = true;
           this->close();
        }
    }

    void habilitarSalvaConNombreTemporal()
    {
        this->salvarArchivoConNombreTemporal = true;
    }


 signals:    
     void cambioEstadoServicio(int, quint16);

     void coneccionCerrada(quint16, bool);

     void finTransferencia(quint16, quint64, bool);

 protected slots:
     /**  FIN DE EJECUCION DE CADA COMANDO INDEPENDIENTE **/
     void finEjecucionComando(int, bool);

     //void cambioEstado(int estado);

     /**
       ESTA SLOT ES CONECTADA A LA SENAL "done" DEL QFtp, LA CUAL ES EMITIDA
       SIEMPRE QUE SE EJECUTA UN COMANDO DESPUES DE LA SENAL "commandFinished"
     **/
     void finEjecucionUltimoComando(bool);

     void coneccionFallidaPorTiempo()
     {         
         this->finEjecucionUltimoComando( true );
     }

     void desconeccionInesperada()
     {
         emit cambioEstadoServicio( Servicio::FUERA_SERVICIO, this->servicio->getId() );
     }

protected:
    /**
      SE ENCARGA DE PROCESAR EVENTOS DEFINIDOS POR EL USUARIO (X2)
    **/
    bool event(QEvent* e)
    {

        if( e->type() != (QEvent::Type)QIRIEvent::IRI_EVENT )
             return ClienteFTP::event( e );
        else
       {
           this->timerControlInactividad.stop();

           cout<<"FTP recibiendo evento"<<endl;
           cout<<"Estado Actual[ "<<this->state()<<" ]"<<endl;
           QIRIEvent *ftpE = static_cast<QIRIEvent*>( e ) ;
           this->procesarEventos( ftpE );
           return true;
       }
    }
public slots:
    void procesarEventos(QIRIEvent *ftpE)
    {        
        int cmdId           = 0;
        qDebug()<<"Procesando";
        this->timerControlInactividad.stop();

        cout<<"FTP recibiendo evento"<<endl;
        cout<<"Estado Actual[ "<<this->state()<<" ]"<<endl;

        if( this->salvarArchivoConNombreTemporal )
        {
            QString tmpFileName = ClienteServicioFTP::generarNombreArchivoTemporal();
            this->put(ftpE->getFileContent(), tmpFileName, QFtp::Binary );
            cmdId = this->rename( tmpFileName, ftpE->getFileName() );
        }
        else
        {
            cmdId = this->put(ftpE->getFileContent(),ftpE->getFileName(), QFtp::Binary );
        }

        this->transferenciasActivas.insert( cmdId, ftpE->getNumTransferencia() );
    }

protected:
    void timerEvent(QTimerEvent *te)
    {
       if( te->timerId() == this->timerControlInactividad.timerId() )
       {
           this->timerControlInactividad.stop();
           cout<<"Cerrar FTP por Inactividad"<<endl;
           this->servicio->setEstado( Servicio::INACTIVO );           
           if( this->transferenciasActivas.empty() )
               emit this->cambioEstadoServicio( Servicio::INACTIVO, this->servicio->getId() );           
           return;
       }
       ClienteFTP::timerEvent( te );
    }

private:               
    QHash<int, quint64>     transferenciasActivas;
    bool                    salvarArchivoConNombreTemporal;
    QBasicTimer             timerControlInactividad;
    int                     tiempoMaximoInactividad;
};


#endif // CLIENTESERVICIOFTP_H
