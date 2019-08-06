#ifndef DAT_SSNOTIFICATION_H
#define DAT_SSNOTIFICATION_H


#include <qvariant.h>
#include <qstring.h>
#include <qstringlist.h>

#include <QQueue>

//#include "BUSINESS_LOGIC/Entity/structs.h"
#include "src/Entity/Fija/SuplementaryServiceEvent.h"


class QSqlQuery;

class Dat_SuplementaryServiceEvent
{
public:
    Dat_SuplementaryServiceEvent(QObject *parent = 0,const char *name = 0);
    Dat_SuplementaryServiceEvent(SuplementaryServiceEvent &old);
    //Dat_SuplementaryServiceEvent(QUpdateX2Event &);
    QQueue<QEvent*> getNotDeliveredEvents(QSqlQuery*);

    ~Dat_SuplementaryServiceEvent();

public:

    QString    getNumType();
    QString    getObjectNumber();
    QString    getTime();
    QString    getCallnumber();
    QString    getCallednumber();
    QString    getEventID();
    QString    getSubEventID();

    QString    getelementID(); //17
    QString    getRecordType();
    QString    getCin(); //6
    QString    getOperatorID(); //5
    QString    getLiiD(); //22
    QString    getCCLiD(); //6  /
    QString    getUsetype();
    QString    getUseresult(); //59 total
    QString    getSername();
    QString    getNotification();
    QString    getCalllndication();
    QString    getCapability(); //810
    QString    getFacilityop();
    QString    getGenericnumber();
    QString    getObjectnumber1();
    QString    getGatewayid();
    QString    getFirstcalling();
    QString    getSecondcalling();
    QString    getNEId();
    QString    getIdMC();
    QString    getDWReportId();
    QString    getDelivered();


public:

    void    setNumType(QString s);
    void    setObjectNumber(QString s);
    void    setTime(QString s);
    void    setCallingNumber(QString s);
    void    setCalledNumber(QString s);
    void    setEventID(QString s);
    void    setSubEventID(QString s);

    void    setElementID(QString s); //17
    void    setRecordType(QString s);
    void    setCin(QString s); //6
    void    setOperatorID(QString s); //5
    void    setLiiD(QString s); //22
    void    setCCLiD(QString s); //6  /
    void    setUsetype(QString s);
    void    setUseresult(QString s); //59 total
    void    setSername(QString s);
    void    setNotification(QString s);
    void    setCalllndication(QString s);
    void    setCapability(QString s); //810
    void    setFacilityop(QString s);
    void    setGenericnumber(QString s);
    void    setObjectnumber1(QString s);
    void    setGatewayid(QString s);
    void    setFirstcalling(QString s);
    void    setSecondcalling(QString s);
    void    setDWReportId(QString);
    void    setDelivered(QString);
    void    setLEAId(QString);

public:
    QString     generateDeleteStatement();
    //QString     generateInsertStatement();
    QString     generateInsertStatementNoSequence();
    void        readRecord(QSqlQuery query);
    QString     generateSelectStatement();
    QString     generateUpdateStatement();
    QStringList generateFieldList();
    QString     escapeString(QString stText,QChar cEscapeChar);

    QString     generateUpdateDelivered();
    bool        insert(QSqlQuery *);
    bool        updateDelivered(QSqlQuery*);
    bool        deleteRecord(QSqlQuery *);
    QString     generateNotDeliveredStatement();


protected:


    QString    NumType;
    QString    objectNumber;
    QString    time;
    QString    callnumber;
    QString    callednumber;
    QString    EventID;
    QString    SubEventID;
    QString    RecordType;
    QString    cin; //6
    QString    operatorID; //5
    QString    liiD; //22
    QString    cCLiD; //6  /
    QString    usetype;
    QString    useresult; //59 total
    QString    sername;
    QString    notification;
    QString    calllndication;
    QString    capability; //810
    QString    facilityop;
    QString    genericnumber;
    QString    objectnumber1;
    QString    gatewayid;
    QString    firstcalling;
    QString    secondcalling;
    QString    id;
    QString    NEId;
    QString    IdMC;
    QString    dWReportId;
    QString    delivered;

};

#endif // DAT_SSNOTIFICATION_H
