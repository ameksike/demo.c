#include "DatCallRelatedEn.h"

 //#include <QDateTime>
#include <qsqldatabase.h>
#include <qsqlquery.h>
#include <string>
#include <iostream>
 
using namespace std;

DatCallRelatedEn::DatCallRelatedEn(QObject *parent,const char *name) 
{
}
	

DatCallRelatedEn::~DatCallRelatedEn()
{
}

DatCallRelatedEn::DatCallRelatedEn(CallRelatedEvent &old)
{
	//En el escritorio esta salvado bien
    
    /*this -> m_stNmask.append("1f");
    QString numType;
    numType.setNum((int)old.NumType); 
    this -> m_stNumtype.append(numType);
	
	
	//Permite tratar una estructa correctamente	
	 unsigned char objectnumberLength[2];      
	 objectnumberLength[0]  = old.objectnumber.Length[0];
	 objectnumberLength[1]  = old.objectnumber.Length[1]; 
     short* pshort = NULL;
	 pshort = (short*)objectnumberLength ; //aquí voy a tener la cantidad de byte.
	 for(int i = 0 ; i <*pshort ;i++  )
	 this -> m_stObjectnumber.append(old.objectnumber.Dato[i]);
	
	
	 //year/moth/day hour/min/seg
	 QString year;
	 year.setNum( convertLength(old.time.nYear[0],old.time.nYear[1]) );
	 
	 QString month;
     month.setNum((int)old.time.nMonth);
          
	 QString day;
     day.setNum((int)old.time.nDay);
     
     QString hour;
     hour.setNum((int)old.time.nHour);
     
     QString min;
     min.setNum((int)old.time.nMin);
     
     
     QString sec;
     sec.setNum((int)old.time.nSec);
      	
	 this -> m_stTime.append(year+":");
	 this -> m_stTime.append(month+":");
	 this -> m_stTime.append(day+" ");
	 
	 this -> m_stTime.append(hour+":");
	 this -> m_stTime.append(min+":");
	 this -> m_stTime.append(sec);
	 
	 
	 //Flag
	 QString flag;
     flag.setNum((int)old.CallOrCalledFlag);
	 this -> m_stCallorcalledflag.append(flag);
     
     //CallingNumber and CalledNumber
     short scant = convertLength(old.CallingNumber[0],old.CallingNumber[1]);
     for(int j = 2 ; j < scant+2 ;j++  )
	 this -> m_stCallingnumber.append(old.CallingNumber[j]);
	 
	
	 short scantt = convertLength(old.CalledNumber[0],old.CalledNumber[1]);
     for(int k = 2 ; k < scantt+2 ;k++  )
	 this -> m_stCallednumber.append(old.CalledNumber[k]);
      
     QString callid1;
     callid1.setNum((int)convertLength(old.CallID1[0],old.CallID1[1]));            		
	 this -> m_stCallid1.append(callid1);
	 
	 QString callid2;
	 callid2.setNum((int)convertLength(old.CallID2[0],old.CallID2[1]));
	 this -> m_stCallid2.append(callid2);
	 
	
	 
	 this -> m_stEventid ="ffff";
	 this -> m_stSubeventid ="0";
	 this -> m_stCombineorsplitflag.append("0");
	 this -> m_stElementid = "0";
	 this -> m_stRecordtype.append("0");
	 
	short scincant = convertLength( old.cin.Length[0] , old.cin.Length[1]);
    for(int m = 0 ; m < scincant ;m++  )
	this -> m_stCin.append(old.cin.Dato[m]);
	cout << endl;
	printf( "%x", old.cin.Length[0] );
	cout<<endl <<scincant;
	printf( "%x", old.cin.Length[1] );
	cout << endl;
	 
	 this -> m_stOperatorid ="56f4";
	 
	 short sliidcant = convertLength( old.liiD.Length[0] , old.liiD.Length[1]);
     for(int k = 0 ; k < sliidcant ;k++)
	 this -> m_stLiid.append(old.liiD.Dato[k]);
	

	 
	
	 this -> m_stCclid ="0";
	 this -> m_stCallstate.append("2") ;
	 this -> m_stNaturecall ="0";
         this -> m_stCapability ="0000";
	 this -> m_stCallingsubadd ="000";
	 this -> m_stCalledsubadd ="00000000";
	 this -> m_stGenericnumber ="0000";
	 this -> m_stRedirctionnumber ="0000";
	 this -> m_stRedirctioninfo ="00000";
	 this -> m_stOrgcallednumber ="0000";
	 this -> m_stDiversioninfo ="0000";
	 this -> m_stConnectednumber ="0000";
	 this -> m_stRingduration ="000";
	 this -> m_stReason ="00";
	 //this -> m_stId =(char*) ;*/
	}

