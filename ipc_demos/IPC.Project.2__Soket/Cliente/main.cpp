#include <QtGui/QApplication>
#include "ChatClient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ChatClient* w = new ChatClient();
    w->Start();
    return a.exec();
}
