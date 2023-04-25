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
	char **token;
	int count = 0, status = 0;

	while (1)
	{
		count++;
		isatty(STDIN_FILENO) == 1 ? write(1, "$ ", 2) : 0;
		chars_read = getline(&input, &len, stdin);
		if (chars_read == -1)
		{
			free(input);
			exit(status);
		}
		if (chars_read == 1)
			continue;
		token = tokenize_line(input);
		if (!token[0]) /* if first argument is " "or "\t" before tokenized */
		{
			free_grid(token);
			continue;
		}
		if (_strcmp(token[0], "exit") == 0 && token[1] == NULL)
		{
			free(input);
			free_grid(token);
			exit(status);
		}
		status = execute(token, input, count, status);
	}
	return (0);
}
