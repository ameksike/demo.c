//---------------------------------------------------------------------------------------
#ifndef SERVERSOCKET_H
#define SERVERSOCKET_H
//---------------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UserControl.h"
//---------------------------------------------------------------------------------------
class ServerSocket
{
    private:
        int  SSocket;
        int  Sockopt;
        int  SocketType;
        int  MaxConect;
        int  Protocolo;
        int  Puerto;
        ints SizeEth0;
        eths Eth0;
	UserControl* UserAdmin;

    private:
        void Asistente_Peticiones();  //... Atiente las peticiones de conexion
        void Asistente_Mensajes(int); //... Atiente los mensajes
	void Configurar_Servidor();

    public:
        ServerSocket();
        ~ServerSocket();
	//........................... Servicios
	static void* Start(void*);
        void Stop();
	void Send(char*, char*, int, int);
        void Send_All(char*, char*, int, int);
        //........................... Configuracion
        void Set_Puerto(int);
        void Set_Protocolo(int);
        void Set_IP(char*);
        void Set_MaxConect(int);
        bool status;
        //........................... Informacion
        char* Get_IP();
        int Get_Port();
        int Get_Protocol();
        int Get_MaxConect();
};
//-----------------------------------------------------------------------------------------
#endif
