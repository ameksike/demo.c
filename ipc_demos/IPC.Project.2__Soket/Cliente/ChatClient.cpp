//--------------------------------------------------------------------------------------
#include "ChatClient.h"
//--------------------------------------------------------------------------------------
ChatClient::ChatClient():SockView()
{
    Nick    = "user";
    IP      = "10.12.167.37";
    Puerto  = 5800;
    login   = new Cliente();
    chat    = new Chat();
    csocket = new ClientSocket(this);
    Create_Signal_Slot();
}
//--------------------------------------------------------------------------------------
void ChatClient::Create_Signal_Slot()
{
    connect(login, SIGNAL( SUserData() ),            this, SLOT( SLConectar() ));
    connect(chat,  SIGNAL( Send_UserData() ),        this, SLOT( SLEnviar() ));
    connect(chat,  SIGNAL( SConectarse() ),          this, SLOT( Start() ));
    connect(chat,  SIGNAL( SDesconectarse() ),       this, SLOT( SLDesconectar() ));
    connect(this,  SIGNAL( SConexion(QString) ),     chat, SLOT( Set_User(QString) ));
    connect(this,  SIGNAL( SConversacion(QString) ), chat, SLOT( Set_Test(QString) ));
    connect(this,  SIGNAL( SDesconexion(QString) ),  chat, SLOT( Del_User(QString) ));
}
//--------------------------------------------------------------------------------------
void ChatClient::Start()
{
    login->show();
}
//--------------------------------------------------------------------------------------
void ChatClient::SLConectar()
{
    if(login->Puerto > 0)
    {
        Puerto = login->Puerto;
        IP     = login->IP;
        Nick   = login->Nick;
    }

    char ip[16];
    char nick [512];
    int puerto = Puerto;
    strcpy (ip, IP.toStdString().c_str());
    strcpy (nick, Nick.toStdString().c_str());

    csocket->Set_IP(ip);
    csocket->Set_Nick(nick);
    csocket->Set_Puerto(puerto);
    
    this->chat->Set_User(Nick);

    if(csocket->Start())
    {
            chat->Nick = Nick;
            chat->show();
            login->hide();
    }
    else
    {
        QString encabezado = "Alerta: Error de Conexion";
        QString cuerpo     = "No se pudo establecer la comunicacion con el servidor";
        QMessageBox Mensaje;
        Mensaje.about(login, encabezado, cuerpo);
    }
}
//--------------------------------------------------------------------------------------
void ChatClient::SLEnviar()
{
       char mensaje [512];
       strcpy (mensaje, chat->Mensaje.toStdString().c_str());
       csocket->Send(mensaje, CONVERSACION);
}
//--------------------------------------------------------------------------------------
void ChatClient::Desconexion(DNet* datagrama)
{
        QString id;
        if(!datagrama) id = "Servidor";
        else id = QString(datagrama->ID);
        emit SDesconexion(id);
}
//--------------------------------------------------------------------------------------
void ChatClient::Conexion(DNet* datagrama)
{
        QString mensaje1 = QString(datagrama->ID);
        emit SConexion(mensaje1);
        QString mensaje2 = QString(datagrama->ID)+": "+QString(datagrama->DT);
        emit SConversacion(mensaje2);
}
//--------------------------------------------------------------------------------------
void ChatClient::Escaner(DNet*){}
//--------------------------------------------------------------------------------------
void ChatClient::Conversacion(DNet* datagrama)
{
        QString mensaje = QString(datagrama->DT);
        emit SConversacion(mensaje);
}
//--------------------------------------------------------------------------------------
void ChatClient::Actualizacion(DNet* datagrama)
{
        this->chat->Add_User(QString(datagrama->DT));
}
//--------------------------------------------------------------------------------------
void ChatClient::SLDesconectar()
{
       char mensaje [] = "adios";
       printf( "ClientSocket - init\n");
       csocket->Send(mensaje, DESCONEXION);
       printf( "ClientSocket - fin: %s\n", mensaje);
}
//--------------------------------------------------------------------------------------
