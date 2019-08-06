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
#include "Unit8.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm8 *Form8;
//---------------------------------------------------------------------------
__fastcall TForm8::TForm8(TComponent* Owner)
        : TForm(Owner)
{
    Dir = "";
    Dirf = "C:\\Base_de_Datos_ProySoft\\";
    NombreNewBD = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button2Click(TObject *Sender)
{
  NombreNewBD = "";
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm8::Button1Click(TObject *Sender)
{
 try
 {
  if(Dir == "" ||Edit1->Text == "" || Edit2->Text == "" )
   {
     ShowMessage(" Le faltan campos sin llenar. \n Por favor vuelva a intentarlo.");
   }
   else
   {
     //... Creo el directorio para mis salvas
     system(" md C:\\Base_de_Datos_ProySoft ");
     //... Creo la Base de Datos
     Dirf.operator +=(Edit1->Text);
     DataModuleTablas->RestaurarDB(Edit1->Text,Dir,Dirf,Dirf,NMStrm1->LocalIP,Edit1->Text,Edit2->Text);
     NombreNewBD = Edit1->Text;
     Close();
   }
     }
  catch(...)
  {
        MessageDlg("      Ha ocurrido un error de conexi�n inesperado.\n  Vuela a intentarlo, verifique el estado del servidor SQL. \nSi el problema persiste salga y vuelva a entrar a la aplicaci�n.",mtWarning, TMsgDlgButtons() << mbOK, 0);
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm8::BitBtn1Click(TObject *Sender)
{
    if(OpenDialog1->Execute())
       Dir = OpenDialog1->FileName;
}
//---------------------------------------------------------------------------
