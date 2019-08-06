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
#include "EditDBrelacionescpp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{
   vOwner = Owner;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
  DataModuleTablas->Insertar_Modulo_Componente(DBLCBIdComponente->Text,DBLCBIdProyecto->Text,DBLCBIdModulo->Text);
  DataModuleTablas->Actualizar();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button2Click(TObject *Sender)
{
  DataModuleTablas->Eliminar_ModuloComponente(DBLCBIdComponente->Text,DBLCBIdProyecto->Text,DBLCBIdModulo->Text);
  DataModuleTablas->Actualizar();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button5Click(TObject *Sender)
{
  DataModuleTablas->Insertar_ComponenteProblema(DBLCBIdComponenteProble->Text,DBLCBIdProblema->Text);
  DataModuleTablas->Actualizar();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button6Click(TObject *Sender)
{
  DataModuleTablas->Eliminar_ComponenteProblema(DBLCBIdComponenteProble->Text,DBLCBIdProblema->Text);
  DataModuleTablas->Actualizar();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button3Click(TObject *Sender)
{
  DataModuleTablas->Insertar_TareaPersona(DBLCBCredencial->Text,DBLCBIdTarea->Text,DBLCBIdComponenteTrabaja->Text);
  DataModuleTablas->Actualizar();
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button4Click(TObject *Sender)
{
  DataModuleTablas->Eliminar_TareaPersona(DBLCBCredencial->Text,DBLCBIdTarea->Text,DBLCBIdComponenteTrabaja->Text);
  DataModuleTablas->Actualizar();
}
//---------------------------------------------------------------------------
