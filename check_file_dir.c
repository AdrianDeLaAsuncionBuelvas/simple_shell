#include "shell.h"

/*Esto es un prototipo. Hay que adaptarlo a la shell*/
/* Se puede comprobar el resultado de este programa con la shell propia de Linux poniendo: which nombre_comando. Ejemplo: which ls */
/*get_path es una función que obtiene el path y luego devuelve cada uno de los directorios como tokens*/

char **get_path()
{
	char *getenv_value = NULL;
	char *tokens = NULL;
	const char *delimiter = ":";
	char **array_dirs = NULL;
	int i = 0;

	getenv_value = getenv("PATH"); /*getenv obtiene variables ambientales, en este caso le mandamos el PATH*/
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

int main (int ac __attribute__((unused)), char **av, char **env)
{
	char **dir_path = get_path(); /*Creamos una variable donde almacenar el path en tokens invocando la función get_path()*/
	struct dirent *path_dirs;
	int i;
	int exec = 0;
	DIR *dr;
	char *concat;
	char *command_to_execute;
	int forking;

	/*Realiza una búsqueda por cada uno de los directorios del path usando un for*/

	for (i = 0; dir_path[i]; i++)
	{
		/*Abre un directrio con opendir*/
		dr = opendir(dir_path[i]);

		if (dr == NULL)
		{
			printf("No se pudo abrir %s\n", dir_path[i]);  /*Si no puede abrir un directorio, avisa y continua al siguiente*/
			continue;
		}

		while ((path_dirs = readdir(dr)) != NULL)   /*Lee un directorio con readdir*/
		{
			if (_strcmp(path_dirs->d_name, av[1]) == 0) /*En las comillas poner nombre de un ejecutable. Compilar y correr"*/
			{
				concat = _strcat(dir_path[i], "/");
				command_to_execute = _strcat(concat, av[1]);
				printf("Intentando ejecutar %s...\n", command_to_execute);

				forking = fork();
				if (forking < 0)
				{
					printf("Error forking\n");
					exit (1);
				}
				else if (forking != 0)
				{
					wait(NULL);
				}
				else
				{
					exec = execve(command_to_execute, av, env);
					if (exec < 0)
						printf("Error ejecutando %s\n", av[1]);
				}
				closedir(dr);   /*Si encuentra, avisa, cierra el directorio con closedir y se sale (se cierra el ciclo)*/
				return (0);
			}

		}
		closedir(dr); /*Si no encuentra el ejecutable en un directorio, lo cierra y pasa al siguiente (se repite el ciclo)*/
	}

	printf("Programa no encontrado\n"); /*Si al final no encuentra nada, avisa. Ya el directorio fue cerrado anteriormente en el ciclo*/

	return (0);
}

