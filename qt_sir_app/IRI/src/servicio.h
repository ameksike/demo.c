#ifndef SERVICIO_H
#define SERVICIO_H

#include<QtGlobal>

#include <QHostAddress>
#include <QTcpServer>
#include <QString>
#include <QDateTime>

#include <stdio.h>
#include <stdlib.h>

#include <cstdlib>
#include <iostream>

#include <fstream>
#include <QEvent>

using namespace std;

class Servicio
{  
  public:
    typedef enum
    {
      FUERA_SERVICIO = 10,
      SERVICIO           ,
      INICIANDO          ,
      ACTIVO             ,
      INACTIVO           ,
      PROCESANDO_EVENTOS_PENDIENTES,
      DESCONOCIDO
    } EstadosServicio;

    Servicio();

    Servicio(Servicio &other);

    virtual ~Servicio();

    quint16 getId();

    QHostAddress getDirIP();

    quint16  getPuerto();

    QString  getUsuario();

    QString  getClave();

    EstadosServicio getEstado();

    bool esEspejo();

    QDateTime getFHUltimoEstado();

    void setId( quint16 _id)
    {
        this->id = _id;
    }

    void setDirIP(QHostAddress _dirIP)
    {
        this->dirIP = _dirIP;
    }

    void setPuerto(quint16 _puerto)
    {
        this->puerto = _puerto;
    }

    void setUsuario(QString _usuario)
    {
        this->usuario = _usuario;
    }

    void setClave(QString _clave)
    {
        this->clave = _clave;
    }

    void setEstado(EstadosServicio _estado)
    {
        this->estado = _estado;
    }

    void setEspejo( bool _espejo = true)
    {
        this->espejo = _espejo;
    }

    bool operator ==(const Servicio& other) const
    {
       bool igual = true;
       igual      = igual && (other.dirIP   == this->dirIP);
       igual      = igual && (other.usuario == this->usuario);
       igual      = igual && (other.clave   == this->clave);
       igual      = igual && (other.puerto  == this->puerto);
       igual      = igual && (other.espejo  == this->espejo);
       return igual;
    }

protected:
  quint16 id;
  QHostAddress dirIP;
  quint16 puerto;
  QString usuario;
  QString clave;
  EstadosServicio estado;
  QDateTime fhUltimoEstado;
  bool espejo;
  virtual bool autenticar();
};

class QServicioEvent: public QEvent
{
  public:

    enum { SERVICIO_EVENT = QEvent::Type( QEvent::User + 130 ) };

    QServicioEvent(Servicio* _s = 0):QEvent( QEvent::Type( SERVICIO_EVENT ) ), s( new Servicio( *_s ) )
    {
    }

    QServicioEvent(QServicioEvent &other):QEvent( other.type() )
    {
        this->s = new Servicio( *other.s );
    }

    ~QServicioEvent()
    {
        cout<<"QServicioEvent::~QServicioEvent() id:"<<this->s->getId()<<endl;
       // delete this->s;
    }

    void setServicio(Servicio*_s)
    {
        this->s = _s;
    }

    Servicio* getServicio()
    {
        return this->s;
    }

private:
    Servicio *s;
};


#endif // SERVICIO_H
