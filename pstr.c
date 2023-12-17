#include "monty.h"

/**
 * pstr - Prints the string starting at the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 */

void pstr(stack_t **stack)
{
    stack_t *current = *stack;

    while (current != NULL && current->n != 0 && current->n >= 0 && current->n <= 127)
    {
        putchar(current->n);
        current = current->next;
    }

    putchar('\n');
    pop_until_null(stack);
}


/**
 * pop_until_null - Pops elements from the stack until a null value is encountered.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pop_until_null(stack_t **stack)
{
	stack_t *current = *stack;
	stack_t *next;

	while (current != NULL && current->n != 0)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = current;
}
