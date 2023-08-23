#include "shell.h"

/**
 * _getenviron - returns the string array copy of our environ
 * @info: Structure containing potential arguments. Used to maintain
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

	return (info->environ);
}

/**
 * _unsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: 1 on delete, 0 otherwise
 * @var: the string env var property
 */
int _unsetenv(info_t *inf, char *var)
{
	list_t *mode = inf->env;
	size_t b = 0;
	char *a;

	if (!mode || !var)
		return (0);

	while (mode)
	{
		a = starts_with(mode->str, var);
		if (a && *a == '=')
		{
			info->env_changed = delete_node_at_index(&(inf->env), i);
			b = 0;
			node = inf->env;
			continue;
		}
		mode = mode->next;
		b++;
	}
	return (inf->env_changed);
}

/**
 * _setenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * @var: the string env var property
 * @value: the string env var value
 *  Return: Always 0
 */
int _setenv(info_t *inf, char *var, char *value)
{
	char *buff = NULL;
	list_t *mode;
	char *a;

	if (!var || !value)
		return (0);

	buff = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buff)
		return (1);
	_strcpy(buff, var);
	_strcat(buff, "=");
	_strcat(buff, value);
	mode = inf->env;
	while (mode)
	{
		a = starts_with(mode->str, var);
		if (a && *a == '=')
		{
			free(mode->str);
			mode->str = buff;
			inf->env_changed = 1;
			return (0);
		}
		mode = mode->next;
	}
	add_mode_end(&(info->env), buff, 0);
	free(buff);
	inf->env_changed = 1;
	return (0);
}
