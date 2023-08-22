#include "main.h"

/**
 * strlen - function returns the length of a string
 * @c: sting argument passed
 * Return: returns the length of a string
 */
int _strlen(char *c)
{
	int len = 0;

	while (*c != '\0')
	{
		len++;
		c++;
	}
	return (len);
}
