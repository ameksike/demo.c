#include "servicio.h"

Servicio::Servicio()
{    
    this->espejo = false;
}
Servicio::Servicio(Servicio &other)
{
    this->dirIP          = other.dirIP;
    this->puerto         = other.puerto;
    this->usuario        = other.usuario;
    this->clave          = other.clave;
    this->id             = other.id;
    this->estado         = other.estado;
    this->fhUltimoEstado = other.fhUltimoEstado;
    this->espejo         = other.espejo;
}

Servicio::~Servicio()
{
}

bool Servicio::autenticar()
{
    return true;
}

quint16 Servicio::getId()
{
    return this->id;
}

QHostAddress Servicio::getDirIP()
{
    return this->dirIP;
}

quint16 Servicio::getPuerto()
{
    return this->puerto;
}

QString Servicio::getUsuario()
{
    return this->usuario;
}

QString Servicio::getClave()
{
    return this->clave;
}

Servicio::EstadosServicio Servicio::getEstado()
{
    return this->estado;
}

QDateTime Servicio::getFHUltimoEstado()
{
    return this->fhUltimoEstado;
}

bool Servicio::esEspejo()
{
    return this->espejo;
}
