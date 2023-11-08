#include "shell.h"

/**
 * execute_command_with_args - executes a command with arguments
 * @command: the command to be executed
 */

void execute_command_with_args(const char *command)
{
	char *args[170];
	int arg_c = 0;
	char *tokenized_command = strtok((char *)command, " ");

	while (tokenized_command != NULL)
	{
		args[arg_c++] = tokenized_command;
		tokenized_command = strtok(NULL, " ");
	}
	args[arg_c] = NULL;
	if (execvp(args[0], args) == -1)
	{
		perror("jsh");
	}
}
