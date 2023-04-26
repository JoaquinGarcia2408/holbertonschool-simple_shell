#ifndef main_h
#define main_h

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/types.h>
extern char **environ;
char **tokenize_line(char *input);
int fork_handler(char **array_counter, char *input, int status);
int execute(char **array_counter, char *input, int status);
char *path_attacher(char *pbuffer, char **arraycounter);
char *_get_env(char *npath);

int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
char *_strdup(char *str);
void free_grid(char **grid);
#endif
