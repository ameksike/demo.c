//---------------------------------------------------------------------------
/**
 * @package    db
 * @subpackage postgres
 * @author     ing. Antonio Membrides Espinosa
 * @date       22/09/2008
 * @version    1.0
 */
//---------------------------------------------------------------------------
#include "CPostgreSQL.h"
#include <QTableView>
#include <QtSql>
//-------------------------------------------------------------------------
CPostgreSQL::CPostgreSQL(QString NombreBD, QString User, QString Passwd, QString Host)
{
        OBJ_DB = &QSqlDatabase::addDatabase("QPSQL");
        OBJ_DB->setHostName(Host);
	OBJ_DB->setDatabaseName(NombreBD);
	OBJ_DB->setUserName(User);
	OBJ_DB->setPassword(Passwd);
	OBJ_ExecSQL	  = 0;
	_Estado_Coneccion = OBJ_DB->open();

}
//-------------------------------------------------------------------------
CPostgreSQL::~CPostgreSQL()
{
	delete OBJ_DB;
	delete OBJ_ExecSQL;
}
//-------------------------------------------------------------------------
bool CPostgreSQL::EjecutarSQL(QString SQLSentencia)
{
	if(!OBJ_ExecSQL)
		OBJ_ExecSQL = new QSqlQuery;

	if(_Estado_Coneccion)
		return OBJ_ExecSQL->exec(SQLSentencia);
	return 0;
}
//-------------------------------------------------------------------------
QSqlQueryModel* CPostgreSQL::EjecutarSQL(QString SQLSentencia, bool Seleccion)
{
        if(Seleccion && _Estado_Coneccion)
	{
		QSqlQueryModel* OBJ_Tabla = new QSqlQueryModel;
		OBJ_Tabla->setQuery(SQLSentencia);
		return OBJ_Tabla;
	}
	return 0;
}
//-------------------------------------------------------------------------
bool CPostgreSQL::Estado_Coneccion()
{
	return _Estado_Coneccion;
}
//-------------------------------------------------------------------------
QTableView* CPostgreSQL::Obtener_Vista(QString SQLSentencia)
{
	QTableView* Vista_Tabla = new QTableView;
	Vista_Tabla->setModel(EjecutarSQL(SQLSentencia, 1));
	return Vista_Tabla;
}
//-------------------------------------------------------------------------
