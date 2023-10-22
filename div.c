#include "monty.h"

/**
 * f_div - Divides the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number.
 */
void f_div(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	int stack_size = 0, result;

	while (current)
	{
		current = current->next;
		stack_size++;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	current = *head;
	int divisor = current->n;
	int dividend = current->next->n;
	if (divisor == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	result = dividend / divisor;
	current->next->n = result;
	*head = current->next;
	free(current);
}
