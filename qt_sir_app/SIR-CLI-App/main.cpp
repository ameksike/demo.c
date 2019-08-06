//---------------------------------------------------------------------------
/**
 * @package    SIR
 * @subpackage SIR-CLI-APP
 * @author     ing. Antonio Membrides Espinosa
 * @date       27/04/2021
 * @version    1.0
 */
//---------------------------------------------------------------------------
#include "src/control/MainCLIApp.h"

int main(int argc, char *argv[])
{
    MainCLIApp app(argc, argv);
    app.on();
    return app.exec();
}
