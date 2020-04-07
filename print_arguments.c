#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
/**
 * main - Prints the arguments of the program without using ac
 * @ac: The number of arguments of program when executed
 * @av: The string with arguments of program when executed
 * Return: 0
 */
int main(int ac __attribute__((unused)), char *av[])
{
	int i;

	for (i = 0; av[i] != '\0'; i++)
	{
		printf("%s\n", av[i]);
	}
	return (0);
}
