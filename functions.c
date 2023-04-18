#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void tokenize_line(char *input)
{
	/* 50 args size of array*/
	char *args[50];
	char *token;
	int i = 0;
	
	token = strtok(input, " ");  /*using " " as delimiter*/
	while (token != NULL)
	{
		args[i] = token;
		i++;
		token = strtok(NULL, " ");  /*adding the new input ignoring the previous*/
	}
	args[i] = NULL;  /*adding NULL to last position*/
	
	/* fork + execve*/
	if (fork() == 0)
	{
		execvp(args[0], args);
		exit(1);
	}
	else
	{
		wait(NULL); 
	}
}
