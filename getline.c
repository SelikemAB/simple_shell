#include "main.h"

/**
 * _getline - reads a line from a fd
 * and stores it in a dynamically allocated buffer.
 * @lineptr: address of the buffer
 * @n: pointer to the size of the buffer
 * @fd: the file descriptor to read from
 *
 * Return: the number of bytes read on success, -1 on error
 */

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	static size_t buff_size = INITIAL_BUFFER_SIZE;
	char *buf = *lineptr;
	ssize_t n_read;

	if (buf == NULL || *n < buff_size)
	{
		if (!_resize_buffer(&buf, n, &buff_size))
			return (-1);

		*lineptr = buf;
	}
	else
		buff_size = *n;

	n_read = _read_file(fd, buf, buff_size);

	if (n_read == -1)
		return (-1);

	buf[n_read] = '\0';

	return (n_read);
}

/**
 * _resize_buffer - resizes buffer
 * @buf: buffer to resize
 * @n: address of original buffer size variable
 * @buff_size: copy of n
 *
 * Return: bool
 */
bool _resize_buffer(char **buf, size_t *n, size_t *buff_size)
{
	*buff_size = INITIAL_BUFFER_SIZE;

	*buf = _realloc(*buf, *buff_size);

	if (buf == NULL)
		return (false);

	*n = *buff_size;

	return (true);
}

/**
 * _read_file - reads file
 * @fd: file descriptor
 * @buf: buffer to read from
 * @buff_size: buffer size
 *
 * Return: bytes read
 */
ssize_t _read_file(int fd, char *buf, size_t buff_size)
{
	ssize_t n_read = 0;

	while ((n_read = read(fd, buf, buff_size - 1)) > 0)
	{
		if (buf[n_read - 1] == '\n')
			break;

		if ((buff_size - 1) > (size_t)n_read)
			break;

		if (!_resize_buffer(&buf, &buff_size, &buff_size))
			return (-1);
	}

	return (n_read);
}
