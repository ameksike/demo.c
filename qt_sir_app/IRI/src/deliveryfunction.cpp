#include "deliveryfunction.h"
#include "src/Entity/Fija/fija_definitions.h"
#include "clienteservicioftp.h"
#include <QCoreApplication>
#include <string>
#include "qsalvaevent.h"
#include <QSettings>
#include "SERVICE/DataAcces/nom_mc.h"
#include <QFile>
#include <QDir>
#include <exception>
#include "src/Entity/irirecord.h"
#include <QDebug>
DeliveryFunctionPrivate::DeliveryFunctionPrivate(QObject *parent, DeliveryMechanism dm):QObject( parent ), deliveryMechanism(dm)
{
   this->logFile = new QFile("/var/IRI/IriEvent.log");

   this->logFile->open( QIODevice::WriteOnly );
    QDebug( this->logFile )<<QDateTime::currentDateTime().toString( "hh:mm:ss" )<<"Iniciando delivery function"<<endl;


    if( this->deliveryMechanism == FTP_DELIVERY_MECHANISM )
    {
        this->ftpManager = new FTPManager(this);
        connect(this->ftpManager, SIGNAL(cambioEstadoServicio(int,quint16)),             this, SLOT(slotCambioEstadoCentroMonitoreo(int,quint16)));
        connect(this->ftpManager, SIGNAL(signalFinTransferencia(quint16, quint64,bool)), this, SLOT(slotFinTransferencia(quint16,quint64,bool)));
        connect(this,SIGNAL(signalsSendQIRIEvent(QIRIEvent*)),this->ftpManager,SLOT(slotsNuevoIRI(QIRIEvent*)));
    }   
    this->numProxTransferencia          = 0;
    this->cantidadIRIPorTransferencia   = 10;
    this->almacenarTodosEventos         = false;
    this->query = new Query("DFConns", "LEA2", "lea", "lea", 5432, "localhost", "QPSQL" );

    /*this->sp    = new SalvaPersistente( this );
    this->sp->start();*/
    //this->activarServiciosEventosPendientes();
}

/**
    ESTA SLOT ES LA ENCARGADA DE PONER EL EVENTO EN LA COLA DEL
    CENTRO DE MONITOREO CORRESPONDIENTE Y ACTIVAR TANTO EL CENTRO
    DE MONITOREO AL QUE VA DIRIGIDO COMO A LOS CENTROS ESPEJOS EXISTENTES
**/
void DeliveryFunctionPrivate::slotNuevoEvento(QX2Event *e)
{
    qDebug()<<"[DeleveryFunctionPrivate::slotNuevoEvento]: "<<e->type()<<endl;



    QString eventMsgLog;
    if( e->type() == QX2Event::CALL_RELATED_EVENT  )
    {
        eventMsgLog = "CALL_RELATED_EVENT";
        qDebug()<<eventMsgLog;

    }
    if( e->type() == QX2Event::CHANNEL_CONTROL_EVENT  )
    {
        eventMsgLog  = "CHANNEL_CONTROL_EVENT";
        qDebug()<<eventMsgLog;
    }

    if( e->type() == QX2Event::SUPLEMENTARY_SERVICE_EVENT  )
    {
        eventMsgLog  = "SUPLEMENTARY_SERVICE_EVENT";
        qDebug()<<eventMsgLog;
    }

    if( e )
    {
        quint16 leaid = e->getLEAID().toInt();
        qDebug()<<"LEaID"<<e->getLEAID();
        QDebug( logFile )<<QDateTime::currentDateTime().toString( "hh:mm:ss.zzz" )<<"[ "<< eventMsgLog <<" ]"<<endl;
        this->eventosRecibidos[ leaid ].enqueue( e );
        Servicio *s   = this->getCentroMonitoreo( leaid );
        this->activarClienteServicio( s );
//
        this->slotCambioEstadoCentroMonitoreo(Servicio::ACTIVO,s->getId());
        this->iniciarTransferencia(leaid);
        //this->activarClientesEspejos();
    }
    delete e;
}


