/********************************************************************************
** Form generated from reading ui file 'mainwindow.ui'
**
** Created: Fri Mar 13 22:07:39 2009
**      by: Qt User Interface Compiler version 4.4.3
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClass
{
public:
    QAction *actionClose;
    QAction *actionAvilitar_puerto;
    QAction *actionDesavilitar_puerto;
    QAction *actionCambiar;
    QAction *actionSalir;
    QAction *actionAvilitar;
    QAction *actionDesavilitar;
    QAction *actionCambiar_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout_11;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGridLayout *gridLayout_9;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_4;
    QWidget *tab_2;
    QGridLayout *gridLayout_10;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_2;
    QLabel *label_2;
    QLineEdit *lineEdit_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_3;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QPushButton *pushButton;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuMenu;
    QMenu *menuPuertos;

    void setupUi(QMainWindow *MainWindowClass)
    {
    if (MainWindowClass->objectName().isEmpty())
        MainWindowClass->setObjectName(QString::fromUtf8("MainWindowClass"));
    MainWindowClass->resize(410, 254);
    actionClose = new QAction(MainWindowClass);
    actionClose->setObjectName(QString::fromUtf8("actionClose"));
    actionAvilitar_puerto = new QAction(MainWindowClass);
    actionAvilitar_puerto->setObjectName(QString::fromUtf8("actionAvilitar_puerto"));
    actionDesavilitar_puerto = new QAction(MainWindowClass);
    actionDesavilitar_puerto->setObjectName(QString::fromUtf8("actionDesavilitar_puerto"));
    actionCambiar = new QAction(MainWindowClass);
    actionCambiar->setObjectName(QString::fromUtf8("actionCambiar"));
    actionSalir = new QAction(MainWindowClass);
    actionSalir->setObjectName(QString::fromUtf8("actionSalir"));
    actionAvilitar = new QAction(MainWindowClass);
    actionAvilitar->setObjectName(QString::fromUtf8("actionAvilitar"));
    actionDesavilitar = new QAction(MainWindowClass);
    actionDesavilitar->setObjectName(QString::fromUtf8("actionDesavilitar"));
    actionCambiar_2 = new QAction(MainWindowClass);
    actionCambiar_2->setObjectName(QString::fromUtf8("actionCambiar_2"));
    centralWidget = new QWidget(MainWindowClass);
    centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
    gridLayout_11 = new QGridLayout(centralWidget);
    gridLayout_11->setSpacing(6);
    gridLayout_11->setMargin(11);
    gridLayout_11->setObjectName(QString::fromUtf8("gridLayout_11"));
    tabWidget = new QTabWidget(centralWidget);
    tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
    tab = new QWidget();
    tab->setObjectName(QString::fromUtf8("tab"));
    gridLayout_9 = new QGridLayout(tab);
    gridLayout_9->setSpacing(6);
    gridLayout_9->setMargin(11);
    gridLayout_9->setObjectName(QString::fromUtf8("gridLayout_9"));
    groupBox_3 = new QGroupBox(tab);
    groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
    gridLayout = new QGridLayout(groupBox_3);
    gridLayout->setSpacing(6);
    gridLayout->setMargin(11);
    gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
    label_3 = new QLabel(groupBox_3);
    label_3->setObjectName(QString::fromUtf8("label_3"));

    gridLayout->addWidget(label_3, 0, 0, 1, 1);

    lineEdit = new QLineEdit(groupBox_3);
    lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
    lineEdit->setMaxLength(5);
    lineEdit->setEchoMode(QLineEdit::Normal);
    lineEdit->setReadOnly(true);

    gridLayout->addWidget(lineEdit, 1, 0, 1, 1);

    label_4 = new QLabel(groupBox_3);
    label_4->setObjectName(QString::fromUtf8("label_4"));

    gridLayout->addWidget(label_4, 2, 0, 1, 1);

    lineEdit_4 = new QLineEdit(groupBox_3);
    lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
    lineEdit_4->setMaxLength(5);

    gridLayout->addWidget(lineEdit_4, 3, 0, 1, 1);


    gridLayout_9->addWidget(groupBox_3, 0, 0, 1, 1);

    groupBox_4 = new QGroupBox(tab);
    groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
    gridLayout_8 = new QGridLayout(groupBox_4);
    gridLayout_8->setSpacing(6);
    gridLayout_8->setMargin(11);
    gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
    gridLayout_7 = new QGridLayout();
    gridLayout_7->setSpacing(6);
    gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
    gridLayout_6 = new QGridLayout();
    gridLayout_6->setSpacing(6);
    gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
    radioButton_5 = new QRadioButton(groupBox_4);
    radioButton_5->setObjectName(QString::fromUtf8("radioButton_5"));

    gridLayout_6->addWidget(radioButton_5, 0, 0, 1, 1);

    radioButton_6 = new QRadioButton(groupBox_4);
    radioButton_6->setObjectName(QString::fromUtf8("radioButton_6"));

    gridLayout_6->addWidget(radioButton_6, 1, 0, 1, 1);

    radioButton_4 = new QRadioButton(groupBox_4);
    radioButton_4->setObjectName(QString::fromUtf8("radioButton_4"));

    gridLayout_6->addWidget(radioButton_4, 2, 0, 1, 1);


    gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);


    gridLayout_8->addLayout(gridLayout_7, 0, 0, 1, 1);


    gridLayout_9->addWidget(groupBox_4, 0, 1, 1, 1);

    tabWidget->addTab(tab, QString());
    tab_2 = new QWidget();
    tab_2->setObjectName(QString::fromUtf8("tab_2"));
    gridLayout_10 = new QGridLayout(tab_2);
    gridLayout_10->setSpacing(6);
    gridLayout_10->setMargin(11);
    gridLayout_10->setObjectName(QString::fromUtf8("gridLayout_10"));
    groupBox_2 = new QGroupBox(tab_2);
    groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
    gridLayout_2 = new QGridLayout(groupBox_2);
    gridLayout_2->setSpacing(6);
    gridLayout_2->setMargin(11);
    gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
    label = new QLabel(groupBox_2);
    label->setObjectName(QString::fromUtf8("label"));

    gridLayout_2->addWidget(label, 0, 0, 1, 1);

    lineEdit_2 = new QLineEdit(groupBox_2);
    lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

    gridLayout_2->addWidget(lineEdit_2, 1, 0, 1, 1);

    label_2 = new QLabel(groupBox_2);
    label_2->setObjectName(QString::fromUtf8("label_2"));

    gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

    lineEdit_3 = new QLineEdit(groupBox_2);
    lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
    lineEdit_3->setMaxLength(32767);
    lineEdit_3->setEchoMode(QLineEdit::Password);

    gridLayout_2->addWidget(lineEdit_3, 3, 0, 1, 1);


    gridLayout_10->addWidget(groupBox_2, 0, 0, 1, 1);

    groupBox = new QGroupBox(tab_2);
    groupBox->setObjectName(QString::fromUtf8("groupBox"));
    gridLayout_5 = new QGridLayout(groupBox);
    gridLayout_5->setSpacing(6);
    gridLayout_5->setMargin(11);
    gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
    gridLayout_4 = new QGridLayout();
    gridLayout_4->setSpacing(6);
    gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
    gridLayout_3 = new QGridLayout();
    gridLayout_3->setSpacing(6);
    gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
    radioButton = new QRadioButton(groupBox);
    radioButton->setObjectName(QString::fromUtf8("radioButton"));

    gridLayout_3->addWidget(radioButton, 0, 0, 1, 1);

    radioButton_2 = new QRadioButton(groupBox);
    radioButton_2->setObjectName(QString::fromUtf8("radioButton_2"));

    gridLayout_3->addWidget(radioButton_2, 1, 0, 1, 1);

    radioButton_3 = new QRadioButton(groupBox);
    radioButton_3->setObjectName(QString::fromUtf8("radioButton_3"));

    gridLayout_3->addWidget(radioButton_3, 2, 0, 1, 1);


    gridLayout_4->addLayout(gridLayout_3, 0, 0, 1, 1);

    pushButton = new QPushButton(groupBox);
    pushButton->setObjectName(QString::fromUtf8("pushButton"));

    gridLayout_4->addWidget(pushButton, 1, 0, 1, 1);


    gridLayout_5->addLayout(gridLayout_4, 0, 0, 1, 1);


    gridLayout_10->addWidget(groupBox, 0, 1, 1, 1);

    tabWidget->addTab(tab_2, QString());

    gridLayout_11->addWidget(tabWidget, 0, 0, 1, 1);

    MainWindowClass->setCentralWidget(centralWidget);
    mainToolBar = new QToolBar(MainWindowClass);
    mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
    MainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
    statusBar = new QStatusBar(MainWindowClass);
    statusBar->setObjectName(QString::fromUtf8("statusBar"));
    MainWindowClass->setStatusBar(statusBar);
    menuBar = new QMenuBar(MainWindowClass);
    menuBar->setObjectName(QString::fromUtf8("menuBar"));
    menuBar->setGeometry(QRect(0, 0, 410, 24));
    menuMenu = new QMenu(menuBar);
    menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
    menuPuertos = new QMenu(menuMenu);
    menuPuertos->setObjectName(QString::fromUtf8("menuPuertos"));
    MainWindowClass->setMenuBar(menuBar);

    menuBar->addAction(menuMenu->menuAction());
    menuMenu->addAction(menuPuertos->menuAction());
    menuMenu->addAction(actionSalir);
    menuPuertos->addAction(actionAvilitar);
    menuPuertos->addAction(actionDesavilitar);
    menuPuertos->addAction(actionCambiar_2);

    retranslateUi(MainWindowClass);

    tabWidget->setCurrentIndex(0);


    QMetaObject::connectSlotsByName(MainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClass)
    {
    MainWindowClass->setWindowTitle(QApplication::translate("MainWindowClass", "Servidor Chat", 0, QApplication::UnicodeUTF8));
    actionClose->setText(QApplication::translate("MainWindowClass", "Close", 0, QApplication::UnicodeUTF8));
    actionAvilitar_puerto->setText(QApplication::translate("MainWindowClass", "Avilitar puerto", 0, QApplication::UnicodeUTF8));
    actionDesavilitar_puerto->setText(QApplication::translate("MainWindowClass", "Desavilitar puerto", 0, QApplication::UnicodeUTF8));
    actionCambiar->setText(QApplication::translate("MainWindowClass", "Cambiar", 0, QApplication::UnicodeUTF8));
    actionSalir->setText(QApplication::translate("MainWindowClass", "Salir", 0, QApplication::UnicodeUTF8));
    actionAvilitar->setText(QApplication::translate("MainWindowClass", "Habilitar", 0, QApplication::UnicodeUTF8));
    actionDesavilitar->setText(QApplication::translate("MainWindowClass", "Deshabilitar", 0, QApplication::UnicodeUTF8));
    actionCambiar_2->setText(QApplication::translate("MainWindowClass", "Cambiar", 0, QApplication::UnicodeUTF8));
    groupBox_3->setTitle(QString());
    label_3->setText(QApplication::translate("MainWindowClass", "Puerto en Uso", 0, QApplication::UnicodeUTF8));
    label_4->setText(QApplication::translate("MainWindowClass", "Nuebo Puerto", 0, QApplication::UnicodeUTF8));
    groupBox_4->setTitle(QApplication::translate("MainWindowClass", " Accion", 0, QApplication::UnicodeUTF8));
    radioButton_5->setText(QApplication::translate("MainWindowClass", "Habilitar", 0, QApplication::UnicodeUTF8));
    radioButton_6->setText(QApplication::translate("MainWindowClass", "Deshabilitar", 0, QApplication::UnicodeUTF8));
    radioButton_4->setText(QApplication::translate("MainWindowClass", "Cambiar", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindowClass", "Configuracion", 0, QApplication::UnicodeUTF8));
    groupBox_2->setTitle(QString());
    label->setText(QApplication::translate("MainWindowClass", "Usuario", 0, QApplication::UnicodeUTF8));
    label_2->setText(QApplication::translate("MainWindowClass", "Contrase\303\261a", 0, QApplication::UnicodeUTF8));
    lineEdit_3->setText(QString());
    lineEdit_3->setInputMask(QString());
    groupBox->setTitle(QApplication::translate("MainWindowClass", " Accion", 0, QApplication::UnicodeUTF8));
    radioButton->setText(QApplication::translate("MainWindowClass", "Crear", 0, QApplication::UnicodeUTF8));
    radioButton_2->setText(QApplication::translate("MainWindowClass", "Eliminar", 0, QApplication::UnicodeUTF8));
    radioButton_3->setText(QApplication::translate("MainWindowClass", "Cambiar", 0, QApplication::UnicodeUTF8));
    pushButton->setText(QApplication::translate("MainWindowClass", "Ejecutar", 0, QApplication::UnicodeUTF8));
    tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindowClass", "Administrar Cuentas", 0, QApplication::UnicodeUTF8));
    menuMenu->setTitle(QApplication::translate("MainWindowClass", "Menu", 0, QApplication::UnicodeUTF8));
    menuPuertos->setTitle(QApplication::translate("MainWindowClass", "Puertos", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClass: public Ui_MainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