QString DatCallRelatedEn::generateDeleteStatement()
{
    return QString("DELETE FROM lea.dat_call_related_en");
}

QString DatCallRelatedEn::generateInsertStatement()
{
    return QString("INSERT INTO lea.dat_call_related_en (nmask,numtype,objectnumber,time,callorcalledflag,callingnumber,callednumber,callid1,callid2,eventid,subeventid,combineorsplitflag,elementid,recordtype,cin,operatorid,liid,cclid,callstate,naturecall,capability,callingsubadd,calledsubadd,genericnumber,redirctingnumber,redirctionnumber,redirctioninfo,orgcallednumber,diversioninfo,connectednumber,ringduration,reason,id) values (") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'") ) + QString(",") + (getObjectnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getCallorcalledflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCallorcalledflag(),QChar('\\')) + QString("'") ) + QString(",") + (getCallingnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallingnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getCallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getCallid1().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid1(),QChar('\\')) + QString("'") ) + QString(",") + (getCallid2().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid2(),QChar('\\')) + QString("'") ) + QString(",") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'") ) + QString(",") + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'") ) + QString(",") + (getCombineorsplitflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCombineorsplitflag(),QChar('\\')) + QString("'") ) + QString(",") + (getElementid().length() == 0 ? QString("null") : QString("'") + escapeString(getElementid(),QChar('\\')) + QString("'") ) + QString(",") + (getRecordtype().length() == 0 ? QString("null") : QString("'") + escapeString(getRecordtype(),QChar('\\')) + QString("'") ) + QString(",") + (getCin().length() == 0 ? QString("null") : QString("'") + escapeString(getCin(),QChar('\\')) + QString("'") ) + QString(",") + (getOperatorid().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatorid(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getCclid().length() == 0 ? QString("null") : QString("'") + escapeString(getCclid(),QChar('\\')) + QString("'") ) + QString(",") + (getCallstate().length() == 0 ? QString("null") : QString("'") + escapeString(getCallstate(),QChar('\\')) + QString("'") ) + QString(",") + (getNaturecall().length() == 0 ? QString("null") : QString("'") + escapeString(getNaturecall(),QChar('\\')) + QString("'") ) + QString(",") + (getCapability().length() == 0 ? QString("null") : QString("'") + escapeString(getCapability(),QChar('\\')) + QString("'") ) + QString(",") + (getCallingsubadd().length() == 0 ? QString("null") : QString("'") + escapeString(getCallingsubadd(),QChar('\\')) + QString("'") ) + QString(",") + (getCalledsubadd().length() == 0 ? QString("null") : QString("'") + escapeString(getCalledsubadd(),QChar('\\')) + QString("'") ) + QString(",") + (getGenericnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getGenericnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getRedirctingnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirctingnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getRedirctionnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirctionnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getRedirctioninfo().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirctioninfo(),QChar('\\')) + QString("'") ) + QString(",") + (getOrgcallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getOrgcallednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getDiversioninfo().length() == 0 ? QString("null") : QString("'") + escapeString(getDiversioninfo(),QChar('\\')) + QString("'") ) + QString(",") + (getConnectednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getConnectednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getRingduration().length() == 0 ? QString("null") : QString("'") + escapeString(getRingduration(),QChar('\\')) + QString("'") ) + QString(",") + (getReason().length() == 0 ? QString("null") : QString("'") + escapeString(getReason(),QChar('\\')) + QString("'") ) + QString(",nextval('lea.dat_call_related_en_sequence'))");
}

