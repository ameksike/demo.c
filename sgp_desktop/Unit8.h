/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       02/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef Unit8H
#define Unit8H
//---------------------------------------------------------------------------
#include "Unit1.h"
#include <Mask.hpp>

#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <NMSTRM.hpp>
#include <Psock.hpp>

//---------------------------------------------------------------------------
class TForm8 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *Edit1;
        TBitBtn *BitBtn1;
        TButton *Button1;
        TButton *Button2;
        TLabel *Label5;
        TEdit *Edit2;
        TOpenDialog *OpenDialog1;
        TNMStrm *NMStrm1;
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
          AnsiString Dir;
          AnsiString Dirf;
          AnsiString NombreNewBD; 
        __fastcall TForm8(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm8 *Form8;
//---------------------------------------------------------------------------
#endif
