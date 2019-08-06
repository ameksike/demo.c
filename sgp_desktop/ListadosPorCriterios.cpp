/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       04/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "ListadosPorCriterios.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
   estadoT = "";
   StringGrid1->Cells[1][0] = " Tareas incumplidas ";
}
//---------------------------------------------------------------------------
void __fastcall TForm5::ComboBox1Change(TObject *Sender)
{
   estadoT = ComboBox1->Text;         //.....almacena el estado a nivel de clase para despues preguntar en la llamada
}
//---------------------------------------------------------------------------
void __fastcall TForm5::DBLookupComboBox1Click(TObject *Sender)
{                                             //.........muestra el listado de errores por cada componente
    DataModuleTablas->Actualizar();
    DBGrid2->DataSource = DataModuleTablas->Listado_Errores(DBLookupComboBox1->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::DBLookupComboBox3Click(TObject *Sender)
{
    DataModuleTablas->Actualizar();          //..muestra el listado de trabajadores por cada  componente
    DBGrid3->DataSource = DataModuleTablas->Listado_Trabajadores(DBLookupComboBox3->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm5::DBLookupComboBox4Click(TObject *Sender)
{
    LimpiarStringGrid(StringGrid1);              //.....muestra una tabla con las tareas incumplidas por cada id de componente que se encuentre en al combobox[DB] 
    DataModuleTablas->Actualizar();              //....actualiza la Base de Datos
    
    int temp = 1;                                //...contador
    TDataSource * MyDataSourse = DataModuleTablas->Listado_FechasTareas(DBLookupComboBox4->Text); //....recive la tabla que devuelve el procedimiento almacenado

    for(int i=0; i< MyDataSourse->DataSet->RecordCount; i++)      //....por cada fila de la tabla que me devuelve el PA crea un objeto tarea
       {
         AnsiString FechaT  = MyDataSourse->DataSet->Fields->operator [](0)->AsString;
         AnsiString FechaE  = MyDataSourse->DataSet->Fields->operator [](1)->AsString;
         AnsiString idTarea = MyDataSourse->DataSet->Fields->operator [](2)->AsString;
         MyDataSourse->DataSet->MoveBy(1);
         Tarea* nueva = new Tarea(FechaT,FechaE,idTarea);  //....creo el objeto
         if(nueva->Incumplimiento())                       //....le preguntamos si incumpio o no
         {
           StringGrid1->Cells[1][temp] = nueva->Get_IdTarea();
           temp++;
         }
       }
       StringGrid1->RowCount = temp + 1; //....dejamos la cantidad de celdas que realmemte hacen falta
}
//---------------------------------------------------------------------------
void TForm5::LimpiarStringGrid(TStringGrid * vStringGrid)    //......limpia la tabla en que muestro los datos
{
  for(int i=1; i< vStringGrid->ColCount; i++)
     for(int j=1;j< vStringGrid->RowCount; j++)
        vStringGrid->Cells[i][j] = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm5::Button1Click(TObject *Sender)
{

  if(estadoT == "Pendiente")           //.....muestra el listado de tareas Pendientes por cada trabajador
  {
    DataModuleTablas->Actualizar();
    DBGrid1->DataSource = DataModuleTablas->Listado_TareasPTrabajador(DBLookupComboBox2->Text);
  }
  else
  if(estadoT == "Terminada")           //.....muestra el listado de tareas Terminiadas por cada trabajador
  {
    DataModuleTablas->Actualizar();
    DBGrid1->DataSource = DataModuleTablas->Listado_TareasTTrabajador(DBLookupComboBox2->Text);
  }
}
//---------------------------------------------------------------------------

