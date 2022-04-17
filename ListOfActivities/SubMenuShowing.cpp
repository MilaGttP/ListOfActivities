
#include "Includes.h";
#include "CommandsMain.h";
#include "Entering.h";
#include "Func.h";
#include "DateTime.h";

#include "SubMenu.h"

using namespace std;

void ShowActsDay()
{
	cout << "\t������� ������� ����: ";
	char buff1[16], buff2[16], buff[32];
	cin.getline(buff1, sizeof buff1);

	strcpy(buff2, AddDay(buff1));
	cout << "\n";
	Show(buff1, buff2, buff);
}


void ShowActsWeek()
{
	cout << "\t������� ������� ����: ";
	char buff1[16], buff2[16], buff[32];
	cin.getline(buff1, sizeof buff1);

	strcpy(buff2, AddWeek(buff1));
	cout << "\n";
	Show(buff1, buff2, buff);
}


void ShowActsMonth()
{
	cout << "\t������� ������� ����: ";
	char buff1[16], buff2[16], buff[32];
	cin.getline(buff1, sizeof buff1);

	strcpy(buff2, AddMonth(buff1));
	cout << "\n";
	Show(buff1, buff2, buff);
}


CommandInfoSub commandsShowing[] =
{
	{ "����", ShowActsDay },
	{ "������", ShowActsWeek },
	{ "�����", ShowActsMonth }
};

const size_t COMMANDS_COUNT_SHOWING = sizeof commandsShowing / sizeof(CommandInfoSub);

void ShowShowing()
{
	cout << "\n\t�������� ������ ��...\n" << endl;
	for (size_t i = 0; i < COMMANDS_COUNT_SHOWING; i++)
		cout << "\t" << i << " - " << commandsShowing[i].name << endl;
}


CommandInfoSub EnterCommandShowing()
{
	int index = EnterNumber("\t����� �������� �����������", 0, COMMANDS_COUNT_SHOWING - 1);
	return commandsShowing[index];
}


void RunShowing()
{
	system("cls");
	Out();
	ShowShowing();

	CommandInfoSub commandSubShow = EnterCommandShowing();
	commandSubShow.commandSub();
}