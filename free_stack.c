#include "monty.h"

/**
 * free_l - free list
 */
void free_l(stack_t **stack)
{
	stack_t *delete = *stack;

	while (*stack)
	{
		delete = delete->next;
		free(*stack);
		*stack = delete;
	}
}
