//-------------------------------------------------------------
#include "chat.h"
#include "ui_chat.h"
//-------------------------------------------------------------
Chat::Chat(QWidget *parent) : QMainWindow(parent)
{
        form = new Ui::MainWindow();
        form->setupUi(this);
        Mensaje = "";
        Nick = "";
        connect(form->lineEdit, SIGNAL(returnPressed()), this, SLOT(Enviar()));
        connect(form->pushButton, SIGNAL(clicked()), this, SLOT(Enviar()));
        connect(form->actionConectarse, SIGNAL(triggered()), this, SLOT(SLConectarse()));
        connect(form->actionDesconectarse, SIGNAL(triggered()), this, SLOT(SLDesconectarse()));
        connect(form->actionSalir, SIGNAL(triggered()), this, SLOT(SLSalir()));
}
//-------------------------------------------------------------
Chat::~Chat()
{
        delete form;
}
//-------------------------------------------------------------
void Chat::Enviar()
{
       Mensaje = form->lineEdit->text();
       if(Mensaje != "")
       {
            form->textEdit->append(Nick+": "+Mensaje);
            form->lineEdit->clear();
            emit  Send_UserData();
       }
}
//-------------------------------------------------------------
void Chat::Set_User(QString user)
{
        if(Nick != user)
        {
            QString Mensaje = "Administrador: Se ha conectado ";
            Mensaje += user;
            form->textEdit->append(Mensaje);
        }
        form->listWidget->addItem(user);
}
//-------------------------------------------------------------
void Chat::Set_Test(QString Mensaje)
{
        form->textEdit->append(Mensaje);
}
//-------------------------------------------------------------
void Chat::Del_User(QString user)
{
        QString Mensaje = "Administrador: ";
        Mensaje += user;
        Mensaje += " se ha desconectado";
        form->textEdit->append(Mensaje);
        Delete_User(user);
}
//-------------------------------------------------------------
void Chat::Add_User(QString user)
{
        form->listWidget->addItem(user);
}
//-------------------------------------------------------------
void Chat::Delete_User(QString user)
{
        int total = form->listWidget->count();
        int pos=0, i=0;
        while(form->listWidget->item(i++)->text() != user)
            pos++;
        if(pos<= total)
            form->listWidget->takeItem(pos);
}
//-------------------------------------------------------------
void Chat::SLConectarse()
{
    emit SConectarse();
}
//-------------------------------------------------------------
void Chat::SLSalir()
{
    exit(1);
}
//-------------------------------------------------------------
void Chat::SLDesconectarse()
{
    emit SDesconectarse();
}
//-------------------------------------------------------------
