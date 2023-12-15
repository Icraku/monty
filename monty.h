#ifndef __ST_HEADER__
#define __ST_HEADER__

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/syscall.h>
#include <string.h>

/**
 * struct stack_s - Doubly linked list representation of a stack
 * @n: interger
 * @prev: points of the previous element of the stack
 * @next: points of the next element of the stack
 *
 * Description: structure for stack, queues, LIFO/FIFO project
 * of a doubly linked list node
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its corresponding function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function 
 * for stack, queues, LIFO, FIFO project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int lineNo);
} instruction_t;

void printTop(stack_t **stack, unsigned int lineNo);
void addition(stack_t **stack, unsigned int lineNo);
void printAll(stack_t **stack, unsigned int lineNo);
void popTop(stack_t **stack, unsigned int lineNo);
void pushToStack(stack_t **stack, unsigned int lineNo, int n);
void swapTopTwo(stack_t **stack, unsigned int lineNo);

void freeStack(stack_t *head);
void freeTknList(char *t[]);

int pushInt(char *list, int lN);
int combinedFind(char *list, int lN);
int nL_Index(char *list);

int strCompare(char *opcode, char *list);
void execInstructions(char *tknStr[], stack_t *stack);

#endif
