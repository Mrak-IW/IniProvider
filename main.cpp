#include <iostream>
#include <fstream>
#include <string>
#include "IniProvider.h"

void main()
{
	ifstream iniFile("test.ini");
	IniProvider *ip = new IniProvider(iniFile);
}