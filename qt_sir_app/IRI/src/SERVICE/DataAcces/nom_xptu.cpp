#include "nom_xptu.h"
#include<QSqlQuery>

Nom_XPTU::Nom_XPTU()
{
}

void Nom_XPTU::setId(QString _id)
{
    this->idxptu = _id;
}

QString Nom_XPTU::getId()
{
    return this->idxptu;
}
QString Nom_XPTU::getDirIP()
{
    return this->dirip;
}

void Nom_XPTU::setDirIP(QString _dirip)
{
    this->dirip = _dirip;
}

QString Nom_XPTU::generateSelectStatement()
{
    return QString("SELECT idxptu, dirip, idredpss, puertohi1 FROM adm.nom_xptu ")
           +(this->getId().length() > 0 ? QString("WHERE (idxptu = ") + this->getId() + QString(" )") : QString(""));
}

QString Nom_XPTU::generateSelectPorDirIP()
{
    return QString("SELECT idxptu FROM adm.nom_xptu ")
           +(this->getDirIP().length() > 0 ? QString("WHERE (dirip = '") + this->getDirIP() + QString("' )") : QString(""));
}

bool Nom_XPTU::dirIPValida(QSqlQuery * query)
{
    QString sql = this->generateSelectPorDirIP();
    bool valida = false;
    if( query->exec( sql ) )
    {
       query->first();
       valida = query->isValid();
    }
    return valida;
}

/*Servicio* Nom_XPTU::getXPTU(QSqlQuery *query)
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
    return mc;
}*/


