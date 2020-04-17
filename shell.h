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
#include <signal.h>
#include <dirent.h>
extern char **environ;

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

#endif
