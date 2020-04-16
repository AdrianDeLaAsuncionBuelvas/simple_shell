#include "shell.h"
/**
 * execute_program - Execute a program
 * @token: Input recieved from strtok
 * Return: Nothing
 */
void execute_program(char **token, char *argv, int number, int isatty_value, char **envi)
{
	pid_t childPID;
	int exec = 0;
	int val_builtin = 0;
	int exec_path = 0;
	char **path;

	if (token[0] == NULL)
		return;

	val_builtin = is_buitin(token);
	if (val_builtin == 1)
	{
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
		path = get_path();
		exec_path = execute_path(token, path, envi);
		if (exec_path < 0)
		{
			exec = execve(token[0], token, NULL);
			if (exec != 0)
			{
				if (isatty_value == 1)
				{
					printf("%s: No such file or directory\n", argv);
					exit(EXIT_FAILURE);
				}
				printf("%s: %d: %s: not found\n", argv, number, token[0]);
				exit(EXIT_FAILURE);
			}
		}
		exit(EXIT_SUCCESS);
	}
}
