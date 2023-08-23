#include "shell.h"

/**
 * _strcpy - copies a string
 * @dest: the destination
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
char *_strdup(const char *strr)
{
	int length = 0;
	char *rett;

	if (strr == NULL)
		return (NULL);
	while (*strr++)
		length++;
	rett = malloc(sizeof(char) * (length + 1));
	if (!rett)
		return (NULL);
	for (length++; length--;)
		rett[length] = *--strr;
	return (rett);
}

/**
 * _puts - prints an input string
 * @str: the string to be printed
 *
 * Return: Nothing
 */
void _puts(char *strr)
{
	int b = 0;

	if (!strr)
		return;
	while (strr[b] != '\0')
	{
		_putchar(strr[b]);
		b++;
	}
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
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
