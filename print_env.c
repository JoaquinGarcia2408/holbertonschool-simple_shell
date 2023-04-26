#include "main.h"

/**
 * print_env - print enviroment
 */


void print_env(void)
{
	int i;
	char **env_cpy = environ;

	if (!env_cpy)
		return;

	for (i = 0; env_cpy[i]; i++)
	{
		printf("%s\n", env_cpy[i]);
	}
}
