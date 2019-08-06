/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       04/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#pragma hdrstop
#include "Control.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Control::Control(TADOConnection *vADOConnection, Classes::TComponent* AOwner)
{
   Owner = AOwner;
   ADOConnection = vADOConnection;
   ADOQuery = new TADOQuery(Owner);
   ADOQuery->Connection = ADOConnection;
   DataSource = new TDataSource(Owner);
   ConetStrin = "";
   
   // Nota: el parametro ' Classes::TComponent* AOwner ' lo necesitan las clases   TADOQuery, TDataSource y TADOConnection   en sus contructores
}
//---------------------------------------------------------------------------
void Control::Conecion(AnsiString Servidor,AnsiString BaseDato)
{  //....................Este metodo es el encargado de establecer una coneccion con la Base de Datos dado el nombre de la misma y el servidor [que se le pasa por parametro ]
    Desconectar();
    //....................
    ConetStrin = "";
    ConetStrin = "Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=";
    ConetStrin.operator +=(BaseDato);
    ConetStrin.operator +=(";Data Source=");
    ConetStrin.operator +=(Servidor);
    //....................
    ADOConnection->ConnectionString = ConetStrin;
    ADOConnection->Connected = true;
}
//---------------------------------------------------------------------------
void Control::Desconectar()
{  //....................Este metodo es el encargado de resetear el ADOConnection es decir desconecta la aplicacion de la Base de Datos
   ADOConnection->Connected = false;
   ADOConnection->ConnectionString.Empty();
}
//---------------------------------------------------------------------------
bool Control::ChequearRegistro(AnsiString user, AnsiString passw)
{  //....................Este metodo es el encargado de chequear la seguridad, es decir chequea el control de accesos a mi Base de Dato
   AnsiString Sentencia = "SELECT Contrase�a  FROM Seguridad WHERE (Usuario = '"; 
   Sentencia += user + "')";
   EjecutarSentenciaSQL(Sentencia, this->DataSource);
   for(int i=0; i<DataSource->DataSet->RecordCount; i++)
     {
       AnsiString pass =  this->DataSource->DataSet->Fields->operator [](0)->AsString;
       this->DataSource->DataSet->MoveBy(1);
       if(pass == passw)
         return true;
     }
   return false;
}
//---------------------------------------------------------------------------
void Control::EjecutarSentenciaSQL(AnsiString vSentencia,TDataSource *vDataSource)
{  //...................Este metodo ejecuta una sentencia en SQL [que se le pasa por parametro ] los resultados se guardan en el DataSource [que se le pasa por parametro ]
   ADOQuery->Close();
   ADOQuery->SQL->Text = vSentencia;
   ADOQuery->Prepared = true;
   ADOQuery->Active = true;
   ADOQuery->ExecSQL();
   //...................
   vDataSource->DataSet = ADOQuery;
}
//---------------------------------------------------------------------------
Control::~Control()
{  //..................Este metodo es el destructor de la clase (donde se destruyen los punteros)
   delete ADOConnection;
   delete ADOQuery;
   delete DataSource;
}
//---------------------------------------------------------------------------
void Control::VaciarBaseDato()
{
  TADOStoredProc* Procedure = new TADOStoredProc(Owner);
  Procedure->Connection = ADOConnection;
  Procedure->ProcedureName = "VaciarDB;1";
  //.........
  Procedure->Active = false;
  Procedure->Prepared = true;
  Procedure->ExecProc();
}
//---------------------------------------------------------------------------

