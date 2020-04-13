#include "shell.h"

/**
 * main - Prints "$ " and wait for a command, then prints it
 *
 * Return: 0
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	char *s = NULL;
	char **tok = NULL;
        int number_prompts = 0;          

	while (1) {
                number_prompts = 0;                
		s = get_line();
                if (s != NULL)
                {
                   number_prompts++;
      		   tok = func_strtok(s);
		   execute_program(tok, argv[0], number_prompts);                
		   free(s);
                   free(tok);
                }
	}
	exit(EXIT_SUCCESS);
}
