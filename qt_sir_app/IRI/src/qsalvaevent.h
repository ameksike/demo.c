#ifndef QSALVAEVENT_H
#define QSALVAEVENT_H

#include <QEvent>
#include <QString>
#include "src/qx2event.h"

class QUpdateX2Event: public QEvent
{
  public:

    enum
    {
      ACTUALIZAR_EVENT = ( QEvent::User + 110 ),
      ELIMINAR_EVENT   = ( QEvent::User + 111 )
    };

    QUpdateX2Event();

    QUpdateX2Event(QUpdateX2Event &);

    QEvent::Type getContentEventType();

    QString getContentEventTime();

    QString getContentEventDWReportId();

    QString getContentEventDelivered();

    QString getContentEventLEAId();

    void setContentEventType(QEvent::Type type);

    void setContentEventTime(QString);

    void setContentEventDWReportId(QString);

    void setContentEventDelivered(QString);

    void setContentEventLEAId(QString);

  private:    
    QEvent::Type contentEventType;
    QString      contentEventDWReportId;
    QString      contentEventTime;
    QString      contentEventDelivered;
    QString      contentEventLEAId;
};

#endif // QSALVAEVENT_H
