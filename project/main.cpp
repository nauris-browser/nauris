#include "mainwindow.h"
#include "browsertab.h"
#include <QApplication>
#include <QWebView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    //w.setWindowTitle("Nauris");
    w.show();

    return a.exec();
}
