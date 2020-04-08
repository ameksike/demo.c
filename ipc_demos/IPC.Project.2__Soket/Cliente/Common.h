#ifndef COMMON_H
#define COMMON_H
//--------------------------- Librerias -------------------------------------
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
//--------------------------- Constantes ------------------------------------
#define ip_size 16  //... # de caracteres para una direccion IP+caracter nulo
#define id_size 20  //... # de caracteres para los identificadores de usuarios
#define dt_size 256 //... # de caracteres para los mensajes
//--------------------------- Definicion de tipos ---------------------------
typedef struct sockaddr* eth;
typedef struct sockaddr_in eths;
typedef socklen_t ints;
typedef int fd_max;
//--------------------------- Estructuras -----------------------------------
struct DNet                //...Dartagrama que se envia por la red
{
        int  Type;         //...Bufer para definir tipo de mensaje
        char IP[ip_size];  //...Bufer para la direccion IP
        char ID[id_size];  //...Bufer para el identificador de usuario o nick
        char DT[dt_size];  //...Bufer para el mensaje
};
//---------------------------------------------------------------------------
class SockView             //...Vista encargada de actualizar las interfacez
{
    public:
        SockView(){}
        ~SockView(){};
        virtual void Desconexion(DNet*)=0;
        virtual void Conexion(DNet*)=0;
        virtual void Escaner(DNet*)=0;
        virtual void Conversacion(DNet*)=0;
        virtual void Actualizacion(DNet*)=0;
};
//---------------------------- Tipos de Mensajes --------------------------
enum MType { DESCONEXION, CONEXION, CONVERSACION, NOTIFICACION, PRESENTACION, ACTUALIZACION, ESCANEAR };
//---------------------------------------------------------------------------
#endif // COMMON_H
