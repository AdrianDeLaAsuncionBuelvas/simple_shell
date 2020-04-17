#include "shell.h"

int is_buitin(char **token)
{
	int chdir_value = 0;
	int i;
	int j;

	if(_strcmp(token[0], "exit") == 0 && !token[1])
	{
		free_memory(token);
		exit(0);
	}

	if (_strcmp(token[0], "cd") == 0)
	{
		if (!token[1])
		{
			chdir_value = chdir("..");
			if (chdir_value != 0)
			{
				printf("Error changing directory\n");
				return (1);
			}
			return (1);
		}

		chdir_value = chdir(token[1]);

		if (chdir_value != 0)
		{
			printf("Error changing directory to: %s\n", token[1]);
			return (1);
		}
		return (1);
	}

	if (_strcmp(token[0], "env") == 0 && !(token[1]))
	{
		for (i = 0; environ[i] != '\0'; i++)
		{
			for (j = 0; environ[j] != '\0'; j++)
			{
				write(1, &environ[i][j], 1);
			}
		}
		write(1, "\n", 1);
		return (1);
	}
	return (0);
}
