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

		if (my_strncmp(user_command, "exit", 4) == 0)
		{
			status = atoi(user_command + 5);
			exit_shell(status);
		}
		else if (my_strncmp(user_command, "env", 3) == 0)
		{
			print_environment();
		}
		else if (my_strncmp(user_command, "setenv", 6) == 0)
		{
			handle_setenv(user_command);
		}
		else if (my_strncmp(user_command, "unsetenv", 8) == 0)
		{
			handle_unsetenv(user_command);
		}
		else if (my_strncmp(user_command, "cd", 2) == 0)
		{
			char *path = my_strtok(user_command + 3, " ");

			change_directory(path);
		}
		else
		{
			execute_prompt(user_command);
		}
	}
	return (0);
}

/**
 * handle_setenv - Handles the setenv command
 * by parsing the input and calling set_environment_variable
 * @command: The input command containing the setenv parameters
 */

void handle_setenv(const char *command)
{
	char *variable = my_strtok((char *)command + 7, " ");
	char *value = my_strtok(NULL, " ");

	if (variable && value)
	{
		if (set_environment_variable(variable, value) == -1)
		{
			write(STDERR_FILENO, "Failed to set environment variable.\n", 36);
		}
	}
	else
	{
		write(STDERR_FILENO, "Usage: setenv VARIABLE VALUE\n", 29);
	}
}

/**
 * handle_unsetenv - Handles the unsetenv command
 * by parsing the input and calling unset_environment_variable
 * @command: The input command containing the unsetenv parameters
 */

void handle_unsetenv(const char *command)
{
	char *variable = my_strtok((char *)command + 9, " ");

	if (variable)
	{
		if (unset_environment_variable(variable) == -1)
		{
			write(STDERR_FILENO, "Failed to unset environment variable.\n", 38);
		}
	}
	else
	{
		write(STDERR_FILENO, "Usage: unsetenv VARIABLE\n", 26);
	}
}
