//--------------------------------------------------------------------------------------
#ifndef CVISTA_H
#define CVISTA_H
//--------------------------------------------------------------------------------------
#include "chat.h"
//--------------------------------------------------------------------------------------
class CVista : public SockView
{
    private:
        Chat* viw;
    public:
        CVista(Chat* nviw);
        void Desconexion(DNet* datagrama);
        void Conexion(DNet* datagrama);
        void Escaner(DNet*);
        void Conversacion(DNet* datagrama);
};
//--------------------------------------------------------------------------------------
#endif // CVISTA_H
