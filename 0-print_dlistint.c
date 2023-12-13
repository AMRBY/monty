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