QString DatCallRelatedEn::generateInsertStatementNoSequence()
{
    return QString("INSERT INTO lea.dat_call_related_en (nmask,numtype,objectnumber,time,callorcalledflag,callingnumber,callednumber,callid1,callid2,eventid,subeventid,combineorsplitflag,elementid,recordtype,cin,operatorid,liid,cclid,callstate,naturecall,capability,callingsubadd,calledsubadd,genericnumber,redirctingnumber,redirctionnumber,redirctioninfo,orgcallednumber,diversioninfo,connectednumber,ringduration,reason,id) values (") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'") ) + QString(",") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'") ) + QString(",") + (getObjectnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'") ) + QString(",") + (getCallorcalledflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCallorcalledflag(),QChar('\\')) + QString("'") ) + QString(",") + (getCallingnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallingnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getCallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getCallid1().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid1(),QChar('\\')) + QString("'") ) + QString(",") + (getCallid2().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid2(),QChar('\\')) + QString("'") ) + QString(",") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'") ) + QString(",") + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'") ) + QString(",") + (getCombineorsplitflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCombineorsplitflag(),QChar('\\')) + QString("'") ) + QString(",") + (getElementid().length() == 0 ? QString("null") : QString("'") + escapeString(getElementid(),QChar('\\')) + QString("'") ) + QString(",") + (getRecordtype().length() == 0 ? QString("null") : QString("'") + escapeString(getRecordtype(),QChar('\\')) + QString("'") ) + QString(",") + (getCin().length() == 0 ? QString("null") : QString("'") + escapeString(getCin(),QChar('\\')) + QString("'") ) + QString(",") + (getOperatorid().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatorid(),QChar('\\')) + QString("'") ) + QString(",") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'") ) + QString(",") + (getCclid().length() == 0 ? QString("null") : QString("'") + escapeString(getCclid(),QChar('\\')) + QString("'") ) + QString(",") + (getCallstate().length() == 0 ? QString("null") : QString("'") + escapeString(getCallstate(),QChar('\\')) + QString("'") ) + QString(",") + (getNaturecall().length() == 0 ? QString("null") : QString("'") + escapeString(getNaturecall(),QChar('\\')) + QString("'") ) + QString(",") + (getCapability().length() == 0 ? QString("null") : QString("'") + escapeString(getCapability(),QChar('\\')) + QString("'") ) + QString(",") + (getCallingsubadd().length() == 0 ? QString("null") : QString("'") + escapeString(getCallingsubadd(),QChar('\\')) + QString("'") ) + QString(",") + (getCalledsubadd().length() == 0 ? QString("null") : QString("'") + escapeString(getCalledsubadd(),QChar('\\')) + QString("'") ) + QString(",") + (getGenericnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getGenericnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getRedirctingnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirctingnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getRedirctionnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirctionnumber(),QChar('\\')) + QString("'") ) + QString(",") + (getRedirctioninfo().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirctioninfo(),QChar('\\')) + QString("'") ) + QString(",") + (getOrgcallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getOrgcallednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getDiversioninfo().length() == 0 ? QString("null") : QString("'") + escapeString(getDiversioninfo(),QChar('\\')) + QString("'") ) + QString(",") + (getConnectednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getConnectednumber(),QChar('\\')) + QString("'") ) + QString(",") + (getRingduration().length() == 0 ? QString("null") : QString("'") + escapeString(getRingduration(),QChar('\\')) + QString("'") ) + QString(",") + (getReason().length() == 0 ? QString("null") : QString("'") + escapeString(getReason(),QChar('\\')) + QString("'") ) + QString(",") + (getId().length() == 0 ? QString("null") : QString("'") + escapeString(getId(),QChar('\\')) + QString("'") ) + QString(")");
}

