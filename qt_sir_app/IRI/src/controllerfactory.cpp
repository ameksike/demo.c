#include "controllerfactory.h"

/** CONTROLADORES CONCRETOS  **/

#include "ngn_fija_controller.h"


Controller* ControllerFactory::getController( QString serviceName )
{
    Controller* concreteController = NULL;

    if( serviceName == "XPTU_NGN_FIJA" )
      concreteController = new  NGN_FIJA_Controller;

    return concreteController;
}
