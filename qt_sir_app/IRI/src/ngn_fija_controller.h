
#ifndef NGN_FIJA_CONTROLLER_H
#define NGN_FIJA_CONTROLLER_H

#include "src/Entity/Utils.h"
#include "src/Entity/Fija/fija_definitions.h"
#include "src/Controler.h"
#include "src/Entity/Fija/HandShake.h"
#include "src/Entity/Fija/CallRelatedEvent.h"
#include "src/Entity/Fija/ChannelControlEvent.h"
#include "src/Entity/Fija/SuplementaryServiceEvent.h"

#include "SERVICE/DataAcces/dat_callrelatedevent.h"
#include "SERVICE/DataAcces/dat_suplementaryserviceevent.h"
#include "SERVICE/DataAcces/dat_channelcontrolevent.h"
#include "src/qx2event.h"
#include <iostream>
#include <QObject>
#include "src/deliveryfunction.h"

class NGN_FIJA_Controller: public Controller
{
    Q_OBJECT
public:
    NGN_FIJA_Controller();
    void iniciarDF();
    virtual ~NGN_FIJA_Controller();

private:
    DeliveryFunction *df;
    bool procesarEncabezadoTrama();

    bool procesarCuerpoTrama();

    bool datosLeidosCompletos();

    void reiniciarBufferTemporal();

    QX2Event::e_X2EVENT getCmdNormalizado();

public slots:
    void slotProcesarDatos(QByteArray);
signals:
    void signalsQX2Event(QX2Event*);
    void signalsQX2Events(QX2Event*);
    void signalsQX2EventByteAarray(QByteArray*);
};

#endif // NGN_FIJA_CONTROLLER_H
