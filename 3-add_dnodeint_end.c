#include "monty.h"
/**
* add_dnodeint_end - length of strings
* Description: find digit
* @head: int pointer
* @n: int
* Return: size_t
*/
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *h, *end = *head;

	h = malloc(sizeof(stack_t));
	if (h == NULL)
	{
		return (NULL);
	}
	h->n = n;
	h->next = NULL;

	if (*head == NULL)
	{
		h->prev = *head;
		*head = h;
	}
	else
	{
		while (end->next)
			end = end->next;
		h->prev = end;
		end->next = h;
	}
	return (*head);
}