QString DatCallRelatedEn::generateUpdateStatement()
{
    return QString("UPDATE lea.dat_call_related_en SET nmask = ") + (getNmask().length() == 0 ? QString("null") : QString("'") + escapeString(getNmask(),QChar('\\')) + QString("'")) +
        QString(", numtype = ") + (getNumtype().length() == 0 ? QString("null") : QString("'") + escapeString(getNumtype(),QChar('\\')) + QString("'")) +
        QString(", objectnumber = ") + (getObjectnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectnumber(),QChar('\\')) + QString("'")) +
        QString(", time = ") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'")) +
        QString(", callorcalledflag = ") + (getCallorcalledflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCallorcalledflag(),QChar('\\')) + QString("'")) +
        QString(", callingnumber = ") + (getCallingnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallingnumber(),QChar('\\')) + QString("'")) +
        QString(", callednumber = ") + (getCallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallednumber(),QChar('\\')) + QString("'")) +
        QString(", callid1 = ") + (getCallid1().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid1(),QChar('\\')) + QString("'")) +
        QString(", callid2 = ") + (getCallid2().length() == 0 ? QString("null") : QString("'") + escapeString(getCallid2(),QChar('\\')) + QString("'")) +
        QString(", eventid = ") + (getEventid().length() == 0 ? QString("null") : QString("'") + escapeString(getEventid(),QChar('\\')) + QString("'")) +
        QString(", subeventid = ") + (getSubeventid().length() == 0 ? QString("null") : QString("'") + escapeString(getSubeventid(),QChar('\\')) + QString("'")) +
        QString(", combineorsplitflag = ") + (getCombineorsplitflag().length() == 0 ? QString("null") : QString("'") + escapeString(getCombineorsplitflag(),QChar('\\')) + QString("'")) +
        QString(", elementid = ") + (getElementid().length() == 0 ? QString("null") : QString("'") + escapeString(getElementid(),QChar('\\')) + QString("'")) +
        QString(", recordtype = ") + (getRecordtype().length() == 0 ? QString("null") : QString("'") + escapeString(getRecordtype(),QChar('\\')) + QString("'")) +
        QString(", cin = ") + (getCin().length() == 0 ? QString("null") : QString("'") + escapeString(getCin(),QChar('\\')) + QString("'")) +
        QString(", operatorid = ") + (getOperatorid().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatorid(),QChar('\\')) + QString("'")) +
        QString(", liid = ") + (getLiid().length() == 0 ? QString("null") : QString("'") + escapeString(getLiid(),QChar('\\')) + QString("'")) +
        QString(", cclid = ") + (getCclid().length() == 0 ? QString("null") : QString("'") + escapeString(getCclid(),QChar('\\')) + QString("'")) +
        QString(", callstate = ") + (getCallstate().length() == 0 ? QString("null") : QString("'") + escapeString(getCallstate(),QChar('\\')) + QString("'")) +
        QString(", naturecall = ") + (getNaturecall().length() == 0 ? QString("null") : QString("'") + escapeString(getNaturecall(),QChar('\\')) + QString("'")) +
        QString(", capability = ") + (getCapability().length() == 0 ? QString("null") : QString("'") + escapeString(getCapability(),QChar('\\')) + QString("'")) +
        QString(", callingsubadd = ") + (getCallingsubadd().length() == 0 ? QString("null") : QString("'") + escapeString(getCallingsubadd(),QChar('\\')) + QString("'")) +
        QString(", calledsubadd = ") + (getCalledsubadd().length() == 0 ? QString("null") : QString("'") + escapeString(getCalledsubadd(),QChar('\\')) + QString("'")) +
        QString(", genericnumber = ") + (getGenericnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getGenericnumber(),QChar('\\')) + QString("'")) +
        QString(", redirctingnumber = ") + (getRedirctingnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirctingnumber(),QChar('\\')) + QString("'")) +
        QString(", redirctionnumber = ") + (getRedirctionnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirctionnumber(),QChar('\\')) + QString("'")) +
        QString(", redirctioninfo = ") + (getRedirctioninfo().length() == 0 ? QString("null") : QString("'") + escapeString(getRedirctioninfo(),QChar('\\')) + QString("'")) +
        QString(", orgcallednumber = ") + (getOrgcallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getOrgcallednumber(),QChar('\\')) + QString("'")) +
        QString(", diversioninfo = ") + (getDiversioninfo().length() == 0 ? QString("null") : QString("'") + escapeString(getDiversioninfo(),QChar('\\')) + QString("'")) +
        QString(", connectednumber = ") + (getConnectednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getConnectednumber(),QChar('\\')) + QString("'")) +
        QString(", ringduration = ") + (getRingduration().length() == 0 ? QString("null") : QString("'") + escapeString(getRingduration(),QChar('\\')) + QString("'")) +
        QString(", reason = ") + (getReason().length() == 0 ? QString("null") : QString("'") + escapeString(getReason(),QChar('\\')) + QString("'")) +
        QString(", id = ") + (getId().length() == 0 ? QString("null") : QString("'") + escapeString(getId(),QChar('\\')) + QString("'"));
}

QString DatCallRelatedEn::generateSelectStatement()
	{
	return QString("SELECT nmask,numtype,objectnumber,time,callorcalledflag,callingnumber,callednumber,callid1,callid2,eventid,subeventid,combineorsplitflag,elementid,recordtype,cin,operatorid,liid,cclid,callstate,naturecall,capability,callingsubadd,calledsubadd,genericnumber,redirctingnumber,redirctionnumber,redirctioninfo,orgcallednumber,diversioninfo,connectednumber,ringduration,reason,id FROM lea.dat_call_related_en");
	}

