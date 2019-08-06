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
#include "ReporteC.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm6 *Form6;
//---------------------------------------------------------------------------
__fastcall TForm6::TForm6(TComponent* Owner)
        : TForm(Owner)
{
     ADOTListadoMasTrabajan = new TADOTable(Owner);                                           //........Creo un ADOTable
     ADOTListadoMasTrabajan->Connection = DataModuleTablas->ADOConnection1;                  //....Lo conecto con el ADOConeccion1
     ADOTListadoMasTrabajan->TableName = "Persona_que_Trabajen_en_mas_de_un_Componente";     //.....Le especifico la tabla con la que voy a trabajar
     //......................................
     QRSubDetail1->DataSet = ADOTListadoMasTrabajan;          //....Conecto el QRSubDetail1 con mi tabla
     //......................................
     QRDBText1->DataSet = ADOTListadoMasTrabajan;            //........Conecto cada uno de los QRDBText1 (que se encuentran dentro del QRSubDetail1) con mi tabla
     QRDBText2->DataSet = ADOTListadoMasTrabajan;
     //......................................
     QRDBText1->DataField = "Nombre";                    //..........Le especifico a cada uno los campos que van a mostrar es decir es un QRDBText1 por campo
     QRDBText2->DataField = "Cant_Comp";
}
//---------------------------------------------------------------------------
void TForm6::Actualizar()
{
     ADOTListadoMasTrabajan->Active = false;
     ADOTListadoMasTrabajan->Active = true;
}
//---------------------------------------------------------------------------
