#include "ngn_fija_controller.h"


NGN_FIJA_Controller::NGN_FIJA_Controller()
{
    this->estado = Sincronizando;

}

NGN_FIJA_Controller::~NGN_FIJA_Controller()
{
}
void NGN_FIJA_Controller::iniciarDF()
{
    this->df= new DeliveryFunction;
    connect(this,SIGNAL(signalsQX2Events(QX2Event*)),this->df,SIGNAL(signalNuevoEvento(QX2Event*)));
    this->df->start();
}
void NGN_FIJA_Controller::slotProcesarDatos(QByteArray datos)
{       
    qDebug()<<"Iniciando Buffer"<<datos.size();
    this->bufferTemp.append( datos );

    if( this->estado == IDLE )
    {
        this->estado = Sincronizando;
    }

    if( (this->estado == RecibiendoNuevaTrama) || (this->estado == ProcesandoEncabezado)  || (this->estado == Sincronizando))
    {
        if( this->estado != ProcesandoEncabezado )
            this->reiniciarBufferTemporal();

        if( !procesarEncabezadoTrama() )
            qDebug()<<"No coincide";
    }

    if( this->estado == ProcesandoCuerpo )
    {
        procesarCuerpoTrama();
    }

    this->bufferTemp.clear();
    emit this->signalDatosProcesados();
    //     this->estado=Sincronizando;
    //     this->bufferTemp.append(datos);
    //     qDebug()<<"Recibiendo :"<<datos.length();
    //     if(this->procesarEncabezadoTrama())
    //     {
    //      qDebug()<<"Procesando :"<<datos.length();
    //      this->estado = ProcesandoCuerpo;
    //      this->buffer.clear();
    //      this->procesarCuerpoTrama();
    //      this->bufferTemp.clear();
    //     }

}

bool NGN_FIJA_Controller::procesarEncabezadoTrama()
{
    if( this->estado == Sincronizando )
    {
        int preambuloPos = this->bufferTemp.indexOf( nsFija::PreambuloX2 );
        if( preambuloPos )
        {
            if( preambuloPos == -1 )
                preambuloPos = this->bufferTemp.length();
            this->bufferTemp.remove(0, preambuloPos );
            cout<<endl<<endl<<"***  Buscando cabecera, elimnando:"<<preambuloPos<<" bytes ***"<<endl<<endl;
            return true;
        }
        else
            this->estado = RecibiendoNuevaTrama;
    }

    if( this->estado == RecibiendoNuevaTrama )
    {
        if( this->bufferTemp.size() < 2 )//los dos primeros bytes indican inicio de trama y comando
            return false;

        if( nsFija::X2PreHeader::getPreAmbulo( this->bufferTemp ) ==  nsFija::PreambuloX2 )
        {
            cout<<"Nueva Trama OK No: ["<<++this->cantTramasRecibidas<<"]"<<endl;
            this->cmdActual          = nsFija::X2PreHeader::getCmdCode( this->bufferTemp );
            estado                   = ProcesandoEncabezado;
        }
        else
        {
            //si no coincide hay que hacer un log
            //this->session->cerrarSession();
            cout<<"No coincide"<<endl;
        }
    }

    if( this->estado == ProcesandoEncabezado )
    {
        switch ( this->cmdActual )
        {
        case nsFija::nCmdCode_SuplementaryServiceEvent:
        case nsFija::nCmdCode_CallRelatedEvent:
        case nsFija::nCmdCode_ChannelEvent:
        case nsFija::nCmdCode_Desconocido:
            {

                this->datosLeer             = 51;
                if( this->datosLeidosCompletos() )
                {
                    qDebug()<<"[CABECERA]"<<endl;
                    this->eventActual        = new QX2Event( &this->buffer, this->getCmdNormalizado() );
                    this->datosLeer          = this->eventActual->getWLength();
                    estado                   = ProcesandoCuerpo;
                    this->reiniciarBufferTemporal();
                }
                break;
            }

        case nsFija::nCmdCode_HandShake           :
            {
                this->datosLeer             = 6;
                if( this->datosLeidosCompletos() )
                {
                    HandShake hs( new QByteArray( this->buffer.left( this->buffer.size() ) ) );
                    this->datosLeer          = hs.getDWLength();
                    estado                   = ProcesandoCuerpo;
                    this->reiniciarBufferTemporal();
                }
                break;
            }

        }
    }
    return true;
}

