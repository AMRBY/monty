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
* ifs - main function
* @fp: the command we get
* @line: the command we get
* Return: monty value
*/

void ifs(FILE *fp, char *line)
{
	char **token = NULL;
	stack_t *head = NULL;
	int i = 0, j;

	while (fgets(line, 100, fp) != NULL)
	{
		i++;
		j = _strlen(line);
		if (j == 1)
			continue;
		line[j - 1] = '\0';
		token = tokenn(line);

		if (_strcmp(token[0], "push") == 0)
		{
			if (token[1])
				add_dnodeint(&head, atoi(token[1]));
			else
			{
				printf("L %i: push integer\n", i);
				free_arr(token);
				free_dlistint(head);
				free(line);
				exit(EXIT_FAILURE);
			}

		}
		else if (_strcmp(token[0], "pall") == 0)
			print_dlistint(head);
		else
		{
			printf("L %i: unknown instruction %s\n", i, token[1]);
			free_arr(token);
			free_dlistint(head);
			free(line);
			exit(EXIT_FAILURE);
		}
	free_arr(token);
	}
	free_dlistint(head);
	free(line);
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
	if (line == NULL)
		return (1);
	ifs(fp, line);
	fclose(fp);
	return (0);
}
