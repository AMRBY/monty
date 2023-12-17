#include "monty.h"
/**
* free_all - free an array
* @token: the array u wanna free
* @head: the array u wanna free
* @line: the array u wanna free
* Return: nothing
*/
void free_all(char **token, stack_t *head, char *line)
{
		free_arr(token);
		free_dlistint(head);
		free(line);
}
/**
* push - free an array
* @token: the array u wanna free
* @head: the array u wanna free
* Return: nothing
*/
void push(char **token, stack_t *head, char *line, int i)
{
	if (token[1])
	{
		add_dnodeint(&head, atoi(token[1]));
	}
	else
	{
		printf("L%i: usage: push integer\n", i);
		free_all(token, head, line);
		exit(EXIT_FAILURE);
	}
}
