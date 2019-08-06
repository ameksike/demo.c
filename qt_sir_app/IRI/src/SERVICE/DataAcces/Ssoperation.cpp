#include "Ssoperation.h"

#include "Ssoperation.h"

#include <qdatetime.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>

 #include <string>
 #include <iostream> 
 
 using namespace std;

Ssoperation::Ssoperation(QObject *parent,const char *name) 
	{
	}

Ssoperation::~Ssoperation()
	{
	}

Ssoperation::Ssoperation(SSOPERATION &old)
	{
		
	this -> m_stNmask.append("1f");
	QString numType;
	
	numType.setNum((int)old.NumType); 
	this -> m_stNumyype.append(numType);
	
	//Permite tratar una estructa correctamente
	/*aqui falta lo de cual viene.*/	
	convertToBDNUMBER(old.MSISDN,m_stNumber);
	
	convertToBDTime(old.time,m_stTime);
    
    convertToBDLOCATION(old.Location,m_stLocation);
     
	convertToBD(old.OperateType,m_stOperatetype);
	
	convertToBD(old.ServiceType,m_stServicetype);
	
	convertToBDNUMBER(old.ForwardNumber,m_stForwardnumber);
	
	convertToBD(old.SuccessFlag , m_stSuccessflag);
	
	convertToBDLiiD(old.liid,m_stLiid);
	
	}

QString Ssoperation::generateDeleteStatement()
	{
	return QString("DELETE FROM lea.ssoperation");
	}

QString Ssoperation::generateInsertStatement()
	{
	return QString("INSERT INTO lea.ssoperation (nMask,numyype,number,time,location,operatetype,servicetype,forwardnumber,successflag,liid,eventtype,id) values (") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumyype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumyype(),QChar('\\')) + QString("'") ) + QString(",") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getLocation().length() == 0 ? QString("null") : QString("'") + escapeString(getLocation(),QChar('\\')) + QString("'") ) + QString(",") + (getOperatetype().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatetype(),QChar('\\')) + QString("'") ) + QString(",") + (getServicetype().length() == 0 ? QString("null") : QString("'") + escapeString(getServicetype(),QChar('\\')) + QString("'") ) + QString(",") + (getForwardnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getForwardnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getSuccessflag().length() == 0 ? QString("null") : QString("'") + escapeString(getSuccessflag(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'") ) + QString(",nextval('lea.ssoperation_sequence'))");
	}

QString Ssoperation::generateInsertStatementNoSequence()
	{
	return QString("INSERT INTO lea.ssoperation (nMask,numyype,number,time,location,operatetype,servicetype,forwardnumber,successflag,liid,eventtype,id) values (") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumyype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumyype(),QChar('\\')) + QString("'") ) + QString(",") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getLocation().length() == 0 ? QString("null") : QString("'") + escapeString(getLocation(),QChar('\\')) + QString("'") ) + QString(",") + (getOperatetype().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatetype(),QChar('\\')) + QString("'") ) + QString(",") + (getServicetype().length() == 0 ? QString("null") : QString("'") + escapeString(getServicetype(),QChar('\\')) + QString("'") ) + QString(",") + (getForwardnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getForwardnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getSuccessflag().length() == 0 ? QString("null") : QString("'") + escapeString(getSuccessflag(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'") ) + QString(",") + (getId().length() == 0 ? QString("null") : QString("'") + escapeString(getId(),QChar('\\')) + QString("'") ) + QString(")");
	}

QString Ssoperation::generateUpdateStatement()
	{
	return QString("UPDATE lea.ssoperation SET nMask = ") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'")) + 
		QString(", numyype = ") + (getNumyype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumyype(),QChar('\\')) + QString("'")) + 
		QString(", number = ") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'")) + 
		QString(", time = ") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'")) + 
		QString(", location = ") + (getLocation().length() == 0 ? QString("null") : QString("'") + escapeString(getLocation(),QChar('\\')) + QString("'")) + 
		QString(", operatetype = ") + (getOperatetype().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatetype(),QChar('\\')) + QString("'")) + 
		QString(", servicetype = ") + (getServicetype().length() == 0 ? QString("null") : QString("'") + escapeString(getServicetype(),QChar('\\')) + QString("'")) + 
		QString(", forwardnumber = ") + (getForwardnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getForwardnumber(),QChar('\\')) + QString("'")) + 
		QString(", successflag = ") + (getSuccessflag().length() == 0 ? QString("null") : QString("'") + escapeString(getSuccessflag(),QChar('\\')) + QString("'")) + 
		QString(", liid = ") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'")) + 
		QString(", eventtype = ") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'")) + 
		QString(", id = ") + (getId().length() == 0 ? QString("null") : QString("'") + escapeString(getId(),QChar('\\')) + QString("'"));
	}