void DatCallRelatedEn::readRecord(QSqlQuery query)
	{
	m_stNmask = query.value(0).isNull() ? "" : query.value(0).toString();
	m_stNumtype = query.value(1).isNull() ? "" : query.value(1).toString();
	m_stObjectnumber = query.value(2).isNull() ? "" : query.value(2).toString();
	m_stTime = query.value(3).isNull() ? "" : query.value(3).toString();
	m_stCallorcalledflag = query.value(4).isNull() ? "" : query.value(4).toString();
	m_stCallingnumber = query.value(5).isNull() ? "" : query.value(5).toString();
	m_stCallednumber = query.value(6).isNull() ? "" : query.value(6).toString();
	m_stCallid1 = query.value(7).isNull() ? "" : query.value(7).toString();
	m_stCallid2 = query.value(8).isNull() ? "" : query.value(8).toString();
	m_stEventid = query.value(9).isNull() ? "" : query.value(9).toString();
	m_stSubeventid = query.value(10).isNull() ? "" : query.value(10).toString();
	m_stCombineorsplitflag = query.value(11).isNull() ? "" : query.value(11).toString();
	m_stElementid = query.value(12).isNull() ? "" : query.value(12).toString();
	m_stRecordtype = query.value(13).isNull() ? "" : query.value(13).toString();
	m_stCin = query.value(14).isNull() ? "" : query.value(14).toString();
	m_stOperatorid = query.value(15).isNull() ? "" : query.value(15).toString();
	m_stLiid = query.value(16).isNull() ? "" : query.value(16).toString();
	m_stCclid = query.value(17).isNull() ? "" : query.value(17).toString();
	m_stCallstate = query.value(18).isNull() ? "" : query.value(18).toString();
	m_stNaturecall = query.value(19).isNull() ? "" : query.value(19).toString();
	m_stCapability = query.value(20).isNull() ? "" : query.value(20).toString();
	m_stCallingsubadd = query.value(21).isNull() ? "" : query.value(21).toString();
	m_stCalledsubadd = query.value(22).isNull() ? "" : query.value(22).toString();
	m_stGenericnumber = query.value(23).isNull() ? "" : query.value(23).toString();
	m_stRedirctingnumber = query.value(24).isNull() ? "" : query.value(24).toString();
	m_stRedirctionnumber = query.value(25).isNull() ? "" : query.value(25).toString();
	m_stRedirctioninfo = query.value(26).isNull() ? "" : query.value(26).toString();
	m_stOrgcallednumber = query.value(27).isNull() ? "" : query.value(27).toString();
	m_stDiversioninfo = query.value(28).isNull() ? "" : query.value(28).toString();
	m_stConnectednumber = query.value(29).isNull() ? "" : query.value(29).toString();
	m_stRingduration = query.value(30).isNull() ? "" : query.value(30).toString();
	m_stReason = query.value(31).isNull() ? "" : query.value(31).toString();
	m_stId = query.value(32).isNull() ? "" : query.value(32).toString();
	}

QStringList DatCallRelatedEn::generateFieldList()
	{
	QStringList	sl;

	sl += "nmask";
	sl += "numtype";
	sl += "objectnumber";
	sl += "time";
	sl += "callorcalledflag";
	sl += "callingnumber";
	sl += "callednumber";
	sl += "callid1";
	sl += "callid2";
	sl += "eventid";
	sl += "subeventid";
	sl += "combineorsplitflag";
	sl += "elementid";
	sl += "recordtype";
	sl += "cin";
	sl += "operatorid";
	sl += "liid";
	sl += "cclid";
	sl += "callstate";
	sl += "naturecall";
	sl += "capability";
	sl += "callingsubadd";
	sl += "calledsubadd";
	sl += "genericnumber";
	sl += "redirctingnumber";
	sl += "redirctionnumber";
	sl += "redirctioninfo";
	sl += "orgcallednumber";
	sl += "diversioninfo";
	sl += "connectednumber";
	sl += "ringduration";
	sl += "reason";
	sl += "id";
	return sl;
	}

QString DatCallRelatedEn::escapeString(QString stData,QChar cEscapeCharacter)
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

QString DatCallRelatedEn::getTableName()
	{
	return "lea.dat_call_related_en";
	}

void DatCallRelatedEn::setNmask(QString s)
	{
	m_stNmask = s;
	}

QString DatCallRelatedEn::getNmask()
	{
	return m_stNmask;
	}

