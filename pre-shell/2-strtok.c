#include "main.h"

/*
 * main - splits a string and returns an array of each word of the string
 * @ac: argument count
 * @av: argument vector
 */

int main (int ac, char **av __attribute__((unused)))
{
	ssize_t line = 0, counter = 0;
	char *buffer, *word, **wordsarray;
	size_t ptr = 0;

	line = getline(&buffer, &ptr, stdin);
	if (line == -1)
	{
		printf("Error\n");
		return (-1);
	}
	wordsarray = malloc(sizeof(char *) * ac);
	if (wordsarray == NULL)
		return (0);
	word = strtok(buffer, " ");
	while (word)
	{
		wordsarray[counter] = strdup(word);
		word = strtok(NULL, " ");
		printf("%s\n", wordsarray[counter]); 
		counter++;
	}
	wordsarray[counter] = NULL;

}
