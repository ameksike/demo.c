
#ifndef SSNOTIFICATION_H_
#define SSNOTIFICATION_H_


//#include "../structs.h" // conjunto de estructura.
#include <QByteArray>
#include <QDateTime>
#include "fija_definitions.h"
#include "qx2event.h"

class SuplementaryServiceEvent: public QX2Event
{
  public :
      SuplementaryServiceEvent(QByteArray *byteArray):QX2Event(/*byteArray,*/ QX2Event::SUPLEMENTARY_SERVICE_EVENT)
      {
          this->setValues( byteArray );
      }

      SuplementaryServiceEvent(QX2Event &header, QByteArray* byteArray):QX2Event( header )
      {
          this->setValues( byteArray );
      }

      SuplementaryServiceEvent():QX2Event(QX2Event::SUPLEMENTARY_SERVICE_EVENT)
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

      QString getUseType()
      {
          return QString().setNum( Utiles::QByteArrayToInteger( &this->UseType, QSysInfo::LittleEndian) );
      }

      QString getUseResult()
      {
          return QString().setNum( Utiles::QByteArrayToInteger( &this->UseResult, QSysInfo::LittleEndian) );
      }

      QString getSerName()
      {
          return QString().setNum( Utiles::QByteArrayToInteger( &this->SerName, QSysInfo::LittleEndian) );
      }

      QString getNotification()
      {
          return QString( this->Notification );
      }

      QString getCalllndication()
      {
          return QString( this->Calllndication );
      }

      QString getFacilityOp()
      {
          return QString( this->FacilityOp );
      }

      QString getGenericNumber()
      {
          return QString( this->GenericNumber );
      }

      QString getCapability()
      {
          return QString( this->Capability );
      }

      QString getObjectNumber1()
      {
          return this->ObjectNumber1;
      }

      QString getGatewayId()
      {
          return this->GatewayId;
      }

      QString getFirstCalling()
      {
          return this->FirstCalling;
      }

      QString getSecondCalling()
      {
          return this->SecondCalling;
      }

      QByteArray* getNMask()
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
          this->time =  dt;
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

      void setCallIdentityNumber(QString s)
      {
          this->cin = QByteArray(s.toStdString().c_str(), s.toStdString().length());
      }

      void setOperatorID( QString s)
      {
          this->operatorID = QByteArray(s.toStdString().c_str(), s.toStdString().length());;
      }

      void setLIID (QString liid)
      {
          this->liiD = liid;
      }

      void setCCLinkID( QString s)
      {
          this->cCLiD = QByteArray(s.toStdString().c_str(), s.toStdString().length());
      }

      void setGenericNumber(QString s)
      {
          this->GenericNumber = QByteArray(s.toStdString().c_str(), s.toStdString().length());
      }

      void setNMask(QString s)
      {
          this->nMask = QByteArray(s.toStdString().c_str(), s.toStdString().length());
      }

      void setUseType(QString s)
      {
          this->UseType = QByteArray(s.toStdString().c_str(), s.toStdString().length());
      }

      void setUseResult(QString s)
      {
          this->UseResult = QByteArray(s.toStdString().c_str(), s.toStdString().length());
      }

      void setSerName(QString s)
      {
          this->SerName = QByteArray(s.toStdString().c_str(), s.toStdString().length());
      }

      void setNotification(QString s)
      {
          this->Notification = QByteArray(s.toStdString().c_str(), s.toStdString().length());
      }

      void setCalllndication(QString s)
      {
          this->Calllndication = QByteArray(s.toStdString().c_str(), s.toStdString().length());
      }

      void setFacilityOp(QString s)
      {
          this->FacilityOp = QByteArray(s.toStdString().c_str(), s.toStdString().length());
      }

      void setCapability(QString s)
      {
          this->Capability = QByteArray(s.toStdString().c_str(), s.toStdString().length());
      }

      void setObjectNumber1(QString s)
      {
          this->ObjectNumber1 = s;
      }

      void setGatewayId(QString s)
      {
          this->GatewayId = s;
      }

      void setFirstCalling(QString s)
      {
          this->FirstCalling = s;
      }

      void setSecondCalling(QString s)
      {
          this->SecondCalling = s;
      }

