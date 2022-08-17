#include "main.h"

/**
 * no_enter - deletes the 'enter' of the last character
 * @line: input string
 *
 * Return: char pointer
 */
char *no_enter(char *line)
{
        int i = 0;

	i = strlen(line);

	if (line[i - 1] == '\n')
		line [i - 1] = '\0';
        return (line);
}

/**
 * get_words - gets number of words in an input string
 * @line: input string
 *
 * Return: word count for success, -1 failed
 */
int get_words(char *line)
{
        int count_words = 0;
	char *line_copy = NULL;
	char *token = NULL;
	size_t n = 0;

	n = strlen(line);
	line_copy = malloc(n + 1);
	if (line_copy == NULL)
	{
		free(line_copy);
		return (-1);
	}
	strcpy(line_copy, line);
	if (n != strlen(line_copy))
	{
		return (0);
	}
	token = strtok(line_copy, " ");
        while (token != NULL)
	{
        	count_words++;
		token = strtok(NULL, " ");
	}
	free(line_copy);
	return (count_words);
}

/**
 * tokenize_line - tokenizes an input string
 * @line: input stringi
 *
 * Return: array of tokens obtained from variable line
 */

char **tokenize_line(char *line)
{
	char *token;
	size_t len = 0, i = 0, n = 0;
	ssize_t read = 0;
	char **argv;

	while (read != EOF)
	{
		printf("($) ");
		read = getline(&line, &len, stdin);
		
		if (read == -1)
		{
			free(line);
			break;
		}

		/*if (!strcmp(line, "\n"))*/
			/*continue;*/
		if (validate_spaces(line))
			continue;

		line = no_enter(line);
		/*if (line == NULL)*/
			/*continue;*/

		n = get_words(line);
		argv = malloc((n + 1) * sizeof(char *));
		token = strtok(line, " ");

		if (n > 1)
		{
			i = 0;
			while (token != NULL)
			{
				argv[i] = strdup(token);
				if (argv[i] == NULL)
				{
					free(argv);
					return (NULL);
				}
				token = strtok(NULL, " ");
				i++;
			}
			argv[i] = NULL;
		}
		else /*if (n == 1)*/
		{	
			argv[0] = strdup(token);
			if (argv[0] == NULL)
			{
				free(argv);
				return (NULL);
			}
			argv[1] = NULL;
		}
		/**else
		 *{
		 *	argv[0] = NULL;
		 *	argv[1] = NULL;
		 *}
		 *free(line);
		 */
		free(line);
		return (argv);		
	}
	return(NULL);
}
