#ifndef CONTROLLERCURL_H
#define CONTROLLERCURL_H

#include <QThread>
#include <QQueue>
#include <QByteArray>
#include  "src/qx2event.h"
class controllerNgn : public QThread
{
    Q_OBJECT
public:
    controllerNgn();
    void run();

signals:
void signalMgs(QByteArray);
void signalsQX2Events(QX2Event*);

};

#endif // CONTROLLERCURL_H
