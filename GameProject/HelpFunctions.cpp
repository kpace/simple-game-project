#include "HelpFunctions.h"

// takes char from '0' to '9'
// \return integer value

int fromCharToInt(char c)
{
	int a = 0;

	if(c > '0' && c < '9')
	{
		a = c - '0';
	}

	return a;
}

// formats char to lower case

void toLowerCase(char& c)
{
	if(c >= 'A' || c <= 'Z')
	{
		c = c + ('a' - 'A');
	}
}