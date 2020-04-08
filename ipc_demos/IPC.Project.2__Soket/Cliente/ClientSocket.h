//---------------------------------------------------------------------------------------
#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
//---------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Common.h"
#include <pthread.h>
//---------------------------------------------------------------------------------------
class ClientSocket
{
    private:
        int    CSocket;
        int    SocketType;
        int    Protocolo;
	int    Puerto;
	char   IP[ip_size];
	char   Nick[id_size];
        ints   SizeEth0;
        eths   Eth0;
        pid_t  CProces;
        SockView* SVista;
        pthread_t idHilo;
        pthread_attr_t atributos;

    private:
        void Asistente_Recepcion();  //... Atiente la recepcion de mensajes
	void Configurar_Cliente();
        bool Conectar();

    public:
        ClientSocket(char*, char*, int, SockView*);
        ClientSocket(SockView*);
        ~ClientSocket();
        //........................... Servicios
        static void* Asistente_Recepcion(void*);
        bool Start();
        void Stop();
        void Send(char*, int);
        //........................... Configuracion
        void Set_Puerto(int);
        void Set_Protocolo(int);
        void Set_IP(char*);
        void Set_Nick(char*);
        //........................... Informacion
        char* Get_IP();
        int Get_Port();
        int Get_Protocol();
        int Get_MaxConect();
};
//---------------------------------------------------------------------------------------
#endif
