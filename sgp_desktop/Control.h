/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       04/07/2006
 * @version    1.5
 */
#ifndef ControlH
#define ControlH
//................Librerias para Bases de Dato...............................
#include <vcl.h>
#include <ADODB.hpp>
//---------------------------------------------------------------------------
class Control
{
  private:
    AnsiString ConetStrin;
    TADOConnection* ADOConnection;
    TADOQuery*  ADOQuery;
    TDataSource* DataSource;
    TComponent* Owner;
  public:
    Control(TADOConnection *vADOConnection, Classes::TComponent* AOwner);
    void Conecion(AnsiString Servidor, AnsiString BaseDato);
    void Desconectar();
    void VaciarBaseDato();
    void EjecutarSentenciaSQL(AnsiString vSentencia, TDataSource *vDataSource);
    bool ChequearRegistro(AnsiString user, AnsiString passw);
    ~Control();
};
//---------------------------------------------------------------------------
#endif
 