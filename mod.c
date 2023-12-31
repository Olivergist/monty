#include "monty.h"

/**
 * f_mod - Computes the remainder of the division
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void f_mod(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_size = 0, remainder;

	current = *head;
	while (current)
	{
		current = current->next;
		stack_size++;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	remainder = current->next->n % current->n;
	current->next->n = remainder;
	*head = current->next;
	free(current);
}
