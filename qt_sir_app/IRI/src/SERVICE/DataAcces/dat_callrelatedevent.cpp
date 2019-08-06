#include "dat_callrelatedevent.h"


#include <qdatetime.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <QSqlRecord>

 #include <string>
 #include <iostream>

 using namespace std;

Dat_CallRelatedEvent::Dat_CallRelatedEvent(QObject */*parent*/,const char */*name*/)
{
}

Dat_CallRelatedEvent::Dat_CallRelatedEvent(QUpdateX2Event &updatex2event)
{
    //this->delivered  = updatex2event.getContentEventDelivered();
    this->time       = updatex2event.getContentEventTime();
    this->IdMC       = updatex2event.getContentEventLEAId();
    this->dWReportId = updatex2event.getContentEventDWReportId();
}

Dat_CallRelatedEvent::Dat_CallRelatedEvent(CallRelatedEvent &old)
{
    this->NumType            = old.getNumType();
    this->CalledNumber       = old.getCalledNumber();
    this->CalledSubAdd       = old.getCalledSubAddr();
    this->CallID1            = old.getCallID1();
    this->CallID2            = old.getCallID2();
    this->CallingNumber      = old.getCallingNumber();
    this->CallingSubAdd      = old.getCallingSubAddr();
    this->CallOrCalledFlag   = old.getCallOrCalledFlag();
    this->CallState          = old.getCallState();
    this->Capability         = old.getCapability();
    this->cCLiD              = old.getCCLinkID();
    this->cin                = old.getCallIdentityNumber();
    this->CombineOrSplitFlag = old.getCombineOrSplitFlag();
    this->ConnectedNumber    = old.getConnectedNumber();
    this->ConnectedSubAdd    = old.getConnectedSubAddr();
    this->DiversionInfo      = old.getDiversionInfo();
    this->elementID          = old.getElementID();
    this->EventID            = old.getEventID();
    this->GenericNumber      = old.getGenericNumber();
    this->liiD               = old.getLIID();
    this->Naturecall         = old.getNatureCall();
    this->objectNumber       = old.getObjectNumber();
    this->operatorID         = old.getOperatorID();
    this->Reason             = old.getReason();
    this->RecordType         = old.getRecordType();
    this->RedirectingNumber  = old.getRedirectingNumber();
    this->RedirectionInfo    = old.getRedirectionInfo();
    this->RedirectionNumber  = old.getRedirectionNumber();
    this->RingDuration       = old.getRingDuration();
    this->SubEventID         = old.getSubEventID();
    this->time               = old.getTime();
    this->NEId               = old.getNEID();
    this->IdMC               = old.getLEAID();
    this->dWReportId         = old.getDWReportID();
    this->OrgCalledNumber    = old.getOriginalCalledNumber();
    this->delivered          = ( old.isDelivered() ) ? "1" : "0";
}


Dat_CallRelatedEvent::~Dat_CallRelatedEvent()
{
}

QString Dat_CallRelatedEvent::generateDeleteStatement()
{
    QString sql = "delete from  iri.dat_callrelatedevent  ";
    sql += " WHERE (time=" + QString("'") + this->gettime() + QString("') AND (") + QString("dwreportid=") + this->getDWReportId() + QString(")");
    sql += " AND (idmc=" + getIdMC() + ")";    
    return sql;
}


