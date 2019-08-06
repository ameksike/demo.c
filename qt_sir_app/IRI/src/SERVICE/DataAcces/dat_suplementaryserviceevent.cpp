#include "dat_suplementaryserviceevent.h"
#include <qdatetime.h>
#include <qsqldatabase.h>
#include <qsqlquery.h>



Dat_SuplementaryServiceEvent::Dat_SuplementaryServiceEvent(SuplementaryServiceEvent &old)
{
    this->NumType        = old.getNumType();
    this->objectNumber   = old.getObjectNumber();
    this->time           = old.getTime();
    this->callnumber     = old.getCallingNumber();
    this->callednumber   = old.getCalledNumber();
    this->EventID        = old.getEventID();
    this->SubEventID     = old.getSubEventID();
    this->RecordType     = old.getRecordType();
    this->cin            = old.getCallIdentityNumber(); //6
    this->operatorID     = old.getOperatorID(); //5
    this->liiD           = old.getLIID(); //22
    this->cCLiD          = old.getCCLinkID(); //6  /
    this->usetype        = old.getUseType();//usetType
    this->useresult      = old.getUseResult();
    this->sername        = old.getSerName();
    this->notification   = old.getNotification();
    this->calllndication = old.getCalllndication();
    this->capability     = old.getCapability(); //810
    this->facilityop     = old.getFacilityOp();
    this->genericnumber  = old.getGenericNumber();
    this->objectnumber1  = old.getObjectNumber1();
    this->gatewayid      = old.getGatewayId();
    this->firstcalling   = old.getFirstCalling();
    this->secondcalling  = old.getSecondCalling();
    this->NEId           = old.getNEID();
    this->IdMC           = old.getLEAID();
    this->dWReportId     = old.getDWReportID();
    this->delivered      = ( old.isDelivered() ) ? "1" : "0";
}


//Dat_SuplementaryServiceEvent::Dat_SuplementaryServiceEvent(QUpdateX2Event &updatex2event)
//{
//    //this->delivered  = updatex2event.getContentEventDelivered();
//    this->time       = updatex2event.getContentEventTime();
//    this->IdMC       = updatex2event.getContentEventLEAId();
//    this->dWReportId = updatex2event.getContentEventDWReportId();
//}


Dat_SuplementaryServiceEvent::~Dat_SuplementaryServiceEvent()
{
}

QString Dat_SuplementaryServiceEvent::generateDeleteStatement()
{
    return QString("DELETE FROM iri.dat_suplementaryserviceevent");
}


