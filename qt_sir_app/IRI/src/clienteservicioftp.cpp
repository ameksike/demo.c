#include "clienteservicioftp.h"

void ClienteServicioFTP::finEjecucionComando(int cmdId, bool error)
{   
   if(error)
   {
       this->errorUltimoComando = this->error();       
       cout<<"ClienteServicioFTP::finEjecucionComando Cmd["<<this->ultimoComandoEjecutado<<"]"<<"ftp Error"<<endl<<"["<<this->errorString().toStdString().c_str()<<"]"<<endl;
   }    
   else
   {
       this->errorUltimoComando = QFtp::NoError;
       cout<<"ClienteServicioFTP::finEjecucionComando Cmd["<<this->ultimoComandoEjecutado<<"]"<<" ftp Bien"<<endl;
     if(this->ultimoComandoEjecutado==4)
       {
//         if(!this->execTransferSalva)
//              this->executePending();

         }

   }

   if( !error && ( ((this->ultimoComandoEjecutado == QFtp::Put) && !this->salvarArchivoConNombreTemporal) || (this->ultimoComandoEjecutado == QFtp::Rename) ) )
   {
       quint64  numTransferencia = this->transferenciasActivas.take( cmdId );
       if( !this->servicio->esEspejo() )       
         emit this->finTransferencia( this->servicio->getId(), numTransferencia, error );

       if( this->transferenciasActivas.empty()  && !this->servicio->esEspejo())
       {
           cout<<"iniciando timer de inactividad"<<endl;
           this->timerControlInactividad.start(this->tiempoMaximoInactividad, this);
       }       
   }
}

void ClienteServicioFTP::finEjecucionUltimoComando(bool error)
{    

    cout<<"ClienteServicioFTP::finEjecucionUltimoComando id:"<<this->servicio->getId()<<"cmd: "<<this->ultimoComandoEjecutado<<endl;

    if( this->ultimoComandoEjecutado == QFtp::ConnectToHost )
    {
        if( !error )
        {           
           this->login();
        }
        else
            emit this->cambioEstadoServicio( Servicio::FUERA_SERVICIO, this->servicio->getId() );
        return;
    }

    if( this->ultimoComandoEjecutado == QFtp::Login )
    {
        if( !error )
        {
            cout<<"coneccion ok"<<endl;
            emit this->cambioEstadoServicio( Servicio::ACTIVO, this->servicio->getId() );
            if( !this->servicio->esEspejo() )
               this->timerControlInactividad.start( this->tiempoMaximoInactividad, this);
        }
        else
        {           
            this->close();
        }
        return;
    }


    if( this->ultimoComandoEjecutado == QFtp::Close )
    {
        emit this->coneccionCerrada( this->servicio->getId(), error );
    }
}
