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

		if (strcmp(user_command, "exit") == 0)
		{
			exit_shell();
		}
		else if (strcmp(user_command, "env") == 0)
		{
			print_environment();
		}
		else
		{
			execute_prompt(user_command);
		}
	}
	return (0);
}
