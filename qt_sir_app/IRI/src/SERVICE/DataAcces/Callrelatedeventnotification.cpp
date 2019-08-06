
#include "Callrelatedeventnotification.h"

#include <qdatetime.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>

 #include <string>
 #include <iostream> 
 
 using namespace std;

Callrelatedeventnotification::Callrelatedeventnotification(QObject *parent,const char *name)
	{
	}

Callrelatedeventnotification::~Callrelatedeventnotification()
	{
	}

Callrelatedeventnotification::Callrelatedeventnotification(CALLRELATEDEVENTNOTIFICATION &old) 
	{
	
	QString nmask;	
	nmask.setNum((int)old.nMask[0], 2);
	this -> m_stNmask.append(nmask);
	nmask.setNum((int)old.nMask[1], 2);
	this -> m_stNmask.append(nmask);
	
    convertToBDTime(old.time,m_stTime);
    
    
    convertToBDNUMBER(old.MSISDN , m_stNumber);
    
	
	//Tratamiento de la location
	//para la primera struct.
	
    //convertToBDLOCATION(old.Location,m_stLocation);
		
	//Flag
	QString flag;
    flag.setNum((int)old.CallOrCalledFlag); 
    this -> m_stCallorcalledflag.append(flag); 
            
    
    QString localflag;
    localflag.setNum((int)old.IsLocalRegisted); 
    this -> m_stIslocalregisted.append(localflag); 
    
    
    //Numeros de Llamada.
    //CallNumber    
    convertToBDNUMBER(old.CallNumber,m_stCallnumber);
	//CalledNumber
	convertToBDNUMBER(old.CalledNumber,m_stCallednumber);
	 
//	convertToBDNUMBER(old.OrgCalledNumber,m_stOrgcallednumber);
	
    QString numTypeServicetype;
    numTypeServicetype.setNum((int)old.ServiceType); 
    this -> m_stServicetype.append(numTypeServicetype);
    
    //Call ID
	
	/*convertToBDCCLiD(old.CallID1 ,m_stCallid1);
	convertToBDCCLiD(old.CallID2 ,m_stCallid2);*/
	
	
	
	
	 convertToBD(old.CombineOrSplitFlag,m_stCombineorsplitflag);
	 convertToBD(old.CombineOrSplitFlag,m_stCombineorsplitflag);
	 
	 convertToBD(old.SuccessFlag,m_stSuccessfag);
	 
	 //convertToBDFAILUREREASON(old.FailureReasson ,m_stFailurereasson);
	 
	 convertToBDLiiD(old.liid,m_stLiid);

	 
	
	     	
		
	 
	}

QString Callrelatedeventnotification::generateDeleteStatement()
	{
	return QString("DELETE FROM lea.callrelatedeventnotification");
	}

QString Callrelatedeventnotification::generateInsertStatement()
	{
	return QString("INSERT INTO lea.callrelatedeventnotification (nMask,numtype,number,time,location,callorcalledflag,islocalregisted,callnumber,callednumber,orgcallednumber,servicetype,sscode,callid1,callid2,eventid,subeventid,combineorsplitflag,successfag,failurereasson,liid,eventtype,id) values (") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'") ) + QString(",") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getLocation().length() == 0 ? QString("null") : QString("'") + escapeString(getLocation(),QChar('\\')) + QString("'") ) + QString(",") + (getCallorcalledflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCallorcalledflag(),QChar('\\')) + QString("'") ) + QString(",") + (getIslocalregisted().length() == 0 ? QString("null") : QString("'") + escapeString(getIslocalregisted(),QChar('\\')) + QString("'") ) + QString(",") + (getCallnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getCallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getOrgcallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getOrgcallednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getServicetype().length() == 0 ? QString("null") : QString("'") + escapeString(getServicetype(),QChar('\\')) + QString("'") ) + QString(",") + (getSscode().length() == 0 ? QString("null") : QString("'") + escapeString(getSscode(),QChar('\\')) + QString("'") ) + QString(",") + (getCallid1().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid1(),QChar('\\')) + QString("'") ) + QString(",") + (getCallid2().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid2(),QChar('\\')) + QString("'") ) + QString(",") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'") ) + QString(",") + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'") ) + QString(",") + (getCombineorsplitflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCombineorsplitflag(),QChar('\\')) + QString("'") ) + QString(",") + (getSuccessfag().length() == 0 ? QString("null") : QString("'") + escapeString(getSuccessfag(),QChar('\\')) + QString("'") ) + QString(",") + (getFailurereasson().length() == 0 ? QString("null") : QString("'") + escapeString(getFailurereasson(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'") ) + QString(",nextval('lea.callrelatedeventnotification_sequence'))");
	}

