#include "shell.h"

/**
 * execute_prompt - executes the prompt from user
 * @prompt: the command to be executed
 *
 */

void execute_prompt(const char *prompt)
{
	pid_t child_proccess = fork();

	if (child_proccess == -1)
	{
		my_printf("Forking error!\n");
		exit(EXIT_FAILURE);
	}
	else if (child_proccess == 0)
	{
		/*Child process*/
		execute_command_with_args(prompt);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*parent process*/
		wait(NULL);
	}
}
