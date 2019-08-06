#include "lig.h"
#include "src/qx2event.h"

LIG::LIG(int argc, char* argv[]):QCoreApplication(argc, argv)
{

    this->init();

}

void LIG::proccessEvent(QX2Event *e)
{
  qDebug()<<"Recibiendo evento"<< e->type();
  //this->df->slotNuevoEvento(e);
  // this->df->slotNuevoEvento(e);
  delete e;
}

LIG::~LIG()
{

}

int LIG::run()
{

}



void LIG::init()
{
    this->loadConfiguration();
    this->TCP_Server = new controllerTcp;
    this->NgnQEvent  = new controllerNgn;
    connect(this->TCP_Server,SIGNAL(sendTrama(QByteArray)),this->NgnQEvent,SIGNAL(signalMgs(QByteArray)));
    connect(this->NgnQEvent,SIGNAL(signalsQX2Events(QX2Event*)),this,SLOT(proccessEvent(QX2Event*)));

    this->TCP_Server->start();
    this->NgnQEvent->start();
}

void LIG::loadConfiguration()
{

        this->setDefaultConfiguration();
}

void LIG::setDefaultConfiguration()
{   
   this->settings = new QSettings(QSettings::IniFormat, QSettings::SystemScope, "");

   /** DATOS DEL LIG  **/
   this->settings->setValue("lig/x1port", QVariant(6666));
   this->settings->setValue("lig/x2port", QVariant(8888));

   /** DATOS PARA ACCEDER A LA BASE DE DATOS **/
   this->settings->setValue("database/name"  , QVariant("LEA2"));
   this->settings->setValue("database/server", QVariant("172.25.46.103"));
   this->settings->setValue("database/user"  , QVariant("lea"));
   this->settings->setValue("database/passw" , QVariant("lea"));
   this->settings->setValue("database/port"  , QVariant(5432));

   /** DATOS PARA EL ENVIO DE IRIs **/
   this->settings->setValue("deliveryfunction/mechanism", QVariant("ftp"));

   /** DATOS PARA LA ADMINISTRACION **/
   this->settings->setValue("cli/allow", QVariant("localhost"));
   this->settings->setValue("cli/maxconnections", QVariant("1"));
   this->settings->setValue("cli/port", QVariant("2323"));

}
