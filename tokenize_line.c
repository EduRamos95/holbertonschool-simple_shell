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
 * get_number - gets number of words in an input string
 * @line: input string
 *
 * Return: word count
 */
int get_number(char *line)
{
	int i = 0, n = 1;

	while (line[i])
	{
		if (line[i] == ' ')
			n++;
		i++;
	}
	return (n);
}

/**
 * tokenize_line - tokenizes an input string
 * @line: input string
 *
 * Return: array of tokens obtained from variable line
 */

char **tokenize_line(char *line)
{
	char *token;
	size_t len = 0, i, n;
	ssize_t read = 0;
	char **argv;

	while (read != EOF)
	{
		printf("($) ");
		read = getline(&line, &len, stdin);
		
		if (read == -1)
		{
			break;
		}
		line = no_enter(line);

		if (validate_spaces(line))
		{
			continue;
		}

		n = get_number(line);

		argv = malloc((n + 1) * sizeof(char *));
		token = strtok(line, " ");
		i = 0;
		if (n > 1)
		{
			i = 0;
			while (token != NULL)
			{
				argv[i] = strdup(token);
				token = strtok(NULL, " ");
				i++;
			}
			argv[i] = NULL;
		}
		else
		{
			argv[0] = strdup(token);
			argv[1] = NULL;
		}
		return (argv);
	}
	return(0);
}
