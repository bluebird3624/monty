#include "monty.h"

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @value: Value to be pushed onto the stack.
 */
void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the Monty byte code file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

/**
 * free_stack - Frees a stack.
 * @stack: Double pointer to the head of the stack.
 */
void free_stack(stack_t **stack)
{
    stack_t *current = *stack;
    stack_t *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    *stack = NULL;
}

/**
 * is_integer - Checks if a string is an integer.
 * @str: The string to be checked.
 * Return: 1 if the string is an integer, 0 otherwise.
 */
int is_integer(char *str)
{
    if (!str)
        return 0;

    if (*str == '-')
        str++;

    while (*str)
    {
        if (!isdigit((unsigned char)*str))
            return 0;
        str++;
    }

    return 1;
}
