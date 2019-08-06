/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       02/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef SistemaGPH
#define SistemaGPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
//--------------------Formas y Clases--------------------------------------------
#include "Unit1.h"
#include "EditDBrelacionescpp.h"
#include "IformacionS.h"
#include "ReporteC.h"
#include "ListadoProyectos.h"
#include "ListadosPorCriterios.h"
#include <Mask.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
#include <DBCtrls.hpp>
#include <Dialogs.hpp>
#include "Unit7R.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *EditarDB;
        TMainMenu *MainMenu1;
        TMenuItem *Opciones1;
        TMenuItem *Sistema1;
        TMenuItem *Conectar1;
        TMenuItem *Desconectar1;
        TMenuItem *Ayuda1;
        TMenuItem *Insertar1;
        TMenuItem *Eliminar1;
        TMenuItem *N1;
        TMenuItem *Copiadeseguridad1;
        TMenuItem *Salir1;
        TMenuItem *N2;
        TMenuItem *Ver1;
        TMenuItem *InformaciondelSistema1;
        TMenuItem *ListadodeProyectos1;
        TMenuItem *Listadodeerroresporcomponentes1;
        TMenuItem *ListadodeImcumplimientoporComponentes1;
        TMenuItem *N4;
        TMenuItem *Listado1;
        TMenuItem *EstadodelasTareasporTrabajador1;
        TMenuItem *Ayuda2;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TTabSheet *TabSheet4;
        TTabSheet *TabSheet5;
        TTabSheet *TabSheet6;
        TGroupBox *GroupBox2;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TGroupBox *GroupBox5;
        TGroupBox *GroupBox6;
        TGroupBox *GroupBox7;
        TGroupBox *GroupBox8;
        TGroupBox *GroupBox9;
        TGroupBox *GroupBox10;
        TGroupBox *GroupBox27;
        TGroupBox *GroupBox11;
        TGroupBox *GroupBox12;
        TGroupBox *GroupBox13;
        TGroupBox *GroupBox14;
        TGroupBox *GroupBox28;
        TGroupBox *GroupBox15;
        TGroupBox *GroupBox16;
        TGroupBox *GroupBox17;
        TGroupBox *GroupBox18;
        TGroupBox *GroupBox29;
        TGroupBox *GroupBox19;
        TGroupBox *GroupBox20;
        TGroupBox *GroupBox21;
        TGroupBox *GroupBox22;
        TGroupBox *GroupBox30;
        TGroupBox *GroupBox23;
        TGroupBox *GroupBox24;
        TGroupBox *GroupBox25;
        TGroupBox *GroupBox26;
        TGroupBox *GroupBox31;
        TDBGrid *DBGrid1;
        TDBGrid *DBGrid2;
        TDBGrid *DBGrid3;
        TDBGrid *DBGrid4;
        TDBGrid *DBGrid5;
        TDBGrid *DBGrid6;
        TMenuItem *EliminarBD1;
        TEdit *Edit1;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *Edit2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *Edit5;
        TLabel *Label6;
        TMemo *Memo1;
        TLabel *Label7;
        TGroupBox *GroupBox32;
        TButton *Button1;
        TGroupBox *GroupBox33;
        TButton *Button2;
        TLabel *Label8;
        TLabel *Label9;
        TEdit *Edit8;
        TLabel *Label10;
        TEdit *Edit9;
        TLabel *Label11;
        TLabel *Label12;
        TEdit *Edit10;
        TEdit *Edit11;
        TButton *Button3;
        TButton *Button4;
        TGroupBox *GroupBox34;
        TButton *Button5;
        TButton *Button6;
        TLabel *Label13;
        TLabel *Label14;
        TEdit *Edit13;
        TLabel *Label15;
        TLabel *Label16;
        TEdit *Edit15;
        TLabel *Label17;
        TGroupBox *GroupBox35;
        TButton *Button7;
        TButton *Button8;
        TLabel *Label19;
        TEdit *Edit18;
        TLabel *Label20;
        TEdit *Edit19;
        TLabel *Label21;
        TLabel *Label22;
        TLabel *Label23;
        TLabel *Label24;
        TLabel *Label25;
        TLabel *Label26;
        TLabel *Label27;
        TEdit *Edit25;
        TGroupBox *GroupBox36;
        TButton *Button9;
        TButton *Button10;
        TLabel *Label28;
        TLabel *Label29;
        TEdit *Edit27;
        TLabel *Label30;
        TLabel *Label31;
        TComboBox *ComboBox1;
        TLabel *Label32;
        TLabel *Label33;
        TLabel *Label34;
        TLabel *Label35;
        TMemo *Memo2;
        TGroupBox *GroupBox37;
        TButton *Button11;
        TButton *Button12;
        TLabel *Label36;
        TLabel *Label37;
        TEdit *Edit33;
        TLabel *Label38;
        TMemo *Memo3;
        TTabSheet *TabSheet7;
        TGroupBox *GroupBox38;
        TGroupBox *GroupBox39;
        TGroupBox *GroupBox40;
        TGroupBox *GroupBox41;
        TGroupBox *GroupBox42;
        TLabel *Label45;
        TGroupBox *GroupBox43;
        TDBGrid *DBGrid7;
        TButton *Button15;
        TButton *Button13;
        TLabel *Label39;
        TEdit *Edit34;
        TLabel *Label40;
        TLabel *Label41;
        TMaskEdit *MaskEdit1;
        TMaskEdit *MaskEdit2;
        TComboBox *ComboBox2;
        TComboBox *ComboBox3;
        TLabel *Label42;
        TLabel *Label43;
        TMemo *Memo4;
        TLabel *Label44;
        TMenuItem *AsignarleunProblemaaunComponente1;
        TMenuItem *EditarlaBasedeDato1;
        TLabel *Label46;
        TLabel *Label47;
        TImage *Image1;
        TMenuItem *N3;
        TMenuItem *N5;
        TMenuItem *ListadodeIncumplimientosporComponentes1;
        TDateTimePicker *DateTimePicker1;
        TDateTimePicker *DateTimePicker2;
        TDateTimePicker *DateTimePicker3;
        TDateTimePicker *DateTimePicker4;
        TDateTimePicker *DateTimePicker5;
        TDateTimePicker *DateTimePicker6;
        TDateTimePicker *DateTimePicker7;
        TDBLookupComboBox *DBLookupComboBox1;
        TDBLookupComboBox *DBLookupComboBox2;
        TComboBox *ComboBox4;
        TDBLookupComboBox *DBLookupComboBox3;
        TDBLookupComboBox *DBLookupComboBox4;
        TDBLookupComboBox *DBLookupComboBox5;
        TDBLookupComboBox *DBLookupComboBox6;
        TDBLookupComboBox *DBLookupComboBox7;
        TDBLookupComboBox *DBLookupComboBox8;
        TDBLookupComboBox *DBLookupComboBox9;
        TDBLookupComboBox *DBLookupComboBox10;
        TDBLookupComboBox *DBLookupComboBox11;
        TDBLookupComboBox *DBLookupComboBox12;
        TDBLookupComboBox *DBLookupComboBox13;
        TDBLookupComboBox *DBLookupComboBox14;
        TEdit *Edit17;
        TLabel *Label18;
        TSaveDialog *SaveDialog1;
        TMenuItem *RestaurarBD1;
        TStatusBar *StatusBar1;
        TTimer *Timer1;
        void __fastcall Conectar1Click(TObject *Sender);
        void __fastcall Desconectar1Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall EditarlaBasedeDato1Click(TObject *Sender);
        void __fastcall Salir1Click(TObject *Sender);
        void __fastcall Button9Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall Button10Click(TObject *Sender);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Insertar1Click(TObject *Sender);
        void __fastcall Eliminar1Click(TObject *Sender);
        void __fastcall AsignarleunProblemaaunComponente1Click(
          TObject *Sender);
        void __fastcall InformaciondelSistema1Click(TObject *Sender);
        void __fastcall ListadodeProyectos1Click(TObject *Sender);
        void __fastcall Listado1Click(TObject *Sender);
        void __fastcall Listadodeerroresporcomponentes1Click(
          TObject *Sender);
        void __fastcall EstadodelasTareasporTrabajador1Click(
          TObject *Sender);
        void __fastcall ListadodeImcumplimientoporComponentes1Click(
          TObject *Sender);
        void __fastcall ListadodeIncumplimientosporComponentes1Click(
          TObject *Sender);
        void __fastcall EliminarBD1Click(TObject *Sender);
        void __fastcall Copiadeseguridad1Click(TObject *Sender);
        void __fastcall RestaurarBD1Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
public:		// User declarations
        TComponent* OwnerTemp;
        void LimpiarComponentes();
        void DesactivarMenu();
        void ActivarMenu();
        AnsiString ConcatenarMemo(TMemo *Memo);
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
