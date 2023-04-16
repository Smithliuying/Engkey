#include "MainWindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
    this->initForm();
}

MainWindow::~MainWindow()
{}

void MainWindow::initForm()
{
    this->initStyle();
}

void MainWindow::initStyle()
{
    //加载样式表
    //QFile file(":/qss/psblack.css");
    //QFile file(":/qss/flatwhite.css");
    QFile file(":/qss/lightblue.css");
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        QString paletteColor = qss.mid(20, 7);
        qApp->setPalette(QPalette(QColor(paletteColor)));
        qApp->setStyleSheet(qss);
        file.close();
    }
}