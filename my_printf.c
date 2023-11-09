#include "shell.h"

/**
 * my_printf - prints input to the standard output
 * @print_command: prints the command to stdout
*/

void my_printf(const char *print_command, ...)
{
	write(STDOUT_FILENO, print_command, strlen(print_command));
}


