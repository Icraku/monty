#define _POSIX_C_SOURCE 200809L
#include "monty.h"

/**
 * execInstructions - executes the instructions of the opcodes
 * @tknStr: contains the file content
 * @stack: the (singly linked) list
 * Return: void
 */
void execInstructions(char *tknStr[], stack_t *stack)
{
	int ind = 0, lN = 1, n = 0;

	instruction_t instruct[] = {
		{"pint", printTop},
		{"add", addition},
		{"pall", printAll},
		{"pop", popTop},
		{"swap", swapTopTwo},
		{"null", NULL}
	};

	for (n = 0, lN = 1; tknStr[n + 1]; lN++, n++)
	{
		if (strCompare("nop", tknStr[n]))
			;
		else if (strCompare("push", tknStr[n]))
			pushToStack(&stack, lN, pushInt(tknStr[n], lN));
		else
		{
			while (!strCompare(instruct[ind].opcode, "null"))
			{
				if (strCompare(instruct[ind].opcode, tknStr[n]))
				{
					instruct[ind].f(&stack, lN);
					break;
				}
				ind++;
			}
			if (strCompare(instruct[ind].opcode, "null") &&
			!strCompare(tknStr[n], "\n"))
			{
				fprintf(stderr, "L%u: instruction %s is unknown", lN, tknStr[n]);
				if (!nL_Index(tknStr[n]))
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	freeStack(stack);
}

/**
 * main - Entry point for the monty interpreter
 * @ac: argument count
 * @av: argument vector ie argument array
 * Return: void
 */
int main(int ac, char *av[])
{
	FILE *file_desc;

	int n = 0;
	stack_t *stack = NULL;
	size_t bufSz = 1020;
	static char *tknStr[1020] = {NULL};

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: Monty file\n");
		exit(EXIT_FAILURE);
	}
	file_desc = fopen(av[1], "r");
	if (file_desc == NULL)
	{
		fprintf(stderr, "ERROR: Cannot open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}

	for (n = 0; getline(&(tknStr[n]), &bufSz, file_desc) > 0; n++)
		;
	execInstructions(tknStr, stack);
	freeTknList(tknStr);
	fclose(file_desc);
	return (0);
}
