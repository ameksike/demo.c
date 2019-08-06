#ifndef TCPSERVER_H
#define TCPSERVER_H

#include <QObject>
#include <QTimer>
#include "src/controllerfactory.h"
#include "src/ngn_fija_controller.h"


typedef enum
{
    NGN_FIJA  = 1,
    NGN_MOVIL = 2,
    AST_PBX   = 3,
    CLI_TELNET = 4
} TIPO_RED;

typedef enum
{
    SESSION_ACTIVA,
    SESSION_PASIVA
} TIPO_SESSION;

class QTcpServer;
class QTcpSocket;
class Controller;
class TCPServer : public QObject
{
	Q_OBJECT

public:
    typedef enum
    {
        activa,
        inactiva,
        RECIBIENDO_DATOS,
        INICIANDO,
        IDLE
    } Session_State;
private:
	QList<QTcpSocket *>clientConnection;
	QTcpServer *tcpServer;
        QByteArray buffer;
        bool isdataSocket;
        QTimer timer;
	int timeOut;
	int cont;
        Controller*    controladora;
        Session_State  estado;
        TIPO_RED       tipoRed;
        TIPO_SESSION   tipoSession;
        QString        serviceName;
        quint64  cantBytesRecibidos;
         QTcpSocket *client;
        Session_State getEstado()
        {
            return this->estado;
        }

        void setEstado( Session_State _estado)
        {
            this->estado = _estado;
        }

        void setController(Controller*);


        QString getServiceName()
        {
            return this->serviceName;
        }
public:
        TCPServer(QString serviceName, QObject* parent = 0);
        void start();
	~TCPServer();

public slots:
	void clientConnected();
	void enviados(qint64);
	void clienteDesconectado();	
        void readData();
        void TimeOutXptu();
        void slotDatosProcesadosController()
        {
            cout<<">>> Session::slotDatosProcesadosController <<<"<<endl;
        }

signals:
		/**
		  *Esta senal es emitida cuando se conecta un cliente al servidor TCP.
		  */
	void isConnected();

	/**
	  *Esta senal es emitida cuando se desconecta un cliente del servidor TCP o cuando curre un timeout.
	  */
	void isDisconnect();

        void signalsDatosXptu(QByteArray);
};

#endif // TCPSERVER_H
