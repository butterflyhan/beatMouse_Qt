#include "mainwindow.h"
#include <QApplication>
#include "stdlib.h"
#include <time.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    srand((unsigned)time(nullptr));


    MainWindow w;
    w.show();

    return a.exec();
}
