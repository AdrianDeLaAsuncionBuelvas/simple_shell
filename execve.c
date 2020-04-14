#include "shell.h"
/**
 * execute_program - Execute a program
 * @token: Input recieved from strtok
 * Return: Nothing
 */
void execute_program(char **token, char *argv, int number, int isatty_value, char **envi)
{
	pid_t childPID;
	int exec = 0, val_builtin = 0;

	if (token[0] == NULL)
		return;

	val_builtin = is_buitin(token, envi);
	if (val_builtin == 1)
	{
		free_memory(token);
		return;
	}

	childPID = fork();
	if (childPID < 0)
	{
		printf("Error during fork\n");
		free_memory(token);
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
			if (isatty_value == 1)
			{
				printf("%s: No such file or directory\n", argv);
				free(token);
				exit(EXIT_SUCCESS);
			}
			printf("%s: %d: %s: not found\n", argv, number, token[0]);
			free(token);
			exit(EXIT_FAILURE);
		}
		free_memory(token);
		exit(EXIT_SUCCESS);
	}
}
