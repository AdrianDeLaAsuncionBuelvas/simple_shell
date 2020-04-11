#include "shell.h"

/**
 * execute_program - Execute a program
 * @token: Input recieved from strtok
 * Return: Nothing
 */

void execute_program(char **token)
{	
        pid_t childPID;
        int exec;

	if (token[0] == NULL)
	{
		return;
	}

	childPID = fork();

	if (childPID < 0)
	{
		printf("Error during fork\n");
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
			perror("Error");
			exit(EXIT_FAILURE);
		}
		return;
	}
}
