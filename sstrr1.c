#include "shell.h"

/**
 * _strcpy - copies a string
 * @det: the destination
 * @src: the source
 *
 * Return: pointer to destination
 */
char *_strcpy(char *det, char *src)
{
	int b = 0;

	if (det == src || src == 0)
		return (det);
	while (src[b])
	{
		det[b] = src[b];
		b++;
	}
	det[b] = 0;
	return (det);
}

/**
 * _strdup - duplicates a string
 * @str: the string to duplicate
 *
 * Return: pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	int length = 0;
	char *rett;

	if (str == NULL)
		return (NULL);
	while (*str++)
		length++;
	rett = malloc(sizeof(char) * (length + 1));
	if (!rett)
		return (NULL);
	for (length++; length--;)
		rett[length] = *--str;
	return (rett);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *str)
{
	int b = 0;

	if (!str)
		return;
	while (str[b] != '\0')
	{
		_putchar(str[b]);
		b++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @a: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char a)
{
	static int b;
	static char buff[WRITE_BUF_SIZE];

	if (a == BUF_FLUSH || b >= WRITE_BUF_SIZE)
	{
		write(1, buff, b);
		b = 0;
	}
	if (a != BUF_FLUSH)
		buff[b++] = a;
	return (1);
}
