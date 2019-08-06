#ifndef DATSSNOTIFICATION_H
#define DATSSNOTIFICATION_H

#include <qvariant.h>
#include <qstring.h>
#include <qstringlist.h>

#include "src/Entity/Fija/SSNotification.h"

class QSqlQuery;

class DatSSNotification
{
    public:
        DatSSNotification(QObject *parent = 0,const char *name = 0);
        DatSSNotification(const SSNotification &old);
        ~DatSSNotification();

    public:
        QString	getNmask();
        QString	getNumtype();
        QString	getObjectnumber();
        QString	getTime();
        QString	getEventid();
        QString	getSubeventid();
        QString	getCallnumber();
        QString	getCallednumber();
        QString	getRecordtype();
        QString	getCin();
        QString	getOperatorid();
        QString	getLiid();
        QString	getCclid();
        QString	getUsetype();
        QString	getUseresult();
        QString	getSername();
        QString	getNotification();
        QString	getCalllndcation();
        QString	getCapability();
        QString	getFacilityop();
        QString	getGenericnumber();
        QString getObjectnumber1();
        QString	getGatewayid();
        QString	getSecondcalling();
        QString getTableName();
        QString getid();

    public:
        void	setNmask(QString s);
        void	setNumtype(QString s);
        void	setObjectnumber(QString s);
        void	setTime(QString s);
        void	setEventid(QString s);
        void	setSubeventid(QString s);
        void	setCallnumber(QString s);
        void	setCallednumber(QString s);
        void	setRecordtype(QString s);
        void	setCin(QString s);
        void	setOperatorid(QString s);
        void	setLiid(QString s);
        void	setCclid(QString s);
        void	setUsetype(QString s);
        void	setUseresult(QString s);
        void	setSername(QString s);
        void	setNotification(QString s);
        void	setCalllndcation(QString s);
        void	setCapability(QString s);
        void	setFacilityop(QString s);
        void	setGenericnumber(QString s);
        void	setObjectnumber1(QString s);
        void	setGatewayid(QString s);
        void	setSecondcalling(QString s);
        void 	setid(QString s);

    public:
        QString     generateDeleteStatement();
        QString     generateInsertStatement();
        QString	    generateInsertStatementNoSequence();
        void	    readRecord(QSqlQuery query);
        QString	    generateSelectStatement();
        QString	    generateUpdateStatement();
        QStringList generateFieldList();
        QString	    escapeString(QString stText,QChar cEscapeChar);

    public:
        void        operator=(const DatSSNotification &old);

    protected:

        QString     m_stNmask;
        QString     m_stNumtype;
        QString     m_stObjectnumber;
        QString     m_stTime;
        QString     m_stEventid;
        QString     m_stSubeventid;
        QString     m_stCallnumber;
        QString     m_stCallednumber;
        QString     m_stRecordtype;
        QString     m_stCin;
        QString     m_stOperatorid;
        QString     m_stLiid;
        QString     m_stCclid;
        QString     m_stUsetype;
        QString     m_stUseresult;
        QString     m_stSername;
        QString     m_stNotification;
        QString     m_stCalllndcation;
        QString     m_stCapability;
        QString     m_stFacilityop;
        QString     m_stGenericnumber;
        QString     m_stObjectnumber1;
        QString     m_stGatewayid;
        QString     m_stSecondcalling;
        QString     m_stid;
};
#endif //DATSSNOTIFICATION_H

