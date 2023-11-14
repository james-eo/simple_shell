#include "shell.h"

/**
 *  main - Enry point
 *  Return: 0 on success
 */

int main(void)
{
	char user_command[127];
	int status;

	while (1)
	{
		display_prompt();
		read_input(user_command, sizeof(user_command));

		if (strncmp(user_command, "exit", 4) == 0)
		{
			status = atoi(user_command + 5);
			exit_shell(status);
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
