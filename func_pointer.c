#include "main.h"

/**
 * func_pointer - prints a pointer address
 * @list: arguments list
 *
 * Return: number of characters printed
 */
int func_pointer(va_list list)
{
	void *ptr = va_arg(list, void *);

	unsigned long hex_ptr = (unsigned long)ptr;
	char hex_digits[] = "0123456789abcdef";
	char hex_str[17] = {'\0'};
	int i, count = 0;

	for (i = 0; i < 16; i++)
	{
		hex_str[15 - i] = hex_digits[hex_ptr & 0xf];
		hex_ptr >>= 4;
	}

	_putchar('0');
	_putchar('x');
	count += 2;

	for (i = 0; i < 16; i++)
	{
		_putchar(hex_str[i]);
		count++;
	}

	return (count);
}

