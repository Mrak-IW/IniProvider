#pragma once
#include <string>
#include <map>
using namespace std;

class IniProvider : public map<string, string>
{
private:
	istream *iniFile;
public:
	IniProvider(istream &iniFile);
	~IniProvider();

	void LoadData();
	bool ContainsKey(string key);
};

