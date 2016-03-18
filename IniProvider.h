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
	/// \brief Создать объект настроек на основании
	/// \param iniFile	istream & - поток ввода. Передаётся по ссылке.
	IniProvider(istream &iniFile);
	~IniProvider();

	/// Подгрузить настройки из файла
	void LoadData();

	/// \brief Проверить наличие конкретной настройки в файле
	/// \param key	string - имя настройки
	///
	/// \return bool - TRUE, если настройка в файле есть
	bool ContainsKey(string key);
};