QString Ssoperation::generateSelectStatement()
	{
	return QString("SELECT nMask,numyype,number,time,location,operatetype,servicetype,forwardnumber,successflag,liid,eventtype,id FROM lea.ssoperation");
	}

void Ssoperation::readRecord(QSqlQuery query)
	{
	m_stNmask = query.value(0).isNull() ? "" : query.value(0).toString();
	m_stNumyype = query.value(1).isNull() ? "" : query.value(1).toString();
	m_stNumber = query.value(2).isNull() ? "" : query.value(2).toString();
	m_stTime = query.value(3).isNull() ? "" : query.value(3).toString();
	m_stLocation = query.value(4).isNull() ? "" : query.value(4).toString();
	m_stOperatetype = query.value(5).isNull() ? "" : query.value(5).toString();
	m_stServicetype = query.value(6).isNull() ? "" : query.value(6).toString();
	m_stForwardnumber = query.value(7).isNull() ? "" : query.value(7).toString();
	m_stSuccessflag = query.value(8).isNull() ? "" : query.value(8).toString();
	m_stLiid = query.value(9).isNull() ? "" : query.value(9).toString();
	m_stEventtype = query.value(10).isNull() ? "" : query.value(10).toString();
	m_stId = query.value(11).isNull() ? "" : query.value(11).toString();
	}

QStringList Ssoperation::generateFieldList()
	{
	QStringList	sl;

	sl += "nMask";
	sl += "numyype";
	sl += "number";
	sl += "time";
	sl += "location";
	sl += "operatetype";
	sl += "servicetype";
	sl += "forwardnumber";
	sl += "successflag";
	sl += "liid";
	sl += "eventtype";
	sl += "id";
	return sl;

	}

QString Ssoperation::escapeString(QString stData,QChar cEscapeCharacter)
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

/*QString Ssoperation::getTableName()
	{
	return "ssoperation";
	}*/

void Ssoperation::setNmask(QString s)
	{
	m_stNmask = s;
	}

QString Ssoperation::getNmask()
	{
	return m_stNmask;
	}

void Ssoperation::setNumyype(QString s)
	{
	m_stNumyype = s;
	}

QString Ssoperation::getNumyype()
	{
	return m_stNumyype;
	}

void Ssoperation::setNumber(QString s)
	{
	m_stNumber = s;
	}

QString Ssoperation::getNumber()
	{
	return m_stNumber;
	}

void Ssoperation::setTime(QString s)
	{
	m_stTime = s;
	}

QString Ssoperation::getTime()
	{
	return m_stTime;
	}

void Ssoperation::setLocation(QString s)
	{
	m_stLocation = s;
	}

QString Ssoperation::getLocation()
	{
	return m_stLocation;
	}

void Ssoperation::setOperatetype(QString s)
	{
	m_stOperatetype = s;
	}

QString Ssoperation::getOperatetype()
	{
	return m_stOperatetype;
	}

void Ssoperation::setServicetype(QString s)
	{
	m_stServicetype = s;
	}

QString Ssoperation::getServicetype()
	{
	return m_stServicetype;
	}

void Ssoperation::setForwardnumber(QString s)
	{
	m_stForwardnumber = s;
	}

QString Ssoperation::getForwardnumber()
	{
	return m_stForwardnumber;
	}

void Ssoperation::setSuccessflag(QString s)
	{
	m_stSuccessflag = s;
	}

QString Ssoperation::getSuccessflag()
	{
	return m_stSuccessflag;
	}

void Ssoperation::setLiid(QString s)
	{
	m_stLiid = s;
	}

QString Ssoperation::getLiid()
	{
	return m_stLiid;
	}

void Ssoperation::setEventtype(QString s)
	{
	m_stEventtype = s;
	}

QString Ssoperation::getEventtype()
	{
	return m_stEventtype;
	}

void Ssoperation::setId(QString s)
	{
	m_stId = s;
	}

QString Ssoperation::getId()
	{
	return m_stId;
	}

void Ssoperation::operator=(const Ssoperation &old)
	{
	this -> m_stNmask = old.m_stNmask;
	this -> m_stNumyype = old.m_stNumyype;
	this -> m_stNumber = old.m_stNumber;
	this -> m_stTime = old.m_stTime;
	this -> m_stLocation = old.m_stLocation;
	this -> m_stOperatetype = old.m_stOperatetype;
	this -> m_stServicetype = old.m_stServicetype;
	this -> m_stForwardnumber = old.m_stForwardnumber;
	this -> m_stSuccessflag = old.m_stSuccessflag;
	this -> m_stLiid = old.m_stLiid;
	this -> m_stEventtype = old.m_stEventtype;
	this -> m_stId = old.m_stId;
	}


