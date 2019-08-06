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
#include "SistemaGP.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
   OwnerTemp = Owner; // .....Hace falta para los componentes dinamicos como los DataSourse
   DesactivarMenu();  //.......desactivamos el menu para que acedan a las opciones hasta que no se conecten a la Base de Datos
   StatusBar1->Panels->Items[0]->Text  = " Estado del Servidor :  sin conexion ";
   StatusBar1->Panels->Items[1]->Text  = " Estado de la Base de Datos : sin conexion ";
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Conectar1Click(TObject *Sender)     //........Conectarse a la Base de Dato
{
   FormConectar->ShowModal();
   if(DataModuleTablas->ADOConnection1->Connected)
   {
     StatusBar1->Panels->Items[0]->Text  = " Estado del Servidor : " + FormConectar->NombreServidor;
     StatusBar1->Panels->Items[1]->Text  = " Estado de la Base de Datos : " + FormConectar->NombreBD;
     ActivarMenu();
   }
      
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Desconectar1Click(TObject *Sender)   //........Desconectarse de la Base de Datos
{
  FormConectar->ControlDB->Desconectar();
  StatusBar1->Panels->Items[0]->Text  = " Estado del Servidor :  sin conexion ";
  StatusBar1->Panels->Items[1]->Text  = " Estado de la Base de Datos : sin conexion ";
  DesactivarMenu();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button7Click(TObject *Sender)        //.......Insertar un Componente
{
  DataModuleTablas->Insertar_Componente(Edit17->Text,DBLookupComboBox14->Text,Edit18->Text,Edit19->Text,DateTimePicker4->Date.DateString());
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
}
//---------------------------------------------------------------------------
void TForm1::LimpiarComponentes()
{                                      //........borra todos los campos de texto de los componentes
  Edit1->Text = "";
  Edit2->Text = "";
  Edit5->Text = "";
  Edit8->Text = "";
  Edit9->Text = "";
  Edit10->Text = "";
  Edit11->Text = "";
  Edit13->Text = "";
  Edit15->Text = "";
  Edit17->Text = "";
  Edit18->Text = "";
  Edit19->Text = "";
  Edit25->Text = "";
  Edit27->Text = "";
  Edit33->Text = "";
  Edit34->Text = "";
  ComboBox1->Text = "";
  ComboBox2->Text = "";
  ComboBox3->Text = "";
  ComboBox4->Text = "";
  Memo1->Clear();
  Memo2->Clear();
  Memo3->Clear();
  Memo4->Clear();
  MaskEdit1->Clear();
  DateTimePicker1->Date.DateString() = "";
  DateTimePicker2->Date.DateString() = "";
  DateTimePicker3->Date.DateString() = "";
  DateTimePicker4->Date.DateString() = "";
  DateTimePicker5->Date.DateString() = "";
  DateTimePicker6->Date.DateString() = "";
  DateTimePicker7->Date.DateString() = "";
}
//---------------------------------------------------------------------------
AnsiString TForm1::ConcatenarMemo(TMemo *Memo)
{
  AnsiString temp = Memo->Lines->operator [](0);      //.....coje todas la lineas del Memo y las une en una sola cadena
  for(int i=1;i<Memo->Lines->Count;i++)
     temp+= " "+ Memo->Lines->operator [](i);
  return temp;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)       //.......Insertar un Proyecto
{
  AnsiString objetivo = ConcatenarMemo(Memo1);
  DataModuleTablas->Insertar_Proyecto(Edit1->Text,Edit2->Text,Edit5->Text,ComboBox4->Text.ToInt(),DateTimePicker1->Date.DateString(),objetivo);
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)        //.......Insertar una Persona o Trabajador
{
  DataModuleTablas->Insertar_Persona(Edit10->Text,Edit8->Text,Edit9->Text,ComboBox2->Text,Edit11->Text,Edit25->Text,ComboBox3->Text,DBLookupComboBox1->Text,DateTimePicker2->Date.DateString());
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)       //.........Insertar un Modulo
{
  AnsiString objetivo = ConcatenarMemo(Memo4);
  DataModuleTablas->Insertar_Modulo(Edit13->Text,DBLookupComboBox2->Text,DBLookupComboBox13->Text,Edit15->Text,objetivo,DateTimePicker3->Date.DateString());
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button11Click(TObject *Sender)    //........Adicionar un Problema
{
  AnsiString descrpcion = ConcatenarMemo(Memo3);
  DataModuleTablas->Insertar_Problema(Edit33->Text,descrpcion);
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button15Click(TObject *Sender)    //.......Adicionar un Usuario
{
 if(MaskEdit2->Text == MaskEdit1->Text)
 {
  DataModuleTablas->Insertar_Usuario(Edit34->Text,MaskEdit2->Text, OwnerTemp);
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
 }
 else
 {
    ShowMessage("Su contrase�a no cocincide, por favor vuelva a intentarlo");
    MaskEdit2->Text = "";
    MaskEdit1->Text = "";
 }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EditarlaBasedeDato1Click(TObject *Sender)
{                              //.....mostrar la opcion de editar tablas
  EditarDB->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Salir1Click(TObject *Sender)
{
  if(MessageDlg(" � Desea cerrar la aplicacion ? ", mtConfirmation, TMsgDlgButtons()<<mbYes <<mbNo,0)== mrYes)
   {
     Application->Terminate();    //....cerrar la aplicacion
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button9Click(TObject *Sender)      //.....Adicionar una Tarea
{
  AnsiString objetivo = ConcatenarMemo(Memo2);
  DataModuleTablas->Insertar_Tarea(Edit27->Text,DBLookupComboBox3->Text,ComboBox1->Text,DateTimePicker5->Date.DateString(),DateTimePicker7->Date.DateString(),DateTimePicker6->Date.DateString(),objetivo);
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button13Click(TObject *Sender)    //.......Eliminar un usuario
{
  DataModuleTablas->Eliminar_Usuario(DBLookupComboBox10->Text);
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)   //...Eliminar un Proyecto
{
   DataModuleTablas->Eliminar_Proyecto(DBLookupComboBox12->Text);
   DataModuleTablas->Actualizar();
   LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender) //...Eliminar un trabajador
{
  DataModuleTablas->Eliminar_Persona(DBLookupComboBox11->Text);
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button6Click(TObject *Sender)    //.....Eliminar un Modulo
{
  DataModuleTablas->Eliminar_Modulo(DBLookupComboBox8->Text,DBLookupComboBox7->Text);
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button8Click(TObject *Sender)    //.........Eliminar un Componente
{
   DataModuleTablas->Eliminar_Componente(DBLookupComboBox6->Text);
   DataModuleTablas->Actualizar();
   LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button10Click(TObject *Sender)    //......Eliminar una Tarea
{
  DataModuleTablas->Eliminar_Tarea(DBLookupComboBox4->Text,DBLookupComboBox5->Text);
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button12Click(TObject *Sender)    //.......Eliminar un Problema
{
  DataModuleTablas->Eliminar_Problema(DBLookupComboBox9->Text);
  DataModuleTablas->Actualizar();
  LimpiarComponentes();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Insertar1Click(TObject *Sender)
{                                                   //......visualisar ventanas ocultamos todas menos la que nos hace falta
  Form2->Show();
  Form2->ComponenteModulo->Visible = true;
  Form2->TareaTrabajador->Visible = false;
  Form2->ProblemaComponente->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Eliminar1Click(TObject *Sender)
{                                                  //......visualisar ventanas ocultamos todas menos la que nos hace falta
  Form2->Show();
  Form2->ComponenteModulo->Visible = false;
  Form2->TareaTrabajador->Visible = false;
  Form2->ProblemaComponente->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::AsignarleunProblemaaunComponente1Click(
      TObject *Sender)                      //......visualisar ventanas ocultamos todas menos la que nos hace falta
{
  Form2->Show();
  Form2->ComponenteModulo->Visible = false;
  Form2->TareaTrabajador->Visible = true;
  Form2->ProblemaComponente->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::InformaciondelSistema1Click(TObject *Sender)
{
  Form3->ShowModal();          //......mostrar la ventana de informacion del sistema
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListadodeProyectos1Click(TObject *Sender)
{
  Form4->Actualizar();
  Form4->QuickRep1->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Listado1Click(TObject *Sender)
{                                          //......visualisar ventanas ocultamos todas menos la que nos hace falta
  Form5->Show();
  Form5->ListadoTareas->Visible = true;
  Form5->ListaProblemasComponentes->Visible = false;
  Form5->IstadoTrabajadoresComponentes->Visible = false;
  Form5->IncumplimientosComponentes->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Listadodeerroresporcomponentes1Click(
      TObject *Sender)                     //......visualisar ventanas ocultamos todas menos la que nos hace falta
{
  Form5->Show();
  Form5->ListadoTareas->Visible = false;
  Form5->ListaProblemasComponentes->Visible = true;
  Form5->IstadoTrabajadoresComponentes->Visible = false;
  Form5->IncumplimientosComponentes->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EstadodelasTareasporTrabajador1Click(
      TObject *Sender)
{                         //......visualisar ventanas ocultamos todas menos la que nos hace falta
  Form5->Show();
  Form5->ListadoTareas->Visible = false;
  Form5->ListaProblemasComponentes->Visible = false;
  Form5->IstadoTrabajadoresComponentes->Visible = true;
  Form5->IncumplimientosComponentes->Visible = false;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListadodeImcumplimientoporComponentes1Click(
      TObject *Sender)
{
  Form6->Actualizar();
  Form6->QuickRep1->Preview();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::ListadodeIncumplimientosporComponentes1Click(
      TObject *Sender)
{
  Form5->Show();           //......visualisar ventanas ocultamos todas menos la que nos hace falta
  Form5->ListadoTareas->Visible = false;
  Form5->ListaProblemasComponentes->Visible = false;
  Form5->IstadoTrabajadoresComponentes->Visible = false;
  Form5->IncumplimientosComponentes->Visible = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::EliminarBD1Click(TObject *Sender)
{
   FormConectar->ControlDB->VaciarBaseDato();
   DataModuleTablas->Actualizar();
}
//---------------------------------------------------------------------------
void TForm1::DesactivarMenu()
{
  EditarlaBasedeDato1->Enabled = false;
  Insertar1->Enabled = false;
  Eliminar1->Enabled = false;
  Eliminar1->Enabled = false;
  AsignarleunProblemaaunComponente1->Enabled = false;

  ListadodeProyectos1->Enabled = false;
  ListadodeImcumplimientoporComponentes1->Enabled = false;
  Listado1->Enabled = false;
  Listadodeerroresporcomponentes1->Enabled = false;
  EstadodelasTareasporTrabajador1->Enabled = false;
  ListadodeIncumplimientosporComponentes1->Enabled = false;

  EliminarBD1->Enabled = false;
  Copiadeseguridad1->Enabled = false;
  RestaurarBD1->Enabled = false; 
}
//---------------------------------------------------------------------------
void TForm1::ActivarMenu()
{
  EditarlaBasedeDato1->Enabled = true;
  Insertar1->Enabled = true;
  Eliminar1->Enabled = true;
  Eliminar1->Enabled = true;
  AsignarleunProblemaaunComponente1->Enabled = true;

  ListadodeProyectos1->Enabled = true;
  ListadodeImcumplimientoporComponentes1->Enabled = true;
  Listado1->Enabled = true;
  Listadodeerroresporcomponentes1->Enabled = true;
  EstadodelasTareasporTrabajador1->Enabled = true;
  ListadodeIncumplimientosporComponentes1->Enabled = true;

  EliminarBD1->Enabled = true;
  Copiadeseguridad1->Enabled = true;
  RestaurarBD1->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Copiadeseguridad1Click(TObject *Sender)
{
   try
   {
     if(MessageDlg("�Desea realizar una copia de seguridad o Backup de la Base de Datos ? ", mtConfirmation, TMsgDlgButtons()<<mbYes <<mbNo,0)== mrYes)
       {
        AnsiString dir = "";
        if(SaveDialog1->Execute())
        {
           dir = SaveDialog1->FileName;
           if(dir.SubString(dir.Length()-3,4)!= ".bak")
              dir = SaveDialog1->FileName + ".bak";
        }
       //... Eliminar el back up anterior
       AnsiString file_eliminar= "del " + dir ;
       system(file_eliminar.c_str());
       //... Efectuo la copia
       DataModuleTablas->Copia_de_Seguridad(FormConectar->NombreBD,dir);
       MessageDlg("La copia de seguridad o Backup se a completado. ", mtInformation, TMsgDlgButtons()<<mbOK,0);
      }
   }
   catch(...)
    {
     MessageDlg("No se pudo realizar la copia de seguridad debido a las politicas locales de administraci�n. ", mtWarning, TMsgDlgButtons()<<mbOK,0);
     return;
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::RestaurarBD1Click(TObject *Sender)
{
  Form7->Show();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
  AnsiString Hora = Time();
  AnsiString timer = "  Hora: ";
  timer.operator +=(Hora);
  timer.operator +=("     ");
  StatusBar1->Panels->Items[2]->Text  = timer;
}
//---------------------------------------------------------------------------

