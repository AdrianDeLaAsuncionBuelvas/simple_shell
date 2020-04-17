#include "shell.h"

char **get_path()
{
	char *getenv_value = NULL;
	char *tokens = NULL;
	const char *delimiter = ":";
	char **array_dirs = NULL;
	int i = 0;

	getenv_value = _getenv_path();
	tokens = strtok(getenv_value, delimiter);
	array_dirs = malloc(200);  /*Hacemos malloc al doble puntero para almacenar el path*/
	array_dirs[i] = tokens;  /*El path lo vamos almacenando en un doble puntero. Cada directorio va en una posición 0,1,2,3...*/

	while (tokens)
	{
		i++;
		tokens = strtok(NULL, delimiter);
		array_dirs[i] = tokens;  /*Almacena el path*/
	}

	i++;
	array_dirs[i] = NULL;
	return (array_dirs); /*Retornamos los directorios del path como tokens almacenados en un doble puntero*/
}

