#include "shell.h"

char **get_path()
{
	char *getenv_value = NULL;
	char *tokens = NULL;
	const char *delimiter = ":";
	char **array_dirs = NULL;
	int i = 0;

	getenv_value = _getenv("PATH");
	tokens = strtok(getenv_value, delimiter);
	array_dirs = malloc(1024);
	array_dirs[i] = tokens;

	while (tokens)
	{
		i++;
		tokens = strtok(NULL, delimiter);
		array_dirs[i] = tokens;
	}

	i++;
	array_dirs[i] = NULL;
	return (array_dirs);
}
