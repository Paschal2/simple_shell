#include "shell.h"

/**
 * _strlen - returns the length of a string
 * @a: the string whose length to check
 *
 * Return: integer length of string
 */
int _strlen(char *a)
{
	int b = 0;

	if (!a)
		return (0);

	while (*a++)
		b++;
	return (b);
}

/**
 * _strcmp - performs lexicogarphic comparison of two strangs.
 * @a1: the first strang
 * @b2: the second strang
 *
 * Return: negative if a1 < b2, positive if a1 > b2, zero if a1 == b2
 */
int _strcmp(char *a1, char *b2)
{
	while (*a1 && *b2)
	{
		if (*a1 != *b2)
			return (*a1 - *b2);
		a1++;
		b2++;
	}
	if (*a1 == *b2)
		return (0);
	else
		return (*a1 < *b2 ? -1 : 1);
}

/**
 * starts_with - checks if needle starts with haystack
 * @haystack: string to search
 * @needless: the substring to find
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needless)
{
	while (*needless)
		if (*needless++ != *haystack++)
			return (NULL);
	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings
 * @det: the destination buffer
 * @src: the source buffer
 *
 * Return: pointer to destination buffer
 */
char *_strcat(char *det, char *src)
{
	char *ret = det;

	while (*det)
		det++;
	while (*src)
		*det++ = *src++;
	*det = *src;
	return (ret);
}
