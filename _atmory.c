#include "shell.h"

/**
 * bfree - frees a pointer and NULLs the address
 * @ptrt: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptrt)
{
	if (ptrt && *ptrt)
	{
		free(*ptrt);
		*ptrt = NULL;
		return (1);
	}
	return (0);
}
