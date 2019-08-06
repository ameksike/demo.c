//---------------------------------------------------------------------------
/**
 * @package    SIR
 * @subpackage IRI
 * @author     ing. Antonio Membrides Espinosa
 * @date       21/02/2021
 * @version    1.0
 */
//---------------------------------------------------------------------------
#include <QtCore/QCoreApplication>
#include "src/lig.h"
int main(int argc, char *argv[])
{
     LIG lig(argc, argv);

    return lig.exec();
}
