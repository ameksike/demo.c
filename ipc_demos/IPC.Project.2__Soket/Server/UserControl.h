//---------------------------------------------------------------------------------------
#ifndef USERCONTROL_H
#define USERCONTROL_H
//---------------------------------------------------------------------------------------
#include "Common.h"
#include "Usuario.h"
#include "CListaSE.cpp"
typedef Usuario User;
//---------------------------------------------------------------------------------------
class UserControl
{
	private:
		fd_max FD_Mayor;  //...El mayor de los descriptores del conjunto maestro
		fd_set FD_Master; //...Conjunto maestro de descriptores de fichero
		fd_set FD_Read;   //...Conjunto temporal de descriptores de fichero para
		int Find_P(int);
		int Find_P(char*);

	public:
		UserControl();
		fd_max  Mayor();
		fd_set* Read();
		bool Exist(int);
		bool Readed(int);
		void Read(fd_set);
		void Add(int, char*);
		void Del(int);
		void Clear();
		//......................Cuentas
		void Set_DatosCuenta(int,char*,char*,int);
		User* Find(int);
		User* Find(char*);
                char* Get_Nick(int);
                CListaSE<User*>* UserList;
		//void Set_UserData(int,);
};
//---------------------------------------------------------------------------------------
#endif // USERCONTROL_H
