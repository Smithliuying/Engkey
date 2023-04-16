#pragma once

#include <QWidget>
#include "ui_videoWindow.h"

class videoWindow : public QWidget
{
	Q_OBJECT

public:
	videoWindow(QWidget *parent = nullptr);
	~videoWindow();

private:
	Ui::videoWindowClass ui;
};
