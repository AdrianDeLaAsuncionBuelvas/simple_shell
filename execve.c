#include "shell.h"

/**
 * execute_program - Execute a program
 * @token: Input recieved from strtok
 * Return: Nothing
 */

void execute_program(char **token, char *argv, int number)
{
        pid_t childPID;
        int exec;
        int i;

	if (token[0] == NULL)
	{              
	    return;
	}

	childPID = fork();

	if (childPID < 0)
	{
		printf("Error during fork\n");                  
                   for (i = 0; token[i]; i++)
                   {
                      free(token[i]);
                   }
                   free(token);
		exit(EXIT_FAILURE);
	}
	else if (childPID != 0)
	{
		wait(NULL);                                
		return;
	}
	else
	{
		exec = execve(token[0], token, NULL);
		if (exec < 0)
		{
		   printf("%s: %d: %s: not found\n", argv, number, token[0]);

                   for (i = 0; token[i]; i++)
                   {
                      free(token[i]);
                   }
                   free(token);
		   exit(EXIT_FAILURE);
		}                
                   for (i = 0; token[i]; i++)
                   {
                      free(token[i]);
                   }
                   free(token);
                   exit(EXIT_SUCCESS);		
	}
}
