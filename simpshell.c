#include "main.h"
int main() 
{
	char *input = NULL;
	size_t len = 0;
	
	while (1) 
	{
		printf("Shell > ");
		if (getline(&input, &len, stdin) != -1)
		{
			input[strlen(input)-1] = '\0'; /* deleting the \n at the end of the input*/
			if (strcmp(input, "exit") == 0)
			{
				break; /* exit from bucle if imput is "exit"*/
			}
			tokenize_line(input); /*calling function to handle more than 1 input*/
		} 
		else
		{
			break; /* exit from bucle if getline() returns -1 (EOF)*/
		}
	}
	
	free(input);
	
	return (0);
}
