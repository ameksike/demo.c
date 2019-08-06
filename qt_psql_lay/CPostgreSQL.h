//---------------------------------------------------------------------------
/**
 * @package    db
 * @subpackage postgres
 * @author     ing. Antonio Membrides Espinosa
 * @date       22/09/2008
 * @version    1.0
 */
//---------------------------------------------------------------------------
#ifndef CPOSTGRESQL_H
#define CPOSTGRESQL_H
//-------------------------------------------------------------------------
class QSqlDatabase;
class QTableView;
#include <QString>
#include <QSqlQueryModel>
//-------------------------------------------------------------------------
class CPostgreSQL
{
 private:
	QSqlQuery*      OBJ_ExecSQL;
	QSqlDatabase*   OBJ_DB;
	bool _Estado_Coneccion;

 public:
	CPostgreSQL(QString NombreBD="postgres", QString User="root", QString Passwd="", QString Host="localhost");
	~CPostgreSQL();
	QTableView* Obtener_Vista(QString SQLSentencia);
	QSqlQueryModel* EjecutarSQL(QString SQLSentencia, bool Seleccion);
	bool EjecutarSQL(QString SQLSentencia);
	bool Estado_Coneccion();
};
//-------------------------------------------------------------------------
#endif
