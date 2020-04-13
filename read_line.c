#include "shell.h"
/**
 * get_line - Prints "$ " and wait for a command
 *
 * Return: The read command or error if not
 *
 **/
char *get_line(void)
{
	ssize_t characters_read = 0;
	size_t num_bytes = 0;
	char *mensaje = NULL;
        int val_isatty = 0;

        val_isatty = isatty(STDIN_FILENO);

        if (val_isatty == 1)
        {
	  printf("$ ");
        }
	characters_read = getline(&mensaje, &num_bytes, stdin);

	if (characters_read == EOF)
	{
            if (val_isatty == 1)
            {
		printf("\n");
            }
                free(mensaje);
		exit(EXIT_SUCCESS);
	}

	if (strcmp(mensaje,"exit\n") == 0)
	{
                free(mensaje);
		exit(EXIT_SUCCESS);
	}
        
        if (strcmp(mensaje,"clear\n") == 0)
        {
                free(mensaje);               
                printf("\033[H\033[J");
                return (NULL);
        }    
	return (mensaje);
}
