/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       02/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef TareaH
#define TareaH
#include <vcl.h>
//---------------------------------------------------------------------------
class  Tarea
{
  private:
     AnsiString FechaTerminada;
     AnsiString FechaEntrega;
     AnsiString IdTarea;
  public:
     Tarea(AnsiString vFechaTerminada,AnsiString vFechaEntrega,AnsiString vIdTarea);
     bool Incumplimiento();        //....... si existe un incumplimiento
     AnsiString Get_IdTarea();     //........ devuelve el id de la tarea
     AnsiString ConfigurarFecha(AnsiString fecha);   //......convierte la fecha en numero
};
//---------------------------------------------------------------------------
#endif
 