#include "monty.h"
/**
* print_dlistint - length of strings
* Description: find digit
* @h: int pointer
* Return: size_t
*/
size_t print_dlistint(const stack_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		printf("%i\n", h->n);
		h = h->next;
		n++;
	}
	return (n);
}
/**
* dlistint_len - length of strings
* Description: find digit
* @h: int pointer
* Return: size_t
*/
size_t dlistint_len(const stack_t *h)
{
	size_t n = 0;

	while (h != NULL)
	{
		h = h->next;
		n++;
	}
	return (n);
}
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