QString Dat_SuplementaryServiceEvent::generateInsertStatementNoSequence()
{
return QString("INSERT INTO iri.dat_suplementaryserviceevent"
               "(numtype,objectnumber,time,"
                "eventid,subeventid,callingnumber,callednumber,"
                 "recordtype,operatorid,cin, liid, cclid,usetype,"
                 "useresult,sername,calllndication,notification,"
                 "capability,facilityop,genericnumber,objectnumber1,"
                 "gatewayid,firstcalling,secondcalling, neid, idmc, dwreportid, delivered)" " values(") +

             (getNumType().length() == 0 ? QString("null") : QString("'") + escapeString(getNumType(),QChar('\\')) + QString("'"))
              + QString(",")+
              (getObjectNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectNumber(),QChar('\\')) + QString("'"))
              + QString(",")+
              (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'"))
              + QString(",")+
              (getEventID().length() == 0 ? QString("null") : QString("'") + escapeString(getEventID(),QChar('\\')) + QString("'"))
              + QString(",")+
              (getSubEventID().length() == 0 ? QString("null") : QString("'") + escapeString(getSubEventID(),QChar('\\')) + QString("'"))
              + QString(",")+
              (getCallnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallnumber(),QChar('\\')) + QString("'"))
              + QString(",")+
              (getCallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallednumber(),QChar('\\')) + QString("'"))
               + QString(",")+
              (getRecordType().length() == 0 ? QString("null") : QString("'") + escapeString(getRecordType(),QChar('\\')) + QString("'"))
               + QString(",")+
              (getOperatorID().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatorID(),QChar('\\')) + QString("'"))
               + QString(",")+
              (getCin().length() == 0 ? QString("null") : QString("'") + escapeString(getCin(),QChar('\\')) + QString("'"))
              + QString(",")+
              (getLiiD().length() == 0 ? QString("null") : QString("'") + escapeString(getLiiD(),QChar('\\')) + QString("'"))
               + QString(",")+
              (getCCLiD().length() == 0 ? QString("null") : QString("'") + escapeString(getCCLiD(),QChar('\\')) + QString("'"))
                + QString(",")+
              (getUsetype().length() == 0 ? QString("null") : QString("'") + escapeString(getUsetype(),QChar('\\')) + QString("'"))
              + QString(",")+
              (getUseresult().length() == 0 ? QString("null") : QString("'") + escapeString(getUseresult(),QChar('\\')) + QString("'"))
               + QString(",")+
              (getSername().length() == 0 ? QString("null") : QString("'") + escapeString(getSername(),QChar('\\')) + QString("'"))
               + QString(",")+
              (getCalllndication().length() == 0 ? QString("null") : QString("'") + escapeString(getCalllndication(),QChar('\\')) + QString("'"))
               + QString(",")+
               (getNotification().length() == 0 ? QString("null") : QString("'") + escapeString(getNotification(),QChar('\\')) + QString("'"))
                + QString(",")+
              (getCapability().length() == 0 ? QString("null") : QString("'") + escapeString(getCapability(),QChar('\\')) + QString("'"))
              + QString(",")+
              (getFacilityop().length() == 0 ? QString("null") : QString("'") + escapeString(getFacilityop(),QChar('\\')) + QString("'"))
               + QString(",")+
              (getGenericnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getGenericnumber(),QChar('\\')) + QString("'"))
               + QString(",")+
              (getObjectnumber1().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectnumber1(),QChar('\\')) + QString("'"))
               + QString(",")+
              (getGatewayid().length() == 0 ? QString("null") : QString("'") + escapeString(getGatewayid(),QChar('\\')) + QString("'"))
              + QString(",")+
              (getFirstcalling().length() == 0 ? QString("null") : QString("'") + escapeString(getFirstcalling(),QChar('\\')) + QString("'"))
              + QString(",")+
              (getSecondcalling().length() == 0 ? QString("null") : QString("'") + escapeString(getSecondcalling(),QChar('\\')) + QString("'"))
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

