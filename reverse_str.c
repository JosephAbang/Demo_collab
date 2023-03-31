#include "main.h"
/**
 * func_revstr - function that reverses a string
 * @list: is the list of arguments the function _printf receives
 * Return: Number of caracteres printing
 */
int func_revstr(va_list list)
{
	char *str;
	int count = 0, i, j = 0;

	str = va_arg(list, char *);
	for (i = 0; str[i] != 0; i++)
	{
		count++;
	}
	for (j = i - 1; j >= 0; j--)
	{
		_putchar(str[j]);
	}
	return (count);
}
/**
 * func_stringUppercase - Prints a string, when out of range print \x0A
 * @list: list of arguments the function _printf is sending
 * Return: Number of characteres printing
 */
int func_stringUppercase(va_list list)
{
	char *str = va_arg(list, char *);
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			count += _putchar('\\');
			count += _putchar('x');
			count += _putchar((str[i] / 16) + '0');
			count += _putchar((str[i] % 16) + (str[i] % 16 < 10 ? '0' : 'A' - 10));
		}
		else
		{
			count += _putchar(str[i]);
		}
	}

	return (count);
}
