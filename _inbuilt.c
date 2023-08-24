#include "shell.h"

/**
 * _ourexit - exits the shell
 * @inf: Structure containing potential arguments. Used to maintain
 * constant function prototype. by Paschal and Co.
 * Return: exits with a given exit status
 * (0) if info.argv[0] != "exit"
 */

int _ourexit(info_t *inf)
{
	int exitcheck;

	if (_erratoi)i /* Declaration for _erratoi function*/
	if (inf->argv[1]) /* If there is an exit arguement */
	{
		exitcheck = _erratoi(inf->argv[1]);
		if (exitcheck == -1)
		{
			inf->status = 2;
			print_err(inf, "Illegal number: ");
			_eputs(inf->argv[1]);
			_eputchar('\n');
			return (1);
		}
		inf->err_num = _erratoi(inf->argv[1]);
		return (-2);
	}
	inf->err_num = -1;
	return (-2);
}

/**
 * _ourcd - changes the current directory of the process
 * @inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _ourcd(info_t *inf)
{
	char *x, *bdr, buffer[1024];
	int chbdr_ret;

	x = getcwd(buffer, 1024);
	if (!x)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!inf->argv[1])
	{
		bdr = _getenv(inf, "HOME=");
		if (!bdr)
			chbdr_ret = /* TODO: what should this be? */
				chbdr((bdr = _getenv(inf, "PWD=")) ? bdr : "/");
		else
			chbdr_ret = chbdr(bdr);
	}
	else if (_strcmp(inf->argv[1], "-") == 0)
	{
		if (!_getenv(inf, "OLDPWD="))
		{
			_puts(x);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(inf, "OLDPWD=")), _putchar('\n');
		chbdr_ret = /* TODO: what should this be? */
			chbdr((bdr = _getenv(inf, "OLDPWD=")) ? bdr : "/");
	}
	else
		chbdr_ret = chbdr(inf->argv[1]);
	if (chbdr_ret == -1)
	{
		print_err(inf, "can't cd to ");
		_eputs(inf->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(inf, "OLDPWD", _getenv(inf, "PWD="));
		_setenv(inf, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _ourhelp - changes the current directory of the process
 * @inf: Structure containing potential arguments. Used to maintain
 * constant function prototype.
 * Return: Always 0
 */
int _ourhelp(info_t *inf)
{
	char **argu_array;

	argu_array = inf->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*argu_array); /* temp att_unused workaround */
	return (0);
}
