#ifndef CONTROL_H
#define CONTROL_H


#include "storage.h"
#include "Circle.h"
#include "abstract_shape.h"

#include <QMainWindow>
#include<QWidget> 
#include<QPoint> //хранение координат точек
#include<QPainter> 
#include<QPen>
#include<QBrush>
#include<QMouseEvent>
#include<QKeyEvent>


#include <memory>
#include<vector>

//создаем область для рисования которая является виджетом
class Paint :public QWidget
{
    Q_OBJECT

private:
    //указатель на объект, который хранит все круги
    Storage* my_storage;
    bool m_ctrlPressed;

public:
    Paint(Storage* my_storage1, QWidget* parent = nullptr);

protected:
    void paintEvent(QPaintEvent* event) override;


    // Метод, который вызывается при нажатии кнопки мыши
    void mousePressEvent(QMouseEvent* event) override;

    //метод, вызываемый при нажатии клавиши на клавиатуре

    void keyPressEvent(QKeyEvent* event) override;

    //метод,вызываемый при отпускании клавиш на клавиатуре
    void keyReleaseEvent(QKeyEvent* event) override;

};




class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    Storage my_storage;

    Paint* m_paintArea;

public:
    MainWindow(QWidget* parent = nullptr);


};

#endif //CONTROL_H