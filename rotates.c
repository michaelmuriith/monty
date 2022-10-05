#include "monty.h"

/**
 * _rotr - rotates the stack to the bottom
 * @stack: head
 * @num_line: num line
 */

void _rotr(stack_t **stack, unsigned int num_line)
{
	stack_t *temp2;

	if (*stack && (*stack)->next)
	{
		temp2 = *stack;
		if (num_line)
			while (temp2->next)
			{
				temp2 = temp2->next;
			}
		temp2->next = *stack;
		temp2->prev->next = NULL;
		temp2->prev = NULL;
		*stack = temp2;
	}
}

/**
 * _rotl - rotates the stack to the top.
 * @stack: head
 * @num_line: num line
 */

void _rotl(stack_t **stack, unsigned int num_line)
{
	stack_t *temp1;
	stack_t *temp2;

	if (*stack && (*stack)->next)
	{
		temp1 = *stack;
		temp2 = temp1;
		*stack = temp1->next;
		(*stack)->prev = NULL;
		if (num_line)
			while (temp2->next)
			{
				temp2 = temp2->next;
			}
		temp2->next = temp1;
		temp1->prev = temp2;
		temp1->next = NULL;
	}
}
