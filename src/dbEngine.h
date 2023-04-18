#pragma once
class dbEngine
{
public:
	static dbEngine* getInst();
	void loadJson(const std::string&);
private:
	dbEngine();
	~dbEngine();
};

