#include "main.h"

/**
 * read_input - reads user input and stores it in a buffer
 * @line_read: address of buffer to store input
 * @n: address of size of buffer
 *
 * Return: nothing
 */

void read_input(char **line_read, size_t *n)
{
	*line_read = malloc(*n);

	if (*line_read == NULL)
		exit(EXIT_FAILURE);

	if (_getline(line_read, n, STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
}

/**
 * find_command - looks through PATH to find command
 * @args: array of tokenized user input
 * @path_env: string of directories in PATH
 *
 * Return: pointer to string containing command path, NULL on failure
 */
char *find_command(char **args, char *path_env)
{
	char command_path[MAX_COMMAND_LEN];
	char *path = strtok(path_env, ":");

	while (path)
	{
		if (_strchr(args[0], '/') != NULL)
			_strcpy(command_path, args[0]);

		else
		{
			_strcpy(command_path, path);
			_strcat(command_path, "/");
			_strcat(command_path, args[0]);
		}

		if (access(command_path, X_OK) == 0)
			return (_strdup(command_path));

		path = strtok(NULL, ":");
	}

	return (NULL);
}

/**
 * execute_command - executes command using execve
 * @command_path: string containing full command path
 * @args: array of tokenized user input
 * @env: array of environment variables
 */

void execute_command(char *command_path, char **args, char **env)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Error");
		exit(EXIT_FAILURE);
	}

	else if (pid == 0)
	{
		if ((execve(command_path, args, env)) == -1)
		{
			perror("Error");
			exit(EXIT_FAILURE);
		}
	}

	else
		wait(NULL);
}

/**
 * tokenize - separates input into arguments
 * @str: input
 * @args: array of arguments
 * @max_args: maximum no. of arguments
 * @delimiters: delimeters
 *
 * Return: nothing
 */
void tokenize(char *str, char **args, int max_args, char *delimiters)
{
	char *token = strtok(str, delimiters);
	int i = 0;

	while (token != NULL && i < max_args)
	{
		args[i++] = token;
		token = strtok(NULL, delimiters);
	}

	args[i] = NULL;
}