QString Dat_CallRelatedEvent::generateInsertStatementNoSequence()
{
    return QString("INSERT INTO iri.dat_callrelatedevent"
        "(numtype,objectNumber,time,callorcalledflag,"
        "callingnumber,callednumber,callid1,callid2,eventid,"
        "subeventid,combineorsplitflag,elementid,recordtype,"
        "cin,operatorid,cclid,liid,callstate,naturecall,capability,"
        "callingsubadd,calledsubadd,genericnumber,redirectingnumber,"
        "redirectionnumber,redirectioninfo,orgcallednumber,diversioninfo,"
        "connectedsubadd,connectednumber,ringduration,reason, neid, idmc, dwreportid, delivered) values (") +

        (getNumType().length() == 0 ? QString("null") : QString("'") + escapeString(getNumType(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getobjectNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getobjectNumber(),QChar('\\')) + QString("'"))
        + QString(",")+
        (gettime().length() == 0 ? QString("null") : QString("'") + escapeString(gettime(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getCallOrCalledFlag().length() == 0 ? QString("null") : QString("'") + escapeString(getCallOrCalledFlag(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getCallingNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallingNumber(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getCalledNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCalledNumber(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getCallID1().length() == 0 ? QString("null") : escapeString(getCallID1(),QChar('\\')) )
        + QString(",")+
        (getCallID2().length() == 0 ? QString("null") : escapeString(getCallID2(),QChar('\\')) )
        + QString(",")+
        (getEventID().length() == 0 ? QString("null") : escapeString(getEventID(),QChar('\\')) )
        + QString(",")+
        (getSubEventID().length() == 0 ? QString("null") : escapeString(getSubEventID(),QChar('\\')))
        + QString(",")+
        (getCombineOrSplitFlag().length() == 0 ? QString("null") : QString("'") + escapeString(getCombineOrSplitFlag(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getelementID().length() == 0 ? QString("null") : QString("'") + escapeString(getelementID(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getRecordType().length() == 0 ? QString("null") : QString("'") + escapeString(getRecordType(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getcin().length() == 0 ? QString("null") : QString("'") + escapeString(getcin(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getoperatorID().length() == 0 ? QString("null") : QString("'") + escapeString(getoperatorID(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getcCLiD().length() == 0 ? QString("null") : QString("'") + escapeString(getcCLiD(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getliiD().length() == 0 ? QString("null") : QString("'") + escapeString(getliiD(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getCallState().length() == 0 ? QString("null") : QString("'") + escapeString(getCallState(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getNaturecall().length() == 0 ? QString("null") : QString("'") + escapeString(getNaturecall(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getCapability().length() == 0 ? QString("null") : QString("'") + escapeString(getCapability(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getCallingSubAdd().length() == 0 ? QString("null") : QString("'") + escapeString(getCallingSubAdd(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getCalledSubAdd().length() == 0 ? QString("null") : QString("'") + escapeString(getCalledSubAdd(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getGenericNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getGenericNumber(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getRedirectingNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirectingNumber(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getRedirectionNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirectionNumber(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getRedirectionInfo().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirectionInfo(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getOrgCalledNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getOrgCalledNumber(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getDiversionInfo().length() == 0 ? QString("null") : QString("'") + escapeString(getDiversionInfo(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getConnectedSubAdd().length() == 0 ? QString("null") : QString("'") + escapeString(getConnectedSubAdd(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getConnectedNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getConnectedNumber(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getRingDuration().length() == 0 ? QString("null") : QString("'") + escapeString(getRingDuration(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getReason().length() == 0 ? QString("null") : QString("'") + escapeString(getReason(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getNEId().length() == 0 ? QString("null") : QString("'") + escapeString(getNEId(),QChar('\\')) + QString("'"))
        + QString(",")+
        (getIdMC().length() == 0 ? QString("null") : escapeString(getIdMC(),QChar('\\')) )
        + QString(",")+
        (getDWReportId().length() == 0 ? QString("null") : getDWReportId() )
        + QString(",")
        + (getDelivered().length() == 0 ? QString("'0'") : QString("'") + getDelivered() + QString("'"))
        + QString(")");
}

QString Dat_CallRelatedEvent::generateUpdateStatement()
{
    return  QString("UPDATE iri.dat_callrelatedevent SET NumType = ") + (getNumType().length() == 0 ? QString("null") : QString("'") + escapeString(getNumType(),QChar('\\')) + QString("'")) +
            QString(", objectNumber = ") + (getobjectNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getobjectNumber(),QChar('\\')) + QString("'")) +
            QString(", time = ") + (gettime().length() == 0 ? QString("null") : QString("'") + escapeString(gettime(),QChar('\\')) + QString("'")) +
            QString(", CallOrCalledFlag = ") + (getCallOrCalledFlag().length() == 0 ? QString("null") : QString("'") + escapeString(getCallOrCalledFlag(),QChar('\\')) + QString("'")) +
            QString(", CallingNumber = ") + (getCallingNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallingNumber(),QChar('\\')) + QString("'")) +
            QString(", CalledNumber = ") + (getCalledNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCalledNumber(),QChar('\\')) + QString("'")) +
            QString(", CallID1 = ") + (getCallID1().length() == 0 ? QString("null") : escapeString(getCallID1(),QChar('\\'))) +
            QString(", CallID2 = ") + (getCallID2().length() == 0 ? QString("null") : escapeString(getCallID2(),QChar('\\'))) +
            QString(", EventID = ") + (getEventID().length() == 0 ? QString("null") : QString("'") + escapeString(getEventID(),QChar('\\')) + QString("'")) +
            QString(", SubEventID = ") + (getSubEventID().length() == 0 ? QString("null") : QString("'") + escapeString(getSubEventID(),QChar('\\')) + QString("'")) +
            QString(", CombineOrSplitFlag = ") + (getCombineOrSplitFlag().length() == 0 ? QString("null") : QString("'") + escapeString(getCombineOrSplitFlag(),QChar('\\')) + QString("'")) +
            QString(", elementID = ") + (getelementID().length() == 0 ? QString("null") : QString("'") + escapeString(getelementID(),QChar('\\')) + QString("'")) +
            QString(", RecordType = ") + (getRecordType().length() == 0 ? QString("null") : QString("'") + escapeString(getRecordType(),QChar('\\')) + QString("'")) +
            QString(", cin = ") + (getcin().length() == 0 ? QString("null") : QString("'") + escapeString(getcin(),QChar('\\')) + QString("'")) +
            QString(", operatorID = ") + (getoperatorID().length() == 0 ? QString("null") : QString("'") + escapeString(getoperatorID(),QChar('\\')) + QString("'")) +
            QString(", cCLiD = ") + (getcCLiD().length() == 0 ? QString("null") : QString("'") + escapeString(getcCLiD(),QChar('\\')) + QString("'")) +
            QString(", liiD = ") + (getliiD().length() == 0 ? QString("null") : QString("'") + escapeString(getliiD(),QChar('\\')) + QString("'")) +
            QString(", CallState = ") + (getCallState().length() == 0 ? QString("null") : QString("'") + escapeString(getCallState(),QChar('\\')) + QString("'")) +
            QString(", Naturecall = ") + (getNaturecall().length() == 0 ? QString("null") : QString("'") + escapeString(getNaturecall(),QChar('\\')) + QString("'"));
            QString(", Capability = ") + (getCapability().length() == 0 ? QString("null") : QString("'") + escapeString(getCapability(),QChar('\\')) + QString("'")) +
            QString(", CallingSubAdd = ") + (getCallingSubAdd().length() == 0 ? QString("null") : QString("'") + escapeString(getCallingSubAdd(),QChar('\\')) + QString("'")) +
            QString(", CalledSubAdd = ") + (getCalledSubAdd().length() == 0 ? QString("null") : QString("'") + escapeString(getCalledSubAdd(),QChar('\\')) + QString("'")) +
            QString(", GenericNumber = ") + (getGenericNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getGenericNumber(),QChar('\\')) + QString("'")) +
            QString(", RedirectingNumber = ") + (getRedirectingNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirectingNumber(),QChar('\\')) + QString("'")) +
            QString(", RedirectionNumber = ") + (getRedirectionNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirectionNumber(),QChar('\\')) + QString("'")) +
            QString(", RedirectionInfo = ") + (getRedirectionInfo().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirectionInfo(),QChar('\\')) + QString("'")) +
            QString(", OrgCalledNumber = ") + (getOrgCalledNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getOrgCalledNumber(),QChar('\\')) + QString("'")) +
            QString(", DiversionInfo = ") + (getDiversionInfo().length() == 0 ? QString("null") : QString("'") + escapeString(getDiversionInfo(),QChar('\\')) + QString("'")) +
            QString(", ConnectedSubAdd = ") + (getConnectedSubAdd().length() == 0 ? QString("null") : QString("'") + escapeString(getConnectedSubAdd(),QChar('\\')) + QString("'")) +
            QString(", ConnectedNumber = ") + (getConnectedNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getConnectedNumber(),QChar('\\')) + QString("'")) +
            QString(", RingDuration = ") + (getRingDuration().length() == 0 ? QString("null") : QString("'") + escapeString(getRingDuration(),QChar('\\')) + QString("'")) +
            QString(", Reason = ") + (getReason().length() == 0 ? QString("null") : QString("'") + escapeString(getReason(),QChar('\\')) + QString("'"))+
            QString(", NEId = ") + (getNEId().length() == 0 ? QString("null") : QString("'") + escapeString(getNEId(),QChar('\\')) + QString("'")) +
            QString(", idmc = ") + (getIdMC().length() == 0 ? QString("null") : getIdMC()) +
            QString(", dwreportid = ") + (getDWReportId().length() == 0 ? QString("null") : getDWReportId());
}

QString Dat_CallRelatedEvent::generateSelectStatement()
{
    return QString("SELECT numtype,objectNumber,time,CallOrCalledFlag,"
               "CallingNumber,CalledNumber,CallID1,CallID1,EventID,"
               "SubEventID,CombineOrSplitFlag,elementID,RecordType,"
               "cin,operatorID,cCLiD,liiD,CallState,Naturecall,Capability,"
               "CallingSubAdd,CalledSubAdd,GenericNumber,RedirectingNumber,"
               "RedirectionNumber,RedirectionInfo,OrgCalledNumber,DiversionInfo,"
               "ConnectedSubAdd,ConnectedNumber,RingDuration,Reason,idcallrelatedeventnotification"
               " FROM lea.Dat_CallRelatedEvent");
}

QString Dat_CallRelatedEvent::generateUpdateDelivered()
{
   QString sql = "UPDATE iri.dat_callrelatedevent SET delivered=" + QString("'") + this->getDelivered() + QString("'") ;
   sql += " WHERE (time=" + QString("'") + this->gettime() + QString("') AND (") + QString("dwreportid=") + this->getDWReportId() + QString(")");
   sql += " AND (idmc=" + getIdMC() + ")";
   return sql;
}

bool Dat_CallRelatedEvent::insert(QSqlQuery *query)
{
    QString sql = this->generateInsertStatementNoSequence();
    cout<<sql.toStdString()<<endl;
    return query->exec( sql );
}

bool Dat_CallRelatedEvent::updateDelivered(QSqlQuery *query)
{
    QString sql = this->generateUpdateDelivered();
    return query->exec( sql );
}

bool Dat_CallRelatedEvent::deleteRecord(QSqlQuery *query)
{
    QString sql = this->generateDeleteStatement();
    return query->exec( sql );
}

QList<quint16> Dat_CallRelatedEvent::getListaIdMCEventosPendientes(QSqlQuery *query)
{
    QList<quint16> idMCs;
    QString sql = this->generateSelectStatementIdMCEventosPendientes();    
    if( query->exec( sql ) )
    {
        while( query->next() )
        {
           idMCs.append( query->value(0).toInt() );
        }
    }
    return idMCs;
}



void Dat_CallRelatedEvent::readRecord(QSqlQuery query)
{

    this->NumType =query.value(0).isNull() ? "" : query.value(0).toString();
    this->objectNumber=query.value(1).isNull() ? "" : query.value(1).toString();
    this->time=query.value(2).isNull() ? "" : query.value(2).toString();
    this->CallOrCalledFlag =query.value(3).isNull() ? "" : query.value(3).toString();
    this->CallingNumber=query.value(4).isNull() ? "" : query.value(4).toString();
    this->CalledNumber=query.value(5).isNull() ? "" : query.value(5).toString();
    this->CallID1=query.value(6).isNull()?"":query.value(6).toString();
    this->CallID2=query.value(7).isNull()?"":query.value(7).toString();
    this->EventID=query.value(8).isNull()?"":query.value(8).toString();
    this->SubEventID=query.value(9).isNull()?"":query.value(9).toString();
    this->CombineOrSplitFlag=query.value(10).isNull()?"":query.value(10).toString();
    this->elementID=query.value(10).isNull()?"":query.value(10).toString();
    this->RecordType=query.value(11).isNull()?"":query.value(11).toString();
    this->cin=query.value(12).isNull()?"":query.value(12).toString();
    this->operatorID=query.value(13).isNull()?"":query.value(13).toString();
    this->cCLiD=query.value(14).isNull()?"":query.value(14).toString();
    this->liiD=query.value(15).isNull()?"":query.value(15).toString();
    this->CallState=query.value(16).isNull()?"":query.value(16).toString();
    this->Naturecall=query.value(17).isNull()?"":query.value(17).toString();
    this->Capability=query.value(18).isNull()?"":query.value(18).toString();
    this->CallingSubAdd=query.value(19).isNull()?"":query.value(19).toString();
    this->CalledSubAdd=query.value(20).isNull()?"":query.value(20).toString();
    this->GenericNumber=query.value(21).isNull()?"":query.value(21).toString();
    this->RedirectingNumber =query.value(22).isNull()?"":query.value(22).toString();
    this->RedirectionNumber =query.value(23).isNull()?"":query.value(23).toString();
    this->RedirectionInfo   =query.value(24).isNull()?"":query.value(24).toString();
    this->OrgCalledNumber   =query.value(25).isNull()?"":query.value(25).toString();
    this->ConnectedSubAdd   =query.value(26).isNull()?"":query.value(26).toString();
    this->ConnectedNumber=query.value(27).isNull()?"":query.value(27).toString();
    this->RingDuration=query.value(28).isNull()?"":query.value(28).toString();
    this->Reason=query.value(29).isNull()?"":query.value(29).toString();
    this->id=query.value(30).isNull()?"":query.value(30).toString();

}


QStringList Dat_CallRelatedEvent::generateFieldList()
{
    QStringList	sl;

    sl += "NumType";
    sl += "objectNumber";
    sl += "time";
    sl += "CallOrCalledFlag";
    sl += "CalledNumber";
    sl += "CallingNumber";
    sl += "CallID1";
    sl += "CallID2";
    sl += "EventID";
    sl += "SubEventID";
    sl += "CombineOrSplitFlag";
    sl += "elementID";
    sl += "RecordType";
    sl += "cin";
    sl += "operatorID";
    sl += "liiD";
    sl += "cCLiD";
    sl += "CallState";
    sl += "Naturecall";
    sl += "Capability";
    sl += "CallingSubAdd";
    sl += "GenericNumber";
    sl += "RedirectingNumber";
    sl += "RedirectionNumber";
    sl += "RedirectionInfo";
    sl += "OrgCalledNumber";
    sl += "DiversionInfo";
    sl += "ConnectedSubAdd";
    sl += "ConnectedNumber";
    sl += "RingDuration";
    sl += "Reason";
    sl  +="idcallrelatedeventnotification";
    return sl;
}

QString Dat_CallRelatedEvent::escapeString(QString stData,QChar cEscapeCharacter)
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

/*****************************GET y SET*****************/
QString    Dat_CallRelatedEvent::getNumType()
{
    return this->NumType;
};
QString    Dat_CallRelatedEvent::getobjectNumber()
{
  return this->objectNumber;
};
QString    Dat_CallRelatedEvent::gettime()
{
    return this->time;
};
QString    Dat_CallRelatedEvent::getCallOrCalledFlag()
{
    return this->CallOrCalledFlag;
};
QString    Dat_CallRelatedEvent::getCallingNumber()
{
    return this->CallingNumber;
};
QString    Dat_CallRelatedEvent::getCalledNumber()
{
    return this->CalledNumber;
};
QString    Dat_CallRelatedEvent::getCallID1()
{
    return this->CallID1;
};
QString    Dat_CallRelatedEvent::getCallID2()
{
    return this->CallID2;
};
QString    Dat_CallRelatedEvent::getEventID()
{
    return this->EventID;
};
QString    Dat_CallRelatedEvent::getSubEventID()
{
     return this->SubEventID;
};
QString    Dat_CallRelatedEvent::getCombineOrSplitFlag()
{
    return this->CombineOrSplitFlag;
}; //130
QString    Dat_CallRelatedEvent::getelementID()
{
    return this->elementID;
}; //17
QString    Dat_CallRelatedEvent::getRecordType()
{
    return this->RecordType;
};
QString    Dat_CallRelatedEvent::getcin()
{
     return this->cin;
}; //6
QString    Dat_CallRelatedEvent::getoperatorID()
{
   return this->operatorID;
}; //5
QString    Dat_CallRelatedEvent::getliiD()
{
     return this->liiD;
}; //22
QString    Dat_CallRelatedEvent::getcCLiD()
{
    return this->cCLiD;
}; //6  /
QString    Dat_CallRelatedEvent::getCallState()
{
    return this->CallState;
};
QString    Dat_CallRelatedEvent::getNaturecall()
{
    return this->Naturecall;
}; //59 total
QString    Dat_CallRelatedEvent::getCapability()
{
    return this->Capability;
};
QString    Dat_CallRelatedEvent::getCallingSubAdd()
{
    return this->CallingSubAdd;
};
QString    Dat_CallRelatedEvent::getCalledSubAdd()
{
      return this->CalledSubAdd;
};
QString    Dat_CallRelatedEvent::getGenericNumber()
{
     return this->GenericNumber;
}; //810
QString    Dat_CallRelatedEvent::getRedirectingNumber()
{
    return this->RedirectingNumber;
};
QString    Dat_CallRelatedEvent::getRedirectionNumber()
{
     return this->RedirectionNumber;
};
QString    Dat_CallRelatedEvent::getRedirectionInfo()
{
    return this->RedirectionInfo;
};
QString    Dat_CallRelatedEvent::getOrgCalledNumber()
{
  return this->OrgCalledNumber;
};
QString    Dat_CallRelatedEvent::getDiversionInfo()
{
  return this->DiversionInfo;
};
QString    Dat_CallRelatedEvent::getConnectedSubAdd()
{
  return this->ConnectedSubAdd;
};
QString    Dat_CallRelatedEvent::getConnectedNumber()
{
    return this->ConnectedNumber;
};
QString    Dat_CallRelatedEvent::getRingDuration()
{
   return this->RingDuration;
};
QString    Dat_CallRelatedEvent::getReason()
{
 return this->Reason;
}; //758

QString Dat_CallRelatedEvent::getNEId()
{
    return this->NEId;
}

QString Dat_CallRelatedEvent::getIdMC()
{
    return this->IdMC;
}

void Dat_CallRelatedEvent::setDWReportId(QString s)
{
    this->dWReportId = s;
}

QString Dat_CallRelatedEvent::getDWReportId()
{
    return this->dWReportId;
}

void Dat_CallRelatedEvent::setDelivered(QString s)
{
    this->delivered = s;
}

QString Dat_CallRelatedEvent::getDelivered()
{
    return this->delivered;
}

//set
void    Dat_CallRelatedEvent::setNumType(QString s)
{
    this->NumType=s;
};
void    Dat_CallRelatedEvent::setobjectNumber(QString s)
{
  this->objectNumber=s;
};
void    Dat_CallRelatedEvent::settime(QString s)
{
     this->time=s;
};
void    Dat_CallRelatedEvent::setCallOrCalledFlag(QString s)
{
    this->CallOrCalledFlag=s;
};
void    Dat_CallRelatedEvent::setCallingNumber(QString s)
{
    this->CallingNumber=s;
};
void    Dat_CallRelatedEvent::setCalledNumber(QString s)
{
   this->CalledNumber=s;
};
void    Dat_CallRelatedEvent::setCallID1(QString s)
{
     this->CallID1=s;
};
void    Dat_CallRelatedEvent::setCallID2(QString s)
{
     this->CallID2=s;
};
void    Dat_CallRelatedEvent::setEventID(QString s)
{
    this->EventID=s;
};
void    Dat_CallRelatedEvent::setSubEventID(QString s)
{
     this->SubEventID=s;
};
void    Dat_CallRelatedEvent::setCombineOrSplitFlag(QString s)
{
     this->CombineOrSplitFlag=s;
}; //130
void    Dat_CallRelatedEvent::setelementID(QString s)
{
    this->elementID=s;
}; //17
void    Dat_CallRelatedEvent::setRecordType(QString s)
{
   this->RecordType=s;
};
void    Dat_CallRelatedEvent::setcin(QString s)
{
      this->cin=s;
}; //6
void    Dat_CallRelatedEvent::setoperatorID(QString s)
{
   this->operatorID=s;
}; //5
void    Dat_CallRelatedEvent::setliiD(QString s)
{
     this->liiD=s;
}; //22
void    Dat_CallRelatedEvent::setcCLiD(QString s)
{
    this->cCLiD=s;
}; //6  /
void    Dat_CallRelatedEvent::setCallState(QString s)
{
    this->CallState=s;
};
void    Dat_CallRelatedEvent::setNaturecall(QString s)
{
    this->Naturecall=s;
}; //59 total
void    Dat_CallRelatedEvent::setCapability(QString s)
{
     this->Capability=s;
};
void    Dat_CallRelatedEvent::setCallingSubAdd(QString s)
{
   this->CallingSubAdd=s;
};
void    Dat_CallRelatedEvent::setCalledSubAdd(QString s)
{
       this->CalledSubAdd=s;
};
void    Dat_CallRelatedEvent::setGenericNumber(QString s)
{
      this->GenericNumber=s;
}; //810
void    Dat_CallRelatedEvent::setRedirectingNumber(QString s)
{
     this->RedirectingNumber=s;
};
void    Dat_CallRelatedEvent::setRedirectionNumber(QString s)
{
     this->RedirectionNumber=s;
};
void    Dat_CallRelatedEvent::setRedirectionInfo(QString s)
{
     this->RedirectionInfo=s;
};
void    Dat_CallRelatedEvent::setOrgCalledNumber(QString s)
{
  this->OrgCalledNumber=s;
};
void    Dat_CallRelatedEvent::setDiversionInfo(QString s)
{
   this->DiversionInfo=s;
};
void    Dat_CallRelatedEvent::setConnectedSubAdd(QString s)
{
   this->ConnectedSubAdd=s;
};
void    Dat_CallRelatedEvent::setConnectedNumber(QString s)
{
    this->ConnectedNumber=s;
};
void    Dat_CallRelatedEvent::setRingDuration(QString s)
{
   this->RingDuration=s;
};
void    Dat_CallRelatedEvent::setReason(QString s)
{
  this->Reason=s;
}; //758

void Dat_CallRelatedEvent::setLEAId(QString leaid)
{
    this->IdMC = leaid;
}

QString Dat_CallRelatedEvent::generateNotDeliveredStatement()
{
   return  QString("SELECT recordtype, liid, cin, operatorid, time, callstate, callorcalledflag, callingnumber, callednumber, reason, naturecall,  dwreportid, neid, idmc FROM iri.dat_callrelatedevent WHERE (delivered = '0') AND (idmc = ") + this->getIdMC() + QString(")");
}

QString Dat_CallRelatedEvent::generateSelectStatementIdMCEventosPendientes()
{
    return QString("SELECT DISTINCT idmc FROM iri.dat_callrelatedevent WHERE (delivered = false)");
}

QQueue<QEvent*> Dat_CallRelatedEvent::getNotDeliveredEvents(QSqlQuery *query)
{
    QQueue<QEvent*> events;
    QString sql = this->generateNotDeliveredStatement();
    query->exec(sql);    
    if( query->isActive() )
    {
       while ( query->next() )
       {            
            CallRelatedEvent *e = new CallRelatedEvent();
            e->setRecordType        ( (quint8)query->value(0).toInt());
            e->setLIID              ( query->value(1).toString() );            
            e->setCallIdentityNumber( Utiles::QStringtoBCD( query->value(2).toString() ) );
            e->setOperatorID        ( Utiles::QStringtoBCD( query->value(3).toString() ) );
            e->setTime              ( query->value(4).toDateTime());
            e->setCallState         ( (quint8)query->value(5).toInt() );
            e->setCallOrCalledFlag  ( (quint8)query->value(6).toInt() );
            e->setCallingNumber     ( query->value(7).toString() );
            e->setCalledNumber      ( query->value(8).toString() );
            e->setReason            ( query->value(9).toByteArray() );
            e->setNatureCall        ( (quint8)query->value(10).toInt() );
            e->setDWReportID        ( query->value(11).toLongLong() );
            e->setNEID              ( query->value(12).toString() );
            e->setLEAID             ( query->value(13).toInt()  );

            e->setNMask             ( QString("") );
            e->setCCLinkID          ( QString("") );
            e->setCapability        ( QString("") );
            e->setOriginalCalledNumber( QString("") );
            e->setRedirectionInfo   ( QString("") );
            e->setConnectedSubAddr  ( QString("") );
            e->setCallingSubAddr    ( QString("") );
            e->setCalledSubAddr     ( QString("") );
            e->setCapability        ( QString("") );
            e->setGenericNumber     ( QString("") );
            e->setDiversionInfo( QString("") );
            e->setPendiente();
            events.append( (QEvent*)e );
       }
    }
    return QQueue<QEvent*>( events );
}

