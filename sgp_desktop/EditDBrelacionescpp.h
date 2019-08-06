/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       04/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef EditDBrelacionescppH
#define EditDBrelacionescppH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <DBCtrls.hpp>
#include "Unit1.h"
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *ComponenteModulo;
        TGroupBox *GRUP;
        TLabel *Label4;
        TGroupBox *GroupBox1;
        TButton *Button1;
        TButton *Button2;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TGroupBox *TareaTrabajador;
        TGroupBox *GroupBox5;
        TLabel *Label11;
        TGroupBox *GroupBox4;
        TButton *Button3;
        TButton *Button4;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TGroupBox *GroupBox3;
        TDBGrid *DBGrid1;
        TDBGrid *DBGrid2;
        TGroupBox *ProblemaComponente;
        TGroupBox *GroupBox8;
        TLabel *Label7;
        TGroupBox *GroupBox9;
        TButton *Button5;
        TButton *Button6;
        TGroupBox *GroupBox7;
        TLabel *Label5;
        TLabel *Label6;
        TGroupBox *GroupBox6;
        TDBGrid *DBGrid3;
        TDBLookupComboBox *DBLCBIdComponente;
        TDBLookupComboBox *DBLCBIdProyecto;
        TDBLookupComboBox *DBLCBIdModulo;
        TDBLookupComboBox *DBLCBIdComponenteProble;
        TDBLookupComboBox *DBLCBIdProblema;
        TDBLookupComboBox *DBLCBIdTarea;
        TDBLookupComboBox *DBLCBIdComponenteTrabaja;
        TDBLookupComboBox *DBLCBCredencial;
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        TComponent* vOwner;
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
