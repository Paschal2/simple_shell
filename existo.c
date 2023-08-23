#include "shell.h"

/**
 **_strncpy - copies a string
 *@dest: the destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncpy(char *dest, char *src, int n)
{
	int b, a;
	char *s = dest;

	b = 0;
	while (src[b] != '\0' && b < n - 1)
	{
		dest[b] = src[b];
		b++;
	}
	if (b < n)
	{
		a = b;
		while (a < n)
		{
			dest[a] = '\0';
			a++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *dest, char *src, int n)
{
	int b, a;
	char *s = dest;

	b = 0;
	a = 0;
	while (dest[b] != '\0')
		b++;
	while (src[a] != '\0' && a < n)
	{
		dest[b] = src[a];
		b++;
		a++;
	}
	if (a < n)
		dest[b] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@a: the string to be parsed
 *@b: the character to look for
 *Return: (a) a pointer to the memory area a
 */
char *_strchr(char *a, char b)
{
	do {
		if (*a == b)
			return (a);
	} while (*a++ != '\0');

	return (NULL);
}
