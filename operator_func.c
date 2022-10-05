#include "monty.h"

/**
 * _add - adds the top two elements of the stack.
 * @stack: head
 * @num_line: number of line
 */
void _add(stack_t **stack, unsigned int num_line)
{
	stack_t *temp1;
	stack_t *temp2;
	int sum = 0;

	if (*stack && (*stack)->next)
	{
		temp2 = (*stack)->next;
		sum = (*stack)->n + temp2->n;
		temp1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp1);
		(*stack)->n = sum;
	}
	else
	{
		dprintf(2, "L%d: can't add, stack too short\n", num_line);
		free(global.line);
		fclose(global.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _div -des the second top element of the stack
 * by the top element of the stack.
 * @stack: node head
 * @num_line: number of the line
 */
void _div(stack_t **stack, unsigned int num_line)
{
	stack_t *temp1;
	stack_t *temp2;
	int divi = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			dprintf(2, "L%u: division by zero\n", num_line);
			free(global.line);
			fclose(global.fil);
			free_l(stack);
			exit(EXIT_FAILURE);
		}
		temp2 = (*stack)->next;
		divi = temp2->n / (*stack)->n;
		temp1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp1);
		(*stack)->n = divi;
	}
	else
	{
		dprintf(2, "L%u: can't div, stack too short\n", num_line);
		free(global.line);
		fclose(global.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mod - computes the rest of the division of the second
 * top element of the stack by the top element of the stack.
 * @stack: head
 * @num_line: integer
 */

void _mod(stack_t **stack, unsigned int num_line)
{
	stack_t *temp1;
	stack_t *temp2;
	int mult = 0;

	if (*stack && (*stack)->next)
	{
		if ((*stack)->n == 0)
		{
			dprintf(2, "L%u: division by zero\n", num_line);
			free(global.line);
			fclose(global.fil);
			free_l(stack);
			exit(EXIT_FAILURE);
		}
		temp2 = (*stack)->next;
		mult = temp2->n % (*stack)->n;
		temp1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp1);
		(*stack)->n = mult;
	}
	else
	{
		dprintf(2, "L%d: can't mod, stack too short\n", num_line);
		free(global.line);
		fclose(global.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _mul - multiplies the second top element of the stack with the
 * top element of the stack
 * @stack: head
 * @num_line: integer
 */

void _mul(stack_t **stack, unsigned int num_line)
{
	stack_t *temp1;
	stack_t *temp2;
	int mult = 0;

	if (*stack && (*stack)->next)
	{
		temp2 = (*stack)->next;
		mult = temp2->n * (*stack)->n;
		temp1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp1);
		(*stack)->n = mult;
	}
	else
	{
		dprintf(2, "L%u: can't mul, stack too short\n", num_line);
		free(global.line);
		fclose(global.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * _sub - subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: head
 * @num_line: number line
 */
void _sub(stack_t **stack, unsigned int num_line)
{
	stack_t *temp1;
	stack_t *temp2;
	int rest = 0;

	if (*stack && (*stack)->next)
	{
		temp2 = (*stack)->next;
		rest = temp2->n - (*stack)->n;
		temp1 = *stack;
		*stack = (*stack)->next;
		if (*stack)
			(*stack)->prev = NULL;
		free(temp1);
		(*stack)->n = rest;
	}
	else
	{
		dprintf(2, "L%u: can't sub, stack too short\n", num_line);
		free(global.line);
		fclose(global.fil);
		free_l(stack);
		exit(EXIT_FAILURE);
	}
}
