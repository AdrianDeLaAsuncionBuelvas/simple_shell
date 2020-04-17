#include "shell.h"

/**
 * main - Executes all main functions
 * @ac: Number of arguments
 * @av: Array of string pointers with arguments
 * @env: receives the environment data
 * Return: 0
 */

int main(int ac __attribute__((unused)), char **av, char **env)
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
			execve_program(tok, av[0], number_prompts, val_isatty, env);
			free(s);
			free(tok);
		}
		val_isatty = 0;
	}
	return (0);
}
