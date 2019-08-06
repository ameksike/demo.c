
/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       04/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef ListadoProyectosH
#define ListadoProyectosH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QuickRpt.hpp>
#include <QRCtrls.hpp>
#include "Unit1.h"
//---------------------------------------------------------------------------
class TForm4 : public TForm
{
__published:	// IDE-managed Components
        TQuickRep *QuickRep1;
        TQRBand *QRBand1;
        TQRLabel *QRLabel1;
        TQRSubDetail *QRSubDetail1;
        TQRShape *QRShape1;
        TQRShape *QRShape2;
        TQRDBText *QRDBText1;
        TQRDBText *QRDBText2;
        TQRShape *QRShape4;
        TQRShape *QRShape5;
        TQRShape *QRShape8;
        TQRLabel *QRLabel2;
        TQRLabel *QRLabel3;
        TQRShape *QRShape7;
        TQRShape *QRShape9;
        TQRShape *QRShape6;
        TQRShape *QRShape3;
        TQRShape *QRShape10;
        TQRSubDetail *QRSubDetail2;
        TQRShape *QRShape11;
        TQRShape *QRShape12;
        TQRShape *QRShape13;
        TQRShape *QRShape14;
private:	// User declarations
public:		// User declarations
          TADOTable * ADOTListadoProyectos;
          void Actualizar();
        __fastcall TForm4(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm4 *Form4;
//---------------------------------------------------------------------------
#endif
