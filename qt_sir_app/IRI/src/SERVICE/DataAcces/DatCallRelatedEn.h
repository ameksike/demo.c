#ifndef DATCALLRELATEDEN_H
#define DATCALLRELATEDEN_H

#include <qvariant.h>
#include <qstring.h>
#include <qstringlist.h>
#include "src/Entity/Fija/CallRelatedEvent.h"

class QSqlQuery;
class CallRelatedEvent;

class DatCallRelatedEn 
{
  public:
    DatCallRelatedEn(QObject *parent = 0,const char *name = 0);
    DatCallRelatedEn(CallRelatedEvent &old);
   ~DatCallRelatedEn();

    QString getNmask();
    QString getNumtype();
    QString getObjectnumber();
    QString getTime();
    QString getCallorcalledflag();
    QString getCallingnumber();
    QString getCallednumber();
    QString getCallid1();
    QString getCallid2();
    QString getEventid();
    QString getSubeventid();
    QString getCombineorsplitflag();
    QString getElementid();
    QString getRecordtype();
    QString getCin();
    QString getOperatorid();
    QString getLiid();
    QString getCclid();
    QString getCallstate();
    QString getNaturecall();
    QString getCapability();
    QString getCallingsubadd();
    QString getCalledsubadd();
    QString getGenericnumber();
    QString getRedirctingnumber();
    QString getRedirctionnumber();
    QString getRedirctioninfo();
    QString getOrgcallednumber();
    QString getDiversioninfo();
    QString getConnectednumber();
    QString getRingduration();
    QString getReason();
    QString getId();
    QString getTableName();

    void  setNmask(QString s);
    void  setNumtype(QString s);
    void  setObjectnumber(QString s);
    void  setTime(QString s);
    void  setCallorcalledflag(QString s);
    void  setCallingnumber(QString s);
    void  setCallednumber(QString s);
    void  setCallid1(QString s);
    void  setCallid2(QString s);
    void  setEventid(QString s);
    void  setSubeventid(QString s);
    void  setCombineorsplitflag(QString s);
    void  setElementid(QString s);
    void  setRecordtype(QString s);
    void  setCin(QString s);
    void  setOperatorid(QString s);
    void  setLiid(QString s);
    void  setCclid(QString s);
    void  setCallstate(QString s);
    void  setNaturecall(QString s);
    void  setCapability(QString s);
    void  setCallingsubadd(QString s);
    void  setCalledsubadd(QString s);
    void  setGenericnumber(QString s);
    void  setRedirctingnumber(QString s);
    void  setRedirctionnumber(QString s);
    void  setRedirctioninfo(QString s);
    void  setOrgcallednumber(QString s);
    void  setDiversioninfo(QString s);
    void  setConnectednumber(QString s);
    void  setRingduration(QString s);
    void  setReason(QString s);
    void  setId(QString s);

    QString					generateDeleteStatement();
    QString					generateInsertStatement();
    QString					generateInsertStatementNoSequence();
    void					readRecord(QSqlQuery query);
    QString					generateSelectStatement();
    QString					generateUpdateStatement();
    QStringList					generateFieldList();
    QString					escapeString(QString stText,QChar cEscapeChar);


    void					operator=(const DatCallRelatedEn &old);
    short  				    convertLength(char array0,char array1)
    {

         char stringConvert[2];
         stringConvert[0]  = array0;
         stringConvert[1]  = array1;

         short * shortConvert = NULL;
         shortConvert = (short*)stringConvert;
         return *shortConvert;
    }    


protected:
    QString					m_stNmask;
    QString					m_stNumtype;
    QString					m_stObjectnumber;
    QString					m_stTime;
    QString					m_stCallorcalledflag;
    QString					m_stCallingnumber;
    QString					m_stCallednumber;
    QString					m_stCallid1;
    QString					m_stCallid2;
    QString					m_stEventid;
    QString					m_stSubeventid;
    QString					m_stCombineorsplitflag;
    QString					m_stElementid;
    QString					m_stRecordtype;
    QString					m_stCin;
    QString					m_stOperatorid;
    QString					m_stLiid;
    QString					m_stCclid;
    QString					m_stCallstate;
    QString					m_stNaturecall;
    QString					m_stCapability;
    QString					m_stCallingsubadd;
    QString					m_stCalledsubadd;
    QString					m_stGenericnumber;
    QString					m_stRedirctingnumber;
    QString					m_stRedirctionnumber;
    QString					m_stRedirctioninfo;
    QString					m_stOrgcallednumber;
    QString					m_stDiversioninfo;
    QString					m_stConnectednumber;
    QString					m_stRingduration;
    QString					m_stReason;
    QString					m_stId;
};
#endif //DATCALLRELATEDEN_H