QString Callrelatedeventnotification::generateInsertStatementNoSequence()
	{
	return QString("INSERT INTO lea.callrelatedeventnotification (nMask,numtype,number,time,location,callorcalledflag,islocalregisted,callnumber,callednumber,orgcallednumber,servicetype,sscode,callid1,callid2,eventid,subeventid,combineorsplitflag,successfag,failurereasson,liid,eventtype) values (") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'") ) + QString(",") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getLocation().length() == 0 ? QString("null") : QString("'") + escapeString(getLocation(),QChar('\\')) + QString("'") ) + QString(",") + (getCallorcalledflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCallorcalledflag(),QChar('\\')) + QString("'") ) + QString(",") + (getIslocalregisted().length() == 0 ? QString("null") : QString("'") + escapeString(getIslocalregisted(),QChar('\\')) + QString("'") ) + QString(",") + (getCallnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getCallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getOrgcallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getOrgcallednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getServicetype().length() == 0 ? QString("null") : QString("'") + escapeString(getServicetype(),QChar('\\')) + QString("'") ) + QString(",") + (getSscode().length() == 0 ? QString("null") : QString("'") + escapeString(getSscode(),QChar('\\')) + QString("'") ) + QString(",") + (getCallid1().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid1(),QChar('\\')) + QString("'") ) + QString(",") + (getCallid2().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid2(),QChar('\\')) + QString("'") ) + QString(",") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'") ) + QString(",") + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'") ) + QString(",") + (getCombineorsplitflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCombineorsplitflag(),QChar('\\')) + QString("'") ) + QString(",") + (getSuccessfag().length() == 0 ? QString("null") : QString("'") + escapeString(getSuccessfag(),QChar('\\')) + QString("'") ) + QString(",") + (getFailurereasson().length() == 0 ? QString("null") : QString("'") + escapeString(getFailurereasson(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'") ) + QString(")");
	}

QString Callrelatedeventnotification::generateUpdateStatement()
	{
	return QString("UPDATE lea.callrelatedeventnotification SET nMask = ") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'")) + 
		QString(", numtype = ") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'")) + 
		QString(", number = ") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'")) + 
		QString(", time = ") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'")) + 
		QString(", location = ") + (getLocation().length() == 0 ? QString("null") : QString("'") + escapeString(getLocation(),QChar('\\')) + QString("'")) + 
		QString(", callorcalledflag = ") + (getCallorcalledflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCallorcalledflag(),QChar('\\')) + QString("'")) + 
		QString(", islocalregisted = ") + (getIslocalregisted().length() == 0 ? QString("null") : QString("'") + escapeString(getIslocalregisted(),QChar('\\')) + QString("'")) + 
		QString(", callnumber = ") + (getCallnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallnumber(),QChar('\\')) + QString("'")) + 
		QString(", callednumber = ") + (getCallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallednumber(),QChar('\\')) + QString("'")) + 
		QString(", orgcallednumber = ") + (getOrgcallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getOrgcallednumber(),QChar('\\')) + QString("'")) + 
		QString(", servicetype = ") + (getServicetype().length() == 0 ? QString("null") : QString("'") + escapeString(getServicetype(),QChar('\\')) + QString("'")) + 
		QString(", sscode = ") + (getSscode().length() == 0 ? QString("null") : QString("'") + escapeString(getSscode(),QChar('\\')) + QString("'")) + 
		QString(", callid1 = ") + (getCallid1().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid1(),QChar('\\')) + QString("'")) + 
		QString(", callid2 = ") + (getCallid2().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid2(),QChar('\\')) + QString("'")) + 
		QString(", eventid = ") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'")) + 
		QString(", subeventid = ") + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'")) + 
		QString(", combineorsplitflag = ") + (getCombineorsplitflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCombineorsplitflag(),QChar('\\')) + QString("'")) + 
		QString(", successfag = ") + (getSuccessfag().length() == 0 ? QString("null") : QString("'") + escapeString(getSuccessfag(),QChar('\\')) + QString("'")) + 
		QString(", failurereasson = ") + (getFailurereasson().length() == 0 ? QString("null") : QString("'") + escapeString(getFailurereasson(),QChar('\\')) + QString("'")) + 
		QString(", liid = ") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'")) + 
		QString(", eventtype = ") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'")) + 
		QString(", id = ") + (getId().length() == 0 ? QString("null") : QString("'") + escapeString(getId(),QChar('\\')) + QString("'"));
	}

