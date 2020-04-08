//---------------------------------------------
#ifndef CHAT_H
#define CHAT_H
//---------------------------------------------
#include <QtGui/QMainWindow>
#include "ClientSocket.h"
//---------------------------------------------
namespace Ui {
    class MainWindow;
}
//---------------------------------------------
class Chat : public QMainWindow
{
    Q_OBJECT
    Q_DISABLE_COPY(Chat)

    public:
        Ui::MainWindow *form;
        Chat(QWidget *parent = 0);
        ~Chat();
        QString Mensaje;
        QString Nick;
        void Add_User(QString);
   private:
        void Delete_User(QString);
        
    public slots:
        void Enviar();
        void Set_Test(QString);
        void Set_User(QString);
        void Del_User(QString);
        void SLConectarse();
        void SLDesconectarse();
        void SLSalir();

    signals:
        void Send_UserData();
        void SConectarse();
        void SDesconectarse();
};
//-------------------------------------------------------------
#endif // CHAT_H

