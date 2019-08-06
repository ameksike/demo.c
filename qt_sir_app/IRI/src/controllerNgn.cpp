#include "controllerNgn.cpp.h"
#include <QDebug>
#include "src/ngn_fija_controller.h"
controllerNgn::controllerNgn()
{

};
void controllerNgn::run()
{
  qDebug()<<"Entrando void controllerNgn::run()";
  NGN_FIJA_Controller *Fija= new NGN_FIJA_Controller;
  connect(this,SIGNAL(signalMgs(QByteArray)),Fija,SLOT(slotProcesarDatos(QByteArray)));
  connect(Fija,SIGNAL(signalsQX2Event(QX2Event*)),this,SIGNAL(signalsQX2Events(QX2Event*)));
  Fija->iniciarDF();
  exec();
}
