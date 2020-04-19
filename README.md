# 0x16. C - Simple Shell

## Table of Contents
* [Description](#description)
* [Requirements](#requirements)
* [Libraries](#libraries)
* [Propotipes](#prototipes)
* [Testing](#testing)
* [Examples](#examples)

### Description
Final project of the quarter, make a shell following certain rules and requirements.
In this project we put into practice all the knowledge acquired, and thus be able to do it.

### Requirements
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

### Compilation
Your shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`


### Libraries
Use this data Librarie for this project:

```
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>
```

### Prototipes
These are the Prototypes of Functions to be used:

```
char *get_line(int isatty_value);
char **func_strtok(char *mensaje);
void execve_program(char **token, char *argv, int num, int isatty, char **env);
int is_buitin(char **token);
void free_memory(char **token);
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *src, char *dest);
char **get_path();
int execute_path(char **token, char **path, char **env);
char *_strdup(char *str);
char *_getenv_path();
void my_puts(char *string);
```

### Testing
Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```
But also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

| Commands| Description|
| ----- | ---- |
| ls | List the content, files or folders of the current directory |
| pwd | Displays the address of the current directory |
| cd | Change the direction to the path it indicates |
| mv | Move a File or folders to the path it indicates |
| cp | Copie a File or folders to the path it indicates |
| rm | Remove a file or directory of the path it indicates |
| echo | Displays arguments passed |

### Examples
```
/**
 * get_line - Prints "$ " and wait for a command
 * @isatty_value: check if it's an entry
 * Return: buffer
 *
 **/
char *get_line(int isatty_value)
{
	ssize_t characters_read = 0;
	size_t num_bytes = 0;
	char *buffer = NULL;

	if (isatty_value == 1)
	{
		printf("$ ");
	}

	characters_read = getline(&buffer, &num_bytes, stdin);

	if (characters_read == EOF)
	{
		if (isatty_value == 1)
		{
			printf("\n");
		}
		free(buffer);
		exit(EXIT_SUCCESS);
	}
	return (buffer);
}
```