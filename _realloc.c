#include "main.h"

/**
 * _realloc - reallocates memory
 * @ptr: pointer to old memory
 * @size: size of new memory
 *
 * Return: pointer to new memory
 */
void *_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(size);

	if (new_ptr == NULL)
		return (NULL);

	if (ptr == NULL)
		return (new_ptr);

	_memcpy(new_ptr, ptr, size);
	free(ptr);

	return (new_ptr);
}
