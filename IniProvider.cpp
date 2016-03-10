#include <iostream>
#include "IniProvider.h"


IniProvider::IniProvider(istream &iniFile)
{
	this->iniFile = &iniFile;
	LoadData();
}

void IniProvider::LoadData()
{
	string buf, parName, parValue;
	istream &file = *iniFile;
	
	//getline(file, str);
	while (!file.eof())
	{
		file >> parName;
		if (parName[0] == '#')
		{
			getline(file, buf);
		}
		else
		{
			file >> buf;
			file >> parValue;
		}
	}
}

IniProvider::~IniProvider()
{
}
