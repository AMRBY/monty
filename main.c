#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
* free_arr - free an array
* @arr: the array u wanna free
* Return: nothing
*/
void free_arr(char **arr)
{
	int i = 0;

	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}
/**
* tokenn - split all the command
* @str: the command we get
* Return: an array of the splited command
*/
char **tokenn(char *str)
{
	char *token, **tokens;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
	{
		perror(str);
		exit(EXIT_FAILURE);
	}
	token = strtok(str, " \t");
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		token = strtok(NULL, " \t");
		i++;
	}
	tokens[i] = NULL;
	return (tokens);
}
/**
* main - main function
* @argc: the command we get
* @argv: the command we get
* Return: monty value
*/

int main(int argc, char *argv[])
{
	char *line = NULL;
	size_t len = 0;
	stack_t *head;
	char **token = NULL;
	int i = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	FILE *fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &len, fp) != -1)
	{
		i++;
		token = tokenn(line);
		if (_strcmp(token[0], "push") == 0)
			add_dnodeint(&head, atoi(token[1]));
		else if (_strcmp(token[0], "pall") == 0)
			print_dlistint(head);
		else
		{
			printf("L %i: unknown instruction %s\n", i, token[1]);
			exit(EXIT_FAILURE);
		}
		free_arr(token);
		free(line);
	}
	fclose(fp);
	return (0);
}
