#include "ftpmanager.h"
#include "qirievent.h"


void FTPManager::timerEvent(QTimerEvent *te)
{
    if( te->timerId() == this->timerInactividad )
    {
        cout<<" 15s de inactividad"<<endl;
        //emit this->cambioEstadoServicio( Servicio::INACTIVO, this->getId() );
        //emit this->cerrarPorInactividad();
        this->detenerTimerControlInactividad();
    }
}

void FTPManager::activarTimerControlInactividad()
{
    if( !this->timerInactividad )
    {
      cout<<"[timer de inactividad del ftp iniciado"<<endl;
      this->timerInactividad = this->startTimer( this->tiempoMaximoInactividad );
    }
}

void FTPManager::detenerTimerControlInactividad()
{
    if( this->timerInactividad )
    {
        this->killTimer( this->timerInactividad );
        this->timerInactividad = 0;
    }
}


/** *******************************************************************************
 *                                                                                *
 *                             METODOS PARA NOMBRAR ARCHIVOS                      *
 *                                                                                *
 ******************************************************************************* **/


QString FTPManager::getNombreArchivo()
{
    QString fileName;
    if( this->MNArchivos == METODO_A )
      fileName = this->getNombreArchivoMetodoA();
    else
      fileName = this->getNombreArchivoMetodoB();
    return fileName;
}

QString FTPManager::getNombreArchivoMetodoA()
{
    QString file;
    file.append( this->metodoA_LIID );
    file.append( "_");
    file.append( this->metodoA_seq );
    file.append( ".");
    file.append( this->metodoA_ext );
    return file;
}

QString FTPManager::getNombreArchivoMetodoB()
{
    /**
        Two letter ASCII Operator ID (as agreed with the national telecom regulators).
        Two letter ASCII identification of the MF node (as assigned by the operator).
    **/
    QString file;
    file.append( this->metodoB_OperatorID );
    file.append( this->metodoB_MFNode );
    file.append( QDateTime::currentDateTime().toString( this->metodoB_DateTimeFormat ) );
    this->generarExtension_eeee();
    file.append( this->metodoB_eeee );
    file.append( this->metodoB_t );

    /**
         Two digits ASCII integer ranging between ["00"..."99"], identifying the last two digits of the year.
         Two digits ASCII integer ranging between ["01"..."12"], identifying the month.
         Two digits ASCII integer ranging between ["01"..."31"], identifying the day.
         Two digits ASCII integer ranging between ["00"..."23"], identifying the hour.
         Two digits ASCII integer ranging between ["00"..."59"], identifying the minute.
         Two digits ASCII integer ranging between ["00"..."59"], identifying the second

      **/

    /**
         0000 = extension
         1=     file type. The type "1" is reserved for IRI data files and type "8" is reserved for national use
    **/
    return file;
}

void FTPManager::setMetodoNombrarArchivos(MetodoNombrarArchivos metodo)
{
    this->MNArchivos = metodo;
}

void FTPManager::setLIID(QString liid)
{
    this->metodoA_LIID = liid;
}

void FTPManager::setOperatorID(QString operatorId)
{
    this->metodoB_OperatorID = operatorId;
}

void  FTPManager::setIRIServerID(QString IRIServerID)
{
    this->metodoB_MFNode = IRIServerID;
}

void FTPManager::setFileType(QString t)
{
    this->metodoB_t = t;
}