/**
  OBTIENE EL CENTRO DE MONITOREO HACIA DONDE DEBE SER ENVIADO EL EVENTO QUE ARRIBO.

  SIEMPRE SE BUSCA EN LA BASE DE DATOS, Y SE COMPARA CON LOS QUE ESTAN
  ACTIVOS O FUERA DE SERVICIO, ESTO GARANTIZA QUE EN CASO DE CAMBIO EN
  ALGUN PARAMETRO DEL CENTRO DE MONITOREO (USUARIO, CLAVE, ETC.)
  PUEDA VERSE

  ESTA PENDIENTE CREAR UNA INTERFACE DE ADMINISTRACION PARA EVITAR LO
  ANTERIORMENTE EXPUESTO Y GANAR EN VELOCIDAD. MEDIANTE ESTA SE GENERA
  UN EVENTO QUE NOTIFIQUE EL CAMBIO QUE SE REALIZO EN LA BASE DE DATOS
  Y SE ACTUALIZA LA INFORMACION EN EL SISTEMA
**/
Servicio *DeliveryFunctionPrivate::getCentroMonitoreo(quint16 leaid)
{
    Nom_MC nom_mc;
    nom_mc.setId( QString().setNum( leaid ) );
    Servicio *sSolicitado = nom_mc.getMC( &this->query->getSqlQuery() );    
    if( this->centrosMonitoreo.contains( leaid ) && sSolicitado)
    {
       Servicio *sUso = this->centrosMonitoreo.value( leaid );
       if( *sSolicitado == *sUso )
       {            
            return sUso;
       }
       else
         /**
            SIGNIFICA QUE HUBO CAMBIO EN ALGUN PARAMETRO DEL SERVICIO
         **/
       {
           sUso->setEstado ( Servicio::DESCONOCIDO     );
           sUso->setClave  ( sSolicitado->getClave()   );
           sUso->setUsuario( sSolicitado->getUsuario() );
           sUso->setDirIP  ( sSolicitado->getDirIP()   );
           sUso->setPuerto ( sSolicitado->getPuerto()  );
       }
    }
    else
    {
        if( sSolicitado )
        {
            this->centrosMonitoreo.insert( leaid, sSolicitado);
        }
    }
    return (sSolicitado) ? (new Servicio( *sSolicitado )) : NULL;
}

/**
    ACTIVA UN CLIENTE DEL SERVICIO SEGUN MECANISMO PARA ENVIAR IRIs
    (FTP O ROSE*)
**/

void DeliveryFunctionPrivate::activarClienteServicio( Servicio* s )
{
    cout<<"DeliveryFunctionPrivate::activarClienteServicio id: "<<s->getId()<<endl;
    if( s )
    {
        quint16 idServicio = s->getId();
        Servicio::EstadosServicio estado = s->getEstado();

        if( estado == Servicio::INICIANDO )
            return;

        if(  estado == Servicio::ACTIVO )
        {
            cout<<"Servicio::ACTIVO"<<endl;
            this->slotCambioEstadoCentroMonitoreo( estado,  idServicio );
            return;
        }

        if( (estado == Servicio::DESCONOCIDO) || (estado == Servicio::PROCESANDO_EVENTOS_PENDIENTES ) )
        {
            if( this->deliveryMechanism == FTP_DELIVERY_MECHANISM )
            {
                s->setEstado( Servicio::INICIANDO );
                this->ftpManager->activarCliente( s );                
            }


            return;
        }

        if( estado == Servicio::FUERA_SERVICIO )
        {
            cout<<"Servicio::FUERASERVICIO"<<endl;
            /**
              ENVIAR EVENTOS A LOS CENTROS DE MONITOREO ESPEJOS
            **/

            iniciarTransferencia( idServicio );

            this->procesarEventos( this->eventosRecibidos[ idServicio  ], true );
        }        
    }
    else
    {
        cout<<"[IDENTIFICADOR DE MC NO REGISTRADO]"<<endl;
    }
}


/**
   ACTIVA CLIENTES QUE HAYAN SIDO CONFIGURADO COMO ESPEJOS PARA ENVIALES TODO
   LA IRIs QUE LLEGAN AL LIG
**/

