#include <iostream>
#include <fstream>
#include <string>
#include "IniProvider.h"

const char* iniName = "test.ini";

void main()
{
	setlocale(LC_ALL, "russian");
	ifstream iniFile(iniName);
	cout << "Тестирование чтения из INI-файла" << endl;
	if (iniFile.is_open())
	{
		IniProvider ini(iniFile);
		//cout << "ini.param2 = " << ini["param2"] << endl << "ini.test = " << ini["test"] << endl;
		cout << "ini.test = " << (ini.ContainsKey("test") ? "not null" : "null") << endl;
		for (auto item = ini.begin(); item != ini.end(); ++item)
		{
			cout << item->first << " : " << item->second << endl;
		}
	}
	else
	{
		cout << "Не получилось открыть файл \"" << iniName << "\"" << endl;
	}
}