QString Dat_SuplementaryServiceEvent::generateUpdateStatement()
{
    return  QString("UPDATE iri.dat_suplementaryserviceevent SET NumType = ") + (getNumType().length() == 0 ? QString("null") : QString("'") + escapeString(getNumType(),QChar('\\')) + QString("'")) +
            QString(", objectNumber = ") + (getObjectNumber().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectNumber(),QChar('\\')) + QString("'")) +
            QString(", time = ") + (getTime().length() == 0 ? QString("null") : QString("'") + escapeString(getTime(),QChar('\\')) + QString("'")) +
            QString(", eventid = ") + (getEventID().length() == 0 ? QString("null") : QString("'") + escapeString(getEventID(),QChar('\\')) + QString("'")) +
            QString(", subeventid = ") + (getSubEventID().length() == 0 ? QString("null") : QString("'") + escapeString(getSubEventID(),QChar('\\')) + QString("'")) +
            QString(", callingnumber = ") + (getCallnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallnumber(),QChar('\\')) + QString("'")) +
            QString(", callednumber = ") + (getCallednumber().length() == 0 ? QString("null") : QString("'") + escapeString(getCallednumber(),QChar('\\')) + QString("'")) +
            QString(", recordtype = ") + (getRecordType().length() == 0 ? QString("null") : QString("'") + escapeString(getRecordType(),QChar('\\')) + QString("'")) +
            QString(", operatorid = ") + (getOperatorID().length() == 0 ? QString("null") : QString("'") + escapeString(getOperatorID(),QChar('\\')) + QString("'")) +
            QString(", cin = ") + (getCin().length() == 0 ? QString("null") : QString("'") + escapeString(getCin(),QChar('\\')) + QString("'")) +
            QString(", liid = ") + (getLiiD().length() == 0 ? QString("null") : QString("'") + escapeString(getLiiD(),QChar('\\')) + QString("'")) +
            QString(", cclid = ") + (getCCLiD().length() == 0 ? QString("null") : QString("'") + escapeString(getCCLiD(),QChar('\\')) + QString("'")) +
            QString(", usetype = ") + (getUsetype().length() == 0 ? QString("null") : QString("'") + escapeString(getUsetype(),QChar('\\')) + QString("'")) +
            QString(", useresult = ") + (getUseresult().length() == 0 ? QString("null") : QString("'") + escapeString(getUseresult(),QChar('\\')) + QString("'")) +
            QString(", sername = ") + (getSername().length() == 0 ? QString("null") : QString("'") + escapeString(getSername(),QChar('\\')) + QString("'")) +
            QString(", calllndication = ") + (getCalllndication().length() == 0 ? QString("null") : QString("'") + escapeString(getCalllndication(),QChar('\\')) + QString("'"));
            QString(", notification = ") + (getNotification().length() == 0 ? QString("null") : QString("'") + escapeString(getNotification(),QChar('\\')) + QString("'")) +
            QString(", capability = ") + (getCapability().length() == 0 ? QString("null") : QString("'") + escapeString(getCapability(),QChar('\\')) + QString("'")) +
            QString(", facilityop = ") + (getFacilityop().length() == 0 ? QString("null") : QString("'") + escapeString(getFacilityop(),QChar('\\')) + QString("'")) +
            QString(", genericnumber = ") + (getGenericnumber().length() == 0 ? QString("null") : QString("'") + escapeString(getGenericnumber(),QChar('\\')) + QString("'")) +
            QString(", objectnumber1 = ") + (getObjectnumber1().length() == 0 ? QString("null") : QString("'") + escapeString(getObjectnumber1(),QChar('\\')) + QString("'")) +
            QString(", gatewayid = ") + (getGatewayid().length() == 0 ? QString("null") : QString("'") + escapeString(getGatewayid(),QChar('\\')) + QString("'")) +
            QString(", firstcalling = ") + (getFirstcalling().length() == 0 ? QString("null") : QString("'") + escapeString(getFirstcalling(),QChar('\\')) + QString("'")) +
            QString(", secondcalling = ") + (getSecondcalling().length() == 0 ? QString("null") : QString("'") + escapeString(getSecondcalling(),QChar('\\')) + QString("'"));
}

QString Dat_SuplementaryServiceEvent::generateSelectStatement()
{
    return QString("SELECT"
                  " dat_ss.numtype,"
                  " dat_ss.objectnumber,"
                  " dat_ss.eventid,"
                   "dat_ss.time,"
                   "dat_ss.subeventid ,"
                   "dat_ss.callingnumber ,"
                   "dat_ss.callednumber,"
                   "dat_ss.recordtype ,"
                   "dat_ss.cin,"
                   "dat_ss.operatorid,"
                   "dat_ss.liid,"
                   "dat_ss.cclid,"
                   "dat_ss.usetype,"
                   "dat_ss.useresult,"
                   "dat_ss.sername,"
                   "dat_ss.notification,"
                   "dat_ss.calllndication,"
                   "dat_ss.capability,"
                   "dat_ss.facilityop,"
                   "dat_ss.objectnumber1,"
                   "dat_ss.genericnumber,"
                   "dat_ss.gatewayid,"
                   "dat_ss.firstcalling,"
                   "dat_ss.secondcalling,"                   
                   "dat_ss.dwreportid,"
                   "dat_ss.neid,"
                   "dat_ss.idmc,"
                   "dat_ss.id"
                   " FROM iri.dat_suplementaryserviceevent dat_ss ");
}

