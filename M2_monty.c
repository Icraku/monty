#include "monty.h"

/**
 * printTop - prints top element of stack
 * @stack: Points to head of stack
 * @lineNo: line number
 */
void printTop(stack_t **stack, unsigned int lineNo)
{
	(void)lineNo;
	if (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * addition - adds the top two elements in stack
 * @stack: Points to head of stack
 * @lineNo: line number
 */
void addition(stack_t **stack, unsigned int lineNo)
{
	(void)lineNo;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		int sum = (*stack)->n + (*stack)->next->n;

		popTop(stack, 0);
		(*stack)->n = sum;
	}
	else
	{
		fprintf(stderr, "L%u: Cannot add, stack too short\n", lineNo);
		exit(EXIT_FAILURE);
	}
}
