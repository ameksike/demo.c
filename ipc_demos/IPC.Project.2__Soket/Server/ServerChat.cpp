//--------------------------------------------------------------------------------------
#include "ServerChat.h"
//--------------------------------------------------------------------------------------
ServerChat::ServerChat()
{
        SSocket = new ServerSocket();
        w = new MainWindow();
        connect(w, SIGNAL( SStart(int) ), this, SLOT( SLStart(int) ));
        connect(w, SIGNAL( SStop() ), this, SLOT( SLStop() ));
}
//--------------------------------------------------------------------------------------
ServerSocket* ServerChat::operator->()
{
	return SSocket;
}
//--------------------------------------------------------------------------------------
void ServerChat::SLStart(int puerto)
{
        SSocket->Set_Puerto(puerto);
        printf ("\nServerChat : Puerto en uso >> %d", SSocket->Get_Port());
        int error = pthread_create (&idHilo, NULL, SSocket->Start, SSocket);
        if (error != 0) perror ("ServerChat Error - No puedo crear thread >>");
}
//--------------------------------------------------------------------------------------
void ServerChat::SLStop()
{
        printf ("ServerChat : Parando la ejecucion del servidor ");
	SSocket->Stop();
        //pthread_exit((void*)idHilo);
}
//---------------------------------------------------------------------------------------
void ServerChat::Start()
{
        w->show();
}
//---------------------------------------------------------------------------------------
