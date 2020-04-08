/********************************************************************************
** Form generated from reading ui file 'chat.ui'
**
** Created: Fri Mar 13 21:34:14 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_CHAT_H
#define UI_CHAT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QListWidget>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QSplitter>
#include <QtGui/QStatusBar>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDesconectarse;
    QAction *actionAcerca_de;
    QAction *actionConectarse;
    QAction *actionSalir;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSplitter *splitter;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_3;
    QTextEdit *textEdit;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_2;
    QListWidget *listWidget;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QMenu *menuEstado;
    QMenu *menuAyuda;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(479, 330);
    actionDesconectarse = new QAction(MainWindow);
    actionDesconectarse->setObjectName(QString::fromUtf8("actionDesconectarse"));
    actionAcerca_de = new QAction(MainWindow);
    actionAcerca_de->setObjectName(QString::fromUtf8("actionAcerca_de"));
    actionConectarse = new QAction(MainWindow);
    actionConectarse->setObjectName(QString::fromUtf8("actionConectarse"));
    actionSalir = new QAction(MainWindow);
    actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    gridLayout = new QGridLayout(centralwidget);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    splitter = new QSplitter(centralwidget);
    splitter->setObjectName(QString::fromUtf8("splitter"));
    splitter->setOrientation(Qt::Horizontal);
    layoutWidget = new QWidget(splitter);
    layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
    verticalLayout = new QVBoxLayout(layoutWidget);
    verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
    verticalLayout->setContentsMargins(0, 0, 0, 0);
    label_3 = new QLabel(layoutWidget);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    verticalLayout->addWidget(label_3);

    textEdit = new QTextEdit(layoutWidget);
    textEdit->setObjectName(QString::fromUtf8("textEdit"));

    verticalLayout->addWidget(textEdit);

    splitter->addWidget(layoutWidget);
    layoutWidget1 = new QWidget(splitter);
    layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
    verticalLayout_2 = new QVBoxLayout(layoutWidget1);
    verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
    verticalLayout_2->setContentsMargins(0, 0, 0, 0);
    label_2 = new QLabel(layoutWidget1);
    label_2->setObjectName(QString::fromUtf8("label_2"));
    label_2->setAlignment(Qt::AlignCenter);

    verticalLayout_2->addWidget(label_2);

    listWidget = new QListWidget(layoutWidget1);
    listWidget->setObjectName(QString::fromUtf8("listWidget"));

    verticalLayout_2->addWidget(listWidget);

    splitter->addWidget(layoutWidget1);

    gridLayout->addWidget(splitter, 0, 0, 1, 3);

    label = new QLabel(centralwidget);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout->addWidget(label, 1, 0, 1, 1);

    lineEdit = new QLineEdit(centralwidget);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

    gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

    pushButton = new QPushButton(centralwidget);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    gridLayout->addWidget(pushButton, 1, 2, 1, 1);

    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 479, 24));
    menuEstado = new QMenu(menubar);
    menuEstado->setObjectName(QString::fromUtf8("menuEstado"));
    menuAyuda = new QMenu(menubar);
    menuAyuda->setObjectName(QString::fromUtf8("menuAyuda"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    menubar->addAction(menuEstado->menuAction());
    menubar->addAction(menuAyuda->menuAction());
    menuEstado->addAction(actionDesconectarse);
    menuEstado->addAction(actionConectarse);
    menuEstado->addAction(actionSalir);
    menuAyuda->addAction(actionAcerca_de);

    retranslateUi(MainWindow);

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Cliente de Chat", 0, QApplication::UnicodeUTF8));
    actionDesconectarse->setText(QApplication::translate("MainWindow", "Desconectarse", 0, QApplication::UnicodeUTF8));
    actionAcerca_de->setText(QApplication::translate("MainWindow", "Acerca de...", 0, QApplication::UnicodeUTF8));
    actionConectarse->setText(QApplication::translate("MainWindow", "Conectarse", 0, QApplication::UnicodeUTF8));
    actionSalir->setText(QApplication::translate("MainWindow", "Salir", 0, QApplication::UnicodeUTF8));
    label_3->setText(QApplication::translate("MainWindow", "Ventana de charla", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindow", "Usuario", 0, QApplication::UnicodeUTF8));
    label->setText(QApplication::translate("MainWindow", "Mensaje :", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("MainWindow", "Enviar", 0, QApplication::UnicodeUTF8));
    menuEstado->setTitle(QApplication::translate("MainWindow", "Estado", 0, QApplication::UnicodeUTF8));
    menuAyuda->setTitle(QApplication::translate("MainWindow", "Ayuda", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHAT_H
