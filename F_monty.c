#include "monty.h"

/**
 * freeTknList - frees the list from the getline command
 * @t: pointer to the string token array
 * Return: Nothing
 */
void freeTknList(char *t[])
{
	int ind = 0;

	while (t[ind] != NULL)
	{
		free(t[ind]);
		ind++;
	}
}

/**
 * freeStack - frees the Stack
 * @head: points to the list/stack
 * Return: Nothing
 */
void freeStack(stack_t *head)
{
	stack_t *node = head;

	if (head == NULL)
		return;
	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
	}
}
