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
//---------------------------------------------------------------------------
USEFORM("SistemaGP.cpp", Form1);
USEFORM("Unit1.cpp", DataModuleTablas); /* TDataModule: File Type */
USEFORM("Registro.cpp", FormRegistro);
USEFORM("Conectar_a.cpp", FormConectar);
USEFORM("EditDBrelacionescpp.cpp", Form2);
USEFORM("IformacionS.cpp", Form3);
USEFORM("ListadoProyectos.cpp", Form4);
USEFORM("ListadosPorCriterios.cpp", Form5);
USEFORM("ReporteC.cpp", Form6);
USEFORM("Unit7R.cpp", Form7);
USEFORM("Unit8.cpp", Form8);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->CreateForm(__classid(TDataModuleTablas), &DataModuleTablas);
                 Application->CreateForm(__classid(TFormRegistro), &FormRegistro);
                 Application->CreateForm(__classid(TFormConectar), &FormConectar);
                 Application->CreateForm(__classid(TForm2), &Form2);
                 Application->CreateForm(__classid(TForm3), &Form3);
                 Application->CreateForm(__classid(TForm4), &Form4);
                 Application->CreateForm(__classid(TForm5), &Form5);
                 Application->CreateForm(__classid(TForm6), &Form6);
                 Application->CreateForm(__classid(TForm7), &Form7);
                 Application->CreateForm(__classid(TForm8), &Form8);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        catch (...)
        {
                 try
                 {
                         throw Exception("");
                 }
                 catch (Exception &exception)
                 {
                         Application->ShowException(&exception);
                 }
        }
        return 0;
}
//---------------------------------------------------------------------------
