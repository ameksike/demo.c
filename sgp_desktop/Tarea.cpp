/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       02/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#pragma hdrstop
#include "Tarea.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
Tarea::Tarea(AnsiString vFechaTerminada,AnsiString vFechaEntrega,AnsiString vIdTarea)
{
      FechaTerminada = ConfigurarFecha(vFechaTerminada);   //...configuramos la fecha antes de guardarla
      FechaEntrega  = ConfigurarFecha(vFechaEntrega);      //...configuramos la fecha antes de guardarla
      IdTarea = vIdTarea;
}
//---------------------------------------------------------------------------
bool Tarea::Incumplimiento()          //....... si existe un incumplimiento
{
    if(FechaTerminada.ToDouble() > FechaEntrega.ToDouble())     //...covierto a numero y los comparamos
       return true;
    return false;
}
//---------------------------------------------------------------------------
AnsiString Tarea::Get_IdTarea()       //........ devuelve el id de la tarea
{
   return IdTarea;
}
//---------------------------------------------------------------------------
AnsiString Tarea::ConfigurarFecha(AnsiString fecha)    //...configuramos la fecha de la forma a�o mes dia [solo los numeros]
{
   AnsiString tempFecha = "";
   for(int i=7; i<=10; i++)
       tempFecha += fecha.operator [](i);   //...coge el a�o y lo guarda
   for(int i=4; i<=5; i++)
       tempFecha += fecha.operator [](i);   //...coge el mes y lo concatena
   for(int i=1; i<=2; i++)
       tempFecha += fecha.operator [](i);   //...coge el dia y lo concatena
   return tempFecha;
}
//---------------------------------------------------------------------------
