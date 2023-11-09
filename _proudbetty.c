#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
a
extern char **environ;

int main(void) 
{
    char user_command[1024];
    int execution_status;

    while (1) 
    {
        printf("my_shell> ");

        if (!fgets(user_command, sizeof(user_command), stdin)) 
        {
            break; // Handle Ctrl+D (EOF)
        }

        user_command[strlen(user_command) - 1] = '\0';

        if (strlen(user_command) == 0) 
        {
            continue;
        }

        pid_t child_pid = fork();

        if (child_pid < 0) 
        {
            perror("Fork failed");
            continue;
        } else if (child_pid == 0) 
        {
            if (execve(user_command, NULL, environ) < 0) 
            {
                printf("Custom Shell: Command '%s' not found\n", user_command);
                exit(1);
            }
        }
        else 
        {
            wait(&execution_status);
        }
    }

    return (0);
}
