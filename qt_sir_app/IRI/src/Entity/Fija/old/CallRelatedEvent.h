#ifndef DATCALLRELATEDEVENT_H_
#define DATCALLRELATEDEVENT_H_

#include <QByteArray>
#include <QDateTime>
#include "fija_definitions.h"
#include "qx2event.h"
#include <QDebug>
#include <QtEndian>


/*
 +X2Event
 */

class CallRelatedEvent: public QX2Event
{
  public:
    CallRelatedEvent(QByteArray *byteArray):QX2Event(/*byteArray, */QX2Event::CALL_RELATED_EVENT )
    {
        this->setValues( byteArray );
    }

    CallRelatedEvent(QX2Event &header, QByteArray* byteArray):QX2Event( header )
    {
        this->setValues( byteArray );
    }

    CallRelatedEvent():QX2Event( QX2Event::CALL_RELATED_EVENT )
    {
    }

    ~CallRelatedEvent()
    {

    }

    QString getNumType()
    {
         return QString().setNum( this->NumType );
    }

    QString getObjectNumber()
    {
        return this->objectNumber;
    }

    QString getTime( QString format = "yyyy-MM-ddThh:mm:ss" )
    {
        this->time.toUTC();
        return this->time.toString( format );
    }

    QString getCallOrCalledFlag()
    {
        return QString().setNum( this->CallOrCalledFlag );
    }

    QString getCallingNumber()
    {
        return this->CallingNumber;
    }

    QString getCalledNumber()
    {
        return this->CalledNumber;
    }

    QString getCallID1()
    {
        return QString().setNum( this->CallID1 );
    }

    QString getCallID2()
    {
        return QString().setNum( this->CallID2 );
    }

    QString getEventID()
    {
        return QString().setNum( this->EventID );
    }

    QString getSubEventID()
    {
        return QString().setNum( this->SubEventID );
    }

    QString getCombineOrSplitFlag()
    {
        return QString().setNum( this->CombineOrSplitFlag );
    }

    QString getElementID()
    {
        return this->elementID;
    }

    QString getRecordType()
    {
        return QString().setNum( this->RecordType );
    }

    QString getCallIdentityNumber()
    {
        return Utiles::QByteArrayBCDToDecimal( &this->cin );
    }

    QString getOperatorID()
    {
        return Utiles::QByteArrayBCDToDecimal( &this->operatorID );
    }

    QString getLIID()
    {
        return this->liiD;
    }

    QString getCCLinkID()
    {
        return QString( this->cCLiD );
    }

    QString getCallState()
    {
        return QString().setNum( this->CallState );
    }

    QString getNatureCall()
    {
        return QString().setNum( this->Naturecall );
    }

    QString getCapability()
    {
        return QString( this->Capability );
    }

    QString getCallingSubAddr()
    {
        return QString( this->CallingSubAdd );
    }

    QString getCalledSubAddr()
    {
        return QString( this->CalledSubAdd );
    }

    QString getGenericNumber()
    {
        return QString( this->GenericNumber );
    }

    QString getRedirectingNumber()
    {
        return this->RedirectingNumber;
    }

    QString getRedirectionNumber()
    {
        return this->RedirectionNumber;
    }

    QString getRedirectionInfo()
    {
        return QString( this->RedirectionInfo );
    }

    QString getOriginalCalledNumber()
    {
        return this->OrgCalledNumber;
    }

    QString getDiversionInfo()
    {
        return QString( this->DiversionInfo );
    }

    QString getConnectedSubAddr()
    {
        return QString( this->ConnectedSubAdd );
    }

    QString getConnectedNumber()
    {
        return this->ConnectedNumber;
    }

    QString getRingDuration()
    {
        return QString().setNum( this->RingDuration );
    }

    QString getReason()
    {
        return QString( this->Reason );
    }

    QByteArray *getNMask()
    {
        return &this->nMask;
    }

    /** **************************************************************** **/
    void setNumType( quint8 t)
    {
         this->NumType = t;
    }

    void setObjectNumber(QString s)
    {
        this->objectNumber = s;
    }

    void setTime( QDateTime dt )
    {        
        this->time =  dt ;
    }

    void setCallOrCalledFlag( quint8 callOrCalled )
    {
        this->CallOrCalledFlag = callOrCalled;
    }

    void setCallingNumber(QString callingNumber)
    {
        this->CallingNumber = callingNumber;
    }

    void setCalledNumber(QString  calledNumber)
    {
        this->CalledNumber = calledNumber;
    }

    void setCallID1( quint16 callId1)
    {
        this->CallID1 = callId1;
    }

    void setCallID2(quint16 callId2)
    {
        this->CallID2 = callId2;
    }

    void setEventID(quint8 eventId)
    {
        this->EventID  = eventId;
    }