void DeliveryFunctionPrivate::activarClientesEspejos()
{
    Nom_MC mcs;
    QList<Servicio*> mcEspejos = mcs.getMCEspejos( &this->query->getSqlQuery() );

    for( int i = 0; i < mcEspejos.length(); i++ )
    {
       Servicio *s = mcEspejos.at( i );

       if( !this->centrosMonitoreoEspejos.contains( s->getId() ) )
       {
           this->centrosMonitoreoEspejos.insert(s->getId(), s );
           this->activarClienteServicio( s );
       }
       else
       {
           if( !(*s == *this->centrosMonitoreoEspejos.value( s->getId() ) ) )
           {
                this->centrosMonitoreoEspejos.remove( s->getId() );
                this->centrosMonitoreoEspejos.insert( s->getId(), s);
                this->activarClienteServicio( s );
           }
       }
    }

    if( !mcEspejos.length() )
    {
        mcEspejos = this->centrosMonitoreoEspejos.values();
        for( int i = 0; i < mcEspejos.length(); i++ )
        {
            if( this->deliveryMechanism == FTP_DELIVERY_MECHANISM )
               QCoreApplication::postEvent( this->ftpManager, new QServicioEvent( mcEspejos.at( i ) ) );
        }
        this->centrosMonitoreoEspejos.clear();
    }
}


/**
  ESTA SLOT ES LA ENCARGADA DE VER LOS CAMBIOS DE ESTADO QUE SE PRODUCEN EN
  LOS CENTROS DE MONITOREO DESDE SU ACTIVACION HASTA SU
  DESACTIVACION( INESPERADAMENTE O POR TIEMPO DE INACTIVIDAD)
**/
void DeliveryFunctionPrivate::slotCambioEstadoCentroMonitoreo(int estado, quint16 idServicio)
{
    cout<<"DeliveryFunctionPrivate::slotCambioEstadoCentroMonitoreo id: "<<idServicio<<endl;
    Servicio *s = this->centrosMonitoreo.value( idServicio );
//    if( !s )
//        s = this->centrosMonitoreoEspejos.value( idServicio );

    if( s )
    {
        /**
          CUANDO ES ACTIVADO EL CLIENTE Y PUDO CONECTARSE AL SERVICIO
        **/
        if( estado == Servicio::ACTIVO )
        {
           cout<<"Nuevo servicio activo: "<<idServicio<<endl;
           if( s->getEstado() == Servicio::PROCESANDO_EVENTOS_PENDIENTES )
               this->procesarEventosPendientes( idServicio );

           if( this->deliveryMechanism == FTP_DELIVERY_MECHANISM )
           {
              s->setEstado( Servicio::ACTIVO );
              if( !this->transferenciasPorCentroMonitoreo.contains( idServicio ) && !s->esEspejo())
                  this->iniciarTransferencia( idServicio );
           }
           return;
        }
        else
        {
            /**
              CUANDO LLEGA UN EVENTO Y NO HAY CONECCION EN ESE MOMENTO
            **/
            if( estado == Servicio::FUERA_SERVICIO )
            {
               s->setEstado( Servicio::FUERA_SERVICIO );
//               if( s->esEspejo() )
//                 return;
//               else
//               {
                   /**
                     EVENTOS QUE PUEDEN ESTAR EN UNA TRANSFERENCIA EN EL MOMENTO
                     QUE  SE PIERDE LA CONECCION CON  EL SERVICIO
                   **/

                   QList<quint64> transferenciasIncompletas = this->transferenciasPorCentroMonitoreo.values( idServicio );

                   while( !transferenciasIncompletas.empty() )
                     this->eventosRecibidos[ idServicio ].append( this->transferenciasActivas.take( transferenciasIncompletas.takeFirst() ) );

                   this->iniciarTransferencia( idServicio );

                   this->procesarEventos( this->eventosRecibidos[ idServicio ], true );
              // }
            }

            /**
             CUANDO ES MONITOREADO Y ENTRA EN SERVICIO NUEVAMENTE
            **/
            if( estado == Servicio::SERVICIO )
            {
               cout<<"[CENTRO DE MONITOREO EN SERVICIO]: "<<idServicio<<endl;

               s->setEstado( Servicio::SERVICIO );
               if( !s->esEspejo() )
               {
                   /**
                        BUSCAR LOS EVENTOS QUE ESTAN EN LA BASE DE DATOS Y PONERLOS
                        EN COLA PARA SER ENVIDADOS
                   **/
                   this->procesarEventosPendientes( idServicio );

                   if( this->eventosRecibidos.contains( idServicio ) )
                   {
                       if( this->deliveryMechanism == FTP_DELIVERY_MECHANISM )
                       {
                            this->ftpManager->activarCliente( s );
                       }
                   }
                   else
                       this->centrosMonitoreo.remove( idServicio );
               }
               else
               {
                   if( this->deliveryMechanism == FTP_DELIVERY_MECHANISM )
                   {
                        this->ftpManager->activarCliente( s );
                   }
               }
               return;
            }

            /**
              CUANDO UN CLIENTE DEL SERVICIO(FTP o ROSE) ENTRE EN INACTIVIDAD
              POR EL TIEMPO CONFIGURADO
              **/
            if( (estado == Servicio::INACTIVO) )
            {
                if( this->deliveryMechanism == FTP_DELIVERY_MECHANISM )
                {
                    cout<<"[slotCambioEstadoCentroMonitoreo]Cerrando servicio por inactividad id: "<<idServicio<<endl;
                    if( !this->eventosRecibidos.contains( idServicio ) && !this->transferenciasPorCentroMonitoreo.contains( idServicio ) )
                    {
                        this->centrosMonitoreo.remove( idServicio );
                        QCoreApplication::sendEvent(this->ftpManager, new QServicioEvent( s ));                        
                        delete s;
                    }
                }
            }
        }
    }
}


