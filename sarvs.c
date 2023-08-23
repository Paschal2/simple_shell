#include "shell.h"

/**
 * is_chain - test if current char in buffer is a chain delimeter
 * @inf: the parameter struct
 * @buff: the char buffer
 * @p: address of current position in buf
 *
 * Return: 1 if chain delimeter, 0 otherwise
 */
int is_chain(info_t *inf, char *buff, size_t *p)
{
	size_t b = *p;

	if (buff[b] == '|' && buff[b + 1] == '|')
	{
		buff[b] = 0;
		b++;
		inf->cmd_buf_type = CMD_OR;
	}
	else if (buff[b] == '&' && buff[b + 1] == '&')
	{
		buff[b] = 0;
		b++;
		inf->cmd_buf_type = CMD_AND;
	}
	else if (buff[b] == ';') /* found end of this command */
	{
		buff[b] = 0; /* replace semicolon with null */
		inf->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*p = b;
	return (1);
}

/**
 * check_chain - checks we should continue chaining based on last status
 * @inf: the parameter struct
 * @buff: the char buffer
 * @p: address of current position in buf
 * @i: starting position in buf
 * @len: length of buf
 *
 * Return: Void
 */
void check_chain(info_t *inf, char *buff, size_t *p, size_t i, size_t len)
{
	size_t b = *p;

	if (inf->cmd_buf_type == CMD_AND)
	{
		if (inf->status)
		{
			buff[i] = 0;
			b = len;
		}
	}
	if (inf->cmd_buf_type == CMD_OR)
	{
		if (!inf->status)
		{
			buff[i] = 0;
			b = len;
		}
	}

	*p = b;
}

/**
 * replace_alias - replaces an aliases in the tokenized string
 * @inf: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *inf)
{
	int b;
	list_t *node;
	char *p;

	for (b = 0; b < 10; b++)
	{
		node = node_starts_with(inf->alias, inf->argv[0], '=');
		if (!node)
			return (0);
		free(inf->argv[0]);
		p = _strchr(node->str, '=');
		if (!p)
			return (0);
		p = _strdup(p + 1);
		if (!p)
			return (0);
		inf->argv[0] = p;
	}
	return (1);
}

/**
 * replace_vars - replaces vars in the tokenized string
 * @inf: the parameter struct
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_vars(info_t *inf)
{
	int b = 0;
	list_t *node;

	for (b = 0; inf->argv[b]; b++)
	{
		if (inf->argv[b][0] != '$' || !inf->argv[b][1])
			continue;

		if (!_strcmp(inf->argv[b], "$?"))
		{
			replace_string(&(inf->argv[b]),
					_strdup(convert_number(inf->status, 10, 0)));
			continue;
		}
		if (!_strcmp(inf->argv[b], "$$"))
		{
			replace_string(&(inf->argv[b]),
					_strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(inf->env, &inf->argv[i][1], '=');
		if (node)
		{
			replace_string(&(inf->argv[i]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&inf->argv[i], _strdup(""));

	}
	return (0);
}

/**
 * replace_string - replaces string
 * @mundane: address of old string
 * @new: new string
 *
 * Return: 1 if replaced, 0 otherwise
 */
int replace_string(char **mundane, char *new)
{
	free(*mundane);
	*mundane = new;
	return (1);
}
