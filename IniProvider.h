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
	// ��, XML-�������� �� VisualStudio DoxyGen ���� ���
	/// <summary> ������� ������ �������� �� ��������� ����� �������� </summary>
	/// <param name="iniFile"> ����� ����� - ���� ��������. ��������� �� ������. </param>
	IniProvider(istream &iniFile);
	~IniProvider();

	/// ���������� ��������� �� �����
	void LoadData();

	/// <summary>
	/// ��������� ������� ���������� ��������� � �����
	/// </summary>
	/// <param name="key">��� ���������</param>
	/// <returns>TRUE, ���� ��������� � ����� ����</returns>
	bool ContainsKey(string key);
};

