#include "shell.h"
/**
 * _getenv - gets the value of an environment variable
 * @name: the name of the variable to find
 * Return: pointer to the value string or null if not found
 */
char *_getenv(const char *name)
{
	int i = 0;
	int len;

	if (name == NULL || environ == NULL)
		return (NULL);
	len = strlen(name);

	while (environ[i] != NULL)
	{
		if (strncmp(environ[i], name, len) == 0)
			if (environ[i][len] == '=')
				return (environ[i] + len + 1);
		i++;
	}
	return (NULL);
}

