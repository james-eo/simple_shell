#include "shell.h"

/**
 *  main - Enry point
 *  Return: 0 on success
 */

int main(void)
{
	char user_command[127];

	while (1)
	{
		display_prompt();
		read_input(user_command, sizeof(user_command));
		execute_prompt(user_command);
	}
	return (0);
}
