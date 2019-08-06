#ifndef X3_CHANNEL_MESSAGE_H_
#define X3_CHANNEL_MESSAGE_H_

//#include "../structs.h" // conjunto de estructura.
#include <QByteArray>
#include <QDateTime>
#include "fija_definitions.h"
#include "src/qx2event.h"

class ChannelControlEvent: public QX2Event
{
    public:

        ChannelControlEvent(QByteArray *byteArray): QX2Event(byteArray, QX2Event::CHANNEL_CONTROL_EVENT )
        {
            this->setValues( byteArray );
        }

        ChannelControlEvent(QX2Event &header, QByteArray* byteArray):QX2Event( header )
        {
            this->setValues( byteArray );
        }

        QString getNumType()
        {
             return QString().setNum( this->NumType );
        }

        QString getObjectNumber()
        {
            return this->objectNumber;
        }

        QString getTime( QString format = "yyyy-MM-ddThh:mm:ss")
        {
            this->time.toUTC();
            return this->time.toString( format );
        }

        QString getRelatedCallStartTime( QString format = "yyyy-MM-ddThh:mm:ss" )
        {
            this->RelatedCallStartTime.toUTC();
            return this->RelatedCallStartTime.toString( format );
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

        QString getLinkInfo()
        {
            return QString( this->LinkInfo );
        }

        QString getReason()
        {
            return QString().setNum( this->Reason );
        }

        QString getFlowDirection()
        {
            return QString( this->FlowDirection );
        }

        QString getResourceState()
        {
            return QString( this->ResourceState );
        }

        ChannelControlEvent(ChannelControlEvent &other):QX2Event( *static_cast<QX2Event*>(&other) )
        {
            this->nMask                 = other.nMask;
            this->NumType               = other.NumType;
            this->objectNumber          = other.objectNumber;
            this->elementID             = other.elementID; //17
            this->time                  = other.time;
            this->RelatedCallStartTime  = other.RelatedCallStartTime;
            this->CombineOrSplitFlag    = other.CombineOrSplitFlag; //130
            this->CallOrCalledFlag      = other.CallOrCalledFlag;
            this->CallID1               = other.CallID1;
            this->CallID2               = other.CallID2;
            this->EventID               = other.EventID;
            this->SubEventID            = other.SubEventID;
            this->CallingNumber         = other.CallingNumber;
            this->CalledNumber          = other.CalledNumber;
            this->RecordType            = other.RecordType;
            this->cin                   = other.cin; //p
            this->operatorID            = other.operatorID; //p
            this->liiD                  = other.liiD; //22
            this->LinkInfo              = other.LinkInfo;//p
            this->FlowDirection         = other.FlowDirection;//p
            this->ResourceState         = other.ResourceState; //758//p
            this->Reason                = other.Reason;
        }

        ~ChannelControlEvent()
        {           
            /*delete this->nMask;
            delete this->time;
            delete this->RelatedCallStartTime;
            delete this->cin;
            delete this->operatorID;
            delete this->LinkInfo;
            delete this->FlowDirection;
            delete this->ResourceState;*/
            cout<<"ChannelControlEvent::~ChannelControlEvent()"<<endl;
        }

      private:
        QByteArray nMask;
        quint8     NumType;
        QString    objectNumber;
        QString    elementID;
        QDateTime  time;
        QDateTime  RelatedCallStartTime;
        quint8     CombineOrSplitFlag;
        quint8     CallOrCalledFlag;        
        quint16    CallID1;
        quint16    CallID2;
        quint32    EventID;
        quint16    SubEventID;
        QString    CallingNumber;
        QString    CalledNumber;
        quint8     RecordType;
        QByteArray cin;
        QByteArray operatorID;
        QString    liiD;
        QByteArray LinkInfo;//ver esto
        quint32    Reason;
        QByteArray FlowDirection;
        QByteArray ResourceState;

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


            //--- ELEMENTID 17
              this->elementID = Utiles::getData(byteArray, 17);

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


            //--- FECHA HORA EN COMENZO LA LLAMADA              
              yy = Utiles::QByteArrayToInteger( new QByteArray( byteArray->left(2) ), QSysInfo::LittleEndian) ;
              // byteArray->remove(0, 2);
              mm  = (quint8)byteArray->at(2);
               //byteArray->remove(0, 1);
              dd  = (quint8)byteArray->at(3);
               //byteArray->remove(0, 1);
              h   = (quint8)byteArray->at(4);
              // byteArray->remove(0, 1);
              m   = (quint8)byteArray->at(5);
              // byteArray->remove(0, 1);
              s   = (quint8)byteArray->at(6);
              byteArray->remove(0, 7);

              this->RelatedCallStartTime.setDate(QDate(yy, mm, dd));
              this->RelatedCallStartTime.setTime(QTime(h, m, s));

            //--- CombineOrSplitFlag
              this->CombineOrSplitFlag = (quint8)byteArray->at(0);
              byteArray->remove(0, 1);

            //--- SI EL OBJETIVO FUE EL LLAMADOR O EL LLAMADO
              this->CallOrCalledFlag =  (quint8)byteArray->at(0);
              byteArray->remove(0, 1);

            //--- CALLID1
              this->CallID1 = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian);
              byteArray->remove(0, 2);
              if(this->CallID1 & 0xFFFF == 0xFFFF)
                 this->CallID1 = 0;

            //--- CALLID2
              this->CallID2 = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian);
              byteArray->remove(0, 2);
              if(this->CallID2 & 0xFFFF == 0xFFFF)
                 this->CallID2 = 0;

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


            //---   RECORD TYPE 1
            this->RecordType = (quint8)byteArray->at(0);
            byteArray->remove(0, 1);

            //--- Call identity number 6
            quint16 len = Utiles::QByteArrayToInteger( new QByteArray( byteArray->left(2) ), QSysInfo::LittleEndian);
            byteArray->remove(0, 2);
            this->cin = byteArray->left(len);
            byteArray->remove(0, 4);

            //--- OPERATOR ID           5
            len = Utiles::QByteArrayToInteger( new QByteArray( byteArray->left(2) ), QSysInfo::LittleEndian);
            byteArray->remove(0, 2);
            this->operatorID = byteArray->left(len);
            byteArray->remove(0, 3);

            //--- LIID                 22
            this->liiD  = Utiles::getData(byteArray, 22);

            //--- LINK INFO
            this->LinkInfo = byteArray->left(94);
            byteArray->remove(0, 94);

            //--- REASON               3
            this->Reason    = Utiles::QByteArrayToInteger(new QByteArray( byteArray->left(3) ), QSysInfo::LittleEndian);
            byteArray->remove(0, 3);

            //--- FLOW DIRECTION
            this->FlowDirection = byteArray->left(3);
            byteArray->remove(0, 3);

            //--- RESOURCE STATE
            this->ResourceState = byteArray->left(2);
            byteArray->remove(0, 2);

            /**
              VER ESTO TAMBIEN
            **/
            byteArray->clear();
        }

};

#endif /*X3_CHANNEL_MESSAGE_H_*/
