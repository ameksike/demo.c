#include "DatSsnotification.h"

 //#include <QDateTime>
#include <qsqldatabase.h>
#include <qsqlquery.h>

#include <stdio.h>
#include <stdlib.h>

DatSSNotification::DatSSNotification(QObject *parent,const char *name)
	{
	}

DatSSNotification::~DatSSNotification()
	{
	}


// para salvar la estructura ..solo se salva hasta lenght
DatSSNotification::DatSSNotification(const SSNotification &old)
	{
		
	this -> m_stNmask = "0";
	this -> m_stNumtype.append("0");
	
	//Permite tratar una estructa correctamente	
	//*char * ptrObjectnumber = new char(atoi(old.objectNumber.Length));
	//memcpy( ptrObjectnumber, old.objectNumber.Dato, atoi(old.objectNumber.Length));
	
	this -> m_stObjectnumber = "86106789003";
	
	this -> m_stTime = "2007811" ; // procesar esto ..solucion poner Time como varchar
	
	this -> m_stEventid = "0";
	this -> m_stSubeventid = "1";
	this -> m_stCallnumber = "86106789004";
	this -> m_stCallednumber = "86106789003";
	this -> m_stRecordtype.append( "3");
	
    //Permite tratar una estructa correctamente
//    char * ptrcin = new char( atoi(old.cin.Length) );
//	memcpy( ptrcin, old.cin.Dato, atoi(old.cin.Length));
	this -> m_stCin = "0";
		
	this -> m_stOperatorid = "654";
	
	//Permite tratar una estructa correctamente
//    char * ptrliid = new char(  atoi(old.liid.Length) );
//	memcpy( ptrliid, old.liid.Dato, atoi(old.liid.Length));
	this -> m_stLiid = "600000";
	
	
//	char * ptrcclid = new char(  atoi(old.cclid.Length) );
//	memcpy( ptrcclid, old.cclid.Dato, atoi(old.cclid.Length) );
	this -> m_stCclid = "0";
	
	
	this -> m_stUsetype = "4";
	this -> m_stUseresult = "0";
	this -> m_stSername = "16";
	this -> m_stNotification = "0";
	this -> m_stCalllndcation = "0";
	this -> m_stCapability = "0";
	this -> m_stFacilityop = "0";
	this -> m_stGenericnumber = "0";
	
//	char * ptrobjectNumber1 = new char(  atoi(old.objectNumber1.Length) );
//	memcpy( ptrobjectNumber1, old.objectNumber1.Dato, atoi(old.objectNumber1.Length) );
	this -> m_stObjectnumber1 = "86106789003";
	
	
//	char * ptrgatewayId = new char(  atoi(old.gatewayId.Length) );
//	memcpy( ptrgatewayId, old.gatewayId.Dato, atoi(old.gatewayId.Length) );
	this -> m_stGatewayid = "iad102hh.com";
	
	//falta FirstCalling	
	this -> m_stSecondcalling = "0";
	
	
	}

QString DatSSNotification::generateDeleteStatement()
	{
	return QString("DELETE FROM lea.dat_ssnotification");
	}

