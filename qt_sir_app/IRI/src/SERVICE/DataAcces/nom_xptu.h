#ifndef NOM_XPTU_H
#define NOM_XPTU_H

#include <QString>
#include "src/servicio.h"
class QSqlQuery;
class Nom_XPTU
{
public:
    Nom_XPTU();
    void setId(QString);
    void setDirIP(QString);
    QString getId();
    QString getDirIP();
    //Servicio *getXPTU(QSqlQuery*);
    bool dirIPValida(QSqlQuery*);

private:
    QString idxptu;
    QString dirip;
    QString denom;
    QString puertohi1;
    QString idredpss;//Proveedor del Servicio de Supervision
    QString iddominio;
    QString generateSelectPorDirIP();
    QString generateSelectStatement();
};

#endif // NOM_XPTU_H
