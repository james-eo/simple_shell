#ifndef SHELL_H
#define SHELL_H


/**
 * This header file contains all the functions
 * of the simple-shell project.
 * It also contains all the relevant header files from
 * the standard library.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>


void display_prompt(void);
void my_printf(const char *print_command, ...);
void read_input(char *input, size_t size_of_input);
void execute_prompt(const char *command);
void execute_command_with_args(const char *command);
void execute_command(const char *command);
int is_command_in_path(const char *command);
void exit_shell(void);




#endif /* SHELL_H */
