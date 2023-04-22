#pragma once
#include <iostream>
#include <vector>
#include "wordSlice.h"
class dbEngine
{
public:
	static dbEngine* getInst();
	std::vector<wordSlice> loadJson(const std::string& js);
private:
	dbEngine();
	~dbEngine();
};