void Dat_SuplementaryServiceEvent::readRecord(QSqlQuery query)
    {

    this->NumType        = query.value(0).isNull() ? "" : query.value(0).toString();
    this->objectNumber   = query.value(1).isNull() ? "" : query.value(1).toString();
    this->time           = query.value(2).isNull() ? "" : query.value(2).toString();
    this->EventID        = query.value(3).isNull() ? "" : query.value(3).toString();
    this->SubEventID     = query.value(4).isNull() ? "" : query.value(4).toString();
    this->callnumber     = query.value(5).isNull() ? "" : query.value(5).toString();
    this->callednumber   = query.value(6).isNull()?"":query.value(6).toString();
    this->RecordType     = query.value(7).isNull()?"":query.value(7).toString();
    this->operatorID     = query.value(8).isNull()?"":query.value(8).toString();
    this->cin            = query.value(9).isNull()?"":query.value(9).toString();
    this->liiD           = query.value(10).isNull()?"":query.value(10).toString();
    this->cCLiD          = query.value(10).isNull()?"":query.value(10).toString();
    this->useresult      = query.value(11).isNull()?"":query.value(11).toString();
    this->sername        = query.value(12).isNull()?"":query.value(12).toString();
    this->calllndication = query.value(13).isNull()?"":query.value(13).toString();
    this->notification   = query.value(14).isNull()?"":query.value(14).toString();
    this->capability     = query.value(15).isNull()?"":query.value(15).toString();
    this->genericnumber  = query.value(16).isNull()?"":query.value(16).toString();
    this->objectnumber1  = query.value(17).isNull()?"":query.value(17).toString();
    this->gatewayid      = query.value(18).isNull()?"":query.value(18).toString();
    this->firstcalling   = query.value(19).isNull()?"":query.value(19).toString();
    this->secondcalling  = query.value(20).isNull()?"":query.value(20).toString();
    this->id             = query.value(21).isNull()?"":query.value(21).toString();

}

QString Dat_SuplementaryServiceEvent::generateUpdateDelivered()
{
   QString sql = "UPDATE iri.dat_suplementaryserviceevent SET delivered=" + QString("'") + this->getDelivered() + QString("'") ;
   sql += " WHERE (time=" + QString("'") + this->getTime() + QString("') AND (") + QString("dwreportid=") + this->getDWReportId() + QString(")");
   sql += " AND (idmc=" + getIdMC() + ")";
   return sql;
}

bool Dat_SuplementaryServiceEvent::insert(QSqlQuery *query)
{    
    QString sql = this->generateInsertStatementNoSequence();
    return query->exec( sql );
}


bool Dat_SuplementaryServiceEvent::deleteRecord(QSqlQuery *query)
{
    QString sql = this->generateDeleteStatement();
    return query->exec( sql );
}

bool Dat_SuplementaryServiceEvent::updateDelivered(QSqlQuery *query)
{
    QString sql = this->generateUpdateDelivered();    
    return query->exec( sql );
}


QStringList Dat_SuplementaryServiceEvent::generateFieldList()
        {
        QStringList	sl;

          sl+="numtype";
          sl+="objectnumber";
          sl+="eventid";
          sl+="time";
          sl+="subeventid";
          sl+="callnumber";
          sl+="callednumber";
          sl+="recordtype";
          sl+="cin";
          sl+="operatorid";
          sl+="liid";
          sl+="cclid";
          sl+="usetype";
          sl+="useresult";
          sl+="sername";
          sl+="notification";
          sl+="calllndication";
          sl+="capability";
          sl+="facilityop";
          sl+="objectnumber1";
          sl+="genericnumber";
          sl+="gatewayid";
          sl+="firstcalling";
          sl+="secondcalling";
          sl+="id";
          sl+="NEId";

        return sl;
        }

