#include "shell.h"

/**
 * read_input - gets prompt as input from users
 * @input: the command to be executed
 * @size_of_input: size of the prompt
 */

void read_input(char *input, size_t size_of_input)
{
	ssize_t read_bytes;

	read_bytes = getline(&input, &size_of_input, stdin);

	if (read_bytes == -1)
	{
		if (feof(stdin))
		{
			my_printf("\n");
			free(input);
			exit(EXIT_SUCCESS);
		}
		else
		{
			my_printf("Input Error.\n");
			free(input);
			exit(EXIT_FAILURE);
		}
	}
	if (input[read_bytes - 1] == '\n')
	{
		input[read_bytes - 1] = '\0';
	}
}
