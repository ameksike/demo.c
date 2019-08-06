#include "dat_channelcontrolevent.h"

#include <qdatetime.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>

#include <string>
#include <iostream>
using namespace std; 

Dat_ChannelControlEvent::Dat_ChannelControlEvent(QObject */*parent*/,const char */*name*/)
{
}

Dat_ChannelControlEvent::~Dat_ChannelControlEvent()
{
}


Dat_ChannelControlEvent::Dat_ChannelControlEvent(QUpdateX2Event &updatex2event)
{
    //this->delivered  = updatex2event.getContentEventDelivered();
    this->m_stTime   = updatex2event.getContentEventTime();
    this->m_stIdMC   = updatex2event.getContentEventLEAId();
    this->dWReportId = updatex2event.getContentEventDWReportId();
}

Dat_ChannelControlEvent::Dat_ChannelControlEvent(ChannelControlEvent  &old)
{    
    this -> m_stNumType              = old.getNumType();
    this -> m_stNumber               = old.getObjectNumber();
    this -> m_stTime                 = old.getTime();
    this -> m_stRelatedcallstarttime = old.getRelatedCallStartTime();
    this -> m_stCombineorsplitflag   = old.getCombineOrSplitFlag();
    this -> m_stCallorcalledflag     = old.getCallOrCalledFlag();
    this -> m_stLeaaccessnum         = "";//movil
    this -> m_stCallid1              = old.getCallID1();
    this -> m_stCallid1              = old.getCallID2();
    this -> m_stEventid              = old.getEventID();
    this -> m_stSubeventid           = old.getSubEventID();
    this -> m_stSuccessflag          = "0";//movil
    this -> m_stFailurereasson       = "";//movil
    this -> m_stLiid                 = old.getLIID();    
    this -> m_stEventtype            = old.getEventType();
    this -> m_stNEId                 = old.getNEID();
    this -> m_stIdMC                 = old.getLEAID();
    this -> dWReportId               = old.getDWReportID();
    this -> m_stCalledNumber         = old.getCalledNumber();
    this -> m_stCallingNumber        = old.getCallingNumber();
    this->operatorID                 = old.getOperatorID();
    this->delivered                  = ( old.isDelivered() ) ? "1" : "0";
    this->cin                        = old.getCallIdentityNumber();
}

QString Dat_ChannelControlEvent::generateDeleteStatement()
{
    QString sql = "delete from iri.dat_channelcontrolevent ";
    sql += " WHERE (time=" + QString("'") + this->getTime() + QString("') AND (") + QString("dwreportid=") + this->getDWReportId() + QString(")");
    sql += " AND (idmc=" + getIdMC() + ")";
    return sql;
}

QString Dat_ChannelControlEvent::generateInsertStatement()
{
    return QString("INSERT INTO iri.dat_channelcontrolevent (numtype,number,time,relatedcallstarttime,combineorsplitflag,callorcalledflag,leaaccessnum,callid1,eventid,subeventid,successflag,failurereasson,liid,id,eventtype) values (")  + (getNumType().length() == 0 ? QString("null") : QString("'") + escapeString(getNumType(),QChar('\\')) + QString("'") ) + QString(",") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getRelatedcallstarttime().length() == 0 ? QString("null") : QString("'") + escapeString(getRelatedcallstarttime(),QChar('\\')) + QString("'") ) + QString(",") + (getCombineorsplitflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCombineorsplitflag(),QChar('\\')) + QString("'") ) + QString(",") + (getCallorcalledflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCallorcalledflag(),QChar('\\')) + QString("'") ) + QString(",") + (getLeaaccessnum().length() == 0 ? QString("null") : QString("'") + escapeString(getLeaaccessnum(),QChar('\\')) + QString("'") ) + QString(",") + (getCallid1().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid1(),QChar('\\')) + QString("'") ) + QString(",") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'") ) + QString(",") + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'") ) + QString(",") + (getSuccessflag().length() == 0 ? QString("null") : QString("'") + escapeString(getSuccessflag(),QChar('\\')) + QString("'") ) + QString(",") + (getFailurereasson().length() == 0 ? QString("null") : QString("'") + escapeString(getFailurereasson(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",nextval('Dat_ChannelControlEvent_sequence'),") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'") ) + QString(")");
}

