#include "monty.h"
/**
 * f_pstr - Prints the string
 * @head: Pointer to the stack head.
 * @counter: Line number (unused).
 * Return: No return.
 */
void f_pstr(stack_t **head, unsigned int counter)
{
	stack_t *current;
	(void)counter;

	current = *head;

	while (current)
	{
		if (current->n > 127 || current->n <= 0)
		{
			break;
		}
		printf("%c", current->n);
		current = current->next;
	}

	printf("\n");
}
