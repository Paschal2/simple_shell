#include "shell.h"

/**
 * _errors - converts a string to an integer
 * @a: the string to be converted
 * Return: 0 if no numbers in string, converted number otherwise
 *         1 on error
 */
int _errors(char *a)
{
	int b = 0;
	unsigned long int result = 0;

	if (*a == '+')
		a++;  /* TODO: why does this make main return 255? */
	for (b = 0;  a[b] != '\0'; b++)
	{
		if (a[b] >= '0' && a[b] <= '9')
		{
			result *= 10;
			result += (a[b] - '0');
			if (result > INT_MAX)
				return (-1);
		}
		else
			return (-1);
	}
	return (result);
}

/**
 * print_err - prints an error message
 * @inf: the parameter & return info struct
 * @str: string containing specified error type
 * Return: 0 if no numbers in string, converted number otherwise
 *        -1 on error
 */
void print_err(info_t *inf, char *str)
{
	_eputs(inf->fname);
	_eputs(": ");
	print_d(inf->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(inf->argv[0]);
	_eputs(": ");
	_eputs(str);
}

/**
 * print_d - function prints a decimal (integer) number (base 10)
 * @input: the input
 * @fd: the filedescriptor to write to
 *
 * Return: number of characters printed
 */
int print_d(int input, int fd)
{
	int (*__putchar)(char) = _putchar;
	int b, count = 0;
	unsigned int _abs_, current;

	if (fd == STDERR_FILENO)
		__putchar = _eputchar;
	if (input < 0)
	{
		_abs_ = -input;
		__putchar('-');
		count++;
	}
	else
		_abs_ = input;
	current = _abs_;
	for (b = 1000000000; b > 1; b /= 10)
	{
		if (_abs_ / b)
		{
			__putchar('0' + current / b);
			count++;
		}
		current %= b;
	}
	__putchar('0' + current);
	count++;

	return (count);
}

/**
 * con_number - converter function, a clone of itoa
 * @num: number
 * @base: base
 * @flags: argument flags
 *
 * Return: string
 */
char *con_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *str;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	str = &buffer[49];
	*str = '\0';

	do	{
		*--str = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--str = sign;
	return (str);
}

/**
 * remove_comments - function replaces first instance of '#' with '\0'
 * @buff: address of the string to modify
 *
 * Return: Always 0;
 */
void rm_comments(char *buff)
{
	int b;

	for (b = 0; buff[b] != '\0'; b++)
		if (buff[b] == '#' && (!b || buff[b - 1] == ' '))
		{
			buff[b] = '\0';
			break;
		}
}
