
#include "Includes.h";
#include "CommandsMain.h"
#include "Func.h";
#include "Entering.h";
#include "FuncWithEntering.h";
#include "TestingData.h";

using namespace std;

void OutObjectDetails()
{
	size_t num = EnterNumber("\tНомер записи", 1, (int)Getlenght());
	Act* p = ElementAt(num - 1);

	system("cls");
	Out();

	OutObjectDetails(p);
}


void Out()
{
	if (Empty())
		cout << "Список дел пуст! \n";

	else
	{
		cout << "Список дел: \n\n";

		cout << left << setw(2) << "№"
			<< setw(20) << "Название дела"
			<< setw(25) << "Дата и время"
			<< setw(12) << "Приоритет \n";

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
	size_t num = EnterNumber("\tНомер записи", 1, (int)Getlenght());
	Act* p = ElementAt(num - 1);

	Edit(p);
}


void Delete()
{
	int num = EnterNumber("\tНомер записи", 1, (int)Getlenght());
	DeleteAt(num - 1);
}