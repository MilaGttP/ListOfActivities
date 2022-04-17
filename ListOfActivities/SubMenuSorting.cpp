
#include "Includes.h";
#include "Entering.h";
#include "Func.h";
#include "CommandsMain.h";

#include "SubMenu.h"

using namespace std;

bool CompareByPriority(Act* ptr1, Act* ptr2)
{
	return ptr1->Priority < ptr2->Priority;
}


bool CompareByDateTime(Act* ptr1, Act* ptr2)
{
	return strcmp(ptr1->Date, ptr2->Date) < 0;
}


void SortByPriority()
{
	Sort(CompareByPriority);
}


void SortByDateTime()
{
	Sort(CompareByDateTime);
}


CommandInfoSub commandsSorting[] =
{
	{ "Приоритету", SortByPriority },
	{ "Дате", SortByDateTime }
};

const size_t COMMANDS_COUNT_SORTING = sizeof commandsSorting / sizeof(CommandInfoSub);

void ShowSorting()
{
	cout << "\n\tСортировать по...\n" << endl;
	for (size_t i = 0; i < COMMANDS_COUNT_SORTING; i++)
		cout << "\t" << i << " - " << commandsSorting[i].name << endl;
}


CommandInfoSub EnterCommandSorting()
{
	int index = EnterNumber("\tНомер комманды сортировки", 0, COMMANDS_COUNT_SORTING);
	return commandsSorting[index];
}


void RunSorting()
{
	system("cls");
	Out();
	ShowSorting();

	CommandInfoSub commandSubSort = EnterCommandSorting();
	commandSubSort.commandSub();
}