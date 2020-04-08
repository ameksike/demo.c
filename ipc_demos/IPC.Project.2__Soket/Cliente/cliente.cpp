//--------------------------------------------------------------------------------------
#include "cliente.h"
#include "ui_cliente.h"
//--------------------------------------------------------------------------------------
Cliente::Cliente(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::ClienteClass)
{
    ui->setupUi(this);
    Nick = "";
    IP = "";
    Puerto = 5800;
    connect(ui->pushButton, SIGNAL( clicked() ), this, SLOT( SLConect() ));
    connect(ui->actionSalir, SIGNAL( triggered() ), this, SLOT( SLSalir() ));
}
//--------------------------------------------------------------------------------------
Cliente::~Cliente()
{
    delete ui;
}
//--------------------------------------------------------------------------------------
void Cliente::SLConect()
{
    Puerto = ui->lineEdit_2->text().toInt();
    IP     = ui->lineEdit->text();
    Nick   = ui->lineEdit_3->text();
    emit  SUserData();
}
//--------------------------------------------------------------------------------------
void Cliente::SLSalir()
{
    exit(1);
}
//--------------------------------------------------------------------------------------
