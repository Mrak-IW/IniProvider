#pragma once
#include <string>
#include <map>
using namespace std;

class IniProvider
{
public:
	map<string, string> properties;
	istream *iniFile;

	IniProvider(istream &iniFile);
	void LoadData();
	~IniProvider();
};

