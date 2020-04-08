//--------------------------------------------------------------------------------------
#include "ClientSocket.h"
//--------------------------------------------------------------------------------------
ClientSocket::ClientSocket(char* nick, char* ip, int puerto=5800, SockView* Widget=0)
{
        SVista     = Widget;
	Puerto     = puerto;
	Protocolo  = AF_INET;
        SocketType = SOCK_STREAM;
	strcpy(IP, ip);
	strcpy(Nick, nick);
}
//--------------------------------------------------------------------------------------
ClientSocket::ClientSocket(SockView* Widget=0)
{
	SVista     = Widget;
        Puerto     = 5800;
        Protocolo  = AF_INET;
        SocketType = SOCK_STREAM;
}
//--------------------------------------------------------------------------------------
ClientSocket::~ClientSocket()
{
	delete SVista;
	Stop();
}
//--------------------------------------------------------------------------------------
void ClientSocket::Configurar_Cliente()
{
	Eth0.sin_family = Protocolo;
	Eth0.sin_port   = htons(Puerto);
	inet_aton(IP, &(Eth0.sin_addr));
        SizeEth0 = sizeof(struct sockaddr);
	memset(&(Eth0.sin_zero), '\0', 8 );
        if((CSocket = socket(Protocolo, SocketType, 0)) == -1)
            perror("ClientSocket Error:  Ha ocurrido un explote en la funcion 'socket' >> ");
}
//--------------------------------------------------------------------------------------
bool ClientSocket::Conectar()
{
        printf( "ClientSocket - Puerto: %d\n", Puerto);
        printf( "ClientSocket - IP: %s\n", IP);
        printf( "ClientSocket - Nick: %s\n", Nick);
        if(connect(CSocket, (eth)&Eth0, SizeEth0) == -1)
        {
		perror("Error:  Ha ocurrido un explote en la funcion 'socket' >> ");
		return 0;
        }
	else
	{
		char msgpresent[] = "solicito permisos para conectarme";
                Send(msgpresent, PRESENTACION);
        }
        return 1;
}
//--------------------------------------------------------------------------------------
void ClientSocket::Send(char* mensaje, int type=CONVERSACION)
{
	DNet datagrama;
	datagrama.Type = type;
	strcpy(datagrama.DT, mensaje);
	strcpy(datagrama.ID, Nick);

	if (send(CSocket, &datagrama, sizeof(datagrama),0) == 1)
	{
                char Error_msj[] = "ClientSocket Error: No se pudo enviar el datagrama al servidor >> ";
		perror(Error_msj);
        }
}
//--------------------------------------------------------------------------------------
void ClientSocket::Asistente_Recepcion()
{
	DNet datagrama;
	while(1)
	{
                int bytes = recv(CSocket, &datagrama, sizeof(DNet),0);
                if(bytes < 0)
                {
                    char Error_msj[] = "ClientSocket Error: Ha ocurrido un explote en la funcion recv >> ";
                    perror(Error_msj);
	            exit(0);
                }
		if(bytes == DESCONEXION)
                {
                        if(SVista) SVista->Desconexion(0);
                        close(CSocket);
                        printf( "ClientSocket - servidor muerto \n");
                        exit(1);
		}
                else switch(datagrama.Type)
		{
			case CONEXION:
			{
                                if(SVista) SVista->Conexion(&datagrama);
			}break;

                        case CONVERSACION:
                        {
                                if(SVista) SVista->Conversacion(&datagrama);
                        }break;

                        case DESCONEXION:
                        {
                                if(SVista) SVista->Desconexion(&datagrama);
                        }break;

                        case ACTUALIZACION:
                        {
                                if(SVista) SVista->Actualizacion(&datagrama);
                        }break;

			default:
			{}break;
		}
	}
}
//--------------------------------------------------------------------------------------
void ClientSocket::Set_Puerto(int puerto)
{
	Puerto = puerto;
}
//--------------------------------------------------------------------------------------
void ClientSocket::Set_IP(char* ip)
{
        strcpy(IP, ip);
}
//--------------------------------------------------------------------------------------
void ClientSocket::Set_Nick(char* nick)
{
	strcpy(Nick, nick);
}
//--------------------------------------------------------------------------------------
//void ClientSocket::Set_Protocolo(int protocolo=AF_INET){}
//--------------------------------------------------------------------------------------
bool ClientSocket::Start()
{ 
	Configurar_Cliente();
        if(!Conectar()) return 0;
	else
	{
                 int error = pthread_create (&idHilo, NULL, ClientSocket::Asistente_Recepcion, this);
                 if (error != 0)
                 {
                    perror ("ClientSocket Error - No puedo lebantar el Asistente  de Recepcion >>");
                    return 0;
                 }
	}
	return 1;
}	
//--------------------------------------------------------------------------------------
void ClientSocket::Stop()
{
	close(CSocket);
        //kill(CProces, SIGKILL);
}
//--------------------------------------------------------------------------------------
char* ClientSocket::Get_IP()
{
	return inet_ntoa(Eth0.sin_addr);
}
//--------------------------------------------------------------------------------------
int ClientSocket::Get_Port()
{
	return this->Eth0.sin_port;
}
//--------------------------------------------------------------------------------------
int ClientSocket::Get_Protocol()
{
	return this->Eth0.sin_family;
}
//--------------------------------------------------------------------------------------
void* ClientSocket::Asistente_Recepcion(void* obj)
{
    ClientSocket* This = (ClientSocket*)obj;
    This->Asistente_Recepcion();
}
//--------------------------------------------------------------------------------------
