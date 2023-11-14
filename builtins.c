#include "shell.h"
#include <unistd.h>
#include <stdio.h>


/**
 * exit_shell - exits the shell
 * @status: prints the exit status
 */

void exit_shell(int status)
{
	my_printf("Exiting shell with status %d.\n", status);
	exit(status);
}

/**
 * print_environment - prints the current environment variables
 */

void print_environment(void)
{
	int index = 0;

	while (environ[index] != NULL)
	{
		my_printf("%s\n", environ[index]);
		index++;
	}
}
