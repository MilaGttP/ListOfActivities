
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
	cout << "\tУкажите название: ";
	cin.getline(startName, sizeof startName);
	cout << "\n";
	Filter(SelectByStartName);
}


void FilterByPriority()
{
	cout << "\tУкажите приоритет: ";
	cin >> startPriority;
	cout << "\n";
	Filter(SelectByStartPriority);
}


void FilterByDescription()
{
	cout << "\tУкажите описание: ";
	cin.getline(startDescription, sizeof startDescription);
	cout << "\n";
	Filter(SelectByStartDescription);
}


void FilterByDateTime()
{
	cout << "\tУкажите дату: ";
	cin.getline(startDateTime, sizeof startDateTime);
	cout << "\n";
	Filter(SelectByStartDateTime);
}


CommandInfoSub commandsFiltering[] =
{
	{ "Названию", FilterByName },
	{ "Приоритету", FilterByPriority },
	{ "Описанию", FilterByDescription },
	{ "Дате и времени", FilterByDateTime }
};

const size_t COMMANDS_COUNT_FILTERING = sizeof commandsFiltering / sizeof(CommandInfoSub);

void ShowFiltering()
{
	cout << "\n\tПоиск по... \n" << endl;
	for (size_t i = 0; i < COMMANDS_COUNT_FILTERING; i++)
		cout << "\t" << i << " - " << commandsFiltering[i].name << endl;
}


CommandInfoSub EnterCommandFilter()
{
	int index = EnterNumber("\tНомер комманды поиска", 0, COMMANDS_COUNT_FILTERING - 1);
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