#include "shell.h"

void exit_function()
{
	kill(getpid(), SIGTERM);
}
