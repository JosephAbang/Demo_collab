#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - print character
 * @args: argument passed from printf
 * Return: nunber of character printed
 */

int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (write(1, &c, 1));
}

/**
 * print_str - print string
 * @args: argument passed from printf
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
 * @args: argument passed from printf
 * Return: nunber of character printed
 */

int print_percent(__attribute__((unused))va_list args)
{
	return (write(1, "%", 1));
}

/**
 * print_integer - prints an integer
 * @args: va_list containing the integer to print
 *
 * Return: the number of characters printed
 */
int print_integer(va_list args)
{
	long int num = va_arg(args, int);
	long int sign = 1, n = 0;
	int count = 0;
	char buffer[1024];

	if (num < 0)
	{
		sign = -1;
		num *= -num;
		count += write(1, "-", 1);
	}
	do {
		buffer[n++] = (num % 10) + '0';
		num /= 10;
		} while (num > 0);

	if (sign == -1)
		buffer[n++] = '-';

	while (--n >= 0)
		count += write(1, &buffer[n], 1);

	return (count);
}
