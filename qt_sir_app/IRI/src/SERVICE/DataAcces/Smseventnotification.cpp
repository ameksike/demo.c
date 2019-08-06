#include "Smseventnotification.h"

#include <qdatetime.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>

#include <string.h>
#include <iostream>

using namespace std; 

Smseventnotification::Smseventnotification(QObject *parent,const char *name) 
	{
	}

Smseventnotification::~Smseventnotification()
	{
	}

Smseventnotification::Smseventnotification(SMSEVENTNOTIFICATION &old) 
	{
	
	this -> m_stNmask.append("1f");
	QString numType;
	
	numType.setNum((int)old.NumType); 
	this -> m_stNumtype.append(numType);
	
	//Permite tratar una estructa correctamente
	/*aqui falta lo de cual viene.*/
	
	convertToBDNUMBER(old.MSISDN,m_stNumber);
	
	convertToBDTime(old.time,m_stTime);
	 
	
	 
	convertToBDNUMBER(old.MSISDN,m_stSmcnumber);
	 
	//convertToBDLOCATION(old.Location,m_stLocation); agregarlo en la BD.
		 
	convertToBDNUMBER(old.PeerPartyNum,m_stPeerpartynum);	
	
	convertToBDSMSSMSMESSAGE(old.SMSMessage,m_stSmsmessage);
	
	convertToBDLiiD(old.liid,m_stLiid);


	}

QString Smseventnotification::generateDeleteStatement()
	{
	return QString("DELETE FROM lea.smseventnotification");
	}

QString Smseventnotification::generateInsertStatement()
	{
	return QString("INSERT INTO lea.smseventnotification (nMask,numtype,number,time,smcnumber,peerpartynum,smsmessage,eventid,liid,eventtype,id) values (") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'") ) + QString(",") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getSmcnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getSmcnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getPeerpartynum().length() == 0 ? QString("null") : QString("'") + escapeString(getPeerpartynum(),QChar('\\')) + QString("'") ) + QString(",") + (getSmsmessage().length() == 0 ? QString("null") : QString("'") + escapeString(getSmsmessage(),QChar('\\')) + QString("'") ) + QString(",") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'") ) + QString(",nextval('lea.smseventnotification_sequence'))");
	}

QString Smseventnotification::generateInsertStatementNoSequence()
	{
	return QString("INSERT INTO lea.smseventnotification (nMask,numtype,number,time,smcnumber,peerpartynum,smsmessage,eventid,liid,eventtype,id) values (") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'") ) + QString(",") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getSmcnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getSmcnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getPeerpartynum().length() == 0 ? QString("null") : QString("'") + escapeString(getPeerpartynum(),QChar('\\')) + QString("'") ) + QString(",") + (getSmsmessage().length() == 0 ? QString("null") : QString("'") + escapeString(getSmsmessage(),QChar('\\')) + QString("'") ) + QString(",") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'") ) + QString(",") + (getId().length() == 0 ? QString("null") : QString("'") + escapeString(getId(),QChar('\\')) + QString("'") ) + QString(")");
	}

QString Smseventnotification::generateUpdateStatement()
	{
		
	return QString("UPDATE lea.smseventnotification SET nMask = ") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'")) + 
		QString(", numtype = ") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'")) + 
		QString(", number = ") + (getNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getNumber(),QChar('\\')) + QString("'")) + 
		QString(", time = ") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'")) + 
		QString(", smcnumber = ") + (getSmcnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getSmcnumber(),QChar('\\')) + QString("'")) + 
		QString(", peerpartynum = ") + (getPeerpartynum().length() == 0 ? QString("null") : QString("'") + escapeString(getPeerpartynum(),QChar('\\')) + QString("'")) + 
		QString(", smsmessage = ") + (getSmsmessage().length() == 0 ? QString("null") : QString("'") + escapeString(getSmsmessage(),QChar('\\')) + QString("'")) + 
		QString(", eventid = ") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'")) + 
		QString(", liid = ") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'")) + 
		QString(", eventtype = ") + (getEventtype().length() == 0 ? QString("null") : QString("'") + escapeString(getEventtype(),QChar('\\')) + QString("'")) + 
		QString(", id = ") + (getId().length() == 0 ? QString("null") : QString("'") + escapeString(getId(),QChar('\\')) + QString("'"));
		
	}

