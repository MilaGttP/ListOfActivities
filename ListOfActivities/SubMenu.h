
#pragma once

typedef void (*CommandSub) ();
const enum { SUBCOMMAND_NAME_SIZE = 64 };

struct CommandInfoSub
{
	char name[SUBCOMMAND_NAME_SIZE];
	CommandSub commandSub;
	bool delayResDisplaying = true;
};

void RunFiltering();
void RunShowing();
void RunSorting();