QString Dat_ChannelControlEvent::generateInsertStatementNoSequence()
{
    return QString("INSERT INTO iri.dat_channelcontrolevent (numtype,number,time,relatedcallstarttime,combineorsplitflag,callorcalledflag,leaaccessnum,callid1,eventid,subeventid,successflag,failurereasson,liid,eventtype, neid, idmc, dwreportid, operatorid, callednumber, callingnumber, delivered, cin) values (")
           + (getNumType().length() == 0 ? QString("null") : QString("'") + escapeString(getNumType(),QChar('\\')) + QString("'") ) + QString(",")
           + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'") ) + QString(",")
           + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",")
           + (getRelatedcallstarttime().length() == 0 ? QString("null") : QString("'") + escapeString(getRelatedcallstarttime(),QChar('\\')) + QString("'") ) + QString(",")
           + (getCombineorsplitflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCombineorsplitflag(),QChar('\\')) + QString("'") ) + QString(",")
           + (getCallorcalledflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCallorcalledflag(),QChar('\\')) + QString("'") ) + QString(",")
           + (getLeaaccessnum().length() == 0 ? QString("null") : QString("'") + escapeString(getLeaaccessnum(),QChar('\\')) + QString("'") ) + QString(",")
           + (getCallid1().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid1(),QChar('\\')) + QString("'") ) + QString(",")
           + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'") ) + QString(",")
           + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'") ) + QString(",")
           + (getSuccessflag().length() == 0 ? QString("null") : QString("'") + escapeString(getSuccessflag(),QChar('\\')) + QString("'") ) + QString(",")
           + (getFailurereasson().length() == 0 ? QString("null") : QString("'") + escapeString(getFailurereasson(),QChar('\\')) + QString("'") ) + QString(",")
           + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",")
           + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'") )  + QString(",")
           + (getNEId().length() == 0 ? QString("null") : QString("'") + escapeString(getNEId(),QChar('\\')) + QString("'") )+ QString(",")
           + (getIdMC().length() == 0 ? QString("null") : escapeString(getIdMC(),QChar('\\')) )+ QString(",")
           + (getDWReportId().length() == 0 ? QString("null") : getDWReportId()) + QString(",")
           + (getOperatorID().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatorID(),QChar('\\')) + QString("'") )+ QString(",")
           + (getCalledNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCalledNumber(),QChar('\\')) + QString("'") )+ QString(",")           
           + (getCallingNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallingNumber(),QChar('\\')) + QString("'") )
           + QString(",")
           + (getDelivered().length() == 0 ? QString("'0'") : QString("'") + getDelivered() + QString("'"))
           + QString(",")
           + (getCallIdentityNumber().length() == 0 ? QString("null") : QString("'") + getCallIdentityNumber() + QString("'"))
           + QString(")");
}

QString Dat_ChannelControlEvent::generateUpdateStatement()
{
    return QString("UPDATE iri.dat_channelcontrolevent SET numtype = ") + (getNumType().length() == 0 ? QString("null") : QString("'") + escapeString(getNumType(),QChar('\\')) + QString("'")) +
            QString(", number = ") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'")) +
            QString(", time = ") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'")) +
            QString(", relatedcallstarttime = ") + (getRelatedcallstarttime().length() == 0 ? QString("null") : QString("'") + escapeString(getRelatedcallstarttime(),QChar('\\')) + QString("'")) +
            QString(", combineorsplitflag = ") + (getCombineorsplitflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCombineorsplitflag(),QChar('\\')) + QString("'")) +
            QString(", callorcalledflag = ") + (getCallorcalledflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCallorcalledflag(),QChar('\\')) + QString("'")) +
            QString(", leaaccessnum = ") + (getLeaaccessnum().length() == 0 ? QString("null") : QString("'") + escapeString(getLeaaccessnum(),QChar('\\')) + QString("'")) +
            QString(", callid1 = ") + (getCallid1().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid1(),QChar('\\')) + QString("'")) +
            QString(", eventid = ") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'")) +
            QString(", subeventid = ") + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'")) +
            QString(", successflag = ") + (getSuccessflag().length() == 0 ? QString("null") : QString("'") + escapeString(getSuccessflag(),QChar('\\')) + QString("'")) +
            QString(", failurereasson = ") + (getFailurereasson().length() == 0 ? QString("null") : QString("'") + escapeString(getFailurereasson(),QChar('\\')) + QString("'")) +
            QString(", liid = ") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'")) +            
            QString(", eventtype = ") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'"));
}

QString Dat_ChannelControlEvent::generateSelectStatement()
{
    return QString("SELECT numtype,number,time,relatedcallstarttime,combineorsplitflag,callorcalledflag,leaaccessnum,callid1,eventid,subeventid,successflag,failurereasson,liid,id,eventtype FROM iri.dat_channelcontrolevent");
}

