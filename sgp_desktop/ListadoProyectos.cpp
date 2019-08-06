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
#include "ListadoProyectos.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
     ADOTListadoProyectos = new TADOTable(Owner);                                  //........Creo un ADOTable
     ADOTListadoProyectos->Connection = DataModuleTablas->ADOConnection1;         //....Lo conecto con el ADOConeccion1
     ADOTListadoProyectos->TableName = "Lista de proyectos con sus lideres";     //.....Le especifico la tabla con la que voy a trabajar
     //......................................
     QRSubDetail1->DataSet = ADOTListadoProyectos;          //....Conecto el QRSubDetail1 con mi tabla
     //......................................
     QRDBText1->DataSet = ADOTListadoProyectos;            //........Conecto cada uno de los QRDBText1 (que se encuentran dentro del QRSubDetail1) con mi tabla
     QRDBText2->DataSet = ADOTListadoProyectos;
     //......................................
     QRDBText1->DataField = "Nombre";                    //..........Le especifico a cada uno los campos que van a mostrar es decir es un QRDBText1 por campo
     QRDBText2->DataField = "PersonaResponsable";
}
//---------------------------------------------------------------------------
void TForm4::Actualizar()
{
     ADOTListadoProyectos->Active = false;
     ADOTListadoProyectos->Active = true;
}
//---------------------------------------------------------------------------
