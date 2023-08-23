#include "shell.h"

/**
 * _ourhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _ourhistory(info_t *inf)
{
	print_list(inf->history);
	return (0);
}

/**
 * onset_aliaz - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int onset_alias(info_t *inf, char *strr)
{
	char *a, b;
	int rett;

	a = _strrchr(strr, '=');
	if (!a)
		return (1);
	b = *a;
	*a = 0;
	rett = delete_node_at_index(&(inf->alias),
		get_node_index(inf->alias, node_starts_with(inf->alias, strr, -1)));
	*a = b;
	return (rett);
}

/**
 * set_alias - sets alias to string
 * @info: parameter struct
 * @str: the string alias
 *
 * Return: Always 0 on success, 1 on error
 */
int set_alias(info_t *inf, char *strr)
{
	char *a;

	a = _strrchr(strr, '=');
	if (!p)
		return (1);
	if (!*++a)
		return (onset_alias(inf, strr));

	onset_alias(inf, strr);
	return (add_node_end(&(inf->alias), strr, 0) == NULL);
}

/**
 * print_alias - prints an alias string
 * @node: the alias node
 *
 * Return: Always 0 on success, 1 on error
 */
int print_alias(list_t *mode)
{
	char *a = NULL, *b = NULL;

	if (mode)
	{
		a = _strrchr(mode->strr, '=');
		for (b = mode->strr; b <= a; b++)
		_putchar(*b);
		_putchar('\'');
		_puts(a + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}

/**
 * _ouralias - mimics the alias builtin (man alias)
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 *  Return: Always 0
 */
int _ouralias(info_t *inf)
{
	int b = 0;
	char *a = NULL;
	list_t *mode = NULL;

	if (inf->argc == 1)
	{
		mode = inf->alias;
		while (mode)
		{
			print_alias(mode);
			mode = mode->next;
		}
		return (0);
	}
	for (b = 1; inf->argv[b]; b++)
	{
		a = _strrchr(inf->argv[b], '=');
		if (a)
			set_alias(inf, inf->argv[b]);
		else
			print_alias(mode_starts_with(inf->alias, inf->argv[b], '='));
	}

	return (0);
}
