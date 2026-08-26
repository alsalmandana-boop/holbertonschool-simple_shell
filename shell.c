#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/**
 * main - Simple shell command interpreter
 * @argc: Number of arguments
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;
	char *args[2];

	(void)argc;

while (1)
{
	if (isatty(STDIN_FILENO))
	{
		printf("#cisfun$ ");
		fflush(stdout);
	}

	nread = getline(&line, &len, stdin);

	if (nread == -1)
		break;

	if (nread > 0 && line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	if (line[0] == '\0')
		continue;

	args[0] = line;
	args[1] = NULL;

	pid = fork();

	if (pid == -1)
	{
		perror("fork");
		free(line);
		exit(EXIT_FAILURE);
	}

	if (pid == 0)
	{
		execve(args[0], args, environ);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}

	wait(&status);
}

free(line);
return (0);
}
