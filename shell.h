#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int exec(char *args[64], char **argv);
char *_getenv(const char *name);
char *search_path(char *command);

/* Environment variables */
extern char **environ;

#endif /* SHELL_H */
