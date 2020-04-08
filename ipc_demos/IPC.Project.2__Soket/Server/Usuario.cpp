//---------------------------------------------------------------------------------------
#include "Usuario.h"
//---------------------------------------------------------------------------------------
Usuario::Usuario(int vID, char* vIP)
{
    this->ID = vID;
    strcpy(this->IP, vIP);
}
//---------------------------------------------------------------------------------------
void Usuario::Set_DatosCuenta(char* vNick, char* vHoraC, int vEstado)
{
    strcpy(this->Nick, vNick);
    strcpy(this->HoraC, vHoraC);
    this->Estado = vEstado;
}
//---------------------------------------------------------------------------------------
void Usuario::Set_DatosPersonales(char* vNombre, char* vApellidos, char* vCorreoE, char vSexso,int vEdad)
{
    strcpy(this->Nombre, vNombre);
    strcpy(this->Apellidos, vApellidos);
    strcpy(this->CorreoE, vCorreoE);
    this->Sexso = vSexso;
    this->Edad  = vEdad;
}
//---------------------------------------------------------------------------------------
int Usuario::Get_ID()
{
    return this->ID;
}
//---------------------------------------------------------------------------------------
char* Usuario::Get_Nick()
{
    return this->Nick;
}
//---------------------------------------------------------------------------------------
char* Usuario::Get_IP()
{
    return this->IP;
}
//---------------------------------------------------------------------------------------
char* Usuario::Get_HoraC()
{
    return this->HoraC;
}
//---------------------------------------------------------------------------------------
int  Usuario::Get_Estado()
{
    return this->Estado;
}
//---------------------------------------------------------------------------------------
char* Usuario::Get_CorreoE()
{
    return this->CorreoE;
}
//---------------------------------------------------------------------------------------
char* Usuario::Get_Nombre()
{
    return this->Nombre;
}
//---------------------------------------------------------------------------------------
char* Usuario::Get_Apellidos()
{
    return this->Apellidos;
}
//---------------------------------------------------------------------------------------
char Usuario::Get_Sexso()
{
    return this->Sexso;
}
//---------------------------------------------------------------------------------------
int  Usuario::Get_Edad()
{
    return this->Edad;
}
//---------------------------------------------------------------------------------------
