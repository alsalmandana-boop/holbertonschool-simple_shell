#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/**
 * exec - Entry point
 * @args: desc,
 * @argv: desc,
 * @line: desc,
 */
void exec(char *args[64], char **argv, char *line)
{
	pid_t pid;
	int path_len = 6 + strlen(args[0]);
	char *path = malloc(path_len);

	if (path == NULL)
	{
		perror("malloc");
		_exit(EXIT_FAILURE);
	}

	strcpy(path, "/bin/");
	strcat(path, args[0]);
	pid = fork();
	if (pid == -1)
	{
		free(path);
		perror("fork");
		free(line);
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{

		execve(path, args, environ);
		perror(argv[0]);
		free(path);
		_exit(EXIT_FAILURE);
	}
	free(path);
}

