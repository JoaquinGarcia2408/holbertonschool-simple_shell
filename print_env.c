#include "main.h"

/**
 * print_env - print enviroment
 */


void print_env(void)
{
	int i;

	if (!environ)
		return;

	for (i = 0; environ[i]; i++)
	{
		printf("%s\n", environ[i]);
	}
}
