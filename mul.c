#include "monty.h"
/**
 * f_mul - Multiplies the top two elements of the stack.
 * @head: Pointer to the stack head.
 * @counter: Line number.
 * Return: No return.
 */
void f_mul(stack_t **head, unsigned int counter)
{
	stack_t *current;
	int stack_size = 0, product;

	current = *head;
	while (current)
	{
		current = current->next;
		stack_size++;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	product = current->next->n * current->n;
	current->next->n = product;
	*head = current->next;
	free(current);
}
