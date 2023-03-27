#include "main.h"
#include <string.h>
#include <unistd.h>
#include <stdarg.h>

/**
 * _printf - Print different formats to standard output
 * @format: format string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, count = 0, int_arg, int_len;
	char *str, c, int_char[12];
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
			}
			/* else if (format[i] == 'd' || format[i] == 'i')
			{
				int_arg = va_arg(args, int);
				if (int_arg == 0)
				{
					int_len = 1;
				}
				else
				{
					while (int_arg != 0)
					{
						int_len++;
						int_arg = 10;
					}
				}
				write(1, &int_arg, int_len);
				count += int_len;
			}
		} */
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
