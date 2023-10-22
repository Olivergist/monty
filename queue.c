#include "monty.h"
/**
 * f_queue - changes the behavior of push
 * @head: Pointer to the stack head.
 * @counter: Line number (unused).
 * Return: No return.
 */
void f_queue(stack_t **head, unsigned int counter)
{
	(void)head;
	(void)counter;
	bus.lifi = 1;
}

/**
 * addqueue - Adds a node to the tail (queue).
 * @n: New value.
 * @head: Pointer to the head of the stack.
 * Return: No return.
 */
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *current;

	current = *head;
	new_node = malloc(sizeof(stack_t));

	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	new_node->n = n;
	new_node->next = NULL;

	if (!current)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		while (current->next)
			current = current->next;

		current->next = new_node;
		new_node->prev = current;
	}
}
