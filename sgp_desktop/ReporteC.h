/**
 * @package    SGP
 * @subpackage app
 * @author     ing. Antonio Membrides Espinosa
 * @date       02/07/2006
 * @version    1.5
 */
//---------------------------------------------------------------------------
#ifndef ReporteCH
#define ReporteCH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <QRCtrls.hpp>
#include <QuickRpt.hpp>
#include "Unit1.h"
//---------------------------------------------------------------------------
class TForm6 : public TForm
{
__published:	// IDE-managed Components
        TQuickRep *QuickRep1;
        TQRBand *QRBand1;
        TQRLabel *QRLabel1;
        TQRShape *QRShape1;
        TQRShape *QRShape2;
        TQRShape *QRShape3;
        TQRShape *QRShape4;
        TQRShape *QRShape5;
        TQRLabel *QRLabel2;
        TQRLabel *QRLabel3;
        TQRSubDetail *QRSubDetail1;
        TQRShape *QRShape6;
        TQRShape *QRShape7;
        TQRShape *QRShape8;
        TQRSubDetail *QRSubDetail2;
        TQRShape *QRShape9;
        TQRShape *QRShape10;
        TQRShape *QRShape11;
        TQRShape *QRShape12;
        TQRDBText *QRDBText1;
        TQRDBText *QRDBText2;
private:	// User declarations
public:		// User declarations
          TADOTable * ADOTListadoMasTrabajan;
          void Actualizar();
        __fastcall TForm6(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm6 *Form6;
//---------------------------------------------------------------------------
#endif
