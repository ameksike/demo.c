//-----------------------------------------------------------------------------------------
#include "UserControl.h"
//-----------------------------------------------------------------------------------------
UserControl::UserControl()
{
	FD_Mayor = 0;
	UserList = new CListaSE<User*>();
}
//-----------------------------------------------------------------------------------------
void UserControl::Add(int id, char* IP)
{
	User* u = new Usuario(id, IP);
	UserList->Adicionar(u);
	FD_SET(id, &FD_Master);
	if (id > FD_Mayor) FD_Mayor = id;
}
//-----------------------------------------------------------------------------------------
void UserControl::Del(int id)
{
	FD_CLR(id, &FD_Master);
	int pos = Find_P(id);
	UserList->Eliminar(pos);
}
//-----------------------------------------------------------------------------------------
void UserControl::Clear()
{
	FD_ZERO(&FD_Master);
	FD_ZERO(&FD_Read);
	UserList->Limpiar();
}
//-----------------------------------------------------------------------------------------
fd_max UserControl::Mayor()
{
	return FD_Mayor+1;
}
//-----------------------------------------------------------------------------------------
fd_set* UserControl::Read()
{
	FD_Read = FD_Master;
	return &FD_Read;
}
//-----------------------------------------------------------------------------------------
bool UserControl::Readed(int id)
{
	return FD_ISSET(id, &FD_Read);
}
//-----------------------------------------------------------------------------------------
bool UserControl::Exist(int id)
{
	return FD_ISSET(id, &FD_Master);
}
//--------------------------------------------------------------------------------------
void UserControl::Read(fd_set r)
{
	FD_Read = r;
}
//--------------------------------------------------------------------------------------
int UserControl::Find_P(int id)
{
	int pos=1;
	while(pos<=UserList->Longitud() && UserList->Obtener(pos)->Get_ID() != id) pos++;
	return pos;
}
//--------------------------------------------------------------------------------------
int UserControl::Find_P(char* nick)
{
	int pos=1;
	for(int i=1; i<=UserList->Longitud(); i++)
		if( !strcmp(UserList->Obtener(i)->Get_Nick(), nick) )
			pos++;
	return pos;
}
//--------------------------------------------------------------------------------------
User* UserControl::Find(int id)
{
	return UserList->Obtener(Find_P(id));
}
//--------------------------------------------------------------------------------------
User* UserControl::Find(char* nick)
{
	return UserList->Obtener(Find_P(nick));
}
//--------------------------------------------------------------------------------------
char* UserControl::Get_Nick(int id)
{
        if(Find(id))
            return Find(id)->Get_Nick();
        else return 0;
}
//--------------------------------------------------------------------------------------
void UserControl::Set_DatosCuenta(int id, char* Nick, char* HoraC, int Estado)
{
	User* u = Find(id);
	if(u)u->Set_DatosCuenta(Nick, HoraC, Estado);
	else printf( "nada\n");
}