      SuplementaryServiceEvent(SuplementaryServiceEvent &other):QX2Event( *static_cast<QX2Event*>(&other) )
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
          this->UseType            = other.UseType;//p
          this->UseResult          = other.UseResult;//p
          this->SerName            = other.SerName;//p
          this->Notification       = other.Notification;//p
          this->Calllndication     = other.Calllndication;//p
          this->FacilityOp         = other.FacilityOp; //p
          this->GenericNumber      = other.GenericNumber; //p
          this->Capability         = other.Capability;//p
          this->ObjectNumber1      = other.ObjectNumber1;
          this->GatewayId          = other.GatewayId;
          this->FirstCalling       = other.FirstCalling;
          this->SecondCalling      = other.SecondCalling;
          this->LEAID              = other.LEAID;
      }

      ~SuplementaryServiceEvent()
      {         
      }

    private:
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
      QByteArray UseType;//4
      QByteArray UseResult;//4
      QByteArray SerName;//4
      QByteArray Notification;//203
      QByteArray Calllndication;//2
      QByteArray FacilityOp;//4
      QByteArray GenericNumber; //203
      QByteArray Capability;//203
      QString    ObjectNumber1;//34
      QString    GatewayId;//17
      QString    FirstCalling;//36
      QString    SecondCalling;//36

    protected:

      void setValues( QByteArray *byteArray)
      {
          //--- MASCARA
            this->nMask  = byteArray->left(4);
            byteArray->remove(0, 4);

          //--- TIPO DE NUMERO
            this->NumType = (quint8)byteArray->at(0);
            byteArray->remove(0, 1);

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

          //--- EVENTID
            this->EventID = Utiles::QByteArrayToInteger( &byteArray->left(4), QSysInfo::LittleEndian);
            byteArray->remove(0, 4);
          //--- SUBEVENTID
            this->SubEventID = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian);
            byteArray->remove(0, 2);

            /*
                  LLAMADOR

                  Esta campo está compuesto por dos subcampos:
                     CallingNumberLength = 2  bytes(indica bytes válidos en CallingNumber)
                     CallingNumber       = 32 bytes(ASCII)

                  !!!   Hay 2 bytes antes del  CallingNumberLength ver después

            */
              //!!!
              byteArray->remove(0, 2);
              this->CallingNumber = Utiles::getData(byteArray, 34);

              Utiles::filtrarCodigos( this->CallingNumber );

            /*
                LLAMADO

                Esta campo está compuesto por dos subcampos:
                   CalledNumberLength = 2  bytes(indica bytes válidos en CalledNumber)
                   CalledNumber       = 32 bytes(ASCII)

                !!!   Hay 2 bytes antes del  CalledNumberLength ver después

            */
              //!!!
              byteArray->remove(0, 2);
              this->CalledNumber  = Utiles::getData(byteArray, 34);

              Utiles::filtrarCodigos( this->CalledNumber );

          //---   RECORD TYPE
            this->RecordType = (quint8)byteArray->at(0);
            byteArray->remove(0, 1);

          //--- Call identity number 6
              quint16 len = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian);
              byteArray->remove(0, 2);              
              this->cin = byteArray->left(len);
              byteArray->remove(0, 4);

          //--- OPERATOR ID           5
              len = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian);
              byteArray->remove(0, 2);              
              this->operatorID = byteArray->left(len);
              byteArray->remove(0, 3);


          //--- LIID                 22
            this->liiD  = Utiles::getData(byteArray, 22);

          //--- CCLID                6
            len = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian);
            byteArray->remove(0, 2);
            this->cCLiD = byteArray->left(len);
            byteArray->remove(0, 4);

          //--- UseType
            this->UseType = byteArray->left(4);
            byteArray->remove(0, 4);            

          //--- UseResult 4
            this->UseResult = byteArray->left(4);
            byteArray->remove(0, 4);

          //--- SerName
            this->SerName = byteArray->left(4);
            byteArray->remove(0, 4);

          /** ESTA INFORMACION ACTUALMENTE ESTA LLEGANDO VACIA **/
          //--- Notification 203
            //this->Notification   = byteArray->left(203);
            byteArray->remove(0, 203);
         /** ************************************************* **/

          //--- Calllndcation 2
            this->Calllndication = byteArray->left(2);
            byteArray->remove(0, 2);

          /** ESTA INFORMACION ACTUALMENTE ESTA LLEGANDO VACIA **/
          //--- Capability           203
            //this->Capability   = byteArray->left(203);
            byteArray->remove(0, 203);
          /** ************************************************* **/

          //--- FacilityOp 4
            this->FacilityOp = byteArray->left(4);
            byteArray->remove(0, 4);

          /** ESTA INFORMACION ACTUALMENTE ESTA LLEGANDO VACIA **/
          //--- GenericNumber        203
            //this->GenericNumber = byteArray->left(203);
            byteArray->remove(0, 203);
          /** ************************************************* **/

          //--- ObjectNumber1     34            
            this->ObjectNumber1 = Utiles::getData(byteArray, 34);

          //--- GatewayId     17
            this->GatewayId = Utiles::getData(byteArray, 17);

          //--- FirstCalling  36
            byteArray->remove(0, 2);
            this->FirstCalling   = Utiles::getData(byteArray, 34);

          //--- SecondCalling      36
            byteArray->remove(0, 2);
            this->SecondCalling  = Utiles::getData(byteArray, 34);

            /**
              VER ESTO TAMBIEN
            **/
            byteArray->clear();
        }
};

#endif /*SSNOTIFICATIONNGN_H_*/
