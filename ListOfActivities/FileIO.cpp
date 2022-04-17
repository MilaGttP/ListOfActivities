
#include "Includes.h";
#include "FileIO.h";
#include "Func.h";
#include "FuncWithEntering.h";

using namespace std;

char binFileName[_MAX_FNAME] = "Actings.bin";

void Save()
{
	fstream stream(binFileName, ios::trunc | ios::out | ios::binary);

	if (!stream.is_open())
	{
		cout << "Ошибка открытия файла " << binFileName << " для записи\n";
		return;
	}

	for (size_t i = 0; i < Getlenght(); i++)
		stream.write((char*)ElementAt(i), sizeof(Act));

	stream.close();
}


void Load()
{
	fstream stream(binFileName, ios::in | ios::out | ios::binary);

	if (!stream.is_open())
	{
		cout << "Ошибка открытия файла " << binFileName << " для чтения\n";
		return;
	}

	while (true)
	{
		Act* p = new Act;

		if (!stream.read((char*)p, sizeof(Act)))
			break;

		Add(p);
	}

	stream.close();
}
