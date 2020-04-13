# 0x16. C - Simple Shell

## Table of Contents
* [Description](#description)
* [Requirements](#requirements)
* [Libraries](#libraries)
* [Propotipes](#prototipes)
* [Testing](#testing)


### Description
Final project of the quarter, make a shell following certain rules and requirements.

### Requirements
* Allowed editors: vi, vim, emacs
* All your files will be compiled on Ubuntu 14.04 LTS
* Your C programs and functions will be compiled with gcc 4.8.4 using the flags -Wall -Werror -Wextra and -pedantic

### Compilation
Your shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`


### Libraries
Use this data Librarie for this project:

`#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>`

### Prototipes
These are the Prototypes of Functions to be used:

`char *get_line(void);
char *func_strtok(char *mensaje);
void execute_program(char *token);
`

### Testing
Your shell should work like this in interactive mode:

`$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
`
