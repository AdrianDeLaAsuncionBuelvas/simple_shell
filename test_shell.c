#include "shell.h"

/**
 * main - Prints "$ " and wait for a command, then prints it
 *
 * Return: 0
 */

int main(void)
{
char *s;
char *tok;
do {
s = get_line();
tok = func_strtok(s);
execute_program(tok);
free(s);
} while (EOF != 0);

return (0);
}
