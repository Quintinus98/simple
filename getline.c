#include "main.h"

/**
 * _getline - Gets line from the terminal.
 * @lineptr: address of string line.
 * @linecap: address of line capacity.
 * @file_stream: file file_stream.
 * Return: Length of line.
*/

int _getline(char **lineptr, size_t *linecap, FILE *file_stream)
{
	char ch = '0', *str;
	ssize_t fd, st;
	static size_t val;

	if (lineptr == NULL || linecap == NULL)
	{
		errno = EINVAL;
		return (-1);
	}

	str = malloc((*linecap = *linecap + 1) * sizeof(char));
	if (!str || val != 0)
		return (-1);
	fflush(file_stream);

	for (; ch != '\n'; val++)
	{
		fd = read(STDIN_FILENO, &ch, 1);
		if (fd == -1 || (fd == 0 && val == 0))
		{
			free(str);
			return (-1);
		}
		str[val] = ch;
		if (val == (*linecap - 1))
		{
			str = _realloc(str, *linecap, (*linecap + 2));
			*linecap += 2;
		}
	}
	str[val] = '\n';
	str[val++] = '\0';
	*lineptr = str;

	st = val;
	if (st != 0)
		val = 0;

	return (st);
}
