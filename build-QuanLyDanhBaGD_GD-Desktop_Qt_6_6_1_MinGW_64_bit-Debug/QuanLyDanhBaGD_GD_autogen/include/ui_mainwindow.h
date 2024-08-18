/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *labelTen;
    QLineEdit *lineEditTen;
    QLabel *labelSoDienThoai;
    QLineEdit *lineEditSoDienThoai;
    QPushButton *btnThemLienHe;
    QPushButton *btnXoaLienHe;
    QListWidget *listWidgetLienHe;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        labelTen = new QLabel(centralwidget);
        labelTen->setObjectName("labelTen");
        labelTen->setGeometry(QRect(50, 20, 100, 20));
        lineEditTen = new QLineEdit(centralwidget);
        lineEditTen->setObjectName("lineEditTen");
        lineEditTen->setGeometry(QRect(150, 20, 200, 20));
        labelSoDienThoai = new QLabel(centralwidget);
        labelSoDienThoai->setObjectName("labelSoDienThoai");
        labelSoDienThoai->setGeometry(QRect(50, 60, 100, 20));
        lineEditSoDienThoai = new QLineEdit(centralwidget);
        lineEditSoDienThoai->setObjectName("lineEditSoDienThoai");
        lineEditSoDienThoai->setGeometry(QRect(150, 60, 200, 20));
        btnThemLienHe = new QPushButton(centralwidget);
        btnThemLienHe->setObjectName("btnThemLienHe");
        btnThemLienHe->setGeometry(QRect(50, 100, 100, 30));
        btnXoaLienHe = new QPushButton(centralwidget);
        btnXoaLienHe->setObjectName("btnXoaLienHe");
        btnXoaLienHe->setGeometry(QRect(160, 100, 100, 30));
        listWidgetLienHe = new QListWidget(centralwidget);
        listWidgetLienHe->setObjectName("listWidgetLienHe");
        listWidgetLienHe->setGeometry(QRect(50, 150, 300, 300));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qu\341\272\243n L\303\275 Danh B\341\272\241", nullptr));
        labelTen->setText(QCoreApplication::translate("MainWindow", "T\303\252n Li\303\252n H\341\273\207:", nullptr));
        labelSoDienThoai->setText(QCoreApplication::translate("MainWindow", "S\341\273\221 \304\220i\341\273\207n Tho\341\272\241i:", nullptr));
        btnThemLienHe->setText(QCoreApplication::translate("MainWindow", "Th\303\252m Li\303\252n H\341\273\207", nullptr));
        btnXoaLienHe->setText(QCoreApplication::translate("MainWindow", "X\303\263a Li\303\252n H\341\273\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
