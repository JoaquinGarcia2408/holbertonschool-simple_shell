#include "main.h"
/**
 * main - simple-shell
 * Return: return -1 if fail or 0 on success
 */
int main(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t chars_read;
	char *inputcpy = NULL;
	char **token;

	while (1)
	{
		isatty(STDIN_FILENO) == 1 ? write(1, "$ ", 2) : 0;
		printf("$ ");
		chars_read = getline(&input, &len, stdin);
		if (chars_read == -1)
		{
			free(input);
			exit(-1);
		}
		inputcpy = malloc(chars_read + 1);
		if (inputcpy == NULL)
		{
			perror("Malloc error: ");
			return (-1);
		}
		_strcpy(inputcpy, input);
		token = tokenize_line(inputcpy);
		execute(token, input);
		free(inputcpy);
	}
	return (0);
}
