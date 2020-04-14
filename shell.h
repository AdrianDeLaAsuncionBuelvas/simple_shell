#ifndef SHELL_H_
#define SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <fcntl.h>

char *get_line(int isatty_value);
char **func_strtok(char *mensaje);
void execute_program(char **token, char *argv, int number, int isatty_value, char **envi);
int is_buitin(char **token, char **envi);
void free_memory(char **token);

#endif
