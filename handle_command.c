#include "shell.h"

/**
 * execute_command_with_args - executes a command with arguments
 * @command: the command to be executed
 */

void execute_command_with_args(const char *command)
{
	char *shell = "/bin/sh";
	char *args[MAX_ARGS];
	char *env[] = {"NULL"};
	int arg_c = 0;
	char *tokenized_command = strtok((char *)command, " ");

	while (tokenized_command != NULL)
	{
		args[arg_c++] = tokenized_command;
		tokenized_command = strtok(NULL, " ");
	}
	args[arg_c] = NULL;
	args[arg_c] = NULL;
	if (execve(shell, args, env) == -1)
	{
		perror("execve");
		exit(EXIT_FAILURE);
	}
}

/**
 * execute_command - executes a command with arguments
 * @command: the command to be executed
 */

void execute_command(const char *command)
{
	char *shell = "/bin/sh";
	char *args[MAX_ARGS];
	char *env[] = {"NULL"};
	int arg_c = 0;
	char *tokenized_command = my_strtok((char *)command, " ");

	while (tokenized_command != NULL)
	{
		args[arg_c++] = tokenized_command;
		tokenized_command = my_strtok(NULL, " ");
	}
	args[arg_c] = NULL;

	if (is_command_in_path(args[0]))
	{
		pid_t child_process = fork();

		if (child_process == -1)
		{
			perror("jsh: Fork failed");
			exit(EXIT_FAILURE);
		}
		else if (child_process == 0)
		{
			if (execve(shell, args, env) == -1)
			{
				perror("execve");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			wait(NULL);
		}
	}
	else
	{
		printf("jsh: %s: command not found\n", args[0]);
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
	char *command_path;
	int found = 0;

	path = getenv("PATH");
	path_copy = malloc(my_strlen(path) + 1);
	my_strcpy(path_copy, path);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		command_path = malloc(my_strlen(token) + my_strlen(command) + 2);
		sprintf(command_path, "%s/%s", token, command);

		if (access(command_path, F_OK) == 0)
		{
			found = 1;
			free(command_path);
			break;
		}

		free(command_path);
		token = strtok(NULL, ":");
	}

	free(path_copy);
	return (found);
}
