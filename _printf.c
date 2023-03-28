#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * get_printer - Get printer function from file
 * @c: symbol
 * Return: pointer to function
 */

int (*get_printer(char c))(va_list)
{
	int i;
	static printer_t printers[] = {
		{'c', print_char},
		{'s', print_str},
		{'%', print_percent},
		{0, NULL}
	};

	for (i = 0; printers[i].spec != 0; i++)
	{
		if (printers[i].spec == c)
			return (printers[i].func);
	}
	return (NULL);
}

/**
 * _printf - produces output according to a format.
 * @format: format string containing the characters and the specifiers
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i = 0;
	int (*printer)(va_list);

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printer = get_printer(format[i]);
			if (!printer)
				return (-1);
			count += printer(args);
		}
		else
		{
			count += write(1, &format[i], 1);
		}
		i++;
	}
	va_end(args);
	return (count);
}
