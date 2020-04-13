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
        int chdir_value;

	if (token[0] == NULL)
	{
	    return;
	}

        if (strcmp(token[0],"cd") == 0)
        {
          if (!token[1])
          {
            chdir_value = chdir("..");
            if (chdir_value != 0)
            {
             printf("Error changing directory\n");
             return;
            }
          return;
          }
          chdir_value = chdir(token[1]);
            if (chdir_value != 0)
            {
             printf("Error changing directory to: %s\n", token[1]);
             return;
            }
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
