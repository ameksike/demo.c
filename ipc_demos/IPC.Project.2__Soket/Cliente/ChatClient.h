#ifndef CHATCLIENT_H
#define CHATCLIENT_H
//--------------------------------------------------------------------------------------
#include "chat.h"
#include "cliente.h"
//--------------------------------------------------------------------------------------
class ChatClient : public QObject, SockView
{
    Q_OBJECT
    private:
        ClientSocket* csocket;
        Cliente* login;
        Chat *chat;
        QString Nick;
        QString IP;
        int Puerto;

    public:
        ChatClient();

    private:
        void Desconexion(DNet* datagrama);
        void Conexion(DNet* datagrama);
        void Escaner(DNet*);
        void Conversacion(DNet* datagrama);
        void Actualizacion(DNet* datagrama);
        void Create_Signal_Slot();

    public slots:
        void SLConectar();
        void SLEnviar();
        void SLDesconectar();
        void Start();

    signals:
        void SDesconexion(QString);
        void SConexion(QString);
        void SEscaner(QString);
        void SConversacion(QString);
};
//--------------------------------------------------------------------------------------
#endif // CHATCLIENT_H
