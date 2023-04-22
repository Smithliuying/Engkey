#pragma once

#include <QMainWindow>
#include <iostream>
#include "ui_MainWindow.h"
#include "videoWindow.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private:
	Ui::MainWindow ui;
	std::unique_ptr<videoWindow> vedio_form_;
private slots:
	void initForm();
	void initStyle();
	void initUniqueStyle();
	void initSignal();
	void makeWord_slot();
	void next_slot();
	void previous_slot();
};
