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
#include "Unit7R.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
        : TForm(Owner)
{
   NombreBD = "";
   DirBack = "";
   DirMdf = "";
   DirLdf = "";
   Servidor = "";
   DBUsed = "";
   NombreSystBack = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button2Click(TObject *Sender)
{
  Close();
  Reset();
}
//---------------------------------------------------------------------------
void __fastcall TForm7::BitBtn1Click(TObject *Sender)
{
  OpenDialog1->Title = " Seleccione el fichero Backup o Salva";
  if(OpenDialog1->Execute())
     DirBack = OpenDialog1->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::BitBtn2Click(TObject *Sender)
{
  SaveDialog1->Title = "  Guardando el fichero *.mdf ";
  if(SaveDialog1->Execute())
    DirMdf = SaveDialog1->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TForm7::BitBtn3Click(TObject *Sender)
{
  SaveDialog1->Title = "  Guardando el fichero *.ldf ";
  if(SaveDialog1->Execute())
    DirLdf = SaveDialog1->FileName;
}
//---------------------------------------------------------------------------
void TForm7::Reset()
{
   NombreBD = "";
   DirBack = "";
   DirMdf = "";
   DirLdf = "";
   Servidor = "";
   DBUsed = "";
   NombreSystBack = "";
}
//---------------------------------------------------------------------------
void __fastcall TForm7::Button1Click(TObject *Sender)
{
  NombreBD = Edit1->Text;
  NombreSystBack = Edit2->Text;
  Servidor = FormConectar->NombreServidor;
  DBUsed = FormConectar->NombreBD;
  DataModuleTablas->RestaurarDB(NombreBD,DirBack,DirMdf,DirLdf,Servidor,DBUsed,NombreSystBack);
}
//---------------------------------------------------------------------------

