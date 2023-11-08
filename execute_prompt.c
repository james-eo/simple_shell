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
		char *args[170];
		int arg_c = 0;
		char *tokenise_command = strtok((char *)prompt, " ");

		while (tokenise_command != NULL)
		{
			args[arg_c++] = tokenise_command;
			tokenise_command = strtok(NULL, " ");
		}
		args[arg_c] = NULL;
		execvp(args[0], args);
		my_printf("jsh: No such file or directory.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		/*parent process*/
		wait(NULL);
	}
}
