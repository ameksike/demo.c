#ifndef CONTROLER_H
#define CONTROLER_H
#include <QObject>
#include <QCoreApplication>

#include "src/qx2event.h"
#include "src/qsalvaevent.h"

#include "SERVICE/DataAcces/Query.h"
#include "src/Entity/Utils.h"
#include <iostream>
#include <QWaitCondition>
#include <QMutex>

using namespace std;


//class Session;

class Controller: public QObject
{
    Q_OBJECT
   public:
    typedef enum
    {
       IDLE,
       Sincronizando,
       RecibiendoNuevaTrama,
       ProcesandoEncabezado,
       ProcesandoCuerpo,
       EnviandoEvento
    } enumControllerStatus;

  protected:
    quint64              cantTramasRecibidas;
    //Session              *session;
    QByteArray            bufferTemp;
    QByteArray           buffer;
    quint8               cmdActual;
    QX2Event*            eventActual;
    quint64              datosLeer;
    quint64              datosLeidos;
    bool                 nuevaTrama;
    bool                 procesandoCabecera;
    enumControllerStatus estado;

  public:
    Controller();

    virtual ~Controller(); 

    quint64 getCantidadTramasRecibidas()
    {
        return this->cantTramasRecibidas;
    }

    enumControllerStatus getEstado()
    {
        return this->estado;
    }



signals:
  void signalProcesarDatos(QByteArray);

  void signalDatosProcesados();

  void signalNuevoEvento(QEvent*);  

protected slots:
  virtual void slotProcesarDatos(QByteArray) = 0;

public slots:
  virtual void slotSessionIniciada(){}
};


#endif // CONTROLER_H
