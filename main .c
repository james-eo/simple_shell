#include "shell.h"

/**
 *  main - Enry point
 *  Return: 0 on success
 */

int main(void)
{
	char user_command[127];
	char *commands[10];
	int num_commands;
	int i;

	while (1)
	{
		display_prompt();
		read_input(user_command, sizeof(user_command));
		num_commands = split_commands(user_command, commands);

		for (i = 0; i < num_commands; ++i)
		{
			process_command(commands[i]);
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

/**
 * split_commands - Splits input commands based on the ";" delimiter
 * @input: The input string containing commands separated by ";"
 * @commands: An array to store the individual commands
 * Return: The number of commands
 */

int split_commands(char *input, char *commands[])
{
	int num_commands = 0;
	char *token = strtok(input, ";");

	while (token != NULL && num_commands < 10)
	{
		commands[num_commands++] = token;
		token = strtok(NULL, ";");
	}
	return (num_commands);
}
