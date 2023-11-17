#include "shell.h"


/**
 * my_strlen - Calculates the length of a null-terminated string.
 * @str: The input string.
 * Return: The length of the string.
 */

size_t my_strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
