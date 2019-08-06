/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       02/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef RegistroH
#define RegistroH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFormRegistro : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *EditUsuario;
        TMaskEdit *MaskEditPass;
        void __fastcall MaskEditPassKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall EditUsuarioKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        bool Active;
        __fastcall TFormRegistro(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFormRegistro *FormRegistro;
//---------------------------------------------------------------------------
#endif
