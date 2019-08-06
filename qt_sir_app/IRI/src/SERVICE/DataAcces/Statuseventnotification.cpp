#include "Statuseventnotification.h"

#include <qdatetime.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>

 #include <string.h>
 #include <iostream> 
 
 using namespace std;

Statuseventnotification::Statuseventnotification(QObject *parent,const char *name) 
	{
	}

Statuseventnotification::~Statuseventnotification()
	{
	}

Statuseventnotification::Statuseventnotification(STATUSEVENTNOTIFICATION &old)
	{
    
    this -> m_stNmask.append("1f");
	QString numType;
	
	numType.setNum((int)old.NumType); 
	this -> m_stNumtype.append(numType);
	
	//Permite tratar una estructa correctamente
	/*aqui falta lo de cual viene.*/
	
	convertToBDNUMBER(old.MSISDN,m_stNumber);
    
    convertToBDTime(old.time,m_stTime);
	
	//Tratamiento de la location
	///para la primera struct.
	
	convertToBDLOCATION(old.OrgLocation,m_stOrglocation);
	
	convertToBDLOCATION(old.CurLocation,m_stCurlocation);
	
	convertToBDLiiD(old.liid,m_stLiid);
	


	}

QString Statuseventnotification::generateDeleteStatement()
	{
	return QString("DELETE FROM statuseventnotification");
	}

QString Statuseventnotification::generateInsertStatement()
	{
	return QString("INSERT INTO statuseventnotification (nMask,numtype,number,time,orglocation,curlocation,liid,eventtype,id) values (") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'") ) + QString(",") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getOrglocation().length() == 0 ? QString("null") : QString("'") + escapeString(getOrglocation(),QChar('\\')) + QString("'") ) + QString(",") + (getCurlocation().length() == 0 ? QString("null") : QString("'") + escapeString(getCurlocation(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'") ) + QString(",nextval('statuseventnotification_sequence'))");
	}

QString Statuseventnotification::generateInsertStatementNoSequence()
	{
	return QString("INSERT INTO statuseventnotification (nMask,numtype,number,time,orglocation,curlocation,liid,eventtype,id) values (") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'") ) + QString(",") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getOrglocation().length() == 0 ? QString("null") : QString("'") + escapeString(getOrglocation(),QChar('\\')) + QString("'") ) + QString(",") + (getCurlocation().length() == 0 ? QString("null") : QString("'") + escapeString(getCurlocation(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'") ) + QString(",") + (getId().length() == 0 ? QString("null") : QString("'") + escapeString(getId(),QChar('\\')) + QString("'") ) + QString(")");
	}

QString Statuseventnotification::generateUpdateStatement()
	{
	return QString("UPDATE statuseventnotification SET nMask = ") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'")) + 
		QString(", numtype = ") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'")) + 
		QString(", number = ") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'")) + 
		QString(", time = ") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'")) + 
		QString(", orglocation = ") + (getOrglocation().length() == 0 ? QString("null") : QString("'") + escapeString(getOrglocation(),QChar('\\')) + QString("'")) + 
		QString(", curlocation = ") + (getCurlocation().length() == 0 ? QString("null") : QString("'") + escapeString(getCurlocation(),QChar('\\')) + QString("'")) + 
		QString(", liid = ") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'")) + 
		QString(", eventtype = ") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'")) + 
		QString(", id = ") + (getId().length() == 0 ? QString("null") : QString("'") + escapeString(getId(),QChar('\\')) + QString("'"));
	}

QString Statuseventnotification::generateSelectStatement()
	{
	return QString("SELECT nMask,numtype,number,time,orglocation,curlocation,liid,eventtype,id FROM statuseventnotification");
	}

void Statuseventnotification::readRecord(QSqlQuery query)
	{
	m_stNmask = query.value(0).isNull() ? "" : query.value(0).toString();
	m_stNumtype = query.value(1).isNull() ? "" : query.value(1).toString();
	m_stNumber = query.value(2).isNull() ? "" : query.value(2).toString();
	m_stTime = query.value(3).isNull() ? "" : query.value(3).toString();
	m_stOrglocation = query.value(4).isNull() ? "" : query.value(4).toString();
	m_stCurlocation = query.value(5).isNull() ? "" : query.value(5).toString();
	m_stLiid = query.value(6).isNull() ? "" : query.value(6).toString();
	m_stEventtype = query.value(7).isNull() ? "" : query.value(7).toString();
	m_stId = query.value(8).isNull() ? "" : query.value(8).toString();
	}

QStringList Statuseventnotification::generateFieldList()
	{
	QStringList	sl;

	sl += "nMask";
	sl += "numtype";
	sl += "number";
	sl += "time";
	sl += "orglocation";
	sl += "curlocation";
	sl += "liid";
	sl += "eventtype";
	sl += "id";
	return sl;
	}

QString Statuseventnotification::escapeString(QString stData,QChar cEscapeCharacter)
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

  /*QString Statuseventnotification::getTableName()
	{
	return "statuseventnotification";
	}*/

void Statuseventnotification::setNmask(QString s)
	{
	m_stNmask = s;
	}

QString Statuseventnotification::getNmask()
	{
	return m_stNmask;
	}

void Statuseventnotification::setNumtype(QString s)
	{
	m_stNumtype = s;
	}

QString Statuseventnotification::getNumtype()
	{
	return m_stNumtype;
	}

void Statuseventnotification::setNumber(QString s)
	{
	m_stNumber = s;
	}

QString Statuseventnotification::getNumber()
	{
	return m_stNumber;
	}

void Statuseventnotification::setTime(QString s)
	{
	m_stTime = s;
	}

QString Statuseventnotification::getTime()
	{
	return m_stTime;
	}

void Statuseventnotification::setOrglocation(QString s)
	{
	m_stOrglocation = s;
	}

QString Statuseventnotification::getOrglocation()
	{
	return m_stOrglocation;
	}

void Statuseventnotification::setCurlocation(QString s)
	{
	m_stCurlocation = s;
	}

QString Statuseventnotification::getCurlocation()
	{
	return m_stCurlocation;
	}

void Statuseventnotification::setLiid(QString s)
	{
	m_stLiid = s;
	}

QString Statuseventnotification::getLiid()
	{
	return m_stLiid;
	}

void Statuseventnotification::setEventtype(QString s)
	{
	m_stEventtype = s;
	}

QString Statuseventnotification::getEventtype()
	{
	return m_stEventtype;
	}

void Statuseventnotification::setId(QString s)
	{
	m_stId = s;
	}

QString Statuseventnotification::getId()
	{
	return m_stId;
	}

void Statuseventnotification::operator=(const Statuseventnotification &old)
	{
	this -> m_stNmask = old.m_stNmask;
	this -> m_stNumtype = old.m_stNumtype;
	this -> m_stNumber = old.m_stNumber;
	this -> m_stTime = old.m_stTime;
	this -> m_stOrglocation = old.m_stOrglocation;
	this -> m_stCurlocation = old.m_stCurlocation;
	this -> m_stLiid = old.m_stLiid;
	this -> m_stEventtype = old.m_stEventtype;
	this -> m_stId = old.m_stId;
	}


