#include "shell.h"
/**
 * execute_program - Execute a program
 * @token: Input recieved from strtok
 * Return: Nothing
 */

void execute_program(char *token)
{
char *args[] = {token, NULL};
int childPID;
int exec;

if (token == NULL)
{
return;
}
	childPID = fork();
	if (childPID < 0)
	{
		printf("Error during fork\n");
		exit(-1);
	}
else if (childPID != 0)
{
wait(NULL);
return;
}
else
{
exec = execve(args[0], args, NULL);
if (exec < 0)
{
perror("Error");
exit(-1);
}
}
}
