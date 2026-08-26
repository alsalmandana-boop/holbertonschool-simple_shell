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
	char *token;
	char *args[64];
	size_t len = 0;
	ssize_t nread;
	int i, status = 0;

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

		i = 0;
		token = strtok(line, " \t\n");

		while (token != NULL && i < 63)
		{
			args[i] = token;
			i++;
			token = strtok(NULL, " \t\n");
		}

		args[i] = NULL;

		if (args[0] == NULL)
			continue;
		status = exec(args, argv);
	}

	free(line);
	return (status);
}
