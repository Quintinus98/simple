#include "main.h"

/**
 * main - Main
 * @argc: count of arguments
 * @argv: list of arguments.
 * Return: Always 0
*/
int main(__attribute__((unused)) int argc, char **argv)
{
	char line[150000], *dynline = NULL;
	int status = isatty(STDIN_FILENO), attempt = 0;
	char **grid = NULL, *sep = " \n";
	alias_t *aliasL = NULL;

	errno = 0;
	while (1 == 1)
	{
		attempt++;
		prompt(status, &dynline, &aliasL);
		_strcpy(line, dynline);
		free(dynline);

		remove_comments(line);
		grid = tokenizer(line, sep);
		if (grid[0] == NULL)
		{
			free(grid);
			continue;
		}
		prepare(grid, attempt, argv, &aliasL);

		free(grid);
	}
	return (errno);
}