/**
  INCORPORA A LA COLA DE EVENTOS DEL CENTRO DE MONITOREO CON IDENTIFICADOR
  idServicio LOS EVENTOS PENDIENTES QUE ESTAN ALMACENADOS EN LA BASE DE DATOS
**/
void DeliveryFunctionPrivate::procesarEventosPendientes( quint16 idServicio )
{
    qDebug()<<"No se hace nada";
}


/**
  ESTE METODO SE ENCARGA DE CREAR LAS TRANFERENCIAS Y ENVIARLAS
  AL CENTRO DE MONITOREO CORRESPONDIENTE. SI EXISTEN CENTROS ESPEJOS
  TAMBIEN DUPLICA ESA INFORMACION PARA ELLOS. ES LLAMADA CUANDO
  EL CENTRO DE MONITOREO AL QUE VA DIRIGIDA LA INFORMACION ENTRANTE ESTA
  TANTO ACTIVO COMO FUERA DE SERVICIO PARA PODER REPLICAR LA INFORMACION
  A LOS CENTROS ESPEJOS ANTES MENCIONADO
**/
void DeliveryFunctionPrivate::iniciarTransferencia( quint16 idServicio )
{
   if( !this->eventosRecibidos.value( idServicio ).empty() )
   {
     QList<quint16> centrosMonitoreoEspejosActivos = this->getCentrosMonitoreoEspejosActivos();

     Servicio *s = this->centrosMonitoreo.value( idServicio );

     if( centrosMonitoreoEspejosActivos.length() || ( s->getEstado() == Servicio::ACTIVO ) )

     {
         if( (this->deliveryMechanism == FTP_DELIVERY_MECHANISM) && s )
         {
             QQueue<QX2Event*> eventos;
             if( s->getEstado() == Servicio::ACTIVO )
                eventos = this->eventosRecibidos.take( idServicio );
             else
                eventos = this->eventosRecibidos.value( idServicio );

            QQueue<QX2Event*> eventosTranferencia;

            while( !eventos.empty() )
            {
                eventosTranferencia.clear();
                if( eventos.length() <= this->cantidadIRIPorTransferencia )
                {
                   eventosTranferencia = eventos;
                   eventos.clear();
                }
                else
                {
                   for( int i=0; i < this->cantidadIRIPorTransferencia; i++)
                       eventosTranferencia.enqueue( eventos.dequeue() );
                }

                QIRIEvent *irie = this->crearIRIEvent( eventosTranferencia );
                if( irie )
                {
                    this->generarNumeroProximaTransferencia();

                    irie->setNumTransferencia( this->numProxTransferencia );

                    QDebug( this->logFile )<<QDateTime::currentDateTime().toString( "hh:mm:ss.zzz" )<<"[INICIANDO TRANSFERENCIA ==> No:"<<this->numProxTransferencia<<" cant. eventos: "<<eventosTranferencia.length() <<"]"<<endl;
                    cout<<"[INICIANDO TRANSFERENCIA ==> No:"<<this->numProxTransferencia<<"]"<<endl;

                    if( s->getEstado() == Servicio::ACTIVO )
                    {
                        irie->addServicio( idServicio );
                        this->transferenciasActivas[ this->numProxTransferencia ].append( eventosTranferencia );
                        this->transferenciasPorCentroMonitoreo.insertMulti(idServicio, this->numProxTransferencia );
                    }

                    irie->addServicio( centrosMonitoreoEspejosActivos );
                    emit this->signalsSendQIRIEvent(irie);
                    //QCoreApplication::sendEvent(this->ftpManager, irie);
                 //   delete irie;
                }
                else
                {
                    while( !eventosTranferencia.empty() )
                        eventosTranferencia.dequeue();
                }
            }
         }
     }else
         QDebug( this->logFile )<<QDateTime::currentDateTime().toString( "hh:mm:ss.zzz" )<<"[IRI no llegó a su destino "<<s->getDirIP()<<"]"<<endl;

     /*else
        {
          QQueue<QEvent*> eventos;
          eventos = this->eventosRecibidos.value( idServicio );
          QQueue<QEvent*> eventosTranferencia;
          while( !eventos.empty() )
          {
              eventosTranferencia.clear();
              if( eventos.length() <= this->cantidadIRIPorTransferencia )
              {
                 eventosTranferencia = eventos;
                 eventos.clear();
              }
              else
              {
                 for( int i=0; i < this->cantidadIRIPorTransferencia; i++)
                     eventosTranferencia.enqueue( eventos.dequeue() );
              }

              QIRIEvent *irie = this->crearIRIEvent( eventosTranferencia );
              if( irie )
              {
                  this->generarNumeroProximaTransferencia();

                  irie->setNumTransferencia( this->numProxTransferencia );

                  QDebug( this->logFile )<<QDateTime::currentDateTime().toString( "hh:mm:ss.zzz" )<<"[INICIANDO TRANSFERENCIA ==> No:"<<this->numProxTransferencia<<" cant. eventos: "<<eventosTranferencia.length() <<"]"<<endl;
                  cout<<"[Salvando TRANSFERENCIA ==> No:"<<this->numProxTransferencia<<"]"<<endl;

                  Servicio *s= this->getCentroMonitoreo(idServicio);

                  QString dirs="/var/IRI/pendin/"+QString ().setNum(s->getId())+"/";
                  QDir d;
                  d.mkdir(dirs);
                  sleep(1);

                 QString name=dirs+ this->ftpManager->generateNameIRItemp();
                 QFile file(name);
                if (!file.open(QIODevice::WriteOnly))
                   return;
                file.write(irie->getFileContent());
                file.close();

              }
              else
              {
                  while( !eventosTranferencia.empty() )
                      eventosTranferencia.dequeue();
              }
          }
        }*/
  }
}


