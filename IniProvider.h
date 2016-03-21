#pragma once
#include <string>
#include <map>
using namespace std;

/// Класс, позволяющий вычитывать и хранить в текстовом виде настройки из конфигурационного файла/потока ввода.
/// Стоит отметить, что после загрузки настроек из файла они хранятся автономно в памяти 
/// и не требуется держать поток открытым, если нет нужды подгрузить настройки повторно.
class IniProvider : public map<string, string>
{
private:
	/// Указатель на поток ввода, из которого будут считаны настройки
	istream *iniFile;
public:
	// Да, XML-комменты от VisualStudio DoxyGen тоже жрёт
	/// <summary> Создать объект настроек на основании </summary>
	/// <param name="iniFile"> Поток ввода. Передаётся по ссылке. </param>
	IniProvider(istream &iniFile);
	~IniProvider();

	/// Подгрузить настройки из файла
	void LoadData();

	/// <summary>
	/// Проверить наличие конкретной настройки в файле
	/// </summary>
	/// <param name="key">Имя настройки</param>
	/// <returns>TRUE, если настройка в файле есть</returns>
	bool ContainsKey(string key);
};

