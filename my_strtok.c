#include "shell.h"

/**
 * my_strtok - function that breaks up a string into tokens
 * @input_str: String that is to be broken up.
 * @delimiter: character specifying where the string is to be broken.
 * Return: result, a pointer to a string token.
 */

char *my_strtok(char *input_str, char *delimiter)
{
	static char *synch;
	char *result = input_str;

	if (!input_str)
		input_str = synch;
	if (!input_str)
		return (NULL);

	while (*input_str && (*input_str == *delimiter || !*delimiter))
		input_str++;
	if (!*input_str)
		return (NULL);
	result = input_str;

	while (*input_str && (*input_str != *delimiter || !*delimiter))
		input_str++;
	if (*input_str)
	{
		*input_str = '\0';
		synch = input_str + 1;
	}
	else
	{
		synch = input_str;
	}
	return (result);
}
