#include "control.h"


#include<QMainWindow>

#include<QWidget>
#include<QPainter>
#include<QMouseEvent>
#include<QKeyEvent>
#include <vector>
#include<QMessageBox>
#include<memory>




Paint::Paint(Storage* my_storage1, QWidget* parent)
    : QWidget(parent),//вызов конструктора
    my_storage(my_storage1), //инициализация указателя на хранилище
    m_ctrlPressed(false) //при нажатии ctrl
{
    setFocusPolicy(Qt::StrongFocus);
    setMinimumSize(400, 300);
}


//Обработчик нажатия мыши
void Paint::mousePressEvent(QMouseEvent* event)
{
    //проверяем, что нажата ЛКМ
    if (event->button() == Qt::LeftButton)
    {
        //координаты клика относительно виджета
        QPoint clickPos = event->pos();
        bool found = false;

        // Проверяем объекты с конца (от последнего к первому)
        for (int i = my_storage->getCount() - 1; i >= 0; --i)
        {
            auto shape = my_storage->getObject(i);

            //проверяем, что фигура существует и клик попал в область
            if (shape && shape->contains(clickPos))
            {
                //если ctrl не нажата
                if (!m_ctrlPressed)
                {
                    //снимаем выделение со всех объектов
                    for (int j = 0; j < my_storage->getCount(); ++j)
                    {
                        auto currentShape = my_storage->getObject(j);
                        currentShape->setSelected(false);
                    }
                }
                shape->setSelected(true); //выделяем новый собственный объект
                found = true; //говорим, что объект нашли
                //break; //выделяем только верхний объект
            }
        }

        //если объект не нашли и ctrl не нажата
        if (!found && !m_ctrlPressed)
        {
            //снимаем выделение со всех объектов
            for (int i = 0; i < my_storage->getCount(); ++i)
            {
                auto shape = my_storage->getObject(i);
                shape->setSelected(false);
            }
        }

        //если не нашли другой объект под курсором
        if (!found)
        {
            //создаем новый круг в месте клика
            auto newCircle = std::make_shared<Circle>(clickPos);
            //добавляем круг 
            my_storage->add(newCircle);
        }
        update(); //вызов перерисовки
    }
}


void Paint::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    //создаем объект для рисования
    QPainter painter(this);

    //сглаживание
    painter.setRenderHint(QPainter::Antialiasing);

    //проходим по всем объектам в хранилище
    for (int i = 0; i < my_storage->getCount(); ++i)
    {
        //получаем объект по индексу
        auto shape = my_storage->getObject(i);

        //если объект существует
        if (shape)
        {
            shape->draw(painter); //вызываем метод рисования объекта
        }
    }
}

//метод, вызываемый при нажатии клавиши на клавиатуре
void Paint::keyPressEvent(QKeyEvent* event)
{
    //если нажата клавиша ctrl
    if (event->key() == Qt::Key_Control)
    {
        m_ctrlPressed = true;

    }
    //если нажата клавиша delete
    else if (event->key() == Qt::Key_Delete)
    {
        //удаляем все выделенные объекты
        my_storage->removeSelected();
        update();
    }
}

//метод,вызываемый при отпускании клавиш на клавиатуре
void Paint::keyReleaseEvent(QKeyEvent* event)
{
    //проверяем какая клавиша была отпущена
    if (event->key() == Qt::Key_Control)
    {
        m_ctrlPressed = false;

    }
}

MainWindow::MainWindow(QWidget* parent) : QMainWindow(parent), my_storage(100)
{
    // Устанавливаем заголовок окна
    setWindowTitle("Круги на форме");

    // Устанавливаем положение и размер окна:
    
    setGeometry(100, 100, 800, 600);

    // Создаем область рисования
    // Передаем ей адрес нашего хранилища и указатель на это окно как родителя
    m_paintArea = new Paint(&my_storage, this);

    // Устанавливаем область рисования как центральный виджет главного окна

    setCentralWidget(m_paintArea);
}





