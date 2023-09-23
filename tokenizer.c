#include "main.h"

/**
 * tokenizer - splits string
 * @s: array of string character.
 * @sep: seperator.
 * Return: an array of each word of the string.
*/
char **tokenizer(char *s, char *sep)
{
	int n = 0;
	char **arr, *token;

	/** Create Dynamic array */
	arr = malloc(30 * sizeof(char *));
	if (arr == NULL)
		return (NULL);

	/** Get Token and use for loop to extract the rest. */
	token = _strtok(s, sep);
	while (token != NULL)
	{
		arr[n] = token;
		token = _strtok(NULL, sep);
		n++;
	}
	arr[n] = NULL;

	return (arr);
}
