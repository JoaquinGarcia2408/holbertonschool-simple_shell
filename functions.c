#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "main.h"

/**
 * tokenize_line - function that tokenizes arguments given by the user
 * @input: string containing the arguments
 * Return: array of strings containing each argument
 */
char **tokenize_line(char *input)
{

	char *token = NULL, *inputcpy = NULL, **inputarray = NULL;
	int wordcounter = 0, arraycounter = 0, cfinder = 0;

	while (input[cfinder])
	{
		/*will check spaces \t \n to count the number of words*/
		if (input[cfinder] == 9 || input[cfinder] == 10 || input[cfinder] == 32)
		{
			cfinder++;
			wordcounter++;
			continue;
		}
		cfinder++;
	}
	inputarray = malloc(sizeof(char *) * (wordcounter + 1));
	if (inputarray == NULL)
	{
		free(input);
		perror("Malloc error: ");
		exit(0);
	}
	inputcpy = strdup(input);
/*Creates a copy of the input string and uses the strtok function to extract 
 *first token using delimiters \t\n.returns a pointer to the first token*/
	token = strtok(inputcpy, " \t\n");
	for (arraycounter = 0; token; arraycounter++)/*extract each subsequent token*/
	{
		inputarray[arraycounter] = strdup(token);
		token = strtok(NULL, " \t\n");
	}
	inputarray[arraycounter] = NULL;
	free(inputcpy);
	return (inputarray);
}
/**
 * _get_env - search for specific word inside env
 * @npath: word to search in env
 * Return: return NULL if failed or pointer to path in success
 */
char *_get_env(char *npath)
{
	int environcounter;
	char *token = NULL, *buffer = NULL, *token_cpy = NULL;

	if (environ == NULL)
		return (NULL);
	for (environcounter = 0; environ[environcounter]; environcounter++)
	{
		buffer = _strdup(environ[environcounter]);
		token = strtok(buffer, "=");
		if (buffer == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
	/*Check if the token matches the given environment variable name*/
		if (_strcmp(token, npath) == 0) 
		{
			token = strtok(NULL, "=");
			if (token != NULL)
			{
				token_cpy = _strdup(token);

				free(buffer);
				return (token_cpy);
			}
		}
		free(buffer);
	}
	return (NULL);
}
/**
 * path_attacher  - add corresponding path to the given command
 * @arraycounter: input given in shell
 * @pbuffer: string given by path
 * Return: full path in success or NULL if fail
 */
char *path_attacher(char *pbuffer, char **arraycounter)
{
	struct stat st;
	size_t buffersize = 1024;
	char *full_path = NULL, *token = NULL, *input_cpy = NULL;

	input_cpy = _strdup(pbuffer);
	token = strtok(input_cpy, ":");
	while (token != NULL)
	{
		full_path = malloc(buffersize);
		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, arraycounter[0]);
		if (stat(full_path, &st) == 0) /*returns 0 if worked*/
		{
			free(input_cpy);
			free(arraycounter[0]);
			return (full_path);
		}

		free(full_path);
		token = strtok(NULL, ":");
	}
	free(input_cpy);
	return (arraycounter[0]);

}
/**
 * fork_handler - fork to create a child proccess and execute a program
 * @array_counter: input given in shell
 * @input: string given by path
 * @status: exit code
 * Return: 0 if works
 */
int fork_handler(char **array_counter, char *input, int status)
{
	pid_t fkvalue;

	fkvalue = fork();
	if (fkvalue == 0)
	{
		execve(array_counter[0], array_counter, environ);
	}
	else
	{
		wait(&status);
	}
	if (fkvalue < 0)
	{
		free(input);
		free_grid(array_counter);
		perror("./shell");

	}
	return (WEXITSTATUS(status));
}
/**
 * execute - checks if the first argument by the user can be executed
 * @array_counter: input given in shell
 * @input: string given by path
 * @status: store the int returned by the fork_handler function
 * @count: would be used to fprintf in case stat fails or path = NULL
 * Return: int
 */
int execute(char **array_counter, char *input, int status, int count)
{
	struct stat st;
	int statchecker;
	char *path;

	statchecker = stat(array_counter[0], &st);
	if (statchecker == 0)
		status = fork_handler(array_counter, input, status);
	else if (statchecker == -1)
	{
		path = _get_env("PATH"); /*PATH has a list of dif dirs separated by : */
		if (path == NULL || strcmp(path, "") == 0)
		{
			fprintf(stderr, "./hsh: %i: %s: not found\n", count, array_counter[0]);
			status = 127;
			return status;
		}
		array_counter[0] = path_attacher(path, array_counter);
		free(path);
		statchecker = stat(array_counter[0], &st);
		if (statchecker == 0)
			status = fork_handler(array_counter, input, status);
		else if (statchecker == -1 || path == NULL)
		{
			fprintf(stderr, "./hsh: %i: %s: not found\n", count, array_counter[0]);
			status = 127;
			return (status);
		}
	}
	return (status);
}
