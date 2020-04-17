#include "shell.h"

char **get_path()
{
	char *getenv_value = NULL;
	char *tokens = NULL;
	const char *delimiter = ":";
	char **array_dirs = NULL;
	int i = 0;

<<<<<<< HEAD
	getenv_value = _getenv("PATH");
=======
	getenv_value = _getenv_path();
>>>>>>> c6db1cc0f79447b586c71a04d2f783bbdd320973
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
