//-------------------------------------------------
#include <QtGui/QApplication>
#include "mainwindow.h"
#include "ServerChat.h"
//-------------------------------------------------
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ServerChat* SOK = new ServerChat();
    //SOK->Set_Port(2112);
    SOK->Start();

    return a.exec();
}
//-------------------------------------------------
