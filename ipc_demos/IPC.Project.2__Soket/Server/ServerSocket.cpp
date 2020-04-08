//--------------------------------------------------------------------------------------
#include "ServerSocket.h"
//--------------------------------------------------------------------------------------
ServerSocket::ServerSocket()
{
        Puerto     = 5800;
        status     = true;
	Sockopt    = 1;
	MaxConect  = 10;
	Protocolo  = AF_INET;
	SocketType = SOCK_STREAM;
	UserAdmin  = new UserControl();
	Configurar_Servidor();
}
//--------------------------------------------------------------------------------------
ServerSocket::~ServerSocket()
{
	//char mensage[] = "Servidor: Bye";
	//Send_All(mensage, 0, -1);
}
//--------------------------------------------------------------------------------------
void ServerSocket::Configurar_Servidor()
{
	//...Obtener socket a la escucha
	if((SSocket = socket(Protocolo, SocketType, 0)) == -1)
		perror("ServerSocket Error:  Ha ocurrido un explote en la funcion 'socket' >> ");

	//...Obviar el mensaje "address already in use" (la dirección ya se está usando)
	if(setsockopt(SSocket, SOL_SOCKET, SO_REUSEADDR, &Sockopt, sizeof(int)) == -1)
		perror("ServerSocket Error:  Ha ocurrido un explote en la funcion 'setsockopt' >> ");

	//...Enlazar eth
	SizeEth0 = sizeof(struct sockaddr);
	Eth0.sin_family = Protocolo;
	Eth0.sin_port = htons(Puerto);
	Eth0.sin_addr.s_addr = INADDR_ANY;
        memset(&(Eth0.sin_zero), '\0', 8);

	if (bind(SSocket, (eth)&Eth0, sizeof(Eth0)) == -1)
		perror("ServerSocket Error: Ha ocurrido un explote en la funcion 'bind' >> ");

	//...Escuchar maxmo de peticiones
	if (listen(SSocket, MaxConect) == -1)
		perror("ServerSocket Error: Ha ocurrido un explote en la funcion 'listen' >> ");
	
	UserAdmin->Clear();
	UserAdmin->Add(SSocket,inet_ntoa(Eth0.sin_addr));
}
//--------------------------------------------------------------------------------------
void ServerSocket::Set_MaxConect(int vNConection)
{
	MaxConect = vNConection;
}
//--------------------------------------------------------------------------------------
void ServerSocket::Set_Puerto(int puerto)
{
        Puerto = puerto;
        Configurar_Servidor();
}
//--------------------------------------------------------------------------------------
void ServerSocket::Set_IP(char* ip)
{
        inet_aton(ip, &(Eth0.sin_addr));
}
//--------------------------------------------------------------------------------------
void ServerSocket::Set_Protocolo(int protocolo=AF_INET)
{
}
//--------------------------------------------------------------------------------------
void ServerSocket::Send_All(char *mensaje, char* remitente, int type=3, int exepcion=-1)
{
	for(int i=0; i<=UserAdmin->Mayor(); i++)
	    if (UserAdmin->Exist(i))
		    if (i != SSocket && i != exepcion)
			this->Send(mensaje, remitente, i, type);
}
//--------------------------------------------------------------------------------------
void ServerSocket::Send(char* mensaje, char* remitente, int cliente, int type=3)
{
	DNet datagrama;
	datagrama.Type = type;
	strcpy(datagrama.DT, mensaje);
	strcpy(datagrama.ID, remitente);

	if (send(cliente, &datagrama, sizeof(datagrama),0) == 1)
	{
		char Error_msj[] = "ServerSocket Error: No se pudo enviar el datagrama al cliente >> ";
		strcat(Error_msj, UserAdmin->Get_Nick(cliente));
		perror(Error_msj);
	}	
}
//--------------------------------------------------------------------------------------
void* ServerSocket::Start(void* obj)
{ 
	printf( "\nServerSocket: Escuchando peticiones...\n");
        ServerSocket* This = (ServerSocket*)obj;
        while(This->status)
	{
		int byte = select(This->UserAdmin->Mayor(), This->UserAdmin->Read(), 0, 0, 0);
		if(byte == -1) perror("ServerSocket Error: Ha ocurrido un explote en la funcion 'select' >> ");

		for(int i=0; i<=This->UserAdmin->Mayor(); i++)
		{
		    if (This->UserAdmin->Readed(i))
		    {
			    if (i == This->SSocket)
				This->Asistente_Peticiones();
			    else
				This->Asistente_Mensajes(i);
		    }
		}
	}
        printf( "\nServerSocket: Esalieeeeeeeeeeee\n");
}
//--------------------------------------------------------------------------------------
void ServerSocket::Stop()
{
        close(SSocket);
        status = false;
}
//--------------------------------------------------------------------------------------
void ServerSocket::Asistente_Peticiones()
{
	eths Eth1;
	ints SizeEth1 = sizeof(Eth1);
        int newClient = accept(SSocket, (eth)&Eth1, &SizeEth1);
        if(newClient == 1)
                perror("ServerSocket Error: No se pudo admitir la nueba conexion >> ");
        else UserAdmin->Add(newClient, inet_ntoa(Eth1.sin_addr));
}
//--------------------------------------------------------------------------------------
void ServerSocket::Asistente_Mensajes(int cliente)
{
        DNet datagrama;
	int bytes = recv(cliente, &datagrama, sizeof(DNet), 0);

        if(bytes <= 0)
        {
                if(bytes == DESCONEXION)
                {
			char mensage[] = "Administrador: Se ha desconectado el usuario: ";
			char usuario[512];
			strcpy(usuario, UserAdmin->Get_Nick(cliente));
			close(cliente);
			UserAdmin->Del(cliente);
			Send_All(mensage, usuario, DESCONEXION);
                }else perror("ServerSocket Error: recv >> ");
        }
        else switch(datagrama.Type)
	{
		case CONVERSACION:
		{
			char mensage[] = "";
			strcat(mensage, datagrama.ID);
			strcat(mensage, ": ");
			strcat(mensage, datagrama.DT);
			Send_All(mensage, datagrama.ID, CONVERSACION, cliente);
		}break;

		case PRESENTACION:
		{
			UserAdmin->Set_DatosCuenta(cliente, datagrama.ID, datagrama.ID, 0);
                        Send_All(datagrama.DT, datagrama.ID, CONEXION, cliente);
                        char remitente[] = "Servidor";
                        for(int i=0; i<=UserAdmin->UserList->Longitud(); i++)
                        {
                            Usuario* user = UserAdmin->UserList->Obtener(i);
                            if(user)
                            {
                                int id = user->Get_ID();
                                if( id != SSocket && id != cliente)
                                    Send(user->Get_Nick(), remitente, cliente, ACTUALIZACION);
                            }

                        }
		}break;

                case DESCONEXION:
                {
                        close(cliente);
                        UserAdmin->Del(cliente);
                        Send_All(datagrama.DT, datagrama.ID, DESCONEXION);
                }break;

		case ESCANEAR:
		{}break;
		
		default:
		{}break;
	}
}
//--------------------------------------------------------------------------------------
int ServerSocket::Get_MaxConect()
{
	return this->MaxConect;
}
//--------------------------------------------------------------------------------------
char* ServerSocket::Get_IP()
{
	return inet_ntoa(Eth0.sin_addr);
}
//--------------------------------------------------------------------------------------
int ServerSocket::Get_Port()
{
        return Puerto;
}
//--------------------------------------------------------------------------------------
int ServerSocket::Get_Protocol()
{
	return this->Eth0.sin_family;
}
//--------------------------------------------------------------------------------------
