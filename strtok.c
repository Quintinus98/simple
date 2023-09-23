#include "main.h"

/**
 * delim - checks if character matches seperator;
 * @ch: character
 * @sep: seperator
 * Return: 1 if it matches 0 if it doesnt.
*/
int delim(char charac, char *sep)
{
	while (*sep != '\0')
	{
		if (charac == *sep)
			return (1);
		sep++;
	}
	return (0);
}

/**
 * _strtok - tokenizes a string.
 * @str: string to tokenize.
 * @sep: seperator.
 * Return: Token or Null.
*/
char *_strtok(char *str, char *sep)
{
	static char *ptr_str;
	char *ret;

	if (!str)
		str = ptr_str;
	if (!str)
		return (NULL);

	while (1)
	{
		if (delim(*str, sep))
		{
			str++;
			continue;
		}
		if (*str == '\0')
			return (NULL);
		break;
	}

	ret = str;
	while (1)
	{
		if (*str == '\0')
		{
			ptr_str = str;
			return (ret);
		}
		if (delim(*str, sep))
		{
			*str = '\0';
			ptr_str = str + 1;
			return (ret);
		}
		str++;
	}
}
