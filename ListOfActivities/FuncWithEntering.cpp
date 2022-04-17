
#include "Includes.h";
#include "Entering.h";
#include "FuncWithEntering.h";
#include "DateTime.h";
#include "Func.h";
#include "Input.h";
#include "CommandsMain.h";

using namespace std;

void OutObjectDetails(Act* pObj)
{
	cout << "\n\tОписание: \n\n" << pObj->Description;
}


void OutObject(Act* pObj, size_t num)
{
	cout << left << setw(2) << num << " "
		<< setw(20) << pObj->Name
		<< setw(25) << pObj->Date
		<< setw(12) << pObj->Priority << endl;

	cout << setfill('-') << setw(60) << '-' << setfill(' ') << endl;
}


Act* Create()
{
	system("cls");
	Out();

	Act* p = new Act();

	cout << "\n\tВведите данные дела: \n";

	cout << "\tНазвание дела: ";
	cin.getline(p->Name, NAME_SIZE);

	cout << "\tДата и время: ";
	cin.getline(p->Date, DATE_SIZE);

	cout << "\tПриоритет: ";
	cin >> p->Priority;
	cin.ignore();

	cout << "\n\tОписание: \n";
	char* sValue;
	InputMultilineText(cin, sValue);
	strncpy(p->Description, sValue, DESCRIPTION_SIZE);

	return p;
}


void Edit(Act* pObj)
{
	system("cls");
	Out();

	char buff[128];
	cout << "\n\tИзменение записи дела: \n";

	cout << "\tНазвание (" << pObj->Name << "): ";
	cin.getline(buff, NAME_SIZE);
	if (*buff != '\0')
		strncpy(pObj->Name, buff, NAME_SIZE);

	cout << "\tДата и время (" << pObj->Date << "): ";
	cin.getline(buff, DATE_SIZE);
	if (*buff != '\0')
		strncpy(pObj->Date, buff, DATE_SIZE);

	cout << "\tПриоритет (" << pObj->Priority << "): ";
	cin.getline(buff, sizeof buff);
	if (*buff != '\0')
		pObj->Priority = atof(buff);

	cout << "\tОписание (" << pObj->Description << "): ";
	cin.getline(buff, DESCRIPTION_SIZE);
	if (*buff != '\0')
		strncpy(pObj->Description, buff, DESCRIPTION_SIZE);

	cout << "\n" << endl;
}