QString Callrelatedeventnotification::generateSelectStatement()
	{
	return QString("SELECT nMask,numtype,number,time,location,callorcalledflag,islocalregisted,callnumber,callednumber,orgcallednumber,servicetype,sscode,callid1,callid2,eventid,subeventid,combineorsplitflag,successfag,failurereasson,liid,eventtype,id FROM lea.callrelatedeventnotification");
	}

void Callrelatedeventnotification::readRecord(QSqlQuery query)
	{
	m_stNmask = query.value(0).isNull() ? "" : query.value(0).toString();
	m_stNumtype = query.value(1).isNull() ? "" : query.value(1).toString();
	m_stNumber = query.value(2).isNull() ? "" : query.value(2).toString();
	m_stTime = query.value(3).isNull() ? "" : query.value(3).toString();
	m_stLocation = query.value(4).isNull() ? "" : query.value(4).toString();
	m_stCallorcalledflag = query.value(5).isNull() ? "" : query.value(5).toString();
	m_stIslocalregisted = query.value(6).isNull() ? "" : query.value(6).toString();
	m_stCallnumber = query.value(7).isNull() ? "" : query.value(7).toString();
	m_stCallednumber = query.value(8).isNull() ? "" : query.value(8).toString();
	m_stOrgcallednumber = query.value(9).isNull() ? "" : query.value(9).toString();
	m_stServicetype = query.value(10).isNull() ? "" : query.value(10).toString();
	m_stSscode = query.value(11).isNull() ? "" : query.value(11).toString();
	m_stCallid1 = query.value(12).isNull() ? "" : query.value(12).toString();
	m_stCallid2 = query.value(13).isNull() ? "" : query.value(13).toString();
	m_stEventid = query.value(14).isNull() ? "" : query.value(14).toString();
	m_stSubeventid = query.value(15).isNull() ? "" : query.value(15).toString();
	m_stCombineorsplitflag = query.value(16).isNull() ? "" : query.value(16).toString();
	m_stSuccessfag = query.value(17).isNull() ? "" : query.value(17).toString();
	m_stFailurereasson = query.value(18).isNull() ? "" : query.value(18).toString();
	m_stLiid = query.value(19).isNull() ? "" : query.value(19).toString();
	m_stEventtype = query.value(20).isNull() ? "" : query.value(20).toString();
	m_stId = query.value(21).isNull() ? "" : query.value(21).toString();
	}

QStringList Callrelatedeventnotification::generateFieldList()
	{
	QStringList	sl;

	sl += "nMask";
	sl += "numtype";
	sl += "number";
	sl += "time";
	sl += "location";
	sl += "callorcalledflag";
	sl += "islocalregisted";
	sl += "callnumber";
	sl += "callednumber";
	sl += "orgcallednumber";
	sl += "servicetype";
	sl += "sscode";
	sl += "callid1";
	sl += "callid2";
	sl += "eventid";
	sl += "subeventid";
	sl += "combineorsplitflag";
	sl += "successfag";
	sl += "failurereasson";
	sl += "liid";
	sl += "eventtype";
	sl += "id";
	return sl;
	}

QString Callrelatedeventnotification::escapeString(QString stData,QChar cEscapeCharacter)
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

/*QString Callrelatedeventnotification::getTableName()
	{
	return "callrelatedeventnotification";
	}*/

void Callrelatedeventnotification::setNmask(QString s)
	{
	m_stNmask = s;
	}

QString Callrelatedeventnotification::getNmask()
	{
	return m_stNmask;
	}

void Callrelatedeventnotification::setNumtype(QString s)
	{
	m_stNumtype = s;
	}

QString Callrelatedeventnotification::getNumtype()
	{
	return m_stNumtype;
	}

void Callrelatedeventnotification::setNumber(QString s)
	{
	m_stNumber = s;
	}

QString Callrelatedeventnotification::getNumber()
	{
	return m_stNumber;
	}

void Callrelatedeventnotification::setTime(QString s)
	{
	m_stTime = s;
	}

QString Callrelatedeventnotification::getTime()
	{
	return m_stTime;
	}

void Callrelatedeventnotification::setLocation(QString s)
	{
	m_stLocation = s;
	}

QString Callrelatedeventnotification::getLocation()
	{
	return m_stLocation;
	}

void Callrelatedeventnotification::setCallorcalledflag(QString s)
	{
	m_stCallorcalledflag = s;
	}

QString Callrelatedeventnotification::getCallorcalledflag()
	{
	return m_stCallorcalledflag;
	}

void Callrelatedeventnotification::setIslocalregisted(QString s)
	{
	m_stIslocalregisted = s;
	}

QString Callrelatedeventnotification::getIslocalregisted()
	{
	return m_stIslocalregisted;
	}

