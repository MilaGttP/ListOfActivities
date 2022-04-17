
#include "Includes.h";
#include "Func.h";
#include "Entering.h";

using namespace std;

static Act** arr = nullptr;
static size_t lenght = 0;

bool Empty()
{
	return arr == nullptr;
}


int Getlenght()
{
	return lenght;
}


Act* ElementAt(size_t index)
{
	return arr[index];
}


void Add(Act* p)
{
	if (Empty())
	{
		arr = new Act * [1];
		arr[0] = p;
	}

	else
	{
		Act** newArr = new Act * [lenght + 1];

		for (size_t i = 0; i < lenght; i++)
			newArr[i] = arr[i];

		newArr[lenght] = p;
		delete[] arr;
		arr = newArr;
	}

	lenght++;
}


void AddRange(const Act sourceArr[], size_t size)
{
	size_t newSize = lenght + size;
	Act** newArr = new Act * [newSize];

	for (size_t i = 0; i < lenght; i++)
		newArr[i] = arr[i];

	for (size_t i = lenght, j = 0; i < newSize; i++, j++)
	{
		newArr[i] = new Act();
		*newArr[i] = sourceArr[j];
	}

	delete[] arr;
	arr = newArr;
	lenght = newSize;
}


void Filter(Select select)
{
	for (size_t i = 0; i < lenght; i++)
	{
		if (select(arr[i]))
			OutObject(arr[i], i + 1);
	}
}


void Show(char buff1[], char buff2[], char buff[])
{
	for (size_t i = 0; i < lenght; i++)
	{
		strcpy(buff, arr[i]->Date);
		buff[10] = '\0';

		if (strcmp(buff, buff1) >= 0 && strcmp(buff, buff2) <= 0)
			OutObject(arr[i], i + 1);
	}
}


void Sort(Compare compare)
{
	for (size_t i = 1; i < lenght; i++)
	{
		Act* tmp = arr[i];
		int j = i - 1;

		for (; j >= 0 && compare(tmp, arr[j]); j--)
			arr[j + 1] = arr[j];

		arr[j + 1] = tmp;
	}
}


void Clear()
{
	for (size_t i = 0; i < lenght; i++)
		delete arr[i];

	delete[] arr;
	arr = nullptr;
	lenght = 0;
}


void DeleteAt(size_t index)
{
	Act** newArr = new Act * [lenght - 1];

	for (size_t i = 0; i < index; i++)
		newArr[i] = arr[i];

	delete arr[index];

	for (size_t i = index + 1; i < lenght; i++)
		newArr[i - 1] = arr[i];

	delete[] arr;
	arr = newArr;
	lenght--;
}