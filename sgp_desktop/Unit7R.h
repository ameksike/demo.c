/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       02/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef Unit7RH
#define Unit7RH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include "Conectar_a.h"
#include "Unit1.h"
//---------------------------------------------------------------------------
class TForm7 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label3;
        TLabel *Label7;
        TEdit *Edit1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TButton *Button1;
        TButton *Button2;
        TOpenDialog *OpenDialog1;
        TLabel *Label8;
        TEdit *Edit2;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label11;
        TSaveDialog *SaveDialog1;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall BitBtn2Click(TObject *Sender);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
       AnsiString NombreBD;
       AnsiString DirBack;
       AnsiString DirMdf;
       AnsiString DirLdf;
       AnsiString Servidor;
       AnsiString DBUsed;
       AnsiString NombreSystBack;
       void Reset();
        __fastcall TForm7(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm7 *Form7;
//---------------------------------------------------------------------------
#endif