QString DatSSNotification::generateInsertStatement()
	{
	return QString("INSERT INTO lea.dat_ssnotification (nmask,numtype,objectnumber,time,eventid,subeventid,callnumber,callednumber,recordtype,cin,operatorid,liid,cclid,usetype,useresult,sername,notification,calllndcation,capability,facilityop,genericnumber,objectnumber1,gatewayid,secondcalling,id) values (") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'") ) + QString(",") + (getObjectnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'") ) + QString(",") + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'") ) + QString(",") + (getCallnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getCallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getRecordtype().length() == 0 ? QString("null") : QString("'") + escapeString(getRecordtype(),QChar('\\')) + QString("'") ) + QString(",") + (getCin().length() == 0 ? QString("null") : QString("'") + escapeString(getCin(),QChar('\\')) + QString("'") ) + QString(",") + (getOperatorid().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatorid(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getCclid().length() == 0 ? QString("null") : QString("'") + escapeString(getCclid(),QChar('\\')) + QString("'") ) + QString(",") + (getUsetype().length() == 0 ? QString("null") : QString("'") + escapeString(getUsetype(),QChar('\\')) + QString("'") ) + QString(",") + (getUseresult().length() == 0 ? QString("null") : QString("'") + escapeString(getUseresult(),QChar('\\')) + QString("'") ) + QString(",") + (getSername().length() == 0 ? QString("null") : QString("'") + escapeString(getSername(),QChar('\\')) + QString("'") ) + QString(",") + (getNotification().length() == 0 ? QString("null") : QString("'") + escapeString(getNotification(),QChar('\\')) + QString("'") ) + QString(",") + (getCalllndcation().length() == 0 ? QString("null") : QString("'") + escapeString(getCalllndcation(),QChar('\\')) + QString("'") ) + QString(",") + (getCapability().length() == 0 ? QString("null") : QString("'") + escapeString(getCapability(),QChar('\\')) + QString("'") ) + QString(",") + (getFacilityop().length() == 0 ? QString("null") : QString("'") + escapeString(getFacilityop(),QChar('\\')) + QString("'") ) + QString(",") + (getGenericnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getGenericnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getObjectnumber1().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectnumber1(),QChar('\\')) + QString("'") ) + QString(",") + (getGatewayid().length() == 0 ? QString("null") : QString("'") + escapeString(getGatewayid(),QChar('\\')) + QString("'") ) + QString(",") + (getSecondcalling().length() == 0 ? QString("null") : QString("'") + escapeString(getSecondcalling(),QChar('\\')) + QString("'") ) + QString(")");
	}

QString DatSSNotification::generateInsertStatementNoSequence()
	{
	return QString("INSERT INTO lea.dat_ssnotification (nmask,numtype,objectnumber,time,eventid,subeventid,callnumber,callednumber,recordtype,cin,operatorid,liid,cclid,usetype,useresult,sername,notification,calllndcation,capability,facilityop,genericnumber,objectnumber1,gatewayid,secondcalling,id) values (") +(getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'") ) + QString(",") + (getObjectnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'") ) + QString(",") + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'") ) + QString(",") + (getCallnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getCallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getRecordtype().length() == 0 ? QString("null") : QString("'") + escapeString(getRecordtype(),QChar('\\')) + QString("'") ) + QString(",") + (getCin().length() == 0 ? QString("null") : QString("'") + escapeString(getCin(),QChar('\\')) + QString("'") ) + QString(",") + (getOperatorid().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatorid(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getCclid().length() == 0 ? QString("null") : QString("'") + escapeString(getCclid(),QChar('\\')) + QString("'") ) + QString(",") + (getUsetype().length() == 0 ? QString("null") : QString("'") + escapeString(getUsetype(),QChar('\\')) + QString("'") ) + QString(",") + (getUseresult().length() == 0 ? QString("null") : QString("'") + escapeString(getUseresult(),QChar('\\')) + QString("'") ) + QString(",") + (getSername().length() == 0 ? QString("null") : QString("'") + escapeString(getSername(),QChar('\\')) + QString("'") ) + QString(",") + (getNotification().length() == 0 ? QString("null") : QString("'") + escapeString(getNotification(),QChar('\\')) + QString("'") ) + QString(",") + (getCalllndcation().length() == 0 ? QString("null") : QString("'") + escapeString(getCalllndcation(),QChar('\\')) + QString("'") ) + QString(",") + (getCapability().length() == 0 ? QString("null") : QString("'") + escapeString(getCapability(),QChar('\\')) + QString("'") ) + QString(",") + (getFacilityop().length() == 0 ? QString("null") : QString("'") + escapeString(getFacilityop(),QChar('\\')) + QString("'") ) + QString(",") + (getGenericnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getGenericnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getObjectnumber1().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectnumber1(),QChar('\\')) + QString("'") ) + QString(",") + (getGatewayid().length() == 0 ? QString("null") : QString("'") + escapeString(getGatewayid(),QChar('\\')) + QString("'") ) + QString(",") + (getSecondcalling().length() == 0 ? QString("null") : QString("'") + escapeString(getSecondcalling(),QChar('\\')) + QString("'") ) + QString(",")+ (getid().length() == 0 ? QString("null") : QString("'") + escapeString(getid(),QChar('\\')) + QString("'") ) + QString(")");
	}