void DatCallRelatedEn::setNumtype(QString s)
	{
	m_stNumtype = s;
	}

QString DatCallRelatedEn::getNumtype()
	{
	return m_stNumtype;
	}

void DatCallRelatedEn::setObjectnumber(QString s)
	{
	m_stObjectnumber = s;
	}

QString DatCallRelatedEn::getObjectnumber()
	{
	return m_stObjectnumber;
	}

void DatCallRelatedEn::setTime(QString s)
	{
	m_stTime = s;
	}

QString DatCallRelatedEn::getTime()
	{
	return m_stTime;
	}

void DatCallRelatedEn::setCallorcalledflag(QString s)
	{
	m_stCallorcalledflag = s;
	}

QString DatCallRelatedEn::getCallorcalledflag()
	{
	return m_stCallorcalledflag;
	}

void DatCallRelatedEn::setCallingnumber(QString s)
	{
	m_stCallingnumber = s;
	}

QString DatCallRelatedEn::getCallingnumber()
	{
	return m_stCallingnumber;
	}

void DatCallRelatedEn::setCallednumber(QString s)
	{
	m_stCallednumber = s;
	}

QString DatCallRelatedEn::getCallednumber()
	{
	return m_stCallednumber;
	}

void DatCallRelatedEn::setCallid1(QString s)
	{
	m_stCallid1 = s;
	}

QString DatCallRelatedEn::getCallid1()
	{
	return m_stCallid1;
	}

void DatCallRelatedEn::setCallid2(QString s)
	{
	m_stCallid2 = s;
	}

QString DatCallRelatedEn::getCallid2()
	{
	return m_stCallid2;
	}

void DatCallRelatedEn::setEventid(QString s)
	{
	m_stEventid = s;
	}

QString DatCallRelatedEn::getEventid()
	{
	return m_stEventid;
	}

void DatCallRelatedEn::setSubeventid(QString s)
	{
	m_stSubeventid = s;
	}

QString DatCallRelatedEn::getSubeventid()
	{
	return m_stSubeventid;
	}

void DatCallRelatedEn::setCombineorsplitflag(QString s)
	{
	m_stCombineorsplitflag = s;
	}

QString DatCallRelatedEn::getCombineorsplitflag()
	{
	return m_stCombineorsplitflag;
	}

void DatCallRelatedEn::setElementid(QString s)
	{
	m_stElementid = s;
	}

QString DatCallRelatedEn::getElementid()
	{
	return m_stElementid;
	}

void DatCallRelatedEn::setRecordtype(QString s)
	{
	m_stRecordtype = s;
	}

QString DatCallRelatedEn::getRecordtype()
	{
	return m_stRecordtype;
	}

void DatCallRelatedEn::setCin(QString s)
	{
	m_stCin = s;
	}

QString DatCallRelatedEn::getCin()
	{
	return m_stCin;
	}

void DatCallRelatedEn::setOperatorid(QString s)
	{
	m_stOperatorid = s;
	}

QString DatCallRelatedEn::getOperatorid()
	{
	return m_stOperatorid;
	}

void DatCallRelatedEn::setLiid(QString s)
	{
	m_stLiid = s;
	}

QString DatCallRelatedEn::getLiid()
	{
	return m_stLiid;
	}

void DatCallRelatedEn::setCclid(QString s)
	{
	m_stCclid = s;
	}

QString DatCallRelatedEn::getCclid()
	{
	return m_stCclid;
	}

void DatCallRelatedEn::setCallstate(QString s)
	{
	m_stCallstate = s;
	}

QString DatCallRelatedEn::getCallstate()
	{
	return m_stCallstate;
	}

void DatCallRelatedEn::setNaturecall(QString s)
	{
	m_stNaturecall = s;
	}

QString DatCallRelatedEn::getNaturecall()
	{
	return m_stNaturecall;
	}

void DatCallRelatedEn::setCapability(QString s)
	{
	m_stCapability = s;
	}

QString DatCallRelatedEn::getCapability()
	{
	return m_stCapability;
	}

void DatCallRelatedEn::setCallingsubadd(QString s)
	{
	m_stCallingsubadd = s;
	}

QString DatCallRelatedEn::getCallingsubadd()
	{
	return m_stCallingsubadd;
	}

void DatCallRelatedEn::setCalledsubadd(QString s)
	{
	m_stCalledsubadd = s;
	}

