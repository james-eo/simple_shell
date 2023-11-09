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

/**
 * execute_command - executes a command with arguments
 * @command: the command to be executed
*/

void execute_command(const char *command)
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

	/*Check if the command exists in the PATH */
	if (is_command_in_path(args[0]))
	{
		pid_t child_process = fork();

		if (child_process == -1)
		{
			my_printf("Forking error!\n");
			exit(EXIT_FAILURE);
		}
		else if (child_process == 0)
		{
			/* Child process */
			if (execvp(args[0], args) == -1)
			{
				perror("jsh");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			/* Parent process */
			wait(NULL);
		}
	}
	else
	{
		my_printf("jsh: %s: command not found\n", args[0]);
	}
}


/**
 * is_command_in_path - checks if a command exists in the PATH
 * @command: the command to check
 * Return: 1 if the command exists, 0 otherwise
*/

int is_command_in_path(const char *command)
{
	char *path;
	char *path_copy;
	char *token;

	if (access(command, F_OK) == 0)
	{
		return (1);
	}
	path = getenv("PATH");
	path_copy = strdup(path);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		char command_path[256];

		snprintf(command_path, sizeof(command_path), "%s/%s", token, command);
		if (access(command_path, F_OK) == 0)
		{
			free(path_copy);
			return (1);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	return (0);
}
