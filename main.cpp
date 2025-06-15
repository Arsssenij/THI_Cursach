<<<<<<< HEAD
#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia));
    MainWindow w;
    w.show();

    return a.exec();
}
=======
#include "mainwindow.h"
#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QLocale::setDefault(QLocale(QLocale::Russian, QLocale::Russia));
    MainWindow w;
    w.show();

    return a.exec();
}
>>>>>>> 4e7010b0031482420c027338dff6fef4a42a4113
