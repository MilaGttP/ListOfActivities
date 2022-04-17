
#pragma once

enum { NAME_SIZE = 40 };
enum { DESCRIPTION_SIZE = 256 };
enum { DATE_SIZE = 25 };

struct Act
{
	char Name[NAME_SIZE];
	char Date[DATE_SIZE];
	int Priority;
	char Description[DESCRIPTION_SIZE];
};

void OutObjectDetails(Act* pObj);
void OutObject(Act* pObj, size_t num);

Act* Create();
void Edit(Act* pObj);