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
#include "Registro.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormRegistro *FormRegistro;
//---------------------------------------------------------------------------
__fastcall TFormRegistro::TFormRegistro(TComponent* Owner)
        : TForm(Owner)
{
   Active = false; 
}
//---------------------------------------------------------------------------
void __fastcall TFormRegistro::MaskEditPassKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN)
   {
       Active = true;
       Close();
   }
   //.................
  if(Key == VK_ESCAPE)
  {
       Active = false;
       Close();
  }
}
//---------------------------------------------------------------------------
void __fastcall TFormRegistro::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  MaskEditPassKeyDown(Sender,Key,Shift);
}
//---------------------------------------------------------------------------
void __fastcall TFormRegistro::EditUsuarioKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   MaskEditPassKeyDown(Sender,Key,Shift);
}
//---------------------------------------------------------------------------

