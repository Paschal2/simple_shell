#include "shell.h"

/**
 * mode - returns true if shell is interactive mode
 * @inf: struct address by Paschal and Co
 *
 * Return: 1 if interactive mode, 0 otherwise
 */
int mode(info_t *inf)
{
	return (isatty(STDIN_FILENO) && inf->readfd <= 2);
}

/**
 * is_meter - checks if character is a delimeter
 * @a: the char to check
 * @meter: the delimeter string
 * Return: 1 if true, 0 if false
 */
int is_meter(char a, char *meter)
{
	while (*meter)
		if (*meter++ == a)
			return (1);
	return (0);
}

/**
 * _isbetic - checks for alphabetic character
 * @d: the character to input
 * Return: 1 if d is alphabetic, 0 otherwise
 */

int _isbetic(int d)
{
	if ((d >= 'a' && d <= 'z') || (d >= 'A' && d <= 'Z'))
		return (1);
	else
		return (0);
}

/**
 * _ototr - converts a string to an integer
 * @a: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 */

int _ototr(char *a)
{
	int b, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (b = 0; a[b] != '\0' && flag != 2; b++)
	{
		if (a[b] == '-')
			sign *= -1;

		if (a[b] >= '0' && a[b] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (a[b] - '0');
		}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (0);
}
