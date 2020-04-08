//---------------------------------------------------------------------------
#include "mainwindow.h"
//---------------------------------------------------------------------------
MainWindow::MainWindow(QWidget *parent, Qt::WFlags flags)
    : QMainWindow(parent, flags)
{
        ui.setupUi(this);
        Puerto = 5800;
        char puertos[5];   sprintf(puertos, "%d", Puerto);
        ui.lineEdit->setText(QString(puertos));
        ui.label_3->setText("Puerto por defecto");

        connect(ui.pushButton, SIGNAL( clicked() ),          this, SLOT( SLStop() ));
        connect(ui.radioButton_4, SIGNAL( clicked() ),       this, SLOT( SLCambiar() ));
        connect(ui.radioButton_5, SIGNAL( clicked() ),       this, SLOT( SLAbilitar() ));
        connect(ui.radioButton_6, SIGNAL( clicked() ),       this, SLOT( SLDesabilitar() ));
        connect(ui.actionAvilitar, SIGNAL( triggered() ),    this, SLOT( SLAbilitar() ));
        connect(ui.actionCambiar_2, SIGNAL( triggered() ),     this, SLOT( SLCambiar() ));
        connect(ui.actionDesavilitar, SIGNAL( triggered() ), this, SLOT( SLDesabilitar() ));
        connect(ui.actionSalir, SIGNAL( triggered() ),       this, SLOT( SLSalir() ));
}
//---------------------------------------------------------------------------
MainWindow::~MainWindow()
{
}
//---------------------------------------------------------------------------
void MainWindow::SLSatrt(){}
//---------------------------------------------------------------------------
void MainWindow::set_puerto(int puerto)
{
        Puerto = puerto;
        printf ("MainWindow : El puerto es...%d\n", Puerto);
        ui.lineEdit->setText(QString(Puerto));
}
//---------------------------------------------------------------------------
void MainWindow::SLStop()
{
    emit SStop();
}
//---------------------------------------------------------------------------
void MainWindow::SLAbilitar()
{
    if(ui.lineEdit_4->text() != "")
        Puerto = ui.lineEdit_4->text().toInt();
    else Puerto = 5800;
    char puertos[5];  sprintf(puertos, "%d", Puerto);
    ui.lineEdit->setText(QString(puertos));
    ui.lineEdit_4->setDisabled(true);
    ui.label_3->setText("Puerto en uso");
    emit SStart(Puerto);
}
//---------------------------------------------------------------------------
void MainWindow::SLCambiar()
{
    ui.lineEdit_4->setDisabled(false);
    ui.label_3->setText("Puerto anterior");
}
//---------------------------------------------------------------------------
void MainWindow::SLDesabilitar()
{
    ui.lineEdit_4->setDisabled(false);
    ui.label_3->setText("Puerto desabilitado");
}
//---------------------------------------------------------------------------
void MainWindow::SLSalir()
{
    exit(1);
}
//---------------------------------------------------------------------------
