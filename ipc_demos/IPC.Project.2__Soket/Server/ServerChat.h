//-------------------------------------------------------------------------------------
#ifndef SERVERCHAT_H
#define SERVERCHAT_H
//--------------------------------------------------------------------------------------
#include "ServerSocket.h"
#include "mainwindow.h"
#include <pthread.h>
//--------------------------------------------------------------------------------------
class ServerChat : public QObject
{
        Q_OBJECT
    private:
        ServerSocket* SSocket;
        pthread_t idHilo;
        pthread_attr_t atributos;
        char* salida;
        MainWindow* w;

    public:
        ServerChat();
        ServerSocket* operator->();
        void Start();

    public slots:
        void SLStart(int);
        void SLStop();
};
//--------------------------------------------------------------------------------------
#endif // SERVERCHAT_H
