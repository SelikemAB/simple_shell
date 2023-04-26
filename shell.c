#include "main.h"

/**
 * main - simple shell program
 * @argc: argument count
 * @argv: argument vector
 * @env: environment
 *
 * Return: (0);
 */
int main(int argc, char **argv, char **env)
{
	char *line_read = NULL, *token, *path, *args[64];
	char path_env[1024], *command_path;
	int i, status;
	size_t n = 64;

	while (1)
	{
		_strcpy(path_env, _getenv("PATH"));
		write(STDOUT_FILENO, "$ ", 2);
		read_input(&line_read, &n);
		tokenize(line_read, args, 63, "\n ");

		if (args[0] == NULL)
		{
			_free(&line_read);
			continue;
		}

		if (_strcmp(args[0], "exit") == 0)
			exit(EXIT_SUCCESS);

		char *command_path = find_command(args, path_env);

		if (command_path == NULL)
			p_error(argv[0], args[0]);

		else
		{
			execute_command(command_path, args, env);
			free(command_path);
		}
		_free(&line_read);
	}

	return (0);
}
