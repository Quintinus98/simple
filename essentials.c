#include "main.h"

/**
 * prompt - Displays "$ {User input}";
 * @mode: Determines if the $ sign will be printed.
 * @line: Address of line in main.
 * @ls: alias list.
 * Return: Returns the entered user input.
*/

void prompt(int mode, char **line, alias_t **ls)
{
	size_t linecap = 0;
	int linelen = 0;

	if (mode == 1)
		write(1, "$ ", 2);
	linelen = _getline(line, &linecap, stdin);
	if (linelen == -1)
	{
		free_alias(ls);
		exit(errno);
	}
}
