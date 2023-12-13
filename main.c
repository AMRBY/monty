#include "monty.h"
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
		tokens[i] = _strdup(token);
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
	FILE *fp;
	char *line;
	stack_t *head = NULL;
	char **token = NULL;
	int i = 0;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line = malloc(sizeof(char) * 2048);
	while (fgets(line, 100, fp) != NULL)
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
			free(line);
			exit(EXIT_FAILURE);
		}
	}
	free(line);
	fclose(fp);
	return (0);
}
