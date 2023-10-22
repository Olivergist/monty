#include "monty.h"

/**
 * f_add - Adds the top two elements of the stack.
 * @head: Pointer to the head of the stack.
 * @counter: Line number.
 */
void f_add(stack_t **head, unsigned int counter)
{
	stack_t *current = *head;
	int stack_size = 0, result;
	int operand1, operand2;

	while (current)
	{
		current = current->next;
		stack_size++;
	}

	if (stack_size < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	current = *head;
	operand1 = current->n;
	operand2 = current->next->n;

	result = operand1 + operand2;
	current->next->n = result;
	*head = current->next;
	free(current);
}
