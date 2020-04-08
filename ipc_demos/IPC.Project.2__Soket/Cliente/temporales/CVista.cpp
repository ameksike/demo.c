//--------------------------------------------------
#include "CVista.h"
//--------------------------------------------------
CVista::CVista(Chat* nviw):SockView()
{
    viw = nviw;
}
//--------------------------------------------------
void CVista::CVista::Desconexion(DNet* datagrama)
{
        printf( "\nCVista - Desconexion \n");
        printf( "CVista - Type: %d\n", datagrama->Type);
        printf( "CVista - IP: %s\n", datagrama->IP);
        printf( "CVista - Nick: %s\n", datagrama->ID);
        printf( "CVista - DT: %s\n", datagrama->DT);

}
//--------------------------------------------------
void CVista::Conexion(DNet* datagrama)
{
        printf( "\nCVista - Conexion \n");
        printf( "CVista - Type: %d\n", datagrama->Type);
        printf( "CVista - IP: %s\n", datagrama->IP);
        printf( "CVista - Nick: %s\n", datagrama->ID);
        printf( "CVista - DT: %s\n", datagrama->DT);
        //viw->Set_User(QString(datagrama->ID));
        //viw->Set_User("AA");
}
//--------------------------------------------------
void CVista::Escaner(DNet*){}
//--------------------------------------------------
void CVista::Conversacion(DNet* datagrama)
{
        printf( "\nCVista - Conversacion \n");
        printf( "CVista - Type: %d\n", datagrama->Type);
        printf( "CVista - IP: %s\n", datagrama->IP);
        printf( "CVista - Nick: %s\n", datagrama->ID);
        printf( "CVista - DT: %s\n", datagrama->DT);
        //viw->Set_Test(QString(datagrama->ID)+":"+QString(datagrama->DT));
        //viw->Set_User("AA");
}
//--------------------------------------------------

