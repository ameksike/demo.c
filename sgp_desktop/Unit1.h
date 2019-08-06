/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       02/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ADODB.hpp>
#include <DB.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TDataModuleTablas : public TDataModule
{
__published:	// IDE-managed Components
        TADOConnection *ADOConnection1;
        TDataSource *DataSProyecto;
        TDataSource *DataSPersona;
        TDataSource *DataSModulo;
        TDataSource *DataSTarea;
        TDataSource *DataSComponente;
        TDataSource *DataSProblema;
        TADOTable *ADOTProyecto;
        TADOTable *ADOTPersona;
        TADOTable *ADOTModulo;
        TADOTable *ADOTTarea;
        TADOTable *ADOTComponente;
        TADOTable *ADOTProblema;
        TADOTable *ADOTSeguridad;
        TDataSource *DataSSeguridad;
        TADOStoredProc *ADOSP_Proyecto;
        TADOStoredProc *ADOSP_Persona;
        TADOStoredProc *ADOSP_Modulo;
        TADOStoredProc *ADOSP_Tarea;
        TADOStoredProc *ADOSP_Componente;
        TADOStoredProc *ADOSP_Problema;
        TADOStoredProc *ADOSP_Seguridad;
        TADOStoredProc *ADOSP_EProyecto;
        TADOStoredProc *ADOSP_EPersona;
        TADOStoredProc *ADOSP_EModulo;
        TADOStoredProc *ADOSP_ETarea;
        TADOStoredProc *ADOSP_EComponente;
        TADOStoredProc *ADOSP_EProblema;
        TADOStoredProc *ADOSP_ESeguridad;
        TADOStoredProc *ADOSPExisteUsuario;
        TADOStoredProc *ADOSP_ITareaPersona;
        TADOStoredProc *ADOSP_ETareaPersona;
        TADOStoredProc *ADOSP_IModuloComponente;
        TADOStoredProc *ADOSP_EModuloComponente;
        TADOStoredProc *ADOSP_IComponenteProblema;
        TADOStoredProc *ADOSP_EComponenteProblema;
        TADOTable *ADOT_TareaPersona;
        TADOTable *ADOT_ModuloComponente;
        TADOTable *ADOT_ComponenteProblema;
        TDataSource *DataS_TareaPersona;
        TDataSource *DataS_ModuloComponente;
        TDataSource *DataS_ComponenteProblema;
        TADOStoredProc *ADOSP_TareasPTrabajador;
        TADOStoredProc *ADOSP_TareasTTrabajador;
        TADOStoredProc *ADOSP_ErroresComponente;
        TADOStoredProc *ADOSP_PersonasComponente;
        TADOStoredProc *ADOSP_IncumplimientoComponente;
        TADOTable *ADOT_Listado_de_ComponentesT;
        TDataSource *DataS_Listado_de_ComponentesT;
private:	// User declarations
public:		// User declarations
         //...........................................................................................
         TComponent* MyOwner;
         //.......................... Metodos del Sistema .............................................
         void ActivarTablas();
         void DesactivarTablas();
         void Actualizar();
         void Copia_de_Seguridad(AnsiString NombreDB,AnsiString Direccion);
         void RestaurarDB(AnsiString NombreDB,AnsiString DireccionBak,AnsiString DireccionMdf,AnsiString DireccionLdf,AnsiString Servidor,AnsiString BDEnUso,AnsiString NombreSystBack);
         //.......................... Metodos que responden a los requrimientos funcionales ..........
         bool Existe_Usuario(AnsiString Usuario, Classes::TComponent* AOwner);
         TDataSource * Listado_TareasTTrabajador(AnsiString Nombre);
         TDataSource * Listado_TareasPTrabajador(AnsiString Nombre);
         TDataSource * Listado_Errores(AnsiString idComponente);
         TDataSource * Listado_Trabajadores(AnsiString Componente);
         TDataSource * Listado_FechasTareas(AnsiString Componente);
         //.......................... Metodos de Insercion ...........................................
         void Insertar_Componente(AnsiString IDComponente,AnsiString Responsable,AnsiString Nombre,AnsiString version, AnsiString FechaInicio);
         void Insertar_Proyecto(AnsiString IdProyecto,AnsiString Nombre,AnsiString Responsable,int Facultad,AnsiString FechaInicio,AnsiString Objetivo);
         void Insertar_Persona(AnsiString Credencial,AnsiString Nombre,AnsiString Apellidos,AnsiString Sexo,AnsiString CarnetIdentidad, AnsiString CorreoE, AnsiString Categoria, AnsiString IdProyecto,AnsiString FechaInicio);
         void Insertar_Modulo(AnsiString IdModulo,AnsiString IdProyecto,AnsiString Responsable,AnsiString Nombre,AnsiString Objetivo,AnsiString FechaInicio);
         void Insertar_Tarea(AnsiString IdTarea,AnsiString IdComponente,AnsiString Estado,AnsiString FechaInicio,AnsiString FechaTerminada,AnsiString FechaEntrega,AnsiString Objetibo);
         void Insertar_Problema(AnsiString IdProblema,AnsiString Descripcion);
         void Insertar_Usuario(AnsiString Usuario,AnsiString Pasword, Classes::TComponent* AOwner);
         void Insertar_ComponenteProblema(AnsiString IdComponente,AnsiString IdProblema);
         void Insertar_Modulo_Componente(AnsiString IdComponente,AnsiString IdProyecto,AnsiString IdModulo);
         void Insertar_TareaPersona(AnsiString IdPersona,AnsiString IdTarea,AnsiString IdComponente);
         //........................... Metodos de Eliminacion ......................................
         void Eliminar_Componente(AnsiString IdComponente);
         void Eliminar_Proyecto(AnsiString IdProyecto);
         void Eliminar_Persona(AnsiString IdPersona);
         void Eliminar_Modulo(AnsiString IdModulo, AnsiString IdProyecto);
         void Eliminar_Tarea(AnsiString IdTarea, AnsiString IdModulo);
         void Eliminar_Problema(AnsiString IdProblema);
         void Eliminar_Usuario(AnsiString IdUsuario);
         void Eliminar_ComponenteProblema(AnsiString IdComponente,AnsiString IdProblema);
         void Eliminar_ModuloComponente(AnsiString IdComponente,AnsiString IdProyecto,AnsiString IdModulo);
         void Eliminar_TareaPersona(AnsiString IdPersona,AnsiString IdTarea,AnsiString IdComponente);
         //...........................................................................................
        __fastcall TDataModuleTablas(TComponent* Owner);
};
//***************************************************************************
extern PACKAGE TDataModuleTablas *DataModuleTablas;
//***************************************************************************
#endif
