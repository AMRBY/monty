#include "monty.h"
/**
* add_dnodeint - length of strings
* Description: find digit
* @head: int pointer
* @n: int
* Return: size_t
*/
stack_t *add_dnodeint(stack_t **head, const int n)
{
	stack_t *h;

	h = malloc(sizeof(stack_t));
	if (h == NULL)
	{
		return (NULL);
	}
	h->n = n;
	h->next = *head;
	h->prev = NULL;
	if (*head)
		(*head)->prev = h;
	*head = h;
	return (h);
}
