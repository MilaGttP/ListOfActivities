
#include "Includes.h";
#include "Entering.h";
#include "CommandsMain.h";
#include "Func.h";

#include "SubMenu.h"

using namespace std;

static char startName[64];
int startPriority;
static char startDescription[128];
static char startDateTime[64];

bool SelectByStartName(Act* pObj)
{
	return strstr(pObj->Name, startName) == pObj->Name;
}

bool SelectByStartPriority(Act* pObj)
{
	return pObj->Priority == startPriority;
}

bool SelectByStartDescription(Act* pObj)
{
	return strstr(pObj->Description, startDescription) == pObj->Description;
}

bool SelectByStartDateTime(Act* pObj)
{
	return strstr(pObj->Date, startDateTime) == pObj->Date;
}


void FilterByName()
{
	cout << "\t������� ��������: ";
	cin.getline(startName, sizeof startName);
	cout << "\n";
	Filter(SelectByStartName);
}


void FilterByPriority()
{
	cout << "\t������� ���������: ";
	cin >> startPriority;
	cout << "\n";
	Filter(SelectByStartPriority);
}


void FilterByDescription()
{
	cout << "\t������� ��������: ";
	cin.getline(startDescription, sizeof startDescription);
	cout << "\n";
	Filter(SelectByStartDescription);
}


void FilterByDateTime()
{
	cout << "\t������� ����: ";
	cin.getline(startDateTime, sizeof startDateTime);
	cout << "\n";
	Filter(SelectByStartDateTime);
}


CommandInfoSub commandsFiltering[] =
{
	{ "��������", FilterByName },
	{ "����������", FilterByPriority },
	{ "��������", FilterByDescription },
	{ "���� � �������", FilterByDateTime }
};

const size_t COMMANDS_COUNT_FILTERING = sizeof commandsFiltering / sizeof(CommandInfoSub);

void ShowFiltering()
{
	cout << "\n\t����� ��... \n" << endl;
	for (size_t i = 0; i < COMMANDS_COUNT_FILTERING; i++)
		cout << "\t" << i << " - " << commandsFiltering[i].name << endl;
}


CommandInfoSub EnterCommandFilter()
{
	int index = EnterNumber("\t����� �������� ������", 0, COMMANDS_COUNT_FILTERING - 1);
	return commandsFiltering[index];
}


void RunFiltering()
{
	system("cls");
	Out();
	ShowFiltering();

	CommandInfoSub commandSubFilt = EnterCommandFilter();
	commandSubFilt.commandSub(); 
}