    void setSubEventID( quint8 subEventId)
    {
        this->SubEventID  = subEventId;
    }

    void setCombineOrSplitFlag( quint8 combineOrSplit)
    {
        this->CombineOrSplitFlag = combineOrSplit;
    }

    void setElementID(QString elementId)
    {
        this->elementID = elementId;
    }

    void setRecordType( quint8 rt)
    {
        this->RecordType  = rt;
    }

    void setCallIdentityNumber( QByteArray cin)
    {
        this->cin = cin;
    }

    void setOperatorID( QByteArray operatorId )
    {
        this->operatorID = operatorId;
    }

    void setLIID (QString liid)
    {
        this->liiD = liid;
    }

    void setCCLinkID( QString s)
    {
        this->cCLiD = QByteArray(s.toStdString().c_str(), s.toStdString().length());
    }

    void setCallState( quint8 callState)
    {
        this->CallState = callState;
    }

    void setNatureCall( quint8 natureCall)
    {
        this->Naturecall  = natureCall;
    }

    void setCapability( QString s)
    {
        this->Capability = QByteArray(s.toStdString().c_str(), s.toStdString().length());
    }

    void setCallingSubAddr(QString s)
    {
        this->CallingSubAdd =  QByteArray(s.toStdString().c_str(), s.toStdString().length());
    }

    void setCalledSubAddr(QString s)
    {
        this->CalledSubAdd  = QByteArray(s.toStdString().c_str(), s.toStdString().length());
    }

    void setGenericNumber(QString s)
    {
        this->GenericNumber = QByteArray(s.toStdString().c_str(), s.toStdString().length());
    }

    void setRedirectingNumber(QString redirectingNumber)
    {
        this->RedirectingNumber = redirectingNumber;
    }

    void setRedirectionNumber(QString redirectionNumber)
    {
        this->RedirectionNumber = redirectionNumber;
    }

    void setRedirectionInfo(QString s)
    {
        this->RedirectionInfo = QByteArray(s.toStdString().c_str(), s.toStdString().length());
    }

    void setOriginalCalledNumber(QString orgCalledNumber)
    {
        this->OrgCalledNumber = orgCalledNumber;
    }

    void setDiversionInfo(QString s)
    {
       this->DiversionInfo = QByteArray(s.toStdString().c_str(), s.toStdString().length());
    }

    void setConnectedSubAddr(QString s)
    {
        this->ConnectedSubAdd = QByteArray(s.toStdString().c_str(), s.toStdString().length());
    }

    void setConnectedNumber(QString connectedNumber)
    {
        this->ConnectedNumber = connectedNumber;
    }

    void setRingDuration(QString s)
    {
        this->RingDuration = s.toLong();
    }

    void setReason(QString s)
    {
        this->Reason  = QByteArray(s.toStdString().c_str(), s.toStdString().length());
    }

    void setNMask(QString s)
    {
        this->nMask = QByteArray(s.toStdString().c_str(), s.toStdString().length());
    }

    CallRelatedEvent(CallRelatedEvent &other):QX2Event( *static_cast<QX2Event*>(&other) )
    {
        this->nMask              = other.nMask;
        this->NumType            = other.NumType;
        this->objectNumber       = other.objectNumber;
        this->time               = other.time;
        this->CallOrCalledFlag   = other.CallOrCalledFlag;
        this->CallingNumber      = other.CallingNumber;
        this->CalledNumber       = other.CalledNumber;
        this->CallID1            = other.CallID1;
        this->CallID2            = other.CallID2;
        this->EventID            = other.EventID;
        this->SubEventID         = other.SubEventID;
        this->CombineOrSplitFlag = other.CombineOrSplitFlag; //130
        this->elementID          = other.elementID; //17
        this->RecordType         = other.RecordType;        
        this->cin                = other.cin; //p
        this->operatorID         = other.operatorID; //p
        this->liiD               = other.liiD; //22
        this->cCLiD              = other.cCLiD; //p  /
        this->CallState          = other.CallState;
        this->Naturecall         = other.Naturecall; //59 total
        this->Capability         = other.Capability;//p
        this->CallingSubAdd      = other.CallingSubAdd;//p
        this->CalledSubAdd       = other.CalledSubAdd;//p
        this->GenericNumber      = other.GenericNumber; //p
        this->RedirectingNumber  = other.RedirectingNumber;
        this->RedirectionNumber  = other.RedirectionNumber;
        this->RedirectionInfo    = other.RedirectionInfo;//p
        this->OrgCalledNumber    = other.OrgCalledNumber;
        this->DiversionInfo      = other.DiversionInfo;//p
        this->ConnectedSubAdd    = other.ConnectedSubAdd;//p
        this->ConnectedNumber    = other.ConnectedNumber;
        this->RingDuration       = other.RingDuration;
        this->Reason             = other.Reason; //758//p
    }

