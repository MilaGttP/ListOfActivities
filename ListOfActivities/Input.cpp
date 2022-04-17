
#include "Includes.h";
#include "Input.h";

using namespace std;

char* InputString(istream& stream) 
{
	static char buff[USHRT_MAX];
	stream.getline(buff, sizeof buff);

	return buff;
}

void InputMultilineText(istream& stream, char*& pStr) 
{
	static char buff[USHRT_MAX];

	while (true) 
	{
		char* pTmp = InputString(stream);
		if (pTmp[0] == '\0') 
			break;
		
		strcat(buff, "\n");
		strcat(buff, pTmp);
	}

	pStr = buff;
}