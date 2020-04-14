#include "shell.h"

/**
 * main - Executes all main functions
 * @argc: Number of arguments
 * @argv: Array of string pointers with arguments
 * Return: Nothing
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	char *s = NULL;
	char **tok = NULL;
	int number_prompts = 0;

	while (1)
	{
		s = get_line();
		if (s != NULL)
		{
			number_prompts++;
			tok = func_strtok(s);
			execute_program(tok, argv[0], number_prompts);
			free(s);
			free(tok);
		}
		s = NULL;
		tok = NULL;
	}
}
