#include "main.h"
/**
 * main - simple-shell
 * Return: return -1 if fail or 0 on success
 */
int main(void)
{
	char *input = NULL, **token;
	size_t len = 0;
	ssize_t chars_read;
	int count = 0, status = 0;

	while (1)
	{
		count++;
		/*if the input is coming from a terminal will print the prompt*/
		isatty(STDIN_FILENO) == 1 ? write(1, "$ ", 2) : 0;
		chars_read = getline(&input, &len, stdin);
		if (chars_read == -1)
		{
			free(input);
			exit(status);
		}
		if (chars_read == 1) /* handles the \n is the only combination of 1 char*/
			continue;
		token = tokenize_line(input);
		if (token && token[0])
		{
			if (_strcmp(token[0], "exit") == 0 && token[1] == NULL) /*handles the exit*/
			{
				free_grid(token);
				free(input);
				exit(status);
				break;
			}
			if (_strcmp(token[0], "env") == 0 && token[1] == NULL) /*handles the env*/
			{
				print_env();
			}
			status = execute(token, input, status);
			free_grid(token);	
		}
		else
			continue;
	}
		return (0);
}