QString Dat_ChannelControlEvent::generateUpdateDelivered()
{
   QString sql = "UPDATE iri.dat_channelcontrolevent SET delivered=" + QString("'") + this->getDelivered() + QString("'") ;
   sql += " WHERE (time=" + QString("'") + this->getTime() + QString("') AND (") + QString("dwreportid=") + this->getDWReportId() + QString(")");
   sql += " AND (idmc=" + getIdMC() + ")";
   return sql;
}

bool Dat_ChannelControlEvent::insert(QSqlQuery *query)
{
    QString sql = this->generateInsertStatementNoSequence();    
    return query->exec( sql );
}

bool Dat_ChannelControlEvent::updateDelivered(QSqlQuery *query)
{
    QString sql = this->generateUpdateDelivered();
    return query->exec( sql );
}


void Dat_ChannelControlEvent::readRecord(QSqlQuery query)
{
    m_stNumType = query.value(1).isNull() ? "" : query.value(1).toString();
    m_stNumber = query.value(2).isNull() ? "" : query.value(2).toString();
    m_stTime = query.value(3).isNull() ? "" : query.value(3).toString();
    m_stRelatedcallstarttime = query.value(4).isNull() ? "" : query.value(4).toString();
    m_stCombineorsplitflag = query.value(5).isNull() ? "" : query.value(5).toString();
    m_stCallorcalledflag = query.value(6).isNull() ? "" : query.value(6).toString();
    m_stLeaaccessnum = query.value(7).isNull() ? "" : query.value(7).toString();
    m_stCallid1 = query.value(8).isNull() ? "" : query.value(8).toString();
    m_stEventid = query.value(9).isNull() ? "" : query.value(9).toString();
    m_stSubeventid = query.value(10).isNull() ? "" : query.value(10).toString();
    m_stSuccessflag = query.value(11).isNull() ? "" : query.value(11).toString();
    m_stFailurereasson = query.value(12).isNull() ? "" : query.value(12).toString();
    m_stLiid = query.value(13).isNull() ? "" : query.value(13).toString();
    m_stId = query.value(14).isNull() ? "" : query.value(14).toString();
    m_stEventtype = query.value(15).isNull() ? "" : query.value(15).toString();
}

QStringList Dat_ChannelControlEvent::generateFieldList()
{
    QStringList	sl;    
    sl += "numtype";
    sl += "number";
    sl += "time";
    sl += "relatedcallstarttime";
    sl += "combineorsplitflag";
    sl += "callorcalledflag";
    sl += "leaaccessnum";
    sl += "callid1";
    sl += "eventid";
    sl += "subeventid";
    sl += "successflag";
    sl += "failurereasson";
    sl += "liid";
    sl += "id";
    sl += "eventtype";
    return sl;
}

QString Dat_ChannelControlEvent::escapeString(QString stData,QChar cEscapeCharacter)
{
    QString		stRet;
    int		nSize = stData.length();

    for (int i = 0;i < nSize;i++)
    {
        if (stData[i] == QChar('\'') || stData[i] == QChar('%'))
        {
            stRet += cEscapeCharacter;
        }
        stRet += stData[i];
    }
    return stRet;
}

/*QString Dat_ChannelControlEvent::getTableName()
	{
        return "iri.Dat_ChannelControlEvent";
	}*/

void Dat_ChannelControlEvent::setNumType(QString s)
	{
        m_stNumType = s;
	}

QString Dat_ChannelControlEvent::getNumType()
	{
        return m_stNumType;
	}

void Dat_ChannelControlEvent::setNumber(QString s)
	{
	m_stNumber = s;
	}

QString Dat_ChannelControlEvent::getNumber()
	{
	return m_stNumber;
	}

void Dat_ChannelControlEvent::setTime(QString s)
	{
	m_stTime = s;
	}

QString Dat_ChannelControlEvent::getTime()
	{
	return m_stTime;
	}

void Dat_ChannelControlEvent::setRelatedcallstarttime(QString s)
	{
	m_stRelatedcallstarttime = s;
	}

QString Dat_ChannelControlEvent::getRelatedcallstarttime()
	{
	return m_stRelatedcallstarttime;
	}

void Dat_ChannelControlEvent::setCombineorsplitflag(QString s)
	{
	m_stCombineorsplitflag = s;
	}

QString Dat_ChannelControlEvent::getCombineorsplitflag()
	{
	return m_stCombineorsplitflag;
	}

void Dat_ChannelControlEvent::setCallorcalledflag(QString s)
	{
	m_stCallorcalledflag = s;
	}

QString Dat_ChannelControlEvent::getCallorcalledflag()
	{
	return m_stCallorcalledflag;
	}

void Dat_ChannelControlEvent::setLeaaccessnum(QString s)
	{
	m_stLeaaccessnum = s;
	}

QString Dat_ChannelControlEvent::getLeaaccessnum()
	{
	return m_stLeaaccessnum;
	}

