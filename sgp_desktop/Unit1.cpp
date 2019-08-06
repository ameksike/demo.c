/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       02/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TDataModuleTablas *DataModuleTablas;
//---------------------------------------------------------------------------
__fastcall TDataModuleTablas::TDataModuleTablas(TComponent* Owner)
        : TDataModule(Owner)
{
    MyOwner = Owner;
}
//---------------------------------------------------------------------------
void TDataModuleTablas::ActivarTablas()
{
   ADOTComponente->Active = true;
   ADOTModulo->Active = true;
   ADOTPersona->Active = true;
   ADOTProblema->Active = true;
   ADOTProyecto->Active = true;
   ADOTSeguridad->Active = true;
   ADOTTarea->Active = true;
   ADOT_TareaPersona->Active = true;
   ADOT_ModuloComponente->Active = true;
   ADOT_ComponenteProblema->Active = true;
   ADOT_Listado_de_ComponentesT->Active = true;
}
//---------------------------------------------------------------------------
void TDataModuleTablas::DesactivarTablas()
{
   ADOTComponente->Active = false;
   ADOTModulo->Active = false;
   ADOTPersona->Active = false;
   ADOTProblema->Active = false;
   ADOTProyecto->Active = false;
   ADOTSeguridad->Active = false;
   ADOTTarea->Active = false;
   ADOT_TareaPersona->Active = false;
   ADOT_ModuloComponente->Active = false;
   ADOT_ComponenteProblema->Active = false;
   ADOT_Listado_de_ComponentesT->Active = false;
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Actualizar()
{
  DesactivarTablas();
  ActivarTablas();
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Insertar_Componente(AnsiString IDComponente,AnsiString Responsable,AnsiString Nombre,AnsiString version, AnsiString FechaInicio)
{ //....Este metotodo permite insertar un componente
  //...................................................................
  TParameter* IdComponente = ADOSP_Componente->Parameters->ParamByName("@IdComponente_1");
  TParameter* TResponsable = ADOSP_Componente->Parameters->ParamByName("@PersonaResponsable_2");
  TParameter* TNombre      = ADOSP_Componente->Parameters->ParamByName("@Nombre_3");
  TParameter* Tversion     = ADOSP_Componente->Parameters->ParamByName("@Version_4");
  TParameter* TFechaInicio = ADOSP_Componente->Parameters->ParamByName("@FechadeInicio_5");
  //....................................................................
  ADOSP_Componente->Active = false;
  //....................................................................
  IdComponente->Value = IDComponente;
  TResponsable->Value = Responsable;
  TNombre->Value      = Nombre;
  Tversion->Value     = version;
  TFechaInicio->Value = FechaInicio;
  //....................................................................
  ADOSP_Componente->Prepared = true;
  ADOSP_Componente->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Insertar_Proyecto(AnsiString IdProyecto,AnsiString Nombre,AnsiString Responsable,int Facultad,AnsiString FechaInicio,AnsiString Objetivo)
{ //....Este metotodo permite insertar un nuevo Proyecto
  //...................................................................
  TParameter* TIdProyecto  = ADOSP_Proyecto->Parameters->ParamByName("@IDdeProyecto_1");
  TParameter* TResponsable = ADOSP_Proyecto->Parameters->ParamByName("@PersonaResponsable_3");
  TParameter* TNombre      = ADOSP_Proyecto->Parameters->ParamByName("@Nombre_2");
  TParameter* TFacultad    = ADOSP_Proyecto->Parameters->ParamByName("@Facultad_4");
  TParameter* TFechaInicio = ADOSP_Proyecto->Parameters->ParamByName("@FechadeInicio_5");
  TParameter* TObjetivo    = ADOSP_Proyecto->Parameters->ParamByName("@Objetivo_6");
  //....................................................................
  ADOSP_Proyecto->Active = false;
  //....................................................................
  TIdProyecto->Value  = IdProyecto;
  TResponsable->Value = Responsable;
  TNombre->Value      = Nombre;
  TFacultad->Value    = Facultad;
  TFechaInicio->Value = FechaInicio;
  TObjetivo->Value    = Objetivo;
  //....................................................................
  ADOSP_Proyecto->Prepared = true;
  ADOSP_Proyecto->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Insertar_Tarea(AnsiString IdTarea,AnsiString IdComponente,AnsiString Estado,AnsiString FechaInicio,AnsiString FechaTerminada,AnsiString FechaEntrega,AnsiString Objetibo)
{ //....Este metotodo permite insertar una nueva Persona o trabajador
  //...................................................................
  TParameter* TIdTarea        = ADOSP_Tarea->Parameters->ParamByName("@IDdeTarea_1");
  TParameter* TIdComponente   = ADOSP_Tarea->Parameters->ParamByName("@IdComponente_2");
  TParameter* TEstado         = ADOSP_Tarea->Parameters->ParamByName("@Estado_4");
  TParameter* TFechaInicio    = ADOSP_Tarea->Parameters->ParamByName("@FechadeInicio_5");
  TParameter* TFechaTerminada = ADOSP_Tarea->Parameters->ParamByName("@FechadeTerminada_6");
  TParameter* TFechaEntrega   = ADOSP_Tarea->Parameters->ParamByName("@FechadeEntrega_7");
  TParameter* TObjetibo       = ADOSP_Tarea->Parameters->ParamByName("@Objetivo_3");
  //....................................................................
  ADOSP_Tarea->Active = false;
  //....................................................................
  TIdTarea->Value        = IdTarea ;
  TIdComponente->Value   = IdComponente;
  TEstado->Value         = Estado;
  TFechaInicio->Value    = FechaInicio;
  TFechaTerminada->Value = FechaTerminada;
  TFechaEntrega->Value   = FechaEntrega;
  TObjetibo->Value       = Objetibo;
  //....................................................................
  ADOSP_Tarea->Prepared = true;
  ADOSP_Tarea->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Insertar_Persona(AnsiString Credencial,AnsiString Nombre,AnsiString Apellidos,AnsiString Sexo,AnsiString CarnetIdentidad, AnsiString CorreoE, AnsiString Categoria, AnsiString IdProyecto,AnsiString FechaInicio)
{ //....Este metotodo permite insertar una nueva Persona o trabajador
  //...................................................................
  TParameter* TCredencial       = ADOSP_Persona->Parameters->ParamByName("@#Credencial_1");
  TParameter* TNombre           = ADOSP_Persona->Parameters->ParamByName("@Nombre_2");
  TParameter* TApellidos        = ADOSP_Persona->Parameters->ParamByName("@Apellidos_3");
  TParameter* TCarnetIdentidad  = ADOSP_Persona->Parameters->ParamByName("@CI_5");
  TParameter* TSexo             = ADOSP_Persona->Parameters->ParamByName("@Sexo_4");
  TParameter* TCorreoE          = ADOSP_Persona->Parameters->ParamByName("@CorreoElectronico_6");
  TParameter* TCategoria        = ADOSP_Persona->Parameters->ParamByName("@Categoria_7");
  TParameter* TIdProyecto       = ADOSP_Persona->Parameters->ParamByName("@IDdeProyecto_8");
  TParameter* TFechaInicio      = ADOSP_Persona->Parameters->ParamByName("@FechadeInicioenProyecto_9");

  //....................................................................
  ADOSP_Persona->Active = false;
  //....................................................................
  TCredencial->Value       = Credencial;
  TNombre->Value           = Nombre;
  TApellidos->Value        = Apellidos;
  TCarnetIdentidad->Value  = CarnetIdentidad;
  TSexo->Value             = Sexo;
  TCorreoE->Value          = CorreoE;
  TCategoria->Value        = Categoria;
  TIdProyecto->Value       = IdProyecto;
  TFechaInicio->Value      = FechaInicio;
  //....................................................................
  ADOSP_Persona->Prepared = true;
  ADOSP_Persona->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Insertar_Modulo(AnsiString IdModulo,AnsiString IdProyecto,AnsiString Responsable,AnsiString Nombre,AnsiString Objetivo,AnsiString FechaInicio)
{ //....Este metotodo permite insertar un nuevo Modulo
  //...................................................................
  TParameter* TIdModulo    = ADOSP_Modulo->Parameters->ParamByName("@IDdeM�dulo_1");
  TParameter* TIdProyecto  = ADOSP_Modulo->Parameters->ParamByName("@IDdeProyecto_2");
  TParameter* TResponsable = ADOSP_Modulo->Parameters->ParamByName("@PersonaResponsable_3");
  TParameter* TNombre      = ADOSP_Modulo->Parameters->ParamByName("@Nombre_4");
  TParameter* TObjetivo    = ADOSP_Modulo->Parameters->ParamByName("@Objetivo_5");
  TParameter* TFechaInicio = ADOSP_Modulo->Parameters->ParamByName("@FechadeInicio_6");
  //....................................................................
  ADOSP_Modulo->Active = false;
  //....................................................................
  TIdModulo->Value    = IdModulo;
  TIdProyecto->Value  = IdProyecto;
  TResponsable->Value = Responsable;
  TNombre->Value      = Nombre;
  TObjetivo->Value    = Objetivo;
  TFechaInicio->Value = FechaInicio;
  //....................................................................
  ADOSP_Modulo->Prepared = true;
  ADOSP_Modulo->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Insertar_Problema(AnsiString IdProblema,AnsiString Descripcion)
{ //....Este metotodo permite insertar un nuevo Problema
  //...................................................................
  TParameter* TIdProblema   = ADOSP_Problema->Parameters->ParamByName("@IDdelProblema_1");
  TParameter* TDescripcion  = ADOSP_Problema->Parameters->ParamByName("@DescripciondelP_2");
  //....................................................................
  ADOSP_Problema->Active = false;
  //....................................................................
  TIdProblema->Value  = IdProblema;
  TDescripcion->Value = Descripcion;
  //....................................................................
  ADOSP_Problema->Prepared = true;
  ADOSP_Problema->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Insertar_Usuario(AnsiString Usuario,AnsiString Pasword, Classes::TComponent* AOwner)
{ //....Este metotodo permite insertar un nuevo Usuario en la tabla de seguriad
  //...................................................................
  if(!Existe_Usuario(Usuario, AOwner))
  {
    TParameter* TUsuario   = ADOSP_Seguridad->Parameters->ParamByName("@Usuario_1");
    TParameter* TPasword   = ADOSP_Seguridad->Parameters->ParamByName("@Contrase�a_2");
    //....................................................................
    ADOSP_Seguridad->Active = false;
    //....................................................................
    TUsuario->Value  = Usuario;
    TPasword->Value  = Pasword;
    //....................................................................
    ADOSP_Seguridad->Prepared = true;
    ADOSP_Seguridad->ExecProc();
    //....................................................................
  }
  else
    ShowMessage("El usuario ya existe, por favor vuelva a intentarlo");
  
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Eliminar_Componente(AnsiString IdComponente)
{ //....Este metotodo permite eliminar un Componente de la tabla de Componente
  //...................................................................
  TParameter* TIdComponente   = ADOSP_EComponente->Parameters->ParamByName("@IdComponente_1");
  //....................................................................
  ADOSP_EComponente->Active = false;
  //....................................................................
  TIdComponente->Value  = IdComponente;
  //....................................................................
  ADOSP_EComponente->Prepared = true;
  ADOSP_EComponente->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Eliminar_Proyecto(AnsiString IdProyecto)
{
  //...................................................................
  TParameter* TIdProyecto  = ADOSP_EProyecto->Parameters->ParamByName("@IDdeProyecto_1");
  //....................................................................
  ADOSP_EProyecto->Active = false;
  //....................................................................
  TIdProyecto->Value  = IdProyecto;
  //....................................................................
  ADOSP_EProyecto->Prepared = true;
  ADOSP_EProyecto->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Eliminar_Persona(AnsiString IdPersona)
{
  //...................................................................
  TParameter* TIdPersona  = ADOSP_EPersona->Parameters->ParamByName("@#Credencial_1");
  //....................................................................
  ADOSP_EPersona->Active = false;
  //....................................................................
  TIdPersona->Value  = IdPersona;
  //....................................................................
  ADOSP_EPersona->Prepared = true;
  ADOSP_EPersona->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Eliminar_Modulo(AnsiString IdModulo, AnsiString IdProyecto)
{
  //...................................................................
  TParameter* TIdModulo   = ADOSP_EModulo->Parameters->ParamByName("@IDdeM�dulo_1");
  TParameter* TIdProyecto = ADOSP_EModulo->Parameters->ParamByName("@IDdeProyecto_2");
  //....................................................................
  ADOSP_EModulo->Active = false;
  //....................................................................
  TIdModulo->Value   = IdModulo;
  TIdProyecto->Value = IdProyecto;
  //....................................................................
  ADOSP_EModulo->Prepared = true;
  ADOSP_EModulo->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Eliminar_Tarea(AnsiString IdTarea, AnsiString IdModulo)
{
 //...................................................................
  TParameter* TIdTarea   = ADOSP_ETarea->Parameters->ParamByName("@IDdeTarea_1");
  TParameter* TIdModulo  = ADOSP_ETarea->Parameters->ParamByName("@IdComponente_2");
  //....................................................................
  ADOSP_ETarea->Active = false;
  //....................................................................
  TIdTarea->Value   = IdTarea;
  TIdModulo->Value  = IdModulo;
  //....................................................................
  ADOSP_ETarea->Prepared = true;
  ADOSP_ETarea->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Eliminar_Problema(AnsiString IdProblema)
{
  //...................................................................
  TParameter* TIdProblema  = ADOSP_EProblema->Parameters->ParamByName("@IDdelProblema_1");
  //....................................................................
  ADOSP_EProblema->Active = false;
  //....................................................................
  TIdProblema->Value  = IdProblema;
  //....................................................................
  ADOSP_EProblema->Prepared = true;
  ADOSP_EProblema->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Eliminar_Usuario(AnsiString IdUsuario)
{
  //...................................................................
  TParameter* TIdUsuario  = ADOSP_ESeguridad->Parameters->ParamByName("@Usuario_1");
  //....................................................................
  ADOSP_EProblema->Active = false;
  //....................................................................
  TIdUsuario->Value  = IdUsuario;
  //....................................................................
  ADOSP_ESeguridad->Prepared = true;
  ADOSP_ESeguridad->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
bool TDataModuleTablas::Existe_Usuario(AnsiString Usuario, Classes::TComponent* AOwner)
{
  TParameter* TUsuario   = ADOSPExisteUsuario->Parameters->ParamByName("@User");
  TUsuario->Value = Usuario;
  //.......................................
  ADOSPExisteUsuario->Active = false;
  ADOSPExisteUsuario->Prepared = true;
  ADOSPExisteUsuario->ExecProc();
  ADOSPExisteUsuario->Active = true;
  //.......................................
  TDataSource*  DSTemp = new TDataSource(AOwner);
  DSTemp->DataSet = ADOSPExisteUsuario;
  AnsiString Existe = DSTemp->DataSet->Fields->operator [](0)->AsString;
  if(Existe == '1')
    return true;
  return false;
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Insertar_ComponenteProblema(AnsiString IdComponente,AnsiString IdProblema)
{
  //...................................................................
  TParameter* TIdComponente  = ADOSP_IComponenteProblema->Parameters->ParamByName("@IdComponente_1");
  TParameter* TIdProblema    = ADOSP_IComponenteProblema->Parameters->ParamByName("@IDdelProblema_2");
  //....................................................................
  ADOSP_IComponenteProblema->Active = false;
  //....................................................................
  TIdComponente->Value  = IdComponente;
  TIdProblema->Value    = IdProblema;
  //....................................................................
  ADOSP_IComponenteProblema->Prepared = true;
  ADOSP_IComponenteProblema->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Insertar_Modulo_Componente(AnsiString IdComponente,AnsiString IdProyecto,AnsiString IdModulo)
{
  //...................................................................
  TParameter* TIdComponente  = ADOSP_IModuloComponente->Parameters->ParamByName("@IdComponente_3");
  TParameter* TIdProyecto    = ADOSP_IModuloComponente->Parameters->ParamByName("@IDdeProyecto_2");
  TParameter* TIdModulo      = ADOSP_IModuloComponente->Parameters->ParamByName("@IDdeM�dulo_1");
  //....................................................................
  ADOSP_IModuloComponente->Active = false;
  //....................................................................
  TIdComponente->Value  = IdComponente;
  TIdProyecto->Value    = IdProyecto;
  TIdModulo->Value      = IdModulo;
  //....................................................................
  ADOSP_IModuloComponente->Prepared = true;
  ADOSP_IModuloComponente->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Insertar_TareaPersona(AnsiString IdPersona,AnsiString IdTarea,AnsiString IdComponente)
{
  //...................................................................
  TParameter* TIdPersona     = ADOSP_ITareaPersona->Parameters->ParamByName("@#Credencial_2");
  TParameter* TIdComponente  = ADOSP_ITareaPersona->Parameters->ParamByName("@IdComponente_3");
  TParameter* TIdTarea       = ADOSP_ITareaPersona->Parameters->ParamByName("@IDdeTarea_1");
  //....................................................................
  ADOSP_ITareaPersona->Active = false;
  //....................................................................
  TIdPersona->Value    = IdPersona;
  TIdComponente->Value = IdComponente;
  TIdTarea->Value      = IdTarea;
  //....................................................................
  ADOSP_ITareaPersona->Prepared = true;
  ADOSP_ITareaPersona->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Eliminar_ComponenteProblema(AnsiString IdComponente,AnsiString IdProblema)
{
  //...................................................................
  TParameter* TIdComponente  = ADOSP_EComponenteProblema->Parameters->ParamByName("@IdComponente_1");
  TParameter* TIdProblema    = ADOSP_EComponenteProblema->Parameters->ParamByName("@IDdelProblema_2");
  //....................................................................
  ADOSP_EComponenteProblema->Active = false;
  //....................................................................
  TIdComponente->Value  = IdComponente;
  TIdProblema->Value    = IdProblema;
  //....................................................................
  ADOSP_EComponenteProblema->Prepared = true;
  ADOSP_EComponenteProblema->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Eliminar_ModuloComponente(AnsiString IdComponente,AnsiString IdProyecto,AnsiString IdModulo)
{
  //...................................................................
  TParameter* TIdComponente  = ADOSP_EModuloComponente->Parameters->ParamByName("@IdComponente_3");
  TParameter* TIdProyecto    = ADOSP_EModuloComponente->Parameters->ParamByName("@IDdeProyecto_2");
  TParameter* TIdModulo      = ADOSP_EModuloComponente->Parameters->ParamByName("@IDdeM�dulo_1");
  //....................................................................
  ADOSP_EModuloComponente->Active = false;
  //....................................................................
  TIdComponente->Value  = IdComponente;
  TIdProyecto->Value    = IdProyecto;
  TIdModulo->Value      = IdModulo;
  //....................................................................
  ADOSP_EModuloComponente->Prepared = true;
  ADOSP_EModuloComponente->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Eliminar_TareaPersona(AnsiString IdPersona,AnsiString IdTarea,AnsiString IdComponente)
{
  //...................................................................
  TParameter* TIdPersona     = ADOSP_ETareaPersona->Parameters->ParamByName("@#Credencial_2");
  TParameter* TIdTarea       = ADOSP_ETareaPersona->Parameters->ParamByName("@IDdeTarea_1");
  TParameter* TIdComponente  = ADOSP_ETareaPersona->Parameters->ParamByName("@IdComponente_3");
  //....................................................................
  ADOSP_ETareaPersona->Active = false;
  //....................................................................
  TIdPersona->Value    = IdPersona;
  TIdTarea->Value      = IdTarea;
  TIdComponente->Value = IdComponente;
  //....................................................................
  ADOSP_ETareaPersona->Prepared = true;
  ADOSP_ETareaPersona->ExecProc();
  //....................................................................
}
//---------------------------------------------------------------------------
TDataSource * TDataModuleTablas::Listado_TareasTTrabajador(AnsiString Nombre)
{
  //...........Creo el DataSourse .....................................
  TDataSource * MyDataSourse = new  TDataSource(MyOwner);
  MyDataSourse->DataSet = ADOSP_TareasTTrabajador;
  //...................................................................
  TParameter* TNombre  = ADOSP_TareasTTrabajador->Parameters->ParamByName("@nombre");
  //....................................................................   
  ADOSP_TareasTTrabajador->Active = false;
  //....................................................................
  TNombre->Value  = Nombre;
  //....................................................................
  ADOSP_TareasTTrabajador->Prepared = true;
  ADOSP_TareasTTrabajador->ExecProc();
  ADOSP_TareasTTrabajador->Active = true;
  //....................................................................
  return MyDataSourse;
}
//---------------------------------------------------------------------------
TDataSource * TDataModuleTablas::Listado_TareasPTrabajador(AnsiString Nombre)
{
  //...........Creo el DataSourse .....................................
  TDataSource * MyDataSourse = new  TDataSource(MyOwner);
  MyDataSourse->DataSet = ADOSP_TareasPTrabajador;
  //...................................................................
  TParameter* TNombre  = ADOSP_TareasPTrabajador->Parameters->ParamByName("@nombre");
  //....................................................................
  ADOSP_TareasPTrabajador->Active = false;
  //....................................................................
  TNombre->Value  = Nombre;
  //....................................................................
  ADOSP_TareasPTrabajador->Prepared = true;
  ADOSP_TareasPTrabajador->ExecProc();
  ADOSP_TareasPTrabajador->Active = true;
  //....................................................................
  return MyDataSourse;
}
//---------------------------------------------------------------------------
TDataSource * TDataModuleTablas::Listado_Errores(AnsiString idComponente)
{
  //...........Creo el DataSourse .....................................
  TDataSource * MyDataSourse = new  TDataSource(MyOwner);
  MyDataSourse->DataSet = ADOSP_ErroresComponente;
  //...................................................................
  TParameter* TidComponente  = ADOSP_ErroresComponente->Parameters->ParamByName("@IdComponente");
  //....................................................................
  ADOSP_ErroresComponente->Active = false;
  //....................................................................
  TidComponente->Value  = idComponente;
  //....................................................................
  ADOSP_ErroresComponente->Prepared = true;
  ADOSP_ErroresComponente->ExecProc();
  ADOSP_ErroresComponente->Active = true;
  //....................................................................
  return MyDataSourse;
}
//---------------------------------------------------------------------------
TDataSource * TDataModuleTablas::Listado_Trabajadores(AnsiString Componente)
{
  //...........Creo el DataSourse .....................................
  TDataSource * MyDataSourse = new  TDataSource(MyOwner);
  MyDataSourse->DataSet = ADOSP_PersonasComponente;
  //...................................................................
  TParameter* TComponente  = ADOSP_PersonasComponente->Parameters->ParamByName("@IdComponente");
  //....................................................................
  ADOSP_PersonasComponente->Active = false;
  //....................................................................
  TComponente->Value  = Componente;
  //....................................................................
  ADOSP_PersonasComponente->Prepared = true;
  ADOSP_PersonasComponente->ExecProc();
  ADOSP_PersonasComponente->Active = true;
  //....................................................................
  return MyDataSourse;
}
//---------------------------------------------------------------------------
TDataSource * TDataModuleTablas::Listado_FechasTareas(AnsiString Componente)
{
  //...........Creo el DataSourse .....................................
  TDataSource * MyDataSourse = new  TDataSource(MyOwner);
  MyDataSourse->DataSet = ADOSP_IncumplimientoComponente;
  //...................................................................
  TParameter* TComponente  = ADOSP_IncumplimientoComponente->Parameters->ParamByName("@IdComponente");
  //....................................................................
  ADOSP_IncumplimientoComponente->Active = false;
  //....................................................................
  TComponente->Value  = Componente;
  //....................................................................
  ADOSP_IncumplimientoComponente->Prepared = true;
  ADOSP_IncumplimientoComponente->ExecProc();
  ADOSP_IncumplimientoComponente->Active = true;
  //....................................................................
  return MyDataSourse;
}
//---------------------------------------------------------------------------
void TDataModuleTablas::Copia_de_Seguridad(AnsiString NombreDB,AnsiString Direccion)
{ //... Este metodo permite hacer un backup a una Base de Datos, co ella se puede crear otra pero con la misma configuracion o restaurar la misma
  //... Creo el TADOQuery  dinamicamente
  TADOQuery *MyQuery = new TADOQuery(MyOwner);
  MyQuery->Connection = ADOConnection1;
  MyQuery->Close();
  //.....Creo la sentecia
  AnsiString SQLSentencia = " BACKUP DATABASE ";
  SQLSentencia.operator +=(NombreDB);
  SQLSentencia.operator +=(" TO DISK = '");
  SQLSentencia.operator +=(Direccion);
  SQLSentencia.operator +=("'");
  MyQuery->SQL->Text = SQLSentencia;
  //... la ejecuto
  MyQuery->ExecSQL();
  //... Nota : si se sobrescribe el backup  incrementa su tama�o en KB, lo recomendarlo es borrarlo
  //... El backup es como un compactado de un *.mdf y *.ldf, que son los 2 ficheros por los que esta compuesto una Base de Datos
}
//---------------------------------------------------------------------------
void TDataModuleTablas::RestaurarDB(AnsiString NombreDB,AnsiString DireccionBak,AnsiString DireccionMdf,AnsiString DireccionLdf,AnsiString Servidor,AnsiString BDEnUso,AnsiString NombreSystBack)
{ //... Este  metodo permite hacer una restauracion o una copia de una base de datos dado un *.bak
 try
 {
  //... Configuro el ADOConnection ...............................................................................
  //... desconecto ADOConnection
  ADOConnection1->Connected = false;
  ADOConnection1->ConnectionString.Empty();
  //... Creo una nueva coneccion a una base de datos del systema, esto es para que no de el error de que la base de dato esta en uso ...
  AnsiString ConetStrin = "";
  ConetStrin = "Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=";
  ConetStrin.operator +=("Northwind");
  ConetStrin.operator +=(";Data Source=");
  ConetStrin.operator +=(Servidor);
  //... Activo la coneccion
  ADOConnection1->ConnectionString = ConetStrin;
  ADOConnection1->Connected = true;
  //...................................................................................................
  //... Creo el TADOQuery  dinamicamente
  TADOQuery *MyQuery = new TADOQuery(MyOwner);
  MyQuery->Connection = ADOConnection1;
  MyQuery->Close();
  //.....Creo la sentecia para hacer una restauracion o copia de una base de dato
  AnsiString SQLSentencia = " RESTORE FILELISTONLY FROM DISK = '";
  SQLSentencia.operator +=(DireccionBak);
  SQLSentencia.operator +=("' ");
  SQLSentencia.operator +=(" RESTORE DATABASE ");
  SQLSentencia.operator +=(NombreDB);
  SQLSentencia.operator +=(" FROM DISK = '");
  SQLSentencia.operator +=(DireccionBak);
  SQLSentencia.operator +=("' ");
  SQLSentencia.operator +=("WITH MOVE '");
  SQLSentencia.operator +=(NombreSystBack);
  SQLSentencia.operator +=("' TO '");  // _Data
  SQLSentencia.operator +=(DireccionMdf);
  SQLSentencia.operator +=("_Data.mdf' ,MOVE '");
  SQLSentencia.operator +=(NombreSystBack);
  SQLSentencia.operator +=("_log'  TO  '");
  SQLSentencia.operator +=(DireccionLdf);
  SQLSentencia.operator +=("_Log.ldf' ");
  MyQuery->SQL->Text = SQLSentencia;
  //... Ejecuto la sentencia SQL
  MyQuery->Prepared = true;
  MyQuery->ExecSQL();
  //...................................................................................................
  //... Restablesco mi coneccion a la base de dato actual  ................................................................
  //... desconecto ADOConnection
  ADOConnection1->Connected = false;
  ADOConnection1->ConnectionString.Empty();
  //... Creo una nueva coneccion a una base de datos del systema, esto es para que no de el error de que la base de dato esta en uso ...
  ConetStrin = "";
  ConetStrin = "Provider=SQLOLEDB.1;Integrated Security=SSPI;Persist Security Info=False;Initial Catalog=";
  ConetStrin.operator +=(BDEnUso);
  ConetStrin.operator +=(";Data Source=");
  ConetStrin.operator +=(Servidor);
  //... Activo la coneccion
  ADOConnection1->ConnectionString = ConetStrin;
  ADOConnection1->Connected = true;
  }catch(...)
      {
        MessageDlg("      Ha ocurrido un error de conexi�n inesperado.\n  Vuela a intentarlo, verifique el estado del servidor SQL. \nSi el problema persiste salga y vuelva a entrar a la aplicaci�n.",mtWarning, TMsgDlgButtons() << mbOK, 0);
      }
/* ejemplo del codigo en SQL
   RESTORE FILELISTONLY
   FROM DISK = 'c:\VideoClub.bak'
   RESTORE DATABASE VideoClub
   FROM DISK = 'c:\VideoClub.bak'
   WITH MOVE 'VideoClub_Data' TO 'c:\VideoClub_Data.mdf',
   MOVE 'VideoClub_Log' TO 'c:\VideoClub_Log.ldf'
*/
}
//---------------------------------------------------------------------------


