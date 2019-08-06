//---------------------------------------------------------------------------
/**
 * @package    db
 * @subpackage postgres
 * @author     ing. Antonio Membrides Espinosa
 * @date       22/09/2008
 * @version    1.0
 */
//---------------------------------------------------------------------------
#include <QApplication>
#include <QTableView>
#include <QtDebug>
#include "CPostgreSQL.h"
//-------------------------------------------------------------------------
int main(int argc, char *argv[])
{
	QApplication* app   = new QApplication(argc, argv);
	CPostgreSQL * DB    = new CPostgreSQL("Membri","postgres","root","10.12.167.167");

	QString sintaxissql1 = "SELECT * FROM \"Personal\".\"Persona\"";
	QString sintaxissql2 = "INSERT INTO \"Personal\".\"Persona\" (\"Nombre\",\"Edad\",\"Sexo\") VALUES ('M', 22, 'F')";
	QString sintaxissql3 = "DELETE FROM \"Personal\".\"Persona\" WHERE \"Personal\".\"Persona\".\"Nombre\" = 'M'";
	QString sintaxissql4 = "UPDATE \"Personal\".\"Persona\" SET \"Nombre\" = \"A\" WHERE \"Nombre\" = 'M'";

	if(DB->EjecutarSQL(sintaxissql3))
           qDebug() << "Exito";

	QTableView* view = DB->Obtener_Vista(sintaxissql1);
	view->show();

	return app->exec();
}
//-------------------------------------------------------------------------