void Dat_ChannelControlEvent::setCallid1(QString s)
	{
	m_stCallid1 = s;
	}

QString Dat_ChannelControlEvent::getCallid1()
	{
	return m_stCallid1;
	}

void Dat_ChannelControlEvent::setEventid(QString s)
	{
	m_stEventid = s;
	}

QString Dat_ChannelControlEvent::getEventid()
	{
	return m_stEventid;
	}

void Dat_ChannelControlEvent::setSubeventid(QString s)
	{
	m_stSubeventid = s;
	}

QString Dat_ChannelControlEvent::getSubeventid()
	{
	return m_stSubeventid;
	}

void Dat_ChannelControlEvent::setSuccessflag(QString s)
	{
	m_stSuccessflag = s;
	}

QString Dat_ChannelControlEvent::getSuccessflag()
	{
	return m_stSuccessflag;
	}

void Dat_ChannelControlEvent::setFailurereasson(QString s)
	{
	m_stFailurereasson = s;
	}

QString Dat_ChannelControlEvent::getFailurereasson()
	{
	return m_stFailurereasson;
	}

void Dat_ChannelControlEvent::setLiid(QString s)
{
    m_stLiid = s;
}

QString Dat_ChannelControlEvent::getLiid()
{
    return m_stLiid;
}

void Dat_ChannelControlEvent::setId(QString s)
{
    m_stId = s;
}

QString Dat_ChannelControlEvent::getId()
{
    return m_stId;
}

void Dat_ChannelControlEvent::setEventtype(QString s)
{
    m_stEventtype = s;
}

QString Dat_ChannelControlEvent::getEventtype()
{
    return m_stEventtype;
}

QString Dat_ChannelControlEvent::getNEId()
{
    return this->m_stNEId;
}

QString Dat_ChannelControlEvent::getIdMC()
{
    return this->m_stIdMC;
}


void Dat_ChannelControlEvent::setDWReportId(QString s)
{
    this->dWReportId = s;
}

QString Dat_ChannelControlEvent::getDWReportId()
{
    return this->dWReportId;
}

void Dat_ChannelControlEvent::setDelivered(QString s)
{
    this->delivered = s;
}

QString Dat_ChannelControlEvent::getDelivered()
{
    return this->delivered;
}

void    Dat_ChannelControlEvent::setCallingNumber(QString s)
{
    this->m_stCallingNumber = s;
};

void    Dat_ChannelControlEvent::setCalledNumber(QString s)
{
   this->m_stCalledNumber = s;
};

QString    Dat_ChannelControlEvent::getCallingNumber()
{
    return this->m_stCallingNumber;
};
QString    Dat_ChannelControlEvent::getCalledNumber()
{
    return this->m_stCalledNumber;
};
QString Dat_ChannelControlEvent::getCallIdentityNumber()
{
    return this->cin;
}

void Dat_ChannelControlEvent::setCallIdentityNumber( QString s)
{
    this->cin = s;
}

void    Dat_ChannelControlEvent::setOperatorID(QString s){
    this->operatorID = s;
} //5
QString    Dat_ChannelControlEvent::getOperatorID(){
    return this->operatorID;
} //5

void Dat_ChannelControlEvent::operator=(const Dat_ChannelControlEvent &old)
{
    this -> m_stNumType              = old.m_stNumType;
    this -> m_stNumber               = old.m_stNumber;
    this -> m_stTime                 = old.m_stTime;
    this -> m_stRelatedcallstarttime = old.m_stRelatedcallstarttime;
    this -> m_stCombineorsplitflag   = old.m_stCombineorsplitflag;
    this -> m_stCallorcalledflag     = old.m_stCallorcalledflag;
    this -> m_stLeaaccessnum         = old.m_stLeaaccessnum;
    this -> m_stCallid1              = old.m_stCallid1;
    this -> m_stEventid              = old.m_stEventid;
    this -> m_stSubeventid           = old.m_stSubeventid;
    this -> m_stSuccessflag          = old.m_stSuccessflag;
    this -> m_stFailurereasson       = old.m_stFailurereasson;
    this -> m_stLiid                 = old.m_stLiid;
    this -> m_stId                   = old.m_stId;
    this -> m_stEventtype            = old.m_stEventtype;
    this -> m_stCalledNumber         = old.m_stCalledNumber;
    this -> m_stCallingNumber        = old.m_stCallingNumber;
    this->operatorID                 = old.operatorID;
    this->cin                        = old.cin;    
}


bool Dat_ChannelControlEvent::deleteRecord(QSqlQuery *query)
{
    QString sql = this->generateDeleteStatement();
    return query->exec( sql );
}


