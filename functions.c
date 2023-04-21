#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"


char **tokenize_line(char *input)
{

	char *token, *inputcpy = NULL, **inputarray = NULL;
	int wordcounter = 0, arraycounter = 0, charfinder = 0, i = 0;

	while(input[charfinder])
	{
		if (input[charfinder] == '\t' || input[charfinder] == '\n' || input[charfinder] == ' ')
		{
			charfinder++;
			wordcounter++;		
		}
		charfinder++;
	}
	inputarray = malloc(sizeof(char *) * (wordcounter + 1));
	if (inputarray == NULL)
	{
		free (input);
		perror("Malloc error: ");
		exit(-1);
	}
	inputcpy = strdup(input);
	token = strtok(inputcpy, " \t\n");
	for (arraycounter = 0; token; arraycounter++)
	{
		inputarray[arraycounter] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	inputarray[arraycounter] = NULL;
	free(inputcpy);
	for (i = 0; i < arraycounter; i++)
		free(inputarray[i]);
	free(inputarray);
	return (inputarray);
}
char *_get_env(char *npath)
{
	int environcounter;
	char *token = NULL, *buffer = NULL, *token_cpy = NULL;

	if(environ == NULL)
		return (NULL);
	for (environcounter = 0; environ[environcounter]; environcounter++)
	{
		buffer = strdup(environ[environcounter]);
		if(buffer == NULL) 
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		token = strtok(buffer, "=");
		if (strcmp(token, npath) == 0)
		{
			token = strtok(NULL, "=");
			if (token != NULL)
			{
				token_cpy = strdup(token);

				free(buffer);
				if(token_cpy == NULL) 
				{
					perror("Memory allocation error");
					exit(EXIT_FAILURE);
				}
				return (token_cpy);
				/*tokencopy?*/
			}
			free(buffer);
		}
		free(buffer);
	}
	return (NULL);
}
char *path_attacher(char *pbuffer, char **arraycounter)
{
	struct stat st;
	size_t buffersize = 1024;
	char *full_path = NULL, *token = NULL, *input_cpy;

	input_cpy = strdup(pbuffer);
	token = strtok(input_cpy, ":");
	while (token != NULL)
	{
		full_path = malloc(buffersize);
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, arraycounter[0]);
		if (stat(full_path, &st) == 0) /*returns 0 if worked*/
		{
			free(input_cpy);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}
	free(input_cpy);
	return (arraycounter[0]);

}
void fork_handler(char **array_counter, char *input)
{
	int fkvalue;
	
	fkvalue = fork();
	if (fkvalue == 0)
	{
		execve(array_counter[0], array_counter, environ);
	}
	else
		wait(NULL);
	if (fkvalue < 0)
	{
		free (input);
	
		perror("Error: ");
		
	}
}
void execute(char **array_counter,char *input)
{
	struct stat st;
	int statchecker;
	char *path, *newpath;

	statchecker = stat(array_counter[0], &st);
	if (statchecker == 0)
		fork_handler(array_counter, input);
	else if (statchecker == -1)
	{
		path = _get_env("PATH"); /*PATH has a list of dif dirs separated by : */
		newpath = path_attacher(path, array_counter);
		array_counter[0] = newpath;
		free(path);
		statchecker = stat(array_counter[0], &st);
		if (statchecker == 0)
			fork_handler(array_counter, input);
		else
			perror("Error");
		free(newpath);
	}


}
