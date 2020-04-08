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

<<<<<<< HEAD
if (token == NULL)
{
return;
}
if (strcmp(token,"exit") == 0)
{
exit(EXIT_SUCCESS);
}
=======
	if (token == NULL)
	{
		return;
	}
>>>>>>> b07ed61631a5c59c2bd4eccef352c144946506ed
	childPID = fork();
	if (childPID < 0)
	{
		printf("Error during fork\n");
		exit(-1);
	}
<<<<<<< HEAD
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
return;
}

=======
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
>>>>>>> b07ed61631a5c59c2bd4eccef352c144946506ed
}
