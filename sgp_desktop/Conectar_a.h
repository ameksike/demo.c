/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       04/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef Conectar_aH
#define Conectar_aH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//--------------------DataModulos--------------------------------------------
//#include "Unit1.h"
//#include <Mask.hpp>
//--------------------Formas y Clases----------------------------------------
#include "Control.h"
#include "Registro.h"
#include "Unit8.h"
//---------------------------------------------------------------------------
class TFormConectar : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *EditServidor;
        TEdit *EditDB;
        void __fastcall EditDBKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall EditServidorKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        int contador;
        Control* ControlDB;
        AnsiString NombreBD;
        AnsiString NombreServidor;
        __fastcall TFormConectar(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormConectar *FormConectar;
//---------------------------------------------------------------------------
#endif
