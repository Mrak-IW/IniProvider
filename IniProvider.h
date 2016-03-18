#pragma once
#include <string>
#include <map>
using namespace std;

/// �����, ����������� ���������� � ������� � ��������� ���� ��������� �� ����������������� �����/������ �����.
/// ����� ��������, ��� ����� �������� �������� �� ����� ��� �������� ��������� � ������ 
/// � �� ��������� ������� ����� ��������, ���� ��� ����� ���������� ��������� ��������.
class IniProvider : public map<string, string>
{
private:
	/// ��������� �� ����� �����, �� �������� ����� ������� ���������
	istream *iniFile;
public:
	/// \brief ������� ������ �������� �� ���������
	/// \param iniFile	istream & - ����� �����. ��������� �� ������.
	IniProvider(istream &iniFile);
	~IniProvider();

	/// ���������� ��������� �� �����
	void LoadData();

	/// \brief ��������� ������� ���������� ��������� � �����
	/// \param key	string - ��� ���������
	///
	/// \return bool - TRUE, ���� ��������� � ����� ����
	bool ContainsKey(string key);
};

