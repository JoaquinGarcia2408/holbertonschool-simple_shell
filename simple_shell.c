#include "main.h"
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
		printf("Shell > ");
		chars_read = getline(&input, &len, stdin);
		if (chars_read == -1)
		{
			free(input);
			exit(-1);
		}
		inputcpy = malloc(sizeof(char) * chars_read);
		if (inputcpy == NULL)
		{
			perror("Malloc error: ");
			return (-1);
		}
		_strcpy(inputcpy, input);
		token = tokenize_line(input);
		execute(token, input);
		free(inputcpy);
	}
	return (0);
}
