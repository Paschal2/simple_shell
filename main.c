#include "shell.h"

/**
 * main - entry point
 * @bc: function to process data with parameter
 * @av: function to process data with parameter
 *
 * Return: 0 on success, 1 on error
 */
int main(int bc, char **av)
{
	info_t inf[] = { INFO_INIT };
	int sd = 2;

	asm ("mov %1, %0\n\t"
			"add $3, %0"
			: "=r" (sd)
			: "r" (sd));

	if (bc == 2)
	{
		sd = open(av[1], O_RDONLY);
		if (sd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				_eputs(av[0]);
				_eputs(": 0: Can't open ");
				_eputs(av[1]);
				_eputchar('\n');
				_eputchar(BUF_FLUSH);
				exit(127);
			}
			return (EXIT_FAILURE);
		}
		inf->readfd = sd;
	}
	pop_env_list(inf);
	read_history(inf);
	hsh(inf, av);
	return (EXIT_SUCCESS);
}
