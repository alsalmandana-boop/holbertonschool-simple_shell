#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void exec(char *args[64], char **argv, char *line);


/* Environment variables */
extern char **environ;

#endif /* SHELL_H */
