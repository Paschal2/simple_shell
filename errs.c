#include "shell.h"

/**
 * _eputs - prints an input string
 * @strr: the string to be printed
 *
 * Return: Nothing
 */
void _eputs(char *strr)
{
	int b = 0;

	if (!strr)
		return;
	while (strr[b] != '\0')
	{
		_eputchar(strr[b]);
		b++;
	}
}

/**
 * _eputchar - writes the character c to stderr
 * @a: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _eputchar(char a)
{
	static int b;
	static char buff[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(2, buff, b);
		b = 0;
	}
	if (a != BUF_FLUSH)
		buff[b++] = a;
	return (1);
}

/**
 * _putfd - writes the character c to given fd
 * @a: The character to print
 * @fd: The filedescriptor to write to
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putfd(char a, int fd)
{
	static int b;
	static char buff[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(fd, buff, b);
		b = 0;
	}
	if (a != BUF_FLUSH)
		buff[b++] = a;
	return (1);
}

/**
 * _putsfd - prints an input string
 * @strr: the string to be printed
 * @fd: the filedescriptor to write to
 *
 * Return: the number of chars put
 */
int _putsfd(char *strr, int fd)
{
	int b = 0;

	if (!strr)
		return (0);
	while (*strr)
	{
		b += _putfd(*strr++, fd);
	}
	return (b);
}