QString DatSSNotification::generateUpdateStatement()
	{
	return QString("UPDATE lea.dat_ssnotification SET nmask = ") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'")) + 
		QString(", numtype = ") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'")) + 
		QString(", objectnumber = ") + (getObjectnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectnumber(),QChar('\\')) + QString("'")) + 
		QString(", time = ") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'")) + 
		QString(", eventid = ") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'")) + 
		QString(", subeventid = ") + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'")) + 
		QString(", callnumber = ") + (getCallnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallnumber(),QChar('\\')) + QString("'")) + 
		QString(", callednumber = ") + (getCallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallednumber(),QChar('\\')) + QString("'")) + 
		QString(", recordtype = ") + (getRecordtype().length() == 0 ? QString("null") : QString("'") + escapeString(getRecordtype(),QChar('\\')) + QString("'")) + 
		QString(", cin = ") + (getCin().length() == 0 ? QString("null") : QString("'") + escapeString(getCin(),QChar('\\')) + QString("'")) + 
		QString(", operatorid = ") + (getOperatorid().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatorid(),QChar('\\')) + QString("'")) + 
		QString(", liid = ") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'")) + 
		QString(", cclid = ") + (getCclid().length() == 0 ? QString("null") : QString("'") + escapeString(getCclid(),QChar('\\')) + QString("'")) + 
		QString(", usetype = ") + (getUsetype().length() == 0 ? QString("null") : QString("'") + escapeString(getUsetype(),QChar('\\')) + QString("'")) + 
		QString(", useresult = ") + (getUseresult().length() == 0 ? QString("null") : QString("'") + escapeString(getUseresult(),QChar('\\')) + QString("'")) + 
		QString(", sername = ") + (getSername().length() == 0 ? QString("null") : QString("'") + escapeString(getSername(),QChar('\\')) + QString("'")) + 
		QString(", notification = ") + (getNotification().length() == 0 ? QString("null") : QString("'") + escapeString(getNotification(),QChar('\\')) + QString("'")) + 
		QString(", calllndcation = ") + (getCalllndcation().length() == 0 ? QString("null") : QString("'") + escapeString(getCalllndcation(),QChar('\\')) + QString("'")) + 
		QString(", capability = ") + (getCapability().length() == 0 ? QString("null") : QString("'") + escapeString(getCapability(),QChar('\\')) + QString("'")) + 
		QString(", facilityop = ") + (getFacilityop().length() == 0 ? QString("null") : QString("'") + escapeString(getFacilityop(),QChar('\\')) + QString("'")) + 
		QString(", genericnumber = ") + (getGenericnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getGenericnumber(),QChar('\\')) + QString("'")) + 
		QString(", objectnumber1 = ") + (getObjectnumber1().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectnumber1(),QChar('\\')) + QString("'")) + 
		QString(", gatewayid = ") + (getGatewayid().length() == 0 ? QString("null") : QString("'") + escapeString(getGatewayid(),QChar('\\')) + QString("'")) + 
		QString(", secondcalling = ") + (getSecondcalling().length() == 0 ? QString("null") : QString("'") + escapeString(getSecondcalling(),QChar('\\')) + QString("'"));
	}

QString DatSSNotification::generateSelectStatement()
	{
	return QString("SELECT nmask,numtype,objectnumber,time,eventid,subeventid,callnumber,callednumber,recordtype,cin,operatorid,liid,cclid,usetype,useresult,sername,notification,calllndcation,capability,facilityop,genericnumber,objectnumber1,gatewayid,secondcalling FROM lea.dat_ssnotification");
	}

