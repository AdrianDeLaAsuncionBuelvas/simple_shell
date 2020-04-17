#include "shell.h"

int execute_path(char **token, char **path, char **envi)
{
	struct dirent *path_dirs;
	int i;
	int exec = 0, forking = 0, error = 0;
	DIR *dr;
	char *concat, *command_to_execute;

	if (path == NULL)
		path[0] = ".";

	for (i = 0; path[i]; i++)
	{
		dr = opendir(path[i]);
		if (dr == NULL)
			continue;

		while ((path_dirs = readdir(dr)) != NULL)
		{
			if (_strcmp(path_dirs->d_name, token[0]) == 0)
			{
				concat = _strcat(path[i], "/");
				command_to_execute = _strcat(concat, token[0]);
				forking = fork();
				if (forking < 0)
				{
					printf("Error forking\n");
					closedir(dr), error = -1;
				}
				else if (forking != 0)
				{
					wait(NULL);
					return (error);
				}
				else
				{
					exec = execve(command_to_execute, token, envi);
					if (exec < 0)
						closedir(dr), error = -1, exit(EXIT_FAILURE);
					closedir(dr);
					error = 0, exit(EXIT_SUCCESS);
				}
			}
		}
		closedir(dr);
	}
	return (-1);
}
