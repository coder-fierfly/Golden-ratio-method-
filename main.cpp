#include "mainwindow.h"//деректива и макрос

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setWindowTitle("Метод золотого сечения");
    w.show();
    return a.exec();
}
