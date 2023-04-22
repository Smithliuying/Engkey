#include "dbEngine.h"
#include "MainWindow.h"
#include <QFile>

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent),
    vedio_form_(std::make_unique<videoWindow>())
{
	ui.setupUi(this);
    this->initForm();
}

MainWindow::~MainWindow()
{}

void MainWindow::initForm()
{
    this->initStyle();
    this->initUniqueStyle();
    this->initSignal();
    this->initDb();
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

void MainWindow::initUniqueStyle()
{
    //ui.textEdit->setFrameShape(QFrame::NoFrame);
    //ui.textEdit->setLineWidth(0);
    //// 设置透明背景
    //QPalette p = ui.textEdit->palette();
    //p.setColor(QPalette::Base, Qt::transparent);
    //ui.textEdit->setPalette(p);
}

void MainWindow::initSignal()
{
    connect(ui.make_action, SIGNAL(triggered()), this, SLOT(makeWord_slot()));
}

void MainWindow::initDb()
{
   wordBook_ = std::move(dbEngine::getInst()->loadJson("C:\\Users\\lyj\\Documents\\穿靴子的猫.json"));
   it_ = wordBook_.begin();
   wordCount_ = wordBook_.size();
   wordIndex_ = 1;
   this->upDate();
}

void MainWindow::upDate()
{
    QString index= QString("%1/%2").arg(wordIndex_).arg(wordCount_);
    ui.label_count->setText(index);
    ui.txtEdit_value->setText(it_->value);
    ui.txtEdit_value->setAlignment(Qt::AlignHCenter);
    ui.label_define->setText(it_->definition);
    ui.label_translation->setText(it_->translation);
}

void MainWindow::makeWord_slot()
{
    vedio_form_->show();
}

void MainWindow::next_slot()
{
    wordIndex_++;
    if (++it_ == wordBook_.end())
    {
        it_ = wordBook_.begin();
        wordIndex_ = 1;
    }
    this->upDate();
}

void MainWindow::previous_slot()
{
    if (it_ == wordBook_.begin())
    {
        it_ = wordBook_.end() - 1;
        wordIndex_ = wordCount_;
    }
    else
    {
        --it_;
        --wordIndex_;
    }
    this->upDate();
}
