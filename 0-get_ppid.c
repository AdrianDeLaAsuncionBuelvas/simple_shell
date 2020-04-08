#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

/**
 * main - Entry point
 * Return: 0
 */
int main(void)
{
	int pp_id;
	pp_id = getppid();
	printf("PPID: %d\n", pp_id);
	return (0);
}