/**
  UNA VEZ QUE CONCLUYE UNA TRANSFERENCIA SE PROCESAN LOS EVENTOS QUE
  INCLUIA LA MISMA. EN CASO DE EXISTIR ERROR DURANTE LA TRANSMISION,
  LOS EVENTOS SE ALMACENAN SI NO ESTABAN PENDIENTE Y EN CASO DE
  QUE LA TRANSMISION SEA EXITOSA Y LOS EVENTOS ESTABAN PENDIENTES
  SE  ELIMINAN DE LA BASE DE DATOS
**/
void DeliveryFunctionPrivate::procesarEventos(QQueue<QX2Event *> &eventos, bool errorTransferencia)
{
    while( !eventos.empty() )
    {
        QX2Event *x2e = eventos.dequeue();
        /**
            SI ESTABA PENDIENTE Y NO HUBO ERROR AL ENVIAR SE ELIMINA
            DE LA BASE DE DATOS
        **/
        if( x2e->estabaPendiente() && !errorTransferencia)
        qDebug()<<"Estaba pendiente";//  this->enviarUpdateEvent( x2e )  ;
        else
        {
          /**
            SI NO ESTABA PENDIENTE Y  HUBO ERROR EN TRANSFERENCIA O ESTA ACTIVADA
            LA OPCION DE ALMACENAR TODOS LOS EVENTOS, SE ALMACENA
            EN LA BASE DE DATOS PARA SER ENVIADO POSTERIORMENTE O CON FINES
            ADMINISTRATIVOS
          **/
          if( !x2e->estabaPendiente() && ( errorTransferencia || this->almacenarTodosEventos ))
          {
             x2e->setDelivered( !errorTransferencia );
             //QCoreApplication::postEvent( this->sp, x2e );
          }
        }
     //   delete x2e;
    }
}


