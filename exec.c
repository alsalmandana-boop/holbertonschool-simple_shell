#include "shell.h"
#include <stdio.h>

/**
 * exec - Entry point
 * @args: array of argument typed by the user
 * @argv: array of arguments passed to the shell
 */
void exec(char *args[64], char **argv)
{
	pid_t pid;
	char *path = NULL;

	if (args[0][0] == '/' || args[0][0] == '.')
	{
		path = malloc(strlen(args[0]) + 1);
		if (path != NULL)
			strcpy(path, args[0]);
	}
	else
		path = search_path(args[0]);

	if (path == NULL)
	{
		fprintf(stderr, "%s: 1: %s: not found\n", argv[0], args[0]);
		return;  
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
		else
		{
			wait(NULL);
		}

	}
	else
		perror(argv[0]);
	free(path);
}

