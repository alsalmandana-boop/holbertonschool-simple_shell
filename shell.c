#include "shell.h"

/**
 * main - Simple UNIX command interpreter
 * @argc: Number of arguments
 * @argv: Argument vector
 *
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	char *command;
	char *args[2];
	size_t len = 0;
	ssize_t nread;
	pid_t pid;
	int status;

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

		command = strtok(line, " \t\n");

		if (command == NULL)
			continue;

		args[0] = command;
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
			_exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}

	free(line);
	return (0);
}
