#include "Controler.h"

Controller::Controller()
    : cmdActual(0), datosLeer(51),
      datosLeidos(0), nuevaTrama(true), procesandoCabecera(false), estado(IDLE)
{    
    this->eventActual           = NULL;
    this->cantTramasRecibidas = 0;
    connect( this, SIGNAL(signalProcesarDatos(QByteArray)), this, SLOT(slotProcesarDatos(QByteArray)));    
}

Controller::~Controller()
{
    delete this->eventActual;
    this->eventActual = NULL;
}



