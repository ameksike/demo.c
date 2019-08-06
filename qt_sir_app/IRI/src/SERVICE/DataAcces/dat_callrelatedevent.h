#ifndef DAT_CALLRELATEDEVENT_H
#define DAT_CALLRELATEDEVENT_H

#ifndef CALLRELATEDEVENTNOTIFICATION_H
#define CALLRELATEDEVENTNOTIFICATION_H

#include <qvariant.h>
#include <qstring.h>
#include <qstringlist.h>
#include <QQueue>

#include "src/Entity/Fija/CallRelatedEvent.h"
#include "src/qsalvaevent.h"

class QSqlQuery;
class Dat_CallRelatedEvent
{
public:
            Dat_CallRelatedEvent(QObject *parent = 0,const char *name = 0);
            Dat_CallRelatedEvent(CallRelatedEvent &old);
            Dat_CallRelatedEvent(QUpdateX2Event &);
            ~Dat_CallRelatedEvent();

public:

        QString    getNumType();
        QString    getobjectNumber();
        QString    gettime();
        QString    getCallOrCalledFlag();
        QString    getCallingNumber();
        QString    getCalledNumber();
        QString    getCallID1();
        QString    getCallID2();
        QString    getEventID();
        QString    getSubEventID();
        QString    getCombineOrSplitFlag(); //130
        QString    getelementID(); //17
        QString    getRecordType();
        QString    getcin(); //6
        QString    getoperatorID(); //5
        QString    getliiD(); //22
        QString    getcCLiD(); //6  /
        QString    getCallState();
        QString    getNaturecall(); //59 total
        QString    getCapability();
        QString    getCallingSubAdd();
        QString    getCalledSubAdd();
        QString    getGenericNumber(); //810
        QString    getRedirectingNumber();
        QString    getRedirectionNumber();
        QString    getRedirectionInfo();
        QString    getOrgCalledNumber();
        QString    getDiversionInfo();
        QString    getConnectedSubAdd();
        QString    getConnectedNumber();
        QString    getRingDuration();
        QString    getReason(); //758
        QString    getNEId();
        QString    getIdMC();
        QString    getDWReportId();
        QString    getDelivered();
        QQueue<QEvent*> getNotDeliveredEvents(QSqlQuery*);

public:

        void   setNumType(QString s);
        void   setobjectNumber(QString s);
        void   settime(QString s);
        void   setCallOrCalledFlag(QString s);
        void   setCallingNumber(QString s);
        void   setCalledNumber(QString s);
        void   setCallID1(QString s);
        void   setCallID2(QString s);
        void   setEventID(QString s);
        void   setSubEventID(QString s);
        void   setCombineOrSplitFlag(QString s); //130
        void   setelementID(QString s); //17
        void   setRecordType(QString s);
        void   setcin(QString s); //6
        void   setoperatorID(QString s); //5
        void   setliiD(QString s); //22
        void   setcCLiD(QString s); //6  /
        void   setCallState(QString s);
        void   setNaturecall(QString s); //59 total
        void   setCapability(QString s);
        void   setCallingSubAdd(QString s);
        void   setCalledSubAdd(QString s);
        void   setGenericNumber(QString s); //810
        void   setRedirectingNumber(QString s);
        void   setRedirectionNumber(QString s);
        void   setRedirectionInfo(QString s);
        void   setOrgCalledNumber(QString s);
        void   setDiversionInfo(QString s);
        void   setConnectedSubAdd(QString s);
        void   setConnectedNumber(QString s);
        void   setRingDuration(QString s);
        void   setReason(QString s);
        void   setDWReportId(QString);
        void   setDelivered(QString);
        void   setLEAId(QString);
public:
        QString     generateDeleteStatement();
        QString     generateInsertStatement();
        QString     generateInsertStatementNoSequence();
        void        readRecord(QSqlQuery query);
        QString     generateSelectStatement();
        QString     generateUpdateStatement();
        QStringList generateFieldList();
        QString     escapeString(QString stText,QChar cEscapeChar);
        /** se encarga de actualizar el estado en la bd segun dwreportid y time**/
        QString     generateUpdateDelivered();
        QString     generateNotDeliveredStatement();
        QString     generateSelectStatementIdMCEventosPendientes();

        bool        insert(QSqlQuery *);
        bool        updateDelivered(QSqlQuery*);
        bool        deleteRecord(QSqlQuery *);
        QList<quint16> getListaIdMCEventosPendientes(QSqlQuery *);


protected:


        QString    NumType;
        QString    objectNumber;
        QString    time;
        QString    CallOrCalledFlag;
        QString    CallingNumber;
        QString    CalledNumber;
        QString    CallID1;
        QString    CallID2;
        QString    EventID;
        QString    SubEventID;
        QString    CombineOrSplitFlag; //130
        QString    elementID; //17
        QString    RecordType;
        QString    cin; //6
        QString    operatorID; //5
        QString    liiD; //22
        QString    cCLiD; //6  /
        QString    CallState;
        QString    Naturecall; //59 total
        QString    Capability;
        QString    CallingSubAdd;
        QString    CalledSubAdd;
        QString    GenericNumber; //810
        QString    RedirectingNumber;
        QString    RedirectionNumber;
        QString    RedirectionInfo;
        QString    OrgCalledNumber;
        QString    DiversionInfo;
        QString    ConnectedSubAdd;
        QString    ConnectedNumber;
        QString    RingDuration;
        QString    Reason; //758
        QString    id;
        QString    NEId;
        QString    IdMC;
        QString    dWReportId;
        QString    delivered;

};
#endif //CALLRELATEDEVENTNOTIFICATION_H

#endif // DAT_CALLRELATEDEVENT_H
