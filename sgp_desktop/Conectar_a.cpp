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
#include "Conectar_a.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFormConectar *FormConectar;
//---------------------------------------------------------------------------
__fastcall TFormConectar::TFormConectar(TComponent* Owner)
        : TForm(Owner)
{
  ControlDB = new Control(DataModuleTablas->ADOConnection1,Owner);
  NombreBD = "";
  NombreServidor = "";
  contador = 0;
}
//---------------------------------------------------------------------------
void __fastcall TFormConectar::EditDBKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 if(Key == VK_RETURN)
 {
   NombreBD = EditDB->Text;
   NombreServidor = EditServidor->Text;
   try
    {
      ControlDB->Conecion(EditServidor->Text, EditDB->Text);
    }
   catch(...)
    {
      if(MessageDlg("   Ha ocurrido un error de conexi�n inesperado.\n   Los problemas mas probables son :        \n       1- Servidor no existe o incorecto.   \n       2- Base de Datos no existe o incorecta.        \n\n Sugerencia: Si desea montar el servidor desde una copia de seguridad\n                     presione OK o de lo contrario presione NO. \n\n Nota: Si el problema persiste salga y vuelva a entrar a la aplicaci�n.",mtWarning, TMsgDlgButtons() << mbNo << mbOK , 0)== mrOk )
       {
          Form8->ShowModal();
          EditDB->Text =  Form8->Edit1->Text;
          EditServidor->Text = Form8->NMStrm1->LocalIP;
       }
      ControlDB->Desconectar();
    }
   if(DataModuleTablas->ADOConnection1->Connected)
   {
     DataModuleTablas->ActivarTablas();
      FormRegistro->ShowModal();
      if (FormRegistro->Active)
       {
         while(!ControlDB->ChequearRegistro(FormRegistro->EditUsuario->Text,FormRegistro->MaskEditPass->Text))
         {
          if(!FormRegistro->Active)
           {
            ControlDB->Desconectar();
            FormRegistro->Active = false;
            FormRegistro->Close();
           }
          ShowMessage("Usuario y contrase�a Incorrecta: por favor vuelva a intentarlo");
          if(contador <= 2)
            {
              contador ++;
              FormRegistro->ShowModal();
            }
         }
         Close();
        }
       else
       {
        ControlDB->Desconectar();
        NombreBD = "";
        NombreServidor = "";
        Close();
       }
       FormRegistro->MaskEditPass->Text = "";
   }
}
 //...........................................................
 if(Key == VK_ESCAPE)
 {
   ControlDB->Desconectar();
   NombreBD = "";
   NombreServidor = "";
   FormRegistro->Active = false;
   Close();
 }
 //...........................................................
}
//---------------------------------------------------------------------------

void __fastcall TFormConectar::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   EditDBKeyDown(Sender,Key,Shift);
}
//---------------------------------------------------------------------------
void __fastcall TFormConectar::EditServidorKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   EditDBKeyDown(Sender,Key,Shift);
}
//---------------------------------------------------------------------------
void __fastcall TFormConectar::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  contador = 0;
}
//---------------------------------------------------------------------------

