#include "monty.h"

/**
 * printAll - print all stack values
 * @stack: pointer to stack's head
 * @lineNo: line number of the file
 * Return: void
 */

void printAll(stack_t **stack, unsigned int lineNo)
{
	stack_t *cur = *stack;
	(void)lineNo;

	while (cur != NULL)
	{
		printf("%d\n", cur->n);
		cur = cur->next;
	}
}

/**
 * popTop - Removes the first/top stack element
 * @stack:pointer to stack's head
 * @lineNo: line number of the file
 * Return: void
 */

void popTop(stack_t **stack, unsigned int lineNo)
{
	stack_t *cur = *stack;
	if(!(*stack))
	{
		fprintf(stderr, "L%u: empty stack cannot be popped\n", lineNo);
		exit(EXIT_FAILURE);
	}
	
	if (cur != NULL)
	{
		*stack = (cur)->next;
		free(cur);
	}
}

/**
 * pushToStack - Pushes element to the stack
 * @stack:pointer to stack's head
 * @lineNo: line number of the file
 * @n: a variable
 * Return: address of the new element that's pushed
 */
void pushToStack(stack_t **stack, unsigned int lineNo, int n)
{
	stack_t *new;
	stack_t *cur = *stack;
	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: To push an integer", lineNo);
		exit(EXIT_FAILURE);
	}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		exit(EXIT_FAILURE);
	}
	new->prev = NULL;
	new->n = n;
	new->next = *stack;

	if (*stack != NULL)
	{
		cur->prev = new;
	}
	*stack = new;
}

/**
 * swapTopTwo - Swaps the first two element to the stack
 * @stack: pointer to stack's head
 * @lineNo: line number of the file
 * Return: void
 */
void swapTopTwo(stack_t **stack, unsigned int lineNo)
{
	stack_t *temp;
	stack_t *cur = *stack;

	if ((*stack) == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: Cannot swap because stack is too short\n", lineNo);
		exit(EXIT_FAILURE);
	}
	if (cur != NULL && cur->next != NULL)
	{
		temp = cur->next;
		if (temp->next)
			temp->next->prev = cur;
		cur->next = temp->next;
		temp->prev = NULL;
		temp->next = cur;
		cur->prev = temp;
		*stack = temp;
	}
}
