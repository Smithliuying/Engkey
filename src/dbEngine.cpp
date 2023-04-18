#include <iostream>
#include <string>
#include "dbEngine.h"
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>


dbEngine* dbEngine::getInst()
{
	static dbEngine db;
	return &db;
}

void dbEngine::loadJson(const std::string& js)
{
	QFile file(js.c_str());
	file.open(QIODevice::ReadOnly);
	QString data = file.readAll();

	QJsonDocument doc = QJsonDocument::fromJson(data.toUtf8());
	QJsonObject obj = doc.object();

	QString name = obj["name"].toString();
	int age = obj["age"].toInt();
	bool married = obj["married"].toBool();

	QJsonObject address = obj["address"].toObject();
	QString street = address["street"].toString();

	QJsonArray hobbies = obj["hobbies"].toArray();
	QString hobby1 = hobbies[0].toString();
}

dbEngine::dbEngine()
{
}

dbEngine::~dbEngine()
{
}
