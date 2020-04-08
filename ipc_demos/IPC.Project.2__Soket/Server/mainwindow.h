#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//--------------------------------------------------------------------------------------
#include <QtGui/QMainWindow>
#include "ui_mainwindow.h"
//--------------------------------------------------------------------------------------
class MainWindow : public QMainWindow
{
    Q_OBJECT

    public:
        MainWindow(QWidget *parent = 0, Qt::WFlags flags = 0);
        ~MainWindow();
        void set_puerto(int);

    private:
        Ui::MainWindowClass ui;
        int Puerto;

    private slots:
        void SLSatrt();
        void SLStop();
        void SLAbilitar();
        void SLCambiar();
        void SLDesabilitar();
        void SLSalir();

    signals:
        void SStart(int);
        void SStop();
};
//--------------------------------------------------------------------------------------
#endif // MAINWINDOW_H
