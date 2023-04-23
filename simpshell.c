#include "main.h"
int main() 
{
	char *input = NULL;
	size_t len = 0;
	ssize_t chars_read;
	char *inputcpy = NULL;
	char **token;
	
	while (1) 
	{
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
		execute(token,input);
		free(inputcpy);
	}
	return (0);
}
