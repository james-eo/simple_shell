#ifndef SHELL_H
#define SHELL_H

#define BUFFER_SIZE 1024
#define MAX_ARGS 170

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
#include <stdarg.h>
#include <errno.h>
#include <stddef.h>

extern char **environ;





void display_prompt(void);
void my_printf(const char *print_command, ...);
void read_input(char *input, size_t size_of_input);
void execute_prompt(const char *command);
void execute_command_with_args(const char *command);
void execute_command(const char *command);
int is_command_in_path(const char *command);
void exit_shell(int status);
void print_environment(void);
ssize_t _getline(char **lineptr, size_t *n);
char *my_strtok(char *input_str, char *delimiter);
int my_strncmp(const char *str1, const char *str2, size_t max_chars);
void handle_setenv(const char *command);
void handle_unsetenv(const char *command);
int set_environment_variable(const char *variable, const char *value);
int unset_environment_variable(const char *variable);



#endif /* SHELL_H */
