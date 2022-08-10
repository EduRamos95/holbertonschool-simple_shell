#include "main.h"
/**
 * PATH_to_dirs - returns string with value of variable PATH
 *
 * Return: string with value of PATH
 */
char *PATH_to_dirs(char **env)
{
	char *path = "PATH=";
	unsigned int i, j;

	for(i = 0; env[i] != NULL; i++)
	{
		for (j = 0; j < 5; j++)
			if (path[j] != env[i][j])
				break;
		if(j == 5)
			break;
	}
	return (env[i]);
}

/**
 * get_full_command - searches for an input command in each
 * directory of PATH
 * @command: input command
 *
 * Return: command with directory if founf, NULL otherwise
 */
char *get_full_command(char *command)
{
	char *line, *token, *check_com, *clone_env;
	size_t n, command_found = 0;
	list_t *paths, *ptr;
	struct stat st;

	line = PATH_to_dirs(environ);
	clone_env = malloc (strlen(line) + 1 - 5);
	strcpy(clone_env, line + 5);
	paths = NULL;
	token = strtok(clone_env, ":");
	while (token != NULL)
	{
		add_node_end(&paths, token);
		token = strtok(NULL, ":");
	}
	/*free(token);*/
	/*ptr = malloc(sizeof(list_t));*/
	/*free(line);*/
	ptr = paths;
	while (ptr)
	{
		n = strlen(ptr->str);
		check_com = malloc(n + strlen(command) + 2);
		strncpy(check_com, ptr->str, n);
		check_com[n] = '/';
		strcpy(check_com + n + 1, command);
		if (stat(check_com, &st) == 0)
		{
			command_found = 1;
			break;
		}
		free(check_com);
		ptr = ptr->next;
	}
	free(clone_env);
	if (command_found)
		return (check_com);
	return (NULL);
}