bool NGN_FIJA_Controller::procesarCuerpoTrama()
{
    switch ( this->cmdActual )
    {        
    case nsFija::nCmdCode_CallRelatedEvent:
        {                        


            if( this->datosLeidosCompletos() )
            {
                //qDebug()<<"trama"<<this->buffer.toHex();
                qDebug()<<"[procesandoCuerpo-->EventNotification]"<<endl;
                //CallRelatedEvent *e = new CallRelatedEvent(*this->eventActual, &this->buffer);

                if(this->buffer.length()>0)
                {
                    qDebug()<<"Buffer length"<<buffer.length();

                    // emit signalsQX2Events(new CallRelatedEvent(*this->eventActual, &this->buffer));
                    // delete this->eventActual;
                    this->buffer.clear();
                }
                this->estado = IDLE;

               }
                return true;
                break;
            }

    case nsFija::nCmdCode_Desconocido :/**   VER DESPUES  **/
        //Control de eventos de notificacion.
    case nsFija::nCmdCode_ChannelEvent:
        {

            qDebug()<<"[procesandoCuerpo-->ChannelEvent]"<<endl;
            /**
                AQUI SOLO SE VA HACER UN LOG PARA NO PONER EL
                EVENTO EN COLA, ESTE NO SE ESTA ENVIANDO AL MC.
                ESTA RELACIONADO CON LA APERTURA Y CIERRE DEL
                CANAL X3(CONTENIDO DE LA COMUNICACION)
                **/
            //ChannelControlEvent e(*this->eventActual, &this->buffer);
            qDebug()<<"CHANEL:"<<this->bufferTemp.toHex();
            this->estado = IDLE;
            // delete this->eventActual;
            return true;
            break;
        }

        //Servicio Suplementario.
    case nsFija::nCmdCode_SuplementaryServiceEvent :
        {
            // qDebug()<<this->buffer.toHex();
            //            if( this->datosLeidosCompletos() )
            //            {
            qDebug()<<"[procesandoCuerpo-->SuplementaryService]"<<endl;
            if( this->datosLeidosCompletos() )
            {
                if(this->buffer.length()>0)
                {
                    qDebug()<<"Buffer length"<<buffer.length();
                    //  emit signalsQX2Events(new CallRelatedEvent(*this->eventActual, &this->buffer));
                    this->buffer.clear();
                    //    delete this->eventActual;
                }
                this->estado = IDLE;

            }
            return true;
            break;
        }

        //HandShanke
    case nsFija::nCmdCode_HandShake           :
        {                        
            if( this->datosLeidosCompletos() )
            {
                cout<<"[procesandoCuerpo-->HandShake]"<<endl;
                HandShake *hs     = new HandShake( &this->buffer );
                /*
                  QByteArray *hsEco = new QByteArray;
                  hsEco->append( nsFija::PreambuloX2 );
                  hsEco->append( nsFija::nCmdCode_HandShake );
                  hsEco->append( "\x00\x00" );         //LEAid                  
                  hsEco->append( "\x00\x00\x00\x00" ); //dwLength
                  hsEco->append( "\x00\x00" );         //
                  this->session->enviarDatos( hsEco );
                  delete hsEco;
                  */
                delete hs;
                this->estado        = IDLE;
            }
            break;
        }
    }
        return false;
    }

    bool NGN_FIJA_Controller::datosLeidosCompletos()
    {
        if( (this->bufferTemp.size()) && (this->datosLeidos < this->datosLeer) )
        {
            qWarning()<<"Datos a leer: "<<this->datosLeer;
            QByteArray d = this->bufferTemp.left( this->datosLeer - this->datosLeidos );
            this->buffer.append( d );
            this->bufferTemp.remove(0, d.size() );
            this->datosLeidos += d.size();
        }
        return (this->datosLeidos == this->datosLeer);
    }

    void NGN_FIJA_Controller::reiniciarBufferTemporal()
    {
        this->datosLeidos = 0;
    }

    QX2Event::e_X2EVENT NGN_FIJA_Controller::getCmdNormalizado()
    {
        QX2Event::e_X2EVENT eventType = QX2Event::PRE_PROCESS;
        switch ( this->cmdActual )
        {
        case nsFija::nCmdCode_SuplementaryServiceEvent:
            {
                eventType =  QX2Event::SUPLEMENTARY_SERVICE_EVENT;
                break;
            }
        case nsFija::nCmdCode_CallRelatedEvent:
            {
                eventType =  QX2Event::CALL_RELATED_EVENT;
                break;
            }
        case nsFija::nCmdCode_ChannelEvent:
        case nsFija::nCmdCode_Desconocido:
            {
                eventType =  QX2Event::CHANNEL_CONTROL_EVENT;
                break;
            }
        case nsFija::nCmdCode_HandShake           :
            {
                eventType =  QX2Event::HANDSHAKE_EVENT;
                break;
            }
        }
        return eventType;
    }
