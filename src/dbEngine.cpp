#include <iostream>
#include <string>
#include <vector>
#include "wordSlice.h"
#include "dbEngine.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <fstream>


dbEngine* dbEngine::getInst()
{
	static dbEngine db;
	return &db;
}

std::vector<wordSlice> dbEngine::loadJson(const std::string& js)
{
	std::vector<wordSlice> wordsbook;
	QFile file(QString::fromLocal8Bit(js.c_str()));
	if (!file.open(QIODevice::ReadOnly))
		qDebug() << "file not found!";
	QString data = file.readAll();
	QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
	QJsonObject obj = doc.object();

	QJsonArray wordLists = obj["wordList"].toArray();
	wordSlice slice;
	foreach (QJsonValue word, wordLists)
	{
		slice.value =  word["value"].toString();
		slice.usphone =  word["usphone"].toString();
		slice.ukphone = word["ukphone"].toString();
		slice.definition = word["definition"].toString();
		slice.translation = word["translation"].toString();
		slice.exchange = word["exchange"].toString();
		slice.captions = word["captions"].toString();
		wordsbook.push_back(std::move(slice));
	}
	
	return wordsbook;
	/*int age = obj["age"].toInt();
	bool married = obj["married"].toBool();

	QJsonObject address = obj["address"].toObject();
	QString street = address["street"].toString();

	QJsonArray hobbies = obj["hobbies"].toArray();
	QString hobby1 = hobbies[0].toString();*/
}

dbEngine::dbEngine()
{
}

dbEngine::~dbEngine()
{
}
