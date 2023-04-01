/** @file main.cpp
 *  @brief implementation of main method.
 *
 *  @author Mateusz Kokoszka
 *  @bug No known bugs.
 */

#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();

    return 0;
}
