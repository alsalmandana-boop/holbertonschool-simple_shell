#include "shell.h"
/**
 * search_path - search for the command inside the path directories
 * @command: the command typed by the user
 * Return: the full path if found or null if not
 */
char *search_path(char *command)
{
	char *path_env, *path_copy, *dir, *full_path;

	path_env = _getenv("PATH");
	if (path_env == NULL || path_env[0] == '\0')
		return (NULL);

	path_copy = malloc(strlen(path_env) + 1);

	if (path_copy == NULL)
		return (NULL);

	strcpy(path_copy, path_env);
	dir = strtok(path_copy, ":");

	while (dir != NULL)
	{
		full_path = malloc(strlen(dir) + strlen(command) + 2);
		if (full_path != NULL)
		{
			strcpy(full_path, dir);
			strcat(full_path, "/");
			strcat(full_path, command);

			if (access(full_path, X_OK) == 0)
			{
				free(path_copy);
				return (full_path);
			}
			free(full_path);
		}
		dir = strtok(NULL, ":");
	}
	free(path_copy);
	return (NULL);
}

