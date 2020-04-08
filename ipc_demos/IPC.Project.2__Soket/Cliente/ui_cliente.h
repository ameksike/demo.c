/********************************************************************************
** Form generated from reading ui file 'cliente.ui'
**
** Created: Fri Mar 13 21:36:39 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CLIENTE_H
#define UI_CLIENTE_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClienteClass
{
public:
    QAction *actionSalir;
    QAction *actionAcerca_de;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QLineEdit *lineEdit_3;
    QLabel *label_2;
    QLineEdit *lineEdit_4;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QMenu *menuArchivo;
    QMenu *menuAyuda;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *ClienteClass)
    {
    if (ClienteClass->objectName().isEmpty())
        ClienteClass->setObjectName(QString::fromUtf8("ClienteClass"));
    ClienteClass->resize(264, 200);
    actionSalir = new QAction(ClienteClass);
    actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
    actionAcerca_de = new QAction(ClienteClass);
    actionAcerca_de->setObjectName(QString::fromUtf8("actionAcerca_de"));
    centralWidget = new QWidget(ClienteClass);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    gridLayout = new QGridLayout(centralWidget);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label_3 = new QLabel(centralWidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 0, 0, 1, 1);

    label_4 = new QLabel(centralWidget);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout->addWidget(label_4, 0, 1, 1, 1);

    lineEdit = new QLineEdit(centralWidget);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

    gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

    lineEdit_2 = new QLineEdit(centralWidget);
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));
    lineEdit_2->setMaxLength(4);

    gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

    label = new QLabel(centralWidget);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 2, 0, 1, 1);

    lineEdit_3 = new QLineEdit(centralWidget);
    lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

    gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

    label_2 = new QLabel(centralWidget);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout->addWidget(label_2, 3, 0, 1, 1);

    lineEdit_4 = new QLineEdit(centralWidget);
    lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
    lineEdit_4->setEchoMode(QLineEdit::Password);

    gridLayout->addWidget(lineEdit_4, 3, 1, 1, 1);

    pushButton = new QPushButton(centralWidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    gridLayout->addWidget(pushButton, 4, 1, 1, 1);

    ClienteClass->setCentralWidget(centralWidget);
    menuBar = new QMenuBar(ClienteClass);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 264, 24));
    menuArchivo = new QMenu(menuBar);
    menuArchivo->setObjectName(QString::fromUtf8("menuArchivo"));
    menuAyuda = new QMenu(menuBar);
    menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
    ClienteClass->setMenuBar(menuBar);
    mainToolBar = new QToolBar(ClienteClass);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    ClienteClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(ClienteClass);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    ClienteClass->setStatusBar(statusBar);

    menuBar->addAction(menuArchivo->menuAction());
    menuBar->addAction(menuAyuda->menuAction());
    menuArchivo->addAction(actionSalir);
    menuAyuda->addAction(actionAcerca_de);

    retranslateUi(ClienteClass);

    QMetaObject::connectSlotsByName(ClienteClass);
    } // setupUi

    void retranslateUi(QMainWindow *ClienteClass)
    {
    ClienteClass->setWindowTitle(QApplication::translate("ClienteClass", "Login", 0, QApplication::UnicodeUTF8));
    actionSalir->setText(QApplication::translate("ClienteClass", "Salir", 0, QApplication::UnicodeUTF8));
    actionAcerca_de->setText(QApplication::translate("ClienteClass", "Acerca de...", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("ClienteClass", "IP Servidor", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("ClienteClass", "Puerto", 0, QApplication::UnicodeUTF8));
    lineEdit->setInputMask(QApplication::translate("ClienteClass", "000.000.000.000; ", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("ClienteClass", "Usuario", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("ClienteClass", "Contrase\303\261a", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("ClienteClass", "Conectarse", 0, QApplication::UnicodeUTF8));
    menuArchivo->setTitle(QApplication::translate("ClienteClass", "Archivo", 0, QApplication::UnicodeUTF8));
    menuAyuda->setTitle(QApplication::translate("ClienteClass", "Ayuda", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ClienteClass: public Ui_ClienteClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTE_H
