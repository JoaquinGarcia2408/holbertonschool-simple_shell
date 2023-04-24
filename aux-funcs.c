#include "main.h"

/**
 * _strcat - concatenate two strings
 * @dest: char string to concatenate to
 * @src: char string
 * Return: pointer to resulting string `dest`
 */

char *_strcat(char *dest, char *src)
{
	int i, c;

	for (i = 0; dest[i] != '\0'; i++)
		;

	for (c = 0; src[c] != '\0'; c++)
	{
		dest[i] = src[c];
		i++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - a function that print a string in reverse
 * @s1: the char pointer
 * @s2: a
 * Return: a
 */
int _strcmp(char *s1, char *s2)
{
	int length = 0;

	while (s1[length] && s2[length])
	{
		if (s1[length] != s2[length])
		{
			return (s1[length] - s2[length]);
		}
		length++;
	}
	return (s1[length] - s2[length]);
}

/**
 * _strcpy - a function that print a string in reverse
 * @dest: the char pointer
 * @src: a
 * Return: a
 */
char *_strcpy(char *dest, char *src)
{
	int length = 0;

	while (src[length])
	{
		dest[length] = src[length];
		length++;
	}
	dest[length] = '\0';
	return (dest);
}

/**
 * _strdup - copy of the string given as a parameter
 * @str: string of char
 *
 * Description: The _strdup() function returns a pointer to a new string which
 * is a duplicate of the string str.
 * Returns NULL if str = NULL
 *
 * Return: a pointer to the duplicated string.
 */

char *_strdup(char *str)
{
	int i, j;
	char *array;

	if (str == NULL)
		return (NULL);

	for (i = 0 ; str[i] != '\0' ; i++)
	{
	}

	array = malloc(sizeof(char) * i + 1);

	if (array == NULL)
		return (NULL);

	for (j = 0 ; j <= i ; j++)
		array[j] = str[j];

	return (array);
}