void DatSSNotification::readRecord(QSqlQuery query)
	{
	m_stNmask = query.value(0).isNull() ? "" : query.value(0).toString();
	m_stNumtype = query.value(1).isNull() ? "" : query.value(1).toString();
	m_stObjectnumber = query.value(2).isNull() ? "" : query.value(2).toString();
	m_stTime = query.value(3).isNull() ? "" : query.value(3).toString();
	m_stEventid = query.value(4).isNull() ? "" : query.value(4).toString();
	m_stSubeventid = query.value(5).isNull() ? "" : query.value(5).toString();
	m_stCallnumber = query.value(6).isNull() ? "" : query.value(6).toString();
	m_stCallednumber = query.value(7).isNull() ? "" : query.value(7).toString();
	m_stRecordtype = query.value(8).isNull() ? "" : query.value(8).toString();
	m_stCin = query.value(9).isNull() ? "" : query.value(9).toString();
	m_stOperatorid = query.value(10).isNull() ? "" : query.value(10).toString();
	m_stLiid = query.value(11).isNull() ? "" : query.value(11).toString();
	m_stCclid = query.value(12).isNull() ? "" : query.value(12).toString();
	m_stUsetype = query.value(13).isNull() ? "" : query.value(13).toString();
	m_stUseresult = query.value(14).isNull() ? "" : query.value(14).toString();
	m_stSername = query.value(15).isNull() ? "" : query.value(15).toString();
	m_stNotification = query.value(16).isNull() ? "" : query.value(16).toString();
	m_stCalllndcation = query.value(17).isNull() ? "" : query.value(17).toString();
	m_stCapability = query.value(18).isNull() ? "" : query.value(18).toString();
	m_stFacilityop = query.value(19).isNull() ? "" : query.value(19).toString();
	m_stGenericnumber = query.value(20).isNull() ? "" : query.value(20).toString();
	m_stObjectnumber1 = query.value(21).isNull() ? "" : query.value(21).toString();
	m_stGatewayid = query.value(22).isNull() ? "" : query.value(22).toString();
	m_stSecondcalling = query.value(23).isNull() ? "" : query.value(23).toString();
	}

QStringList DatSSNotification::generateFieldList()
	{
	QStringList	sl;

	sl += "nmask";
	sl += "numtype";
	sl += "objectnumber";
	sl += "time";
	sl += "eventid";
	sl += "subeventid";
	sl += "callnumber";
	sl += "callednumber";
	sl += "recordtype";
	sl += "cin";
	sl += "operatorid";
	sl += "liid";
	sl += "cclid";
	sl += "usetype";
	sl += "useresult";
	sl += "sername";
	sl += "notification";
	sl += "calllndcation";
	sl += "capability";
	sl += "facilityop";
	sl += "genericnumber";
	sl += "objectnumber1";
	sl += "gatewayid";
	sl += "secondcalling";
	return sl;
	}

QString DatSSNotification::escapeString(QString stData,QChar cEscapeCharacter)
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

QString DatSSNotification::getTableName()
	{
	return "lea.dat_ssnotification";
	}

void DatSSNotification::setNmask(QString s)
	{
	m_stNmask = s;
	}

QString DatSSNotification::getNmask()
	{
	return m_stNmask;
	}

void DatSSNotification::setNumtype(QString s)
	{
	m_stNumtype = s;
	}

QString DatSSNotification::getNumtype()
	{
	return m_stNumtype;
	}

void DatSSNotification::setObjectnumber(QString s)
	{
	m_stObjectnumber = s;
	}

QString DatSSNotification::getObjectnumber()
	{
	return m_stObjectnumber;
	}

void DatSSNotification::setTime(QString s)
	{
	m_stTime = s;
	}

QString DatSSNotification::getTime()
	{
	return m_stTime;
	}

void DatSSNotification::setEventid(QString s)
	{
	m_stEventid = s;
	}

QString DatSSNotification::getEventid()
	{
	return m_stEventid;
	}

void DatSSNotification::setSubeventid(QString s)
	{
	m_stSubeventid = s;
	}

QString DatSSNotification::getSubeventid()
	{
	return m_stSubeventid;
	}

void DatSSNotification::setCallnumber(QString s)
	{
	m_stCallnumber = s;
	}

QString DatSSNotification::getCallnumber()
	{
	return m_stCallnumber;
	}

void DatSSNotification::setCallednumber(QString s)
	{
	m_stCallednumber = s;
	}

QString DatSSNotification::getCallednumber()
	{
	return m_stCallednumber;
	}

void DatSSNotification::setRecordtype(QString s)
	{
	m_stRecordtype = s;
	}

QString DatSSNotification::getRecordtype()
	{
	return m_stRecordtype;
	}

void DatSSNotification::setCin(QString s)
	{
	m_stCin = s;
	}

QString DatSSNotification::getCin()
	{
	return m_stCin;
	}