    QByteArray nMask;
    quint8     NumType;
    QString    objectNumber;    
    QDateTime  time;
    quint8     CallOrCalledFlag;
    QString    CallingNumber;
    QString    CalledNumber;
    quint16    CallID1;
    quint16    CallID2;
    quint32    EventID;
    quint16    SubEventID;
    quint8     CombineOrSplitFlag; //130
    QString    elementID; //17
    quint8     RecordType;
    QByteArray cin; //6
    QByteArray operatorID; //5
    QString    liiD; //22
    QByteArray cCLiD; //6  /
    quint8     CallState;
    quint8     Naturecall; //59 total
    QByteArray Capability;
    QByteArray CallingSubAdd;
    QByteArray CalledSubAdd;
    QByteArray GenericNumber; //810
    QString    RedirectingNumber;
    QString    RedirectionNumber;
    QByteArray RedirectionInfo;
    QString    OrgCalledNumber;
    QByteArray DiversionInfo;
    QByteArray ConnectedSubAdd;
    QString    ConnectedNumber;
    quint32    RingDuration;
    QByteArray Reason; //758

  public:

    void setValues( QByteArray *byteArray)
    {

        //--- MASCARA
          this->nMask  = byteArray->left(4);
          byteArray->remove(0, 4);

        //--- TIPO DE NUMERO
          this->NumType = (quint8)byteArray->at(0);
          byteArray->remove(0, 1);

          qDebug()<<"getData campo OBJETIVO";
        //--- OBJETIVO          
         this->objectNumber = Utiles::getData(byteArray, 34);

        //--- FECHA HORA DEL EVENTO

          quint16 yy = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian) ;
         // byteArray->remove(0, 2);
          quint8 mm  = (quint8)byteArray->at(2);
          //byteArray->remove(0, 1);
          quint8 dd  = (quint8)byteArray->at(3);
          //byteArray->remove(0, 1);
          quint8 h   = (quint8)byteArray->at(4);
         // byteArray->remove(0, 1);
          quint8 m   = (quint8)byteArray->at(5);
         // byteArray->remove(0, 1);
          quint8 s   = (quint8)byteArray->at(6);
          byteArray->remove(0, 7);

          this->time.setDate(QDate(yy, mm, dd));
          this->time.setTime(QTime(h, m, s));


        //--- SI EL OBJETIVO FUE EL LLAMADOR O EL LLAMADO
          this->CallOrCalledFlag =  (quint8)byteArray->at(0);
          byteArray->remove(0, 1);


        /*
              LLAMADOR

              Esta campo está compuesto por dos subcampos:
                 CallingNumberLength = 2  bytes(indica bytes válidos en CallingNumber)
                 CallingNumber       = 32 bytes(ASCII)

              !!!   Hay 2 bytes antes del  CallingNumberLength ver después

        */
          //!!!
          qDebug()<<"getData campo CallingNumber";
          byteArray->remove(0, 2);
          this->CallingNumber = Utiles::getData(byteArray, 34);

          //Utiles::filtrarCodigos( this->CallingNumber );

        /*
            LLAMADO

            Esta campo está compuesto por dos subcampos:
               CalledNumberLength = 2  bytes(indica bytes válidos en CalledNumber)
               CalledNumber       = 32 bytes(ASCII)

            !!!   Hay 2 bytes antes del  CalledNumberLength ver después

        */
          //!!!
           qDebug()<<"getData campo CalledNumber";
          byteArray->remove(0, 2);
          this->CalledNumber  = Utiles::getData(byteArray, 34);

          //Utiles::filtrarCodigos( this->CalledNumber );

