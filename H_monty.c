#include "monty.h"

/**
 * combinedFind - function to find combination of numbers and non-numbers
 * @list: the string to look into
 * @lN: the line number
 * Return: 1, 0 if error
 */
int combinedFind(char *list, int lN)
{
	int ind = 1;

	while (list[ind])
	{
		if (list[ind] == '\n' || list[ind] == '\0')
			break;
		else if (list[ind] == ' ' || (list[ind] >= '0' && list[ind] <= '9'))
			ind++;
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n", lN);
			exit(EXIT_FAILURE);
		}
	}
	return (1);
}

/**
 * strCompare - compares two strings
 * @opcode: the string to be compared
 * @list: the string to be compared to
 * Return: 0
 */
int strCompare(char *opcode, char *list)
{
	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0' && (*list == '\n' || *list == '\0' || *list == ' '))
				return (1);
		}
		else
			return (0);
	}
	return (0);
}

/**
 * pushInt - the integer for the push opcode
 * @list: the contents of the specific file
 * @lN: the line number
 * Return: the number
 */
int pushInt(char *list, int lN)
{
	char *opcode = "push";

	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
				while (*list)
				{
					if (*list == ' ')
						list++;

					else if (*list == '-' || (*list >= '0' && *list <= '9'))
					{
						combinedFind(list, lN);
						return (atoi(list));
					}
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", lN);
						exit(EXIT_FAILURE);
					}
				}
		}
		else
			list++;
	}
	return (0);
}

/**
 * nL_Index - finder of the '\n' ie the newline
 * @list: the string to find the newline
 * Return: 1, otherwise 0
 */
int nL_Index(char *list)
{
	char *opcode = "\n";

	while (*list != '\0')
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
				return (1);
		}
		else
			list++;
	}
	return (0);
}