QString Dat_SuplementaryServiceEvent::escapeString(QString stData,QChar cEscapeCharacter)
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
QString    Dat_SuplementaryServiceEvent::getNumType()
{
    return this->NumType;
}
QString    Dat_SuplementaryServiceEvent::getObjectNumber(){
    return this->objectNumber;
}
QString    Dat_SuplementaryServiceEvent::getTime(){
    return this->time;
}
QString    Dat_SuplementaryServiceEvent::getCallnumber(){
    return this->callnumber;
}
QString    Dat_SuplementaryServiceEvent::getCallednumber(){
    return this->callednumber;
}
QString    Dat_SuplementaryServiceEvent::getEventID(){
    return this->EventID;
}
QString    Dat_SuplementaryServiceEvent::getSubEventID(){
    return this->SubEventID;
}

QString    Dat_SuplementaryServiceEvent::getRecordType(){
    return this->RecordType;
}
QString    Dat_SuplementaryServiceEvent::getCin(){
    return this->cin;
} //6
QString    Dat_SuplementaryServiceEvent::getOperatorID(){
    return this->operatorID;
} //5
QString    Dat_SuplementaryServiceEvent::getLiiD(){
    return this->liiD;
} //22
QString    Dat_SuplementaryServiceEvent::getCCLiD(){
    return this->cCLiD;
} //6  /
QString    Dat_SuplementaryServiceEvent::getUsetype(){
    return this->usetype;
}
QString    Dat_SuplementaryServiceEvent::getUseresult(){
    return this->useresult;
} //59 total
QString    Dat_SuplementaryServiceEvent::getSername(){
    return this->sername;
}
QString    Dat_SuplementaryServiceEvent::getNotification(){
    return this->notification;
}
QString    Dat_SuplementaryServiceEvent::getCalllndication(){
    return this->calllndication;
}
QString    Dat_SuplementaryServiceEvent::getCapability(){
    return this->capability;
} //810
QString    Dat_SuplementaryServiceEvent::getFacilityop(){
    return this->facilityop;
}
QString    Dat_SuplementaryServiceEvent::getGenericnumber(){
    return this->genericnumber;
}
QString    Dat_SuplementaryServiceEvent::getObjectnumber1(){
    return this->objectnumber1;
}
QString    Dat_SuplementaryServiceEvent::getGatewayid(){
    return this->gatewayid;
}
QString    Dat_SuplementaryServiceEvent::getFirstcalling(){
    return this->firstcalling;
}
QString    Dat_SuplementaryServiceEvent::getSecondcalling(){
    return this->secondcalling;
}

QString Dat_SuplementaryServiceEvent::getNEId()
{
    return this->NEId;
}

QString Dat_SuplementaryServiceEvent::getIdMC()
{
    return this->IdMC;
}

void    Dat_SuplementaryServiceEvent::setNumType(QString s){
    this->NumType=s;
}
void    Dat_SuplementaryServiceEvent::setObjectNumber(QString s){
    this->objectNumber=s;
}
void    Dat_SuplementaryServiceEvent::setTime(QString s){
    this->time=s;
}
void    Dat_SuplementaryServiceEvent::setCallingNumber(QString s){
    this->callnumber=s;
}
void    Dat_SuplementaryServiceEvent::setCalledNumber(QString s){
    this->callednumber=s;
}
void    Dat_SuplementaryServiceEvent::setEventID(QString s){
    this->EventID=s;
}
void    Dat_SuplementaryServiceEvent::setSubEventID(QString s){
    this->SubEventID=s;
}

