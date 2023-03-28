#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - print character
 * @arg: argument passed from printf
 * Return: nunber of character printed
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);
	return (write(1, &c, 1));
}

/**
 * print_str - print string
 * @arg: argument passed from printf
 * Return: nunber of character printed
 */
int print_str(va_list args)
{
	char *str = va_arg(args, char *);
	int len = 0;

	if (str == NULL)
		str = "(null)";
	while (*str)	
	{
		len++;
		str++;
	}
	return (write(1, str - len, len));
}


/**
 * print_percent - print percent
 * @arg: argument passed from printf
 * Return: nunber of character printed
 */

int print_percent(__attribute__((unused))va_list args)
{
	return (write(1, "%", 1));
}
