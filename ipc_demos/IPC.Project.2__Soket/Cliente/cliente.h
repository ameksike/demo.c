//--------------------------------------------------------------------------------------
#ifndef CLIENTE_H
#define CLIENTE_H
//--------------------------------------------------------------------------------------
#include <QtGui/QMainWindow>
#include <QMessageBox>
//--------------------------------------------------------------------------------------
namespace Ui
{
    class ClienteClass;
}
//--------------------------------------------------------------------------------------
class Cliente : public QMainWindow
{
        Q_OBJECT

    public:
        Cliente(QWidget *parent = 0);
        ~Cliente();

    public:
        QString Nick;
        QString IP;
        int Puerto;

    private:
        Ui::ClienteClass *ui;

    private slots:
        void SLConect();
        void SLSalir();

    signals:
        void SUserData();

};
//--------------------------------------------------------------------------------------
#endif // CLIENTE_H
