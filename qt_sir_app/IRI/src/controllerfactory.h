#ifndef CONTROLLERFACTORY_H
#define CONTROLLERFACTORY_H
#include "Controler.h"

class ControllerFactory
{
public:
    ControllerFactory(){};

    static Controller* getController( QString );
};

#endif // CONTROLLERFACTORY_H