/**
  SE ENCARGA DE CREAR UN EVENTO DEL TIPO QIRIEvent CON EL IRIRECORD A ENVIAR
**/
QIRIEvent* DeliveryFunctionPrivate::crearIRIEvent(QQueue<QX2Event*> &colaX2e)
{
    cout<<"DeliveryFunctionPrivate::crearIRIEvent"<<endl;
    QByteArray iriData = this->crearIRIRecord( colaX2e );
    QIRIEvent* iriE = NULL;

    cout<<"iridata length: "<<iriData.length()<<endl;
    if( iriData.length() > 0)
    {
        iriE = new QIRIEvent( iriData );
    }
    return iriE;
}


/**
  CREAR IRIRECORD SEGUN EVENTO
**/
QByteArray DeliveryFunctionPrivate::crearIRIRecord(QQueue<QX2Event*> colaX2e)
{
    string iriContent = IRIUtil::create( colaX2e );
    return QByteArray( iriContent.c_str(), iriContent.length());   
}

/**
  GENERA UN EVENTO QUE SE EMPLEA PARA ELIMINAR LOS EVENTOS DE LA BASE
  DE DATOS PARA UN CENTRO DE MONITOREO
**/
//QUpdateX2Event *DeliveryFunctionPrivate::enviarUpdateEvent(QEvent *e)
//{
//    cout<<"DeliveryFunctionPrivate::enviarUpdateEvent"<<e->type()<<endl;
//    QUpdateX2Event *updateE = NULL;
//    if( e->type() == QEvent::Type( QX2Event::CALL_RELATED_EVENT ) )
//    {
//       CallRelatedEvent *x2e = static_cast<CallRelatedEvent*>( e );
//       updateE = new QUpdateX2Event;
//       //updateE->setContentEventDelivered( delivered );
//       updateE->setContentEventLEAId( x2e->getLEAID() );
//       updateE->setContentEventTime( x2e->getTime() );
//       updateE->setContentEventDWReportId( x2e->getDWReportID() );
//       updateE->setContentEventType( x2e->type() );
//    }
//
//    if( e->type() == QEvent::Type( QX2Event::SUPLEMENTARY_SERVICE_EVENT ) )
//    {
//       SuplementaryServiceEvent *x2e = static_cast<SuplementaryServiceEvent*>( e );
//       updateE = new QUpdateX2Event;
//       //updateE->setContentEventDelivered( delivered );
//       updateE->setContentEventLEAId( x2e->getLEAID() );
//       updateE->setContentEventTime( x2e->getTime() );
//       updateE->setContentEventDWReportId( x2e->getDWReportID() );
//       updateE->setContentEventType( x2e->type() );
//    }
//
//    if( updateE )
//    {
//       // QCoreApplication::postEvent(this->sp, updateE);
//        //QCoreApplication::sendPostedEvents(this->sp, QEventLoop::AllEvents);
//    }
//    return updateE;
//}


