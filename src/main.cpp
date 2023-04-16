#include <QApplication>
#include "MainWindow.h"

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    w.setWindowTitle("enKey   Author: yingjiejk@163.com   QQ: 1163649807");
    w.show();
    return app.exec();
}