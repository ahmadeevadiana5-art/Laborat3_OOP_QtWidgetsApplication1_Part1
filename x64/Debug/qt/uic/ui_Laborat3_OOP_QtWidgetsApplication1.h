/********************************************************************************
** Form generated from reading UI file 'Laborat3_OOP_QtWidgetsApplication1.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LABORAT3_OOP_QTWIDGETSAPPLICATION1_H
#define UI_LABORAT3_OOP_QTWIDGETSAPPLICATION1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Laborat3_OOP_QtWidgetsApplication1Class
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *Laborat3_OOP_QtWidgetsApplication1Class)
    {
        if (Laborat3_OOP_QtWidgetsApplication1Class->objectName().isEmpty())
            Laborat3_OOP_QtWidgetsApplication1Class->setObjectName("Laborat3_OOP_QtWidgetsApplication1Class");
        Laborat3_OOP_QtWidgetsApplication1Class->resize(600, 400);
        menuBar = new QMenuBar(Laborat3_OOP_QtWidgetsApplication1Class);
        menuBar->setObjectName("menuBar");
        Laborat3_OOP_QtWidgetsApplication1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(Laborat3_OOP_QtWidgetsApplication1Class);
        mainToolBar->setObjectName("mainToolBar");
        Laborat3_OOP_QtWidgetsApplication1Class->addToolBar(mainToolBar);
        centralWidget = new QWidget(Laborat3_OOP_QtWidgetsApplication1Class);
        centralWidget->setObjectName("centralWidget");
        Laborat3_OOP_QtWidgetsApplication1Class->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(Laborat3_OOP_QtWidgetsApplication1Class);
        statusBar->setObjectName("statusBar");
        Laborat3_OOP_QtWidgetsApplication1Class->setStatusBar(statusBar);

        retranslateUi(Laborat3_OOP_QtWidgetsApplication1Class);

        QMetaObject::connectSlotsByName(Laborat3_OOP_QtWidgetsApplication1Class);
    } // setupUi

    void retranslateUi(QMainWindow *Laborat3_OOP_QtWidgetsApplication1Class)
    {
        Laborat3_OOP_QtWidgetsApplication1Class->setWindowTitle(QCoreApplication::translate("Laborat3_OOP_QtWidgetsApplication1Class", "Laborat3_OOP_QtWidgetsApplication1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Laborat3_OOP_QtWidgetsApplication1Class: public Ui_Laborat3_OOP_QtWidgetsApplication1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LABORAT3_OOP_QTWIDGETSAPPLICATION1_H
