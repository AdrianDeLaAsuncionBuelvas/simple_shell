#include "shell.h"

/**
 * execute_program - Execute a program
 * @token: Input recieved from strtok
 * Return: Nothing
 */

void execute_program(char *token)
{
	char *argv[] = {token, NULL};
	pid_t childPID;
	int exec;

	if (token == NULL)
	{
		return;
	}
	if (strcmp(token, "exit") == 0)
	{
		exit(EXIT_SUCCESS);
	}
	if (token == NULL)
	{
		return;
	}

	childPID = fork();
	if (childPID < 0)
	{
		printf("Error during fork\n");
		exit(-1);
	}
	else if (childPID != 0)
	{
		wait(NULL);
		return;
	}
	else
	{
		exec = execve(argv[0], argv, NULL);
		if (exec < 0)
		{
			perror("./shell");
			exit(-1);
		}
		return;
	}

}
