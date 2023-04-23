#include "main.h"
/**
 * main - prints all the arguments, without using ac.
 * @av:  is a NULL terminated array of strings
 * Return: 0
 **/
int main (char **av)
{
	int i = 0;

	while (av[i] != NULL)
	{
		printf ("%s", av[i]);
		i++
	}
	printf("\n");
	return 0;
}
