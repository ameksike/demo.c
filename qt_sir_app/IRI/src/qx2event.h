#ifndef QX2EVENT_H
#define QX2EVENT_H

    #include <QEvent>
    #include <QString>
    #include "src/Entity/Utils.h"
    #include <iostream>
    using namespace std;

    class QX2Event: public QEvent
    {
      public:
        /**
           PARA NORMALIZAR LOS EVENTOS  PRODUCIDOS EN X2
           EL VALOR TIENE QUE SER >= QEvent::User(1000) Y <=  QEvent::MaxUser(65535)
        **/
        typedef enum
        {
            // PARA PREPROCESAR EL COMANDO Y DETERMINAR CANT. DATOS RESTANTES
            PRE_PROCESS                 = QEvent::Type( QEvent::User + 1   ),

            CALL_RELATED_EVENT          = QEvent::Type( QEvent::User + 10  ),
            CHANNEL_CONTROL_EVENT       = QEvent::Type( QEvent::User + 20  ),
            SUPLEMENTARY_SERVICE_EVENT  = QEvent::Type( QEvent::User + 30  ),
            SHORT_MESSAGE_SERVICE_EVENT = QEvent::Type( QEvent::User + 40  ),
            USER_STATUS_EVENT           = QEvent::Type( QEvent::User + 50  ),
            QUERY_PRIVATE_EVENT         = QEvent::Type( QEvent::User + 60  ),
            HANDSHAKE_EVENT             = QEvent::Type( QEvent::User + 70  ),
            HANDOVER_EVENT              = QEvent::Type( QEvent::User + 80  ),
            MAX_X2_EVENT                = QEvent::Type( QEvent::User + 100 )
        } e_X2EVENT;

        QX2Event(QByteArray *byteArray, QX2Event::e_X2EVENT event = QX2Event::PRE_PROCESS):QEvent( QEvent::Type( event ) )
        {            
            this->setValues(byteArray);
            this->pendiente = false;
            this->delivered = false;
        }

        QX2Event(QX2Event &other):QEvent( other.type() )
        {                    
           this->eventType  = other.eventType;
           this->dwReportID = other.dwReportID;
           this->NEID       = other.NEID;
           this->LEAID      = other.LEAID;
           this->wLength    = other.wLength;
           this->pendiente  = other.pendiente;
           this->delivered  = other.delivered;
        }

        QX2Event(QX2Event::e_X2EVENT event = QX2Event::PRE_PROCESS):QEvent( QEvent::Type( event ) )
        {
        }

        virtual ~QX2Event()
        {
            cout<<"QX2Event::~QX2Event()"<<endl;
        }

        QString getEventType()
        {
           return QString().setNum( this->eventType );
        }

        QString getDWReportID()
        {
           return QString().setNum( this->dwReportID );
        }

        QString getNEID()
        {
           return this->NEID;
        }

        QString getLEAID()
        {
           return QString().setNum( this->LEAID );
        }

        quint16 getWLength()
        {
           return this->wLength;
        }
//----------------------------------------------------------
        void setEventType( quint8 et)
        {
           this->eventType = et;
        }

        void setDWReportID( quint32 reportId)
        {
           this->dwReportID = reportId ;
        }

        void setNEID(QString neid)
        {
           this->NEID = neid;
        }

        void setLEAID(quint16 leaid)
        {
           this->LEAID = leaid;
        }

        void setWLength( quint16 wlength)
        {
           this->wLength = wlength;
        }

        void setPendiente( bool pendiente = true)
        {
            this->pendiente = pendiente;
        }

        bool estabaPendiente()
        {
            return this->pendiente;
        }

        bool isDelivered()
        {
            return this->delivered;
        }

        void setDelivered( bool delivered = true )
        {
            this->delivered = delivered;
        }

      protected:
        quint8  eventType;
        quint32 dwReportID;
        QString NEID;
        quint16 LEAID;
        quint16 wLength;
        bool pendiente;
        bool delivered;

        void setValues(QByteArray *byteArray)
        {            
           this->eventType  = (quint8)byteArray->at(0);
           byteArray->remove(0, 1);

           if( (this->eventType & 0xFF) == 0xFF )
               this->eventType = 0;

           this->dwReportID = Utiles::QByteArrayToInteger( & byteArray->left(4) , QSysInfo::LittleEndian);
           byteArray->remove(0, 4);

           qDebug()<<"getData campo NEID";
           this->NEID       = Utiles::getData(byteArray, 42);

           this->LEAID      = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian);
           byteArray->remove(0, 2);

           this->wLength    = Utiles::QByteArrayToInteger( &byteArray->left(2), QSysInfo::LittleEndian);
           byteArray->remove(0, 2);
        }
    };

#endif // QX2EVENT_H