QString Smseventnotification::generateSelectStatement()
	{
	return QString("SELECT nMask,numtype,number,time,smcnumber,peerpartynum,smsmessage,eventid,liid,eventtype,id FROM lea.smseventnotification");
	}

void Smseventnotification::readRecord(QSqlQuery query)
	{
	m_stNmask = query.value(0).isNull() ? "" : query.value(0).toString();
	m_stNumtype = query.value(1).isNull() ? "" : query.value(1).toString();
	m_stNumber = query.value(2).isNull() ? "" : query.value(2).toString();
	m_stTime = query.value(3).isNull() ? "" : query.value(3).toString();
	m_stSmcnumber = query.value(4).isNull() ? "" : query.value(4).toString();
	m_stPeerpartynum = query.value(5).isNull() ? "" : query.value(5).toString();
	m_stSmsmessage = query.value(6).isNull() ? "" : query.value(6).toString();
	m_stEventid = query.value(7).isNull() ? "" : query.value(7).toString();
	m_stLiid = query.value(8).isNull() ? "" : query.value(8).toString();
	m_stEventtype = query.value(9).isNull() ? "" : query.value(9).toString();
	m_stId = query.value(10).isNull() ? "" : query.value(10).toString();
	}

QStringList Smseventnotification::generateFieldList()
	{
	QStringList	sl;

	sl += "nMask";
	sl += "numtype";
	sl += "number";
	sl += "time";
	sl += "smcnumber";
	sl += "peerpartynum";
	sl += "smsmessage";
	sl += "eventid";
	sl += "liid";
	sl += "eventtype";
	sl += "id";
	return sl;
	}

QString Smseventnotification::escapeString(QString stData,QChar cEscapeCharacter)
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

/*QString Smseventnotification::getTableName()
	{
	return "smseventnotification";
	}*/

void Smseventnotification::setNmask(QString s)
	{
	m_stNmask = s;
	}

QString Smseventnotification::getNmask()
	{
	return m_stNmask;
	}

void Smseventnotification::setNumtype(QString s)
	{
	m_stNumtype = s;
	}

QString Smseventnotification::getNumtype()
	{
	return m_stNumtype;
	}

void Smseventnotification::setNumber(QString s)
	{
	m_stNumber = s;
	}

QString Smseventnotification::getNumber()
	{
	return m_stNumber;
	}

void Smseventnotification::setTime(QString s)
	{
	m_stTime = s;
	}

QString Smseventnotification::getTime()
	{
	return m_stTime;
	}

void Smseventnotification::setSmcnumber(QString s)
	{
	m_stSmcnumber = s;
	}

QString Smseventnotification::getSmcnumber()
	{
	return m_stSmcnumber;
	}

void Smseventnotification::setPeerpartynum(QString s)
	{
	m_stPeerpartynum = s;
	}

QString Smseventnotification::getPeerpartynum()
	{
	return m_stPeerpartynum;
	}

void Smseventnotification::setSmsmessage(QString s)
	{
	m_stSmsmessage = s;
	}

QString Smseventnotification::getSmsmessage()
	{
	return m_stSmsmessage;
	}

void Smseventnotification::setEventid(QString s)
	{
	m_stEventid = s;
	}

QString Smseventnotification::getEventid()
	{
	return m_stEventid;
	}

void Smseventnotification::setLiid(QString s)
	{
	m_stLiid = s;
	}

QString Smseventnotification::getLiid()
	{
	return m_stLiid;
	}

void Smseventnotification::setEventtype(QString s)
	{
	m_stEventtype = s;
	}

QString Smseventnotification::getEventtype()
	{
	return m_stEventtype;
	}

void Smseventnotification::setId(QString s)
	{
	m_stId = s;
	}

QString Smseventnotification::getId()
	{
	return m_stId;
	}

void Smseventnotification::operator=(const Smseventnotification &old)
	{
	this -> m_stNmask = old.m_stNmask;
	this -> m_stNumtype = old.m_stNumtype;
	this -> m_stNumber = old.m_stNumber;
	this -> m_stTime = old.m_stTime;
	this -> m_stSmcnumber = old.m_stSmcnumber;
	this -> m_stPeerpartynum = old.m_stPeerpartynum;
	this -> m_stSmsmessage = old.m_stSmsmessage;
	this -> m_stEventid = old.m_stEventid;
	this -> m_stLiid = old.m_stLiid;
	this -> m_stEventtype = old.m_stEventtype;
	this -> m_stId = old.m_stId;
	}


