#include "monty.h"

/**
 * _pchar - prints the char at the top of the stack, followed by a new line
 * @stack: head
 * @num_line: integer
 */

void _pchar(stack_t **stack, unsigned int num_line)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		free(global.line);
		fclose(global.fil);
		free_l(stack);
		dprintf(2, "L%u: can't pchar, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
	if (temp->n >= 128 || temp->n < 0)
	{
		free(global.line);
		fclose(global.fil);
		free_l(stack);
		dprintf(2, "L%d: can't pchar, value out of range\n", num_line);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}

/**
 * _pstr - prints the string starting at the top of the stack
 * @stack: head
 * @num_line: num line
 */
void _pstr(stack_t **stack, unsigned int num_line)
{
	stack_t *temp;

	temp = *stack;
	if (num_line)
		while (temp && temp->n != 0 && temp->n > 0 && temp->n < 128)
		{
			printf("%c", temp->n);
			temp = temp->next;
		}
	printf("\n");
}

/**
 * _pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: head
 * @num_line: num linea
 */
void _pall(stack_t **stack, unsigned int num_line)
{
	stack_t *temp;

	temp = *stack;
	if (num_line)
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
}

/**
 * _pint - prints the value at the top of the stack
 * @stack: head
 * @num_line: num line
 */
void _pint(stack_t **stack, unsigned int num_line)
{
	stack_t *temp;

	temp = *stack;
	if (temp == NULL)
	{
		free(global.line);
		fclose(global.fil);
		free_l(stack);
		dprintf(2, "L%u: can't pint, stack empty\n", num_line);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", temp->n);
}
