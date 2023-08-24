#include "shell.h"

/**
 * _getenviron - returns the string array copy of our environ
 * @inf: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
char **_getenviron(info_t *inf)
{
	if (!inf->environ || inf->env_changed)
	{
		inf->environ = list_to_strings(inf->env);
		inf->env_changed = 0;
	}

	return (inf->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(info_t *inf, char *var)
{
	list_t *node = inf->env;
	size_t b = 0;
	char *a;

	if (!node || !var)
		return (0);

	while (node)
	{
		a = starts_with(node->str, var);
		if (a && *a == '=')
		{
			inf->env_changed = delete_node_at_index(&(inf->env), b);
			b = 0;
			node = inf->env;
			continue;
		}
		node = node->next;
		b++;
	}
	return (inf->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @inf: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *inf, char *var, char *value)
{
	char *buff = NULL;
	list_t *node;
	char *a;

	if (!var || !value)
		return (0);

	buff = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, value);
	node = inf->env;
	while (node)
	{
		a = starts_with(node->str, var);
		if (a && *a == '=')
		{
			free(node->str);
			node->str = buff;
			inf->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(inf->env), buff, 0);
	free(buff);
	inf->env_changed = 1;
	return (0);
}
