#include "shell.h"

/**
 * main - Executes all main functions
 * @argc: Number of arguments
 * @argv: Array of string pointers with arguments
 * Return: Nothing
 */

int main(int argc __attribute__((unused)), char **argv, char **env)
{
	char *s = NULL;
	char **tok = NULL;
	int number_prompts = 0;
	int val_isatty = 0;

	while (1)
	{
		val_isatty = isatty(STDIN_FILENO);
		s = get_line(val_isatty);

		if (s != NULL)
		{
			number_prompts++;
			tok = func_strtok(s);
			execute_program(tok, argv[0], number_prompts, val_isatty, env);
			free(s);
			free(tok);
		}
		s = NULL;
		tok = NULL;
		val_isatty = 0;
	}
	return (0);
}