/**
  LAS TRANFERENCIAS SON IDENTIFICADAS CON UN NUMERO, AL UN CENTRO DE MONITOREO
  CONCLUIR UNA, NOTIFICA CON SU IDENTIFICADOR, EL NUMERO DE  LA TRANFERENCIA
  Y SI OCURRIO O NO ERROR EN  LA MISMA (FALLA EN LA RED, etc.).
  LOS CENTROS DE MONITOREO ESPEJOS NO NOTIFICAN FIN DE TRANSFERENCIA
**/
void DeliveryFunctionPrivate::slotFinTransferencia(quint16 idServicio, quint64 numTransf, bool errorTransferencia)
{
    cout<<"DeliveryFunctionPrivate::[slotFinTransferencia "<<numTransf<<"] id: "<<idServicio<<endl;
    QQueue<QX2Event*> eventos = this->transferenciasActivas.take( numTransf );
    this->transferenciasPorCentroMonitoreo.remove( idServicio, numTransf ) ;
    cout<<"servicio id: "<<idServicio<<" tranf restantes: "<<this->transferenciasPorCentroMonitoreo.values( idServicio ).length()<<endl;
    this->procesarEventos( eventos, errorTransferencia );
    /**
      SI SE HAN RECIBIDO EVENTOS PARA EL CENTRO DE MONITOREO QUE CONCLUYO
      LA TRANSFERENCIA, SE INDICA INICIAR OTRA PARA EL MISMO
     **/
    if( this->eventosRecibidos.contains( idServicio ) )
        this->iniciarTransferencia( idServicio );
}

/**
  ESTE METODO SE ENCARGA DE BUSCAR EN LA BASE DE DATOS CUALES SON LOS
  CENTROS DE MONITOREO QUE TIENEN EVENTOS PENDIENTES Y LOS ACTIVA
**/
void DeliveryFunctionPrivate::activarServiciosEventosPendientes()
{
    /** Busca en el directorio pendientes si hay buscarl el lea id y verificar que exista informacion**/
    QDir dir("/var/IRI/pendin/");
    QStringList lis=  dir.entryList();

    if( lis.length()-2 > 0 )
        QDebug( this->logFile )<<QDateTime::currentDateTime().toString( "hh:mm:ss" )<<"Extrayendo servicios con eventos pendientes"<<endl;
     quint16 leaid = 0;

  for(int i=2;i < lis.count();i++)
    {
        QString lea=lis.value(i);
        leaid = lea.toInt();
        Servicio *s = this->getCentroMonitoreo( leaid );
        if( s && (s->getEstado() != Servicio::FUERA_SERVICIO) )
        {
            s->setEstado( Servicio::PROCESANDO_EVENTOS_PENDIENTES );
            this->activarClienteServicio( s );
        }
    }
}


/**
  EL TIPO DE DATOS UTILIZADO PARA CREAR LA TRANSFERENCIA ES quint64,
  EN ESTE METODO CUANDO EXCEDE EL VALOR MAXIMO LO REINICIA A TRAVES
  DE LA EXCEPCION QUE SE GENERA
**/
void DeliveryFunctionPrivate::generarNumeroProximaTransferencia()
{
    try
    {
        this->numProxTransferencia++;
    }
    catch(...)
    {
        this->numProxTransferencia = 1;
    }
}

/**
    SI EXISTEN CENTROS DE MONITOREO ESPEJOS, DEVUELVE UNA LISTA DE
    LOS QUE ESTAN ACTIVOS
**/
QList<quint16> DeliveryFunctionPrivate::getCentrosMonitoreoEspejosActivos()
{
    QList<quint16> centrosMonitoreoEspejosActivos;
    QList<Servicio*> listaCentrosMonitoreoEspejos = this->centrosMonitoreoEspejos.values();
    for( int i = 0; i < listaCentrosMonitoreoEspejos.length(); i++)
    {
        Servicio *s = listaCentrosMonitoreoEspejos.at( i );
        if( s->getEstado() == Servicio::ACTIVO )
          centrosMonitoreoEspejosActivos.append( s->getId() );
    }
    return centrosMonitoreoEspejosActivos;
}
