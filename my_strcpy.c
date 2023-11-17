#include "shell.h"


/**
 * my_strcpy - custom string copy function
 * @dest: destination buffer
 * @src: source string
 * Return: the number of characters copied
 */

int my_strcpy(char *dest, const char *src)
{
	int count = 0;

	while (*src != '\0')
	{
		*dest++ = *src++;
		count++;
	}
	*dest = '\0';
	return (count);
}
