#include "shell.h"
#include <unistd.h>
#include <stdio.h>


/**
 * exit_shell - exits the shell
 */

void exit_shell(void)
{
	my_printf("Exiting shell.\n");
	exit(EXIT_SUCCESS);
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
