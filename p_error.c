#include "main.h"

/**
 * p_error - prints error message to stderr
 * @argv: program name
 * @args: command name
 *
 * Return: nothing
 */
void p_error(char *argv, char *args)
{
	char arr[MAX_COMMAND_LEN];

	_strcpy(arr, argv);
	_strcat(arr, ": ");
	_strcat(arr, args);
	_strcat(arr, ": ");
	_strcat(arr, "command not found\n");

	write(STDERR_FILENO, arr, _strlen(arr));
}
