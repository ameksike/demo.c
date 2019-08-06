#ifndef CHNCONTROLEVENTNOTIFICATION_H
#define CHNCONTROLEVENTNOTIFICATION_H

#include <qvariant.h>
#include <qstring.h>
#include <qstringlist.h>
#include "src/qsalvaevent.h"

#include "src/Entity/structs.h"
#include "src/Entity/Fija/ChannelControlEvent.h"

class QSqlQuery;

class Dat_ChannelControlEvent
{
    public:
        Dat_ChannelControlEvent(QObject *parent = 0,const char *name = 0);
        Dat_ChannelControlEvent(ChannelControlEvent &old);
        Dat_ChannelControlEvent(QUpdateX2Event &);
        ~Dat_ChannelControlEvent();

    public:        
        QString	getNumType();
        QString	getNumber();
        QString	getTime();
        QString	getRelatedcallstarttime();
        QString	getCombineorsplitflag();
        QString	getCallorcalledflag();
        QString getOperatorID();        
        QString	getLeaaccessnum();
        QString	getCallid1();
        QString	getCallid2();
        QString	getEventid();
        QString	getSubeventid();
        QString	getSuccessflag();
        QString	getFailurereasson();
        QString	getLiid();
        QString	getId();
        QString	getEventtype();
        QString getNEId();
        QString getIdMC();
        QString getDWReportId();
        QString getDelivered();
        QString getCallingNumber();
        QString getCalledNumber();
        QString getCallIdentityNumber();

    public:        
        void	setNumType(QString s);
        void	setNumber(QString s);
        void	setTime(QString s);
        void	setRelatedcallstarttime(QString s);
        void	setCombineorsplitflag(QString s);
        void	setCallorcalledflag(QString s);
        void	setLeaaccessnum(QString s);
        void	setCallid1(QString s);
         void	setCallid2(QString s);
        void	setEventid(QString s);
        void	setSubeventid(QString s);
        void	setSuccessflag(QString s);
        void	setFailurereasson(QString s);
        void	setLiid(QString s);
        void	setId(QString s);
        void	setEventtype(QString s);
        void    setDWReportId(QString);
        void    setDelivered(QString);
        void   setCallingNumber(QString s);
        void   setCalledNumber(QString s);
        void   setOperatorID(QString s);
        void   setCallIdentityNumber( QString s);

    public:
        QString     generateDeleteStatement();
        QString     generateInsertStatement();
        QString     generateInsertStatementNoSequence();
        void        readRecord(QSqlQuery query);
        QString     generateSelectStatement();
        QString     generateUpdateStatement();
        QString     escapeString(QString stText,QChar cEscapeChar);
        QStringList generateFieldList();
        QString     generateUpdateDelivered();

        bool        insert(QSqlQuery *);
        bool        updateDelivered(QSqlQuery*);
        bool        deleteRecord(QSqlQuery *);

    public:
        void	operator=(const Dat_ChannelControlEvent &old);

    protected:        
        QString	m_stNumType;
        QString	m_stNumber;
        QString	m_stTime;
        QString	m_stRelatedcallstarttime;
        QString	m_stCombineorsplitflag;
        QString	m_stCallorcalledflag;
        QString	m_stLeaaccessnum;
        QString	m_stCallid1;
        QString	m_stCallid2;
        QString	m_stEventid;
        QString	m_stSubeventid;
        QString	m_stSuccessflag;
        QString	m_stFailurereasson;
        QString	m_stLiid;
        QString	m_stId;
        QString	m_stEventtype;
        QString m_stNEId;
        QString m_stIdMC;
        QString m_stCallingNumber;
        QString m_stCalledNumber;
        QString dWReportId;
        QString delivered;
        QString operatorID;
        QString cin;
};
#endif //CHNCONTROLEVENTNOTIFICATION_H