void Callrelatedeventnotification::setCallnumber(QString s)
	{
	m_stCallnumber = s;
	}

QString Callrelatedeventnotification::getCallnumber()
	{
	return m_stCallnumber;
	}

void Callrelatedeventnotification::setCallednumber(QString s)
	{
	m_stCallednumber = s;
	}

QString Callrelatedeventnotification::getCallednumber()
	{
	return m_stCallednumber;
	}

void Callrelatedeventnotification::setOrgcallednumber(QString s)
	{
	m_stOrgcallednumber = s;
	}

QString Callrelatedeventnotification::getOrgcallednumber()
	{
	return m_stOrgcallednumber;
	}

void Callrelatedeventnotification::setServicetype(QString s)
	{
	m_stServicetype = s;
	}

QString Callrelatedeventnotification::getServicetype()
	{
	return m_stServicetype;
	}

void Callrelatedeventnotification::setSscode(QString s)
	{
	m_stSscode = s;
	}

QString Callrelatedeventnotification::getSscode()
	{
	return m_stSscode;
	}

void Callrelatedeventnotification::setCallid1(QString s)
	{
	m_stCallid1 = s;
	}

QString Callrelatedeventnotification::getCallid1()
	{
	return m_stCallid1;
	}

void Callrelatedeventnotification::setCallid2(QString s)
	{
	m_stCallid2 = s;
	}

QString Callrelatedeventnotification::getCallid2()
	{
	return m_stCallid2;
	}

void Callrelatedeventnotification::setEventid(QString s)
	{
	m_stEventid = s;
	}

QString Callrelatedeventnotification::getEventid()
	{
	return m_stEventid;
	}

void Callrelatedeventnotification::setSubeventid(QString s)
	{
	m_stSubeventid = s;
	}

QString Callrelatedeventnotification::getSubeventid()
	{
	return m_stSubeventid;
	}

void Callrelatedeventnotification::setCombineorsplitflag(QString s)
	{
	m_stCombineorsplitflag = s;
	}

QString Callrelatedeventnotification::getCombineorsplitflag()
	{
	return m_stCombineorsplitflag;
	}

void Callrelatedeventnotification::setSuccessfag(QString s)
	{
	m_stSuccessfag = s;
	}

QString Callrelatedeventnotification::getSuccessfag()
	{
	return m_stSuccessfag;
	}

void Callrelatedeventnotification::setFailurereasson(QString s)
	{
	m_stFailurereasson = s;
	}

QString Callrelatedeventnotification::getFailurereasson()
	{
	return m_stFailurereasson;
	}

void Callrelatedeventnotification::setLiid(QString s)
	{
	m_stLiid = s;
	}

QString Callrelatedeventnotification::getLiid()
	{
	return m_stLiid;
	}

void Callrelatedeventnotification::setEventtype(QString s)
	{
	m_stEventtype = s;
	}

QString Callrelatedeventnotification::getEventtype()
	{
	return m_stEventtype;
	}

void Callrelatedeventnotification::setId(QString s)
	{
	m_stId = s;
	}

QString Callrelatedeventnotification::getId()
	{
	return m_stId;
	}

void Callrelatedeventnotification::operator=(const Callrelatedeventnotification &old)
	{
	this -> m_stNmask = old.m_stNmask;
	this -> m_stNumtype = old.m_stNumtype;
	this -> m_stNumber = old.m_stNumber;
	this -> m_stTime = old.m_stTime;
	this -> m_stLocation = old.m_stLocation;
	this -> m_stCallorcalledflag = old.m_stCallorcalledflag;
	this -> m_stIslocalregisted = old.m_stIslocalregisted;
	this -> m_stCallnumber = old.m_stCallnumber;
	this -> m_stCallednumber = old.m_stCallednumber;
	this -> m_stOrgcallednumber = old.m_stOrgcallednumber;
	this -> m_stServicetype = old.m_stServicetype;
	this -> m_stSscode = old.m_stSscode;
	this -> m_stCallid1 = old.m_stCallid1;
	this -> m_stCallid2 = old.m_stCallid2;
	this -> m_stEventid = old.m_stEventid;
	this -> m_stSubeventid = old.m_stSubeventid;
	this -> m_stCombineorsplitflag = old.m_stCombineorsplitflag;
	this -> m_stSuccessfag = old.m_stSuccessfag;
	this -> m_stFailurereasson = old.m_stFailurereasson;
	this -> m_stLiid = old.m_stLiid;
	this -> m_stEventtype = old.m_stEventtype;
	this -> m_stId = old.m_stId;
	}


