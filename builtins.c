#include "main.h"

/**
 * builtins - shell builtins.
 * @s: string to compare.
 * Return: Always 0.
*/
int (*builtins(char *s))(char **text, int attempt, alias_t **ls)
{
	builtin_t sys[] = {
		{"env", _printenv},
		{"alias", _alias},
		{NULL, NULL}
	};
	int i = 0;

	while (sys[i].builtin)
	{
		if (_strcmp(sys[i].builtin, s) == 0)
			return (sys[i].func);
		i++;
	}

	return (NULL);
}

/**
 * _exitshell - exits shell.
 * @grid: list of arguments
 * @cnt: count of program run.
 * @lg: line grid - Multi line grid.
 * @sg: sub grid.
 * @h: head alias
 * Return: Always 0.
*/
int _exitshell(char **grid, int cnt, alias_t **h)
{
	int status = errno;

	if (grid[1])
	{
		status = _atoi(grid[1]);
		if (status <= 0)
		{
			exit_error(cnt, grid[1]);
			status = 2;
		}
	}

	free_alias(h);
	free(grid);
	exit(status);
}

/**
 * _printenv - prints env.
 * @grid: list of arguments
 * @cnt: count of program run.
 * @ls: alias list
 * Return: Always 0.
*/
int _printenv(char **grid, int cnt, alias_t **ls)
{
	int i;
	char newline = '\n';

	(void)grid;
	(void)ls;
	(void)cnt;
	if (!environ)
		return (-1);
	for (i = 0; environ[i]; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, &newline, 1);
	}

	return (0);
}
