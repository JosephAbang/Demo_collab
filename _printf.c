#include "main.h"
#include <unistd.h>
#include <stdarg.h>
#include <string.h>


/**
 * _printf - Print different formats to standard output
 * @format: format string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	char *str, c;
	va_list args;

	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' || format[i] == '\0')
		{
			i++;
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				count++;
			}
			else if (format[i] == 's')
			{
				str = va_arg(args, char *);
				write(1, str, strlen(str));
				count += strlen(str);
			}
			else if (format[i] == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				count++;
			}}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
