

#include <QApplication>
#include "control.h"

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);  // создаем приложение

    MainWindow window;  // создаем главное окно
    window.show();      // показываем окно

    return app.exec();  // запускаем главный цикл приложения
}