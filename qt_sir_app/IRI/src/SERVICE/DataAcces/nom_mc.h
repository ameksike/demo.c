#ifndef NOM_MC_H
#define NOM_MC_H
#include <QString>
#include "src/servicio.h"
class QSqlQuery;

class Nom_MC
{
public:
    Nom_MC();
    void setId(QString);
    QString getId();
    Servicio *getMC(QSqlQuery*);
    QList<Servicio*> getMCEspejos(QSqlQuery*);

private:
    QString id;
    QString diripServidorIRI;
    QString puertoServidorIRI;
    QString usuarioServidorIRI;
    QString claveServidorIRI;
    QString generateSelectStatement();
    QString generateSelectStatementMCEspejos();

};

#endif // NOM_MC_H
