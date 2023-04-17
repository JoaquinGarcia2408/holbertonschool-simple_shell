#include "main.h"
int main()
{
	char *text;
	size_t length;
	ssize_t read;
	while (1)
	{
		printf("$ ");
		fflush(stdout);
		read = getline(&text, &length, stdin);
		if (read == -1)
			break;
		printf("%s", text);
	}
	free(text);
	return(0);
}
