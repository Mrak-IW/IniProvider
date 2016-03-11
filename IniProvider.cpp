#include <iostream>
#include <sstream>
#include "IniProvider.h"


IniProvider::IniProvider(istream &iniFile)
{
	this->iniFile = &iniFile;
	LoadData();
}

IniProvider::~IniProvider()
{
}

void IniProvider::LoadData()
{
	const int wordCount = 3;
	string buf;
	string words[wordCount];
	string &paramName = words[0];
	string &sign = words[1];
	string &paramValue = words[2];
	istream &file = *iniFile;
	int i;

	while (!file.eof())
	{
		getline(file, buf);
		istringstream iss(buf);
		//Разбиваем строку на слова
		for (i = 0; i < wordCount && iss >> words[i]; i++);

		//Проверка на соответствие шаблону "<имя> = <значение>" и несоответствие "#комментарий"
		if (i == wordCount)
		{
			if (paramName[0] != '#' && sign == "=")
			{
				(*this).insert(pair<string, string>(paramName, paramValue));
			}
		}
	}

}

bool IniProvider::ContainsKey(string key)
{
	return (*this).find(key) != (*this).end();
}


