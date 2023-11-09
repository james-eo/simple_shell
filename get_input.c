#include "shell.h"

/**
 * read_input - gets prompt as input from users
 * @input: the command to executed
 * @size_of_input: size of the prompt
 *
 */

void read_input(char *input, size_t size_of_input)
{
	if (fgets(input, size_of_input, stdin) == NULL)
	{
		if (feof(stdin))
		{
			my_printf("\n");
			exit(EXIT_SUCCESS);
		}
		else
		{
			my_printf("Input Error.\n");
			exit(EXIT_FAILURE);
		}
	}
	input[strcspn(input, "\n")] = '\0';
}
