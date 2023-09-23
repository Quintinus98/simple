#include "main.h"

/**
 * fetch_env - gets an environment variable
 * @env_var: name of env var to get.
 * Return: Environment variable.
*/

char **fetch_env(char *env_var)
{
	int len = 0, i = 0;

	if (!env_var || env_var[0] == '\0')
		return (NULL);

	len = _strlen(env_var);
	/** Get env matching env_var and = sign.*/
	for (i = 0; environ[i] != NULL; i++)
		if (_strncmp(environ[i], env_var, len) == 0 && environ[i][len] == '=')
			return (&environ[i]);

	return (NULL);
}

/**
 * _putenv - Puts an env variable into environ
 * @env: environment variable
 * Return: 0 if successful or -1 if it fails.
*/
int _putenv(char *env)
{
	int len = 0, i = 0;
	char **new_environ;

	while (environ[len])
		len++;

	new_environ = malloc((len + 2) * sizeof(char *));
	if (!new_environ)
		return (-1);

	for (i = 0; environ[i]; i++)
	{
		new_environ[i] = environ[i];
	}
	free(environ);
	environ = new_environ;
	environ[i] = env;
	environ[i + 1] = NULL;


	return (0);
}
