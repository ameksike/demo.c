#include "nom_mc.h"
#include <QSqlQuery>
#include <QVariant>
#include <QHostAddress>

Nom_MC::Nom_MC()
{
}

void Nom_MC::setId(QString _id)
{
    this->id = _id;
}

QString Nom_MC::getId()
{
    return this->id;
}

QString Nom_MC::generateSelectStatement()
{
    return QString("SELECT idmc, diripservidoriri, puertoservidoriri, usuarioservidoriri, claveservidoriri FROM adm.nom_mc ")
           +(this->getId().length() > 0 ? QString("WHERE (idmc = ") + this->getId() + QString(" )") : QString(""));
}

QString Nom_MC::generateSelectStatementMCEspejos()
{
    return QString("SELECT idmc, diripservidoriri, puertoservidoriri, usuarioservidoriri, claveservidoriri FROM adm.nom_mc ")
           + QString("WHERE esespejo");
}



Servicio* Nom_MC::getMC(QSqlQuery *query)
{
    Servicio *mc = NULL;
    QString sql = this->generateSelectStatement();
    if( query->exec( sql ) )
    {
      query->first();
      mc = new Servicio;
      mc->setId( query->value(0).toInt() );
      mc->setDirIP( QHostAddress( query->value(1).toString() ) );
      mc->setPuerto( query->value(2).toInt() );
      mc->setUsuario( query->value(3).toString() );
      mc->setClave( query->value(4).toString() );
      mc->setEstado( Servicio::DESCONOCIDO );
    }
    return new Servicio( *mc );
}

QList<Servicio*> Nom_MC::getMCEspejos(QSqlQuery *query)
{
   QString sql = this->generateSelectStatementMCEspejos();

   QList<Servicio*> mcEspejos;

   if( query->exec( sql ) )
   {
       while( query->next() )
       {
           Servicio *mc = new Servicio;
           mc->setId( query->value(0).toInt() );
           mc->setDirIP( QHostAddress( query->value(1).toString() ) );
           mc->setPuerto( query->value(2).toInt() );
           mc->setUsuario( query->value(3).toString() );
           mc->setClave( query->value(4).toString() );
           mc->setEstado( Servicio::DESCONOCIDO );
           mc->setEspejo();
           mcEspejos.append( mc );
       }
   }
   return QList<Servicio*>( mcEspejos );
}
