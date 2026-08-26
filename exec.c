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
void exec(char *args[64], char **argv)
{
	pid_t pid;
	int path_len;
	char *path;

	if (args[0][0] == '/')
	{
		path_len = strlen(args[0]) + 1;
		path = malloc(path_len);
		if (path == NULL)
			return;
		strcpy(path, args[0]);
	}
	else
	{
		path_len = 6 + strlen(args[0]);
		path = malloc(path_len);
		if (path == NULL)
			return;
		strcpy(path, "/bin/");
		strcat(path, args[0]);
	}

	if (access(path, X_OK) == 0)
	{
		pid = fork();
		if (pid == -1)
		{
			free(path);
			perror("fork");
			return;
		}
		else if (pid == 0)
		{

			execve(path, args, environ);
			perror(argv[0]);
			free(path);
			_exit(EXIT_FAILURE);
		}

	}
	else
		perror(argv[0]);
	free(path);
}

