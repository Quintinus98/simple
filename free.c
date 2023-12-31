#include "main.h"

/**
 * free_alias - frees a list_t list.
 * @head: Beginning of the list.
 * Return: Nothing.
*/

void free_alias(alias_t **head)
{
	alias_t *nextNode, *currentNode;

	if (head == NULL)
		return;

	currentNode = *head;
	while (currentNode)
	{
		nextNode = currentNode->next;
		free(currentNode->name);
		free(currentNode->val);
		free(currentNode);
		currentNode = nextNode;
	}
	*head = NULL;
}

/**
 * free_grid - prints a grid of integers
 * @grid: grid
 *
 * Return: Nothing.
 */
void free_grid(char **grid)
{
	int h;

	for (h = 0; grid[h] != NULL; h++)
	{
		free(grid[h]);
	}
	free(grid);
}
