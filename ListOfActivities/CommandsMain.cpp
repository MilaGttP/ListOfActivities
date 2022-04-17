
#include "Includes.h";
#include "CommandsMain.h"
#include "Func.h";
#include "Entering.h";
#include "FuncWithEntering.h";
#include "TestingData.h";

using namespace std;

void OutObjectDetails()
{
	size_t num = EnterNumber("\t����� ������", 1, (int)Getlenght());
	Act* p = ElementAt(num - 1);

	system("cls");
	Out();

	OutObjectDetails(p);
}


void Out()
{
	if (Empty())
		cout << "������ ��� ����! \n";

	else
	{
		cout << "������ ���: \n\n";

		cout << left << setw(2) << "�"
			<< setw(20) << "�������� ����"
			<< setw(25) << "���� � �����"
			<< setw(12) << "��������� \n";

		cout << setfill('=') << setw(60) << '=' << setfill(' ') << endl;

		for (size_t i = 0; i < Getlenght(); i++)
			OutObject(ElementAt(i), i + 1);
	}
}


void CreateTestingData()
{
	AddRange(testingArr, TEST_ARR_SIZE);
}


void Add()
{
	Add(Create());
}


void Edit()
{
	size_t num = EnterNumber("\t����� ������", 1, (int)Getlenght());
	Act* p = ElementAt(num - 1);

	Edit(p);
}


void Delete()
{
	int num = EnterNumber("\t����� ������", 1, (int)Getlenght());
	DeleteAt(num - 1);
}