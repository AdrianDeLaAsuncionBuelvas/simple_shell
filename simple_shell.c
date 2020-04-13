#include "shell.h"

/**
 * main - Prints "$ " and wait for a command, then prints it
 *
 * Return: 0
 */

int main(int argc __attribute__((unused)), char **argv)
{
	char *str = NULL;
	char **tok = NULL;
        int number_prompts = 0;

	while (1) {
                number_prompts = 0;
		str = get_line();
                if (str != NULL)
                {
			number_prompts++;
			tok = func_strtok(str);
			execute_program(tok, argv[0], number_prompts);
			free(str);
			free(tok);
                }
	}
	exit(EXIT_SUCCESS);
}
