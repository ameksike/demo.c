//---------------------------------------------------------------------------------------
#ifndef USUARIO_H
#define USUARIO_H
//---------------------------------------------------------------------------------------
#define ip_size 16  //... # de caracteres para una direccion IP+caracter nulo
#define id_size 20  //... # de caracteres para los identificadores de usuarios
#define dt_size 256 //... # de caracteres para los mensajes
#include <string.h>
//---------------------------------------------------------------------------------------
class Usuario
{
    private:
	int  ID;
        char Nick[id_size];
        char IP[ip_size];
        char HoraC[9];
        int  Estado;

        char CorreoE[dt_size];
        char Nombre[dt_size];
        char Apellidos[dt_size];
        char Sexso;
        int  Edad;

    public:
        Usuario(int, char*);
        void  Set_DatosCuenta(char*,char*,int);
        void  Set_DatosPersonales(char*,char*,char*,char,int);
        char* Get_Nick();
        int   Get_ID();
        char* Get_IP();
        char* Get_HoraC();
        int   Get_Estado();
        char* Get_CorreoE();
        char* Get_Nombre();
        char* Get_Apellidos();
        char  Get_Sexso();
        int   Get_Edad();
};
//---------------------------------------------------------------------------------------
#endif // USUARIO_H
