#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_Laborat3_OOP_QtWidgetsApplication1.h"

class Laborat3_OOP_QtWidgetsApplication1 : public QMainWindow
{
    Q_OBJECT

public:
    Laborat3_OOP_QtWidgetsApplication1(QWidget *parent = nullptr);
    ~Laborat3_OOP_QtWidgetsApplication1();

private:
    Ui::Laborat3_OOP_QtWidgetsApplication1Class ui;
};