        //--- CALLID1
          this->CallID1 = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian);
          byteArray->remove(0, 2);
          if( this->CallID1 & 0xFFFF == 0xFFFF )// esto lo da la mascara ver despues
            this->CallID1 = 0;

        //--- CALLID2
          this->CallID2 = Utiles::QByteArrayToInteger( &byteArray->left(2) , QSysInfo::LittleEndian);
          byteArray->remove(0, 2);
          if( this->CallID2 & 0xFFFF == 0xFFFF )// esto lo da la mascara ver despues
            this->CallID2 = 0;

        //--- EVENTID
          this->EventID = Utiles::QByteArrayToInteger( &byteArray->left(4), QSysInfo::LittleEndian);
          byteArray->remove(0, 4);
          if( this->EventID & 0xFFFFFFFF ==  0xFFFFFFFF )// esto lo da la mascara ver despues
            this->EventID = 0;

        //--- SUBEVENTID
          this->SubEventID = Utiles::QByteArrayToInteger( &byteArray->left(2) , QSysInfo::LittleEndian);
          byteArray->remove(0, 2);
          if( this->SubEventID & 0xFFFF == 0xFFFF )// esto lo da la mascara ver despues
            this->SubEventID = 0;

        //--- CombineOrSplitFlag
          this->CombineOrSplitFlag = (quint8)byteArray->at(0);
          byteArray->remove(0, 1);

         qDebug()<<"getData campo elementID";
        //--- ELEMENTID 17
          this->elementID = Utiles::getData(byteArray, 17);

        //---   RECORD TYPE 1
          this->RecordType = (quint8)byteArray->at(0);
          byteArray->remove(0, 1);        

        //--- Call identity number(CIN) 6
          quint16 len = Utiles::QByteArrayToInteger( &byteArray->left(2) , QSysInfo::LittleEndian);
          byteArray->remove(0, 2);
          qDebug()<<"Cin len: "<<len;
          if(len > 4)
          {
              qWarning()<<"longitud del cin > 4";
              len = 4;
          }
          this->cin = byteArray->left(len);
          byteArray->remove(0, 4);

        //--- OPERATOR ID           5
          len = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian);
          byteArray->remove(0, 2);
          if(len > 3)
          {
              qWarning()<<"longitud del operator id > 3";
              len = 3;
          }
          this->operatorID = byteArray->left(len);
          byteArray->remove(0, 3);

         qDebug()<<"getData campo LIID";
        //--- LIID                 22
          this->liiD  = Utiles::getData(byteArray, 22);

        //--- CCLID                6
          len = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian);
          byteArray->remove(0, 2);
          if(len > 4)
          {
              qWarning()<<"longitud del cclid > 4";
              len = 4;
          }
          this->cCLiD = byteArray->left(len);
          byteArray->remove(0, 4);

        //--- CALLSTATE            1
          this->CallState  = (quint8)byteArray->at(0);
          byteArray->remove(0, 1);

        //--- NatureCall           1
          this->Naturecall = (quint8)byteArray->at(0);
          byteArray->remove(0, 1);//155

        /**  ESTA INFORMACION ACTUALMENTE ESTA LLEGANDO VACIA   **/
        //--- Capability           203
          //this->Capability   = byteArray->left(203);
          //byteArray->remove(0, 203);

        //--- CallingSubAdd        202
          //this->CallingSubAdd = byteArray->left(202);
          //byteArray->remove(0, 202);

        //--- CalledSubAdd         202
          //this->CalledSubAdd  = byteArray->left(202);
          //byteArray->remove(0, 202);

        //--- GenericNumber        203
          //this->GenericNumber  = byteArray->left(203);
          //byteArray->remove(0, 203);

          byteArray->remove(0, 810);
        /** *************************************************   **/

          qDebug()<<"getData campo redirectingnumber";
        //--- RedirectingNumber     36 - 2
          byteArray->remove(0, 2);//!!! ver
          this->RedirectingNumber = Utiles::getData(byteArray, 34);

          qDebug()<<"getData campo redirectionnumber";
        //--- RedirectionNumber     36 - 2
          byteArray->remove(0, 2);//!!! ver
          this->RedirectionNumber = Utiles::getData(byteArray, 34);

        //--- RedirctionInfo       202
          this->RedirectionInfo   = byteArray->left(202);
          byteArray->remove(0, 202);

          qDebug()<<"getData campo orgcallednumber";
        //--- OrgCalledNumber      36 - 2
          byteArray->remove(0, 2);
          this->OrgCalledNumber   = Utiles::getData(byteArray, 34);
          
        /** ESTA INFORMACION ACTUALMENTE ESTA LLEGANDO VACIA   **/
        //--- DiversionInfo        203
          //this->DiversionInfo     = 0;byteArray->left(203);
          //byteArray->remove(0, 203);

        //--- ConnectedSubAdd      202
          //this->ConnectedSubAdd   = byteArray->left(202);
          //byteArray->remove(0, 202);
          byteArray->remove(0, 405);
        /** *************************************************  **/

        //--- ConnectedNumber      36 - 2
          byteArray->remove(0, 2);//!!! ver
          this->ConnectedNumber   = Utiles::getData(byteArray, 34);

        //--- RingDuration         4
          this->RingDuration      = Utiles::QByteArrayToInteger(&byteArray->left(4), QSysInfo::LittleEndian);
          byteArray->remove(0, 4);

        //--- REASON               3
          this->Reason    = byteArray->left(3);
          byteArray->remove(0, 3);

          /**
              RESTAN 2 BYTES, NO TIENE CAMPO DEFINIDO EN
              LA DOCUMENTACION. !!! VER DESPUES !!!
          **/
          //byteArray->clear();
      }
};

#endif /*DATCALLRELATEDEVENT_H_*/