QString DatCallRelatedEn::getCalledsubadd()
	{
	return m_stCalledsubadd;
	}

void DatCallRelatedEn::setGenericnumber(QString s)
	{
	m_stGenericnumber = s;
	}

QString DatCallRelatedEn::getGenericnumber()
	{
	return m_stGenericnumber;
	}

void DatCallRelatedEn::setRedirctingnumber(QString s)
	{
	m_stRedirctingnumber = s;
	}

QString DatCallRelatedEn::getRedirctingnumber()
	{
	return m_stRedirctingnumber;
	}

void DatCallRelatedEn::setRedirctionnumber(QString s)
	{
	m_stRedirctionnumber = s;
	}

QString DatCallRelatedEn::getRedirctionnumber()
	{
	return m_stRedirctionnumber;
	}

void DatCallRelatedEn::setRedirctioninfo(QString s)
	{
	m_stRedirctioninfo = s;
	}

QString DatCallRelatedEn::getRedirctioninfo()
	{
	return m_stRedirctioninfo;
	}

void DatCallRelatedEn::setOrgcallednumber(QString s)
	{
	m_stOrgcallednumber = s;
	}

QString DatCallRelatedEn::getOrgcallednumber()
	{
	return m_stOrgcallednumber;
	}

void DatCallRelatedEn::setDiversioninfo(QString s)
	{
	m_stDiversioninfo = s;
	}

QString DatCallRelatedEn::getDiversioninfo()
	{
	return m_stDiversioninfo;
	}

void DatCallRelatedEn::setConnectednumber(QString s)
	{
	m_stConnectednumber = s;
	}

QString DatCallRelatedEn::getConnectednumber()
	{
	return m_stConnectednumber;
	}

void DatCallRelatedEn::setRingduration(QString s)
	{
	m_stRingduration = s;
	}

QString DatCallRelatedEn::getRingduration()
	{
	return m_stRingduration;
	}

void DatCallRelatedEn::setReason(QString s)
	{
	m_stReason = s;
	}

QString DatCallRelatedEn::getReason()
	{
	return m_stReason;
	}

void DatCallRelatedEn::setId(QString s)
	{
	m_stId = s;
	}

QString DatCallRelatedEn::getId()
	{
	return m_stId;
	}

void DatCallRelatedEn::operator=(const DatCallRelatedEn &old)
	{
	this -> m_stNmask = old.m_stNmask;
	this -> m_stNumtype = old.m_stNumtype;
	this -> m_stObjectnumber = old.m_stObjectnumber;
	this -> m_stTime = old.m_stTime;
	this -> m_stCallorcalledflag = old.m_stCallorcalledflag;
	this -> m_stCallingnumber = old.m_stCallingnumber;
	this -> m_stCallednumber = old.m_stCallednumber;
	this -> m_stCallid1 = old.m_stCallid1;
	this -> m_stCallid2 = old.m_stCallid2;
	this -> m_stEventid = old.m_stEventid;
	this -> m_stSubeventid = old.m_stSubeventid;
	this -> m_stCombineorsplitflag = old.m_stCombineorsplitflag;
	this -> m_stElementid = old.m_stElementid;
	this -> m_stRecordtype = old.m_stRecordtype;
	this -> m_stCin = old.m_stCin;
	this -> m_stOperatorid = old.m_stOperatorid;
	this -> m_stLiid = old.m_stLiid;
	this -> m_stCclid = old.m_stCclid;
	this -> m_stCallstate = old.m_stCallstate;
	this -> m_stNaturecall = old.m_stNaturecall;
	this -> m_stCapability = old.m_stCapability;
	this -> m_stCallingsubadd = old.m_stCallingsubadd;
	this -> m_stCalledsubadd = old.m_stCalledsubadd;
	this -> m_stGenericnumber = old.m_stGenericnumber;
	this -> m_stRedirctingnumber = old.m_stRedirctingnumber;
	this -> m_stRedirctionnumber = old.m_stRedirctionnumber;
	this -> m_stRedirctioninfo = old.m_stRedirctioninfo;
	this -> m_stOrgcallednumber = old.m_stOrgcallednumber;
	this -> m_stDiversioninfo = old.m_stDiversioninfo;
	this -> m_stConnectednumber = old.m_stConnectednumber;
	this -> m_stRingduration = old.m_stRingduration;
	this -> m_stReason = old.m_stReason;
	this -> m_stId = old.m_stId;
	}