void    Dat_SuplementaryServiceEvent::setRecordType(QString s){
    this->RecordType=s;
}
void    Dat_SuplementaryServiceEvent::setCin(QString s){
    this->cin=s;
} //6
void    Dat_SuplementaryServiceEvent::setOperatorID(QString s){
    this->operatorID=s;
} //5
void    Dat_SuplementaryServiceEvent::setLiiD(QString s){
    this->liiD=s;
} //22
void    Dat_SuplementaryServiceEvent::setCCLiD(QString s){
    this->cCLiD=s;
} //6  /
void    Dat_SuplementaryServiceEvent::setUsetype(QString s){
    this->usetype=s;
}
void    Dat_SuplementaryServiceEvent::setUseresult(QString s){
     this->useresult=s;
} //59 total
void    Dat_SuplementaryServiceEvent::setSername(QString s){
    this->sername=s;
}
void    Dat_SuplementaryServiceEvent::setNotification(QString s){
    this->notification=s;
}
void    Dat_SuplementaryServiceEvent::setCalllndication(QString s){
    this->calllndication=s;
}
void    Dat_SuplementaryServiceEvent::setCapability(QString s){
    this->capability=s;
} //810
void    Dat_SuplementaryServiceEvent::setFacilityop(QString s){
    this->facilityop=s;
}
void    Dat_SuplementaryServiceEvent::setGenericnumber(QString s){
    this->genericnumber=s;
}
void    Dat_SuplementaryServiceEvent::setObjectnumber1(QString s){
    this->objectnumber1=s;
}
void    Dat_SuplementaryServiceEvent::setGatewayid(QString s){
    this->gatewayid=s;
}
void    Dat_SuplementaryServiceEvent::setFirstcalling(QString s){
    this->firstcalling=s;
}
void    Dat_SuplementaryServiceEvent::setSecondcalling(QString s)
{
    this->secondcalling=s;
}

void Dat_SuplementaryServiceEvent::setDWReportId(QString s)
{
    this->dWReportId = s;
}

void   Dat_SuplementaryServiceEvent::setLEAId(QString s)
{
    this->IdMC = s;
}

QString Dat_SuplementaryServiceEvent::getDWReportId()
{
    return this->dWReportId;
}

void Dat_SuplementaryServiceEvent::setDelivered(QString s)
{
    this->delivered = s;
}

QString Dat_SuplementaryServiceEvent::getDelivered()
{
    return this->delivered;
}

QString Dat_SuplementaryServiceEvent::generateNotDeliveredStatement()
{
   QString where = QString(" WHERE (dat_ss.delivered = '0') AND (dat_ss.idmc = ") + this->getIdMC() + QString(")");
   return this->generateSelectStatement().append( where );;
}

QQueue<QEvent*> Dat_SuplementaryServiceEvent::getNotDeliveredEvents(QSqlQuery *query)
{
    QQueue<QEvent*> events;
    QString sql = this->generateNotDeliveredStatement();
    query->exec(sql);
    if( query->isActive() )
    {
       while ( query->next() )
       {
            SuplementaryServiceEvent *e = new SuplementaryServiceEvent;
            e->setNumType           ( (quint8)query->value(0).toInt() );
            e->setObjectNumber      ( query->value(1).toString() );
            e->setEventID           ( (quint8)query->value(2).toInt());
            e->setTime              ( query->value(3).toDateTime() );
            e->setSubEventID        ( (quint8)query->value(4).toInt() );
            e->setCallingNumber     ( query->value(5).toString() );
            e->setCalledNumber      ( query->value(6).toString() );
            e->setRecordType        ( (quint8)query->value(7).toInt() );
            e->setCallIdentityNumber( Utiles::QStringtoBCD( query->value(8).toString() ) );
            e->setOperatorID        ( Utiles::QStringtoBCD( query->value(9).toString() ) );
            e->setLIID              ( query->value(10).toString() );
            e->setCCLinkID          ( query->value(11).toString() );
            e->setUseType           ( query->value(12).toString()      );
            e->setUseResult         ( query->value(13).toString());
            e->setSerName           ( query->value(14).toString() );
            e->setNotification      ( query->value(15).toString() );
            e->setCalllndication    ( query->value(16).toString() );
            e->setCapability        ( query->value(17).toString());
            e->setFacilityOp        ( query->value(18).toString());
            e->setObjectNumber1     ( query->value(19).toString());
            e->setGenericNumber     ( query->value(20).toString() );
            e->setGatewayId         ( query->value(21).toString() );
            e->setFirstCalling      ( query->value(22).toString() );
            e->setSecondCalling     ( query->value(23).toString() );
            e->setDWReportID        ( query->value(24).toLongLong() );
            e->setNEID              ( query->value(25).toString() );
            e->setLEAID             ( query->value(26).toInt()  );
            e->setNMask             ( QString("") );
            e->setPendiente();
            events.append( e );
       }
    }
    return events;
}
