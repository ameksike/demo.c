/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       04/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef ListadosPorCriteriosH
#define ListadosPorCriteriosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include "Unit1.h"
#include "Tarea.h"
//---------------------------------------------------------------------------
class TForm5 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *ListaProblemasComponentes;
        TGroupBox *GroupBox5;
        TDBGrid *DBGrid2;
        TGroupBox *GroupBox6;
        TLabel *Label4;
        TLabel *Label5;
        TDBLookupComboBox *DBLookupComboBox1;
        TGroupBox *IstadoTrabajadoresComponentes;
        TGroupBox *GroupBox4;
        TLabel *Label6;
        TDBLookupComboBox *DBLookupComboBox3;
        TGroupBox *GroupBox1;
        TDBGrid *DBGrid3;
        TLabel *Label7;
        TGroupBox *IncumplimientosComponentes;
        TLabel *Label8;
        TGroupBox *GroupBox8;
        TGroupBox *GroupBox9;
        TLabel *Label9;
        TDBLookupComboBox *DBLookupComboBox4;
        TStringGrid *StringGrid1;
        TGroupBox *ListadoTareas;
        TLabel *Label3;
        TGroupBox *GroupBox2;
        TDBGrid *DBGrid1;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox7;
        TDBLookupComboBox *DBLookupComboBox2;
        TLabel *Label2;
        TComboBox *ComboBox1;
        TLabel *Label1;
        TButton *Button1;
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall DBLookupComboBox1Click(TObject *Sender);
        void __fastcall DBLookupComboBox3Click(TObject *Sender);
        void __fastcall DBLookupComboBox4Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declaration
          AnsiString estadoT;                                    //..almacena el estado de una tarea [Pendiente | Teminada]
          void LimpiarStringGrid(TStringGrid * vStringGrid);     //...limpiar la tabla de salida
        __fastcall TForm5(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm5 *Form5;
//---------------------------------------------------------------------------
#endif
