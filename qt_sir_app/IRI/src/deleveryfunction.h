#ifndef DELEVERYFUNCTION_H
#define DELEVERYFUNCTION_H

    #include <QThread>
    #include <iostream>
    #include "irirecord.h"

    #include "SERVICE/DataAcces/Query.h"
    #include "servicio.h"

    #include <QSet>

    #include "qx2event.h"

    using namespace std;

    class DeliveryFunctionPrivate : public QObject
    {
        Q_OBJECT
      public:
        typedef enum
        {
           FTP_DELIVERY_MECHANISM,
           ROSE_DELIVERY_MECHANISM
        } DeliveryMechanism;

        DeliveryFunctionPrivate( DeliveryMechanism dm = FTP_DELIVERY_MECHANISM);

        ~DeliveryFunctionPrivate()
        {
            delete this->query;
        }

      private:
        DeliveryMechanism deliveryMechanism;
        Query *query;
        QHash<QString, Servicio*> centrosMonitoreo;
        QHash<QString, Servicio*> centrosMonitoreoActivos;

        void cargarCentrosMonitoreo();

      private slots:
        void nuevoEvento(QEvent *);

      private:
        void procesarEvento(QEvent *);
    };


    class DeliveryFunction: public QThread
    {
        Q_OBJECT
      public:
        DeliveryFunction(){}

      signals:
        /**  senal para pasar los eventos al  hilo  **/
        void nuevoEvento(QEvent *);

      protected:
        bool event(QEvent *e)
        {
            if( (e->type() > QEvent::User ) && (e->type() < QX2Event::MAX_X2_EVENT) )
            {
                QX2Event *_e = NULL;
                if( e->type() == QX2Event::CALL_RELATED_EVENT )
                  _e = new CallRelatedEvent( *static_cast<CallRelatedEvent*>( e ) );

                if( e->type() == QX2Event::CHANNEL_CONTROL_EVENT )
                  _e = new ChannelControlEvent( *static_cast<ChannelControlEvent*>( e ) );

                if( e->type() == QX2Event::SUPLEMENTARY_SERVICE_EVENT )
                  _e = new SuplementaryServiceEvent( *static_cast<SuplementaryServiceEvent*>( e ) );

                if( _e )
                {
                   emit nuevoEvento( _e );
                   return true;
                }                
            }            
            return QThread::event( e );
        }

        void run()
        {
            cout<<"[Delivery function started]"<<endl;
            DeliveryFunctionPrivate *df = new DeliveryFunctionPrivate;
            connect(this, SIGNAL(nuevoEvento(QEvent*)), df, SLOT(nuevoEvento(QEvent*)));
            exec();
        }
    };


#endif // DELEVERYFUNCTION_H
