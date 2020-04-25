<https://latorredev.com/assets/Img/Certifications/Holberton.png>

# What is "the Shell"?

Simply put, the shell is a program that takes commands from the keyboard and gives them to the operating system to perform. In the old days, it was the only user interface available on a Unix-like system such as Linux. Nowadays, we have graphical user interfaces (GUIs) in addition to command line interfaces (CLIs) such as the shell.

On most Linux systems a program called bash (which stands for Bourne Again SHell, an enhanced version of the original Unix shell program, sh, written by Steve Bourne) acts as the shell program. Besides bash, there are other shell programs that can be installed in a Linux system. These include: ksh, tcsh and zsh.

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

### hsh
our shell recognizes basic commands like, pwd, ls, cd, exit, it also recognizes aliases like -l, -1, -s ... etc ...

recognizes basic commands written with the path for example "bin / ls" or abbreviation "ls" recognizes both commands and aliases.


### Requirements
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

### List of allowed functions and system calls

    access (man 2 access)
    chdir (man 2 chdir)
    close (man 2 close)
    closedir (man 3 closedir)
    execve (man 2 execve)
    exit (man 3 exit)
    _exit (man 2 _exit)
    fflush (man 3 fflush)
    fork (man 2 fork)
    free (man 3 free)
    getcwd (man 3 getcwd)
    getline (man 3 getline)
    isatty (man 3 isatty)
    kill (man 2 kill)
    malloc (man 3 malloc)
    open (man 2 open)
    opendir (man 3 opendir)
    perror (man 3 perror)
    read (man 2 read)
    readdir (man 3 readdir)
    signal (man 2 signal)
    stat (__xstat) (man 2 stat)
    lstat (__lxstat) (man 2 lstat)
    fstat (__fxstat) (man 2 fstat)
    strtok (man 3 strtok)
    wait (man 2 wait)
    waitpid (man 2 waitpid)
    wait3 (man 2 wait3)
    wait4 (man 2 wait4)
    write (man 2 write)

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

### AUTHORS

#### Eduardo Vega <1643@holbertonschool.com>

#### Adrian De La Asuncion <1550@holbertonschool.com>