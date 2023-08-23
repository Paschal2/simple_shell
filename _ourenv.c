#include "shell.h"

/**
 * _ourenv - prints the current environment
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int _ourenv(info_t *inf)
{
	print_list_str(inf->env);
	return (0);
}

/**
 * _getenv - gets the value of an environ variable
 * @info: Structure containing potential arguments. Used to maintain
 * @name: env var name
 *
 * Return: the value
 */
char *_getenv(info_t *inf, const char *nam)
{
	list_t *mode = inf->env;
	char *a;

	while (mode)
	{
		a = starts_with(mode->str, nam);
		if (a && *a)
			return (a);
		mode = mode->next;
	}
	return (NULL);
}

/**
 * _oursetenv - Initialize a new environment variable,
 *             or modify an existing one
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 *  Return: Always 0
 */
int _oursetenv(info_t *inf)
{
	if (inf->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(inf, inf->argv[1], inf->argv[2]))
		return (0);
	return (1);
}

/**
 * _ourunsetenv - Remove an environment variable
 * @info: Structure containing potential arguments. Used to maintain
 *        constant function prototype.
 * Return: Always 0
 */
int _ourunsetenv(info_t *inf)
{
	int b;

	if (inf->argc == 1)
	{
		_eputs("Too few arguements.\n");
		return (1);
	}
	for (b = 1; b <= inf->argc; b++)
		_unsetenv(inf, inf->argv[b]);

	return (0);
}

/**
 * pop_env_list - populates env linked list
 * @info: Structure containing potential arguments. Used to maintain
 *          constant function prototype.
 * Return: Always 0
 */
int pop_env_list(info_t *inf)
{
	list_t *mode = NULL;
	size_t b;

	for (b = 0; environ[b]; b++)
		add_mode_end(&mode, environ[b], 0);
	inf->env = mode;
	return (0);
}
