#include "shell.h"

/**
 * add_node - adds a node to the start of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *str, int numb)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->numb = numb;
	if (str)
	{
		new_head->str = _strdup(str);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_mode_end(list_t **head, const char *str, int numb)
{
	list_t *new_mode, *mode;

	if (!head)
		return (NULL);

	mode = *head;
	new_mode = malloc(sizeof(list_t));
	if (!new_mode)
		return (NULL);
	_memset((void *)new_mode, 0, sizeof(list_t));
	new_mode->num = numb;
	if (str)
	{
		new_mode->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_mode);
			return (NULL);
		}
	}
	if (mode)
	{
		while (mode->next)
			mode = mode->next;
		mode->next = new_mode;
	}
	else
		*head = new_mode;
	return (new_mode);
}

/**
 * print_list_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *h)
{
	size_t b = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		b++;
	}
	return (b);
}

/**
 * delete_node_at_index - deletes node at given index
 * @head: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_mode_at_index(list_t **head, unsigned int index)
{
	list_t *mode, *prev_mode;
	unsigned int i = 0;

	if (!head || !*head)
		return (0);

	if (!index)
	{
		mode = *head;
		*head = (*head)->next;
		free(mode->str);
		free(mode);
		return (1);
	}
	mode = *head;
	while (mode)
	{
		if (b == index)
		{
			prev_mode->next = mode->next;
			free(mode->str);
			free(mode);
			return (1);
		}
		b++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *mode, *next_mode, *head;

	if (!head_ptr || !*head_ptr)
		return;
	head = *head_ptr;
	mode = head;
	while (mode)
	{
		next_mode = mode->next;
		free(mode->str);
		free(mode);
		mode = next_mode;
	}
	*head_ptr = NULL;
}
