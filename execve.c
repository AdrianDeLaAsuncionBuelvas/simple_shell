#include "shell.h"

/**
 * execve_program - Execute a program
 * @token: Input recieved from strtok
 * @argv: arguments recived for line
 * @num: numbers promps
 * @isatty: valida if file intro
 * @env: environment varible
 */

void execve_program(char **token, char *argv, int num, int isatty, char **env)
{
	pid_t childPID;
	int exec = 0, val_builtin = 0, exec_path = 0;
	char **path;

	if (token[0] == NULL)
		return;

	val_builtin = is_buitin(token);
	if (val_builtin == 1)
		return;

	childPID = fork();
	if (childPID < 0)
		printf("Error during fork\n"), free_memory(token), exit(0);

	else if (childPID != 0)
	{
		wait(NULL);
		return;
	}
	else
	{
		path = get_path();
		exec_path = execute_path(token, path, env);
		if (exec_path < 0)
		{
			exec = execve(token[0], token, NULL);
			if (exec != 0)
			{
				if (isatty == 1)
				{
					printf("%s: No such file or directory\n", argv);
					exit(0);
				}
				printf("%s: %d: %s: not found\n", argv, num, token[0]);
				exit(0);
			}
		}
		exit(0);
	}
}
