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

	this->clear();

	while (!file.eof())
	{
		getline(file, buf);
		istringstream iss(buf);
		//��������� ������ �� �����
		for (i = 0; i < wordCount && iss >> words[i]; i++);

		//�������� �� ������������ ������� <���> = <��������> ��� <���> = "������ - ��������" � �������������� #�����������
		if (i == wordCount)
		{
			if (sign == "=")
			{
				//���� ������ - �� �����������
				if (paramName[0] != '#')
				{
					//���� �� ����� ��������� ��������
					if (paramValue[0] == '\"')
					{
						//���� ������ �� ����� ��� ������ �����
						if (paramValue[paramValue.length() - 1] != '\"')
						{
							getline(iss, buf, '\"');
							paramValue = paramValue.substr(1) + buf;
						}
						else
						{
							paramValue = paramValue.substr(1, paramValue.length() - 2);
						}
					}
					(*this).insert(pair<string, string>(paramName, paramValue));
				}
			}
		}
	}
}

bool IniProvider::ContainsKey(string key)
{
	return (*this).find(key) != (*this).end();
}


