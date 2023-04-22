#pragma once
#include <QMainWindow>
#include <iostream>
#include "ui_MainWindow.h"
#include "videoWindow.h"
#include "wordSlice.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

	void initForm();
	void initStyle();
	void initUniqueStyle();
	void initSignal();
	void initDb();
	void upDate();

private:
	Ui::MainWindow ui;
	std::unique_ptr<videoWindow> vedio_form_;
	std::vector<wordSlice> wordBook_;
	std::vector<wordSlice>::iterator it_;
	uint32_t wordCount_;
	uint32_t wordIndex_;
private slots:
	void makeWord_slot();
	void next_slot();
	void previous_slot();
};