void DatSSNotification::setOperatorid(QString s)
	{
	m_stOperatorid = s;
	}

QString DatSSNotification::getOperatorid()
	{
	return m_stOperatorid;
	}

void DatSSNotification::setLiid(QString s)
	{
	m_stLiid = s;
	}

QString DatSSNotification::getLiid()
	{
	return m_stLiid;
	}

void DatSSNotification::setCclid(QString s)
	{
	m_stCclid = s;
	}

QString DatSSNotification::getCclid()
	{
	return m_stCclid;
	}

void DatSSNotification::setUsetype(QString s)
	{
	m_stUsetype = s;
	}

QString DatSSNotification::getUsetype()
	{
	return m_stUsetype;
	}

void DatSSNotification::setUseresult(QString s)
	{
	m_stUseresult = s;
	}

QString DatSSNotification::getUseresult()
	{
	return m_stUseresult;
	}

void DatSSNotification::setSername(QString s)
	{
	m_stSername = s;
	}

QString DatSSNotification::getSername()
	{
	return m_stSername;
	}

void DatSSNotification::setNotification(QString s)
	{
	m_stNotification = s;
	}

QString DatSSNotification::getNotification()
	{
	return m_stNotification;
	}

void DatSSNotification::setCalllndcation(QString s)
	{
	m_stCalllndcation = s;
	}

QString DatSSNotification::getCalllndcation()
	{
	return m_stCalllndcation;
	}

void DatSSNotification::setCapability(QString s)
	{
	m_stCapability = s;
	}

QString DatSSNotification::getCapability()
	{
	return m_stCapability;
	}

void DatSSNotification::setFacilityop(QString s)
	{
	m_stFacilityop = s;
	}

QString DatSSNotification::getFacilityop()
	{
	return m_stFacilityop;
	}

void DatSSNotification::setGenericnumber(QString s)
	{
	m_stGenericnumber = s;
	}

QString DatSSNotification::getGenericnumber()
	{
	return m_stGenericnumber;
	}

void DatSSNotification::setObjectnumber1(QString s)
	{
	m_stObjectnumber1 = s;
	}

QString DatSSNotification::getObjectnumber1()
	{
	return m_stObjectnumber1;
	}

void DatSSNotification::setGatewayid(QString s)
	{
	m_stGatewayid = s;
	}

QString DatSSNotification::getGatewayid()
	{
	return m_stGatewayid;
	}

void DatSSNotification::setSecondcalling(QString s)
	{
	m_stSecondcalling = s;
	}

QString DatSSNotification::getSecondcalling()
	{
	return m_stSecondcalling;
	}
	
QString  DatSSNotification::getid()
	{
     return m_stid;	
	}
	
        void DatSSNotification::setid(QString s)
	{
	m_stid = s;
	}

void DatSSNotification::operator=(const DatSSNotification &old)
	{
	this -> m_stNmask = old.m_stNmask;
	this -> m_stNumtype = old.m_stNumtype;
	this -> m_stObjectnumber = old.m_stObjectnumber;
	this -> m_stTime = old.m_stTime;
	this -> m_stEventid = old.m_stEventid;
	this -> m_stSubeventid = old.m_stSubeventid;
	this -> m_stCallnumber = old.m_stCallnumber;
	this -> m_stCallednumber = old.m_stCallednumber;
	this -> m_stRecordtype = old.m_stRecordtype;
	this -> m_stCin = old.m_stCin;
	this -> m_stOperatorid = old.m_stOperatorid;
	this -> m_stLiid = old.m_stLiid;
	this -> m_stCclid = old.m_stCclid;
	this -> m_stUsetype = old.m_stUsetype;
	this -> m_stUseresult = old.m_stUseresult;
	this -> m_stSername = old.m_stSername;
	this -> m_stNotification = old.m_stNotification;
	this -> m_stCalllndcation = old.m_stCalllndcation;
	this -> m_stCapability = old.m_stCapability;
	this -> m_stFacilityop = old.m_stFacilityop;
	this -> m_stGenericnumber = old.m_stGenericnumber;
	this -> m_stObjectnumber1 = old.m_stObjectnumber1;
	this -> m_stGatewayid = old.m_stGatewayid;
	this -> m_stSecondcalling = old.m_stSecondcalling;
	}


