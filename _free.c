#include "main.h"

/**
 * _free - frees pointer pointed to by lineptr
 * @lineptr: address of pointer to be freed
 *
 * Return: nothing
 */
void _free(char **lineptr)
{
	free(*lineptr);
	*lineptr = NULL;
}
