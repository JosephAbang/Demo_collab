#include "main.h"

/**
 * _puts - Prints a string followed by a newline to stdout.
 * @str: A pointer to the string to be printed.
 *
 * Return: void.
 */
int _puts(const char *str)
{
	int len = 0;

	while (*str)
	{
		_putchar(*str++);
		len++;
	}

	return (len);
}



/**
 * func_pointer - prints the memory address of a pointer
 * @list: list of arguments
 *
 * Return: number of characters printed
 */
int func_pointer(va_list list)
{
	void *ptr = va_arg(list, void *);
	unsigned long int hex_ptr = (unsigned long int)ptr;

	return (_print_hex(hex_ptr, "0x", 1, 16));
}

/**
 * _print_hex - prints a number in hexadecimal format
 * @n: number to print
 * @prefix: prefix to print before the number (e.g. "0x")
 * @uppercase: whether to print the letters in uppercase
 * @width: minimum width of the output (pads with zeros)
 *
 * Return: number of characters printed
 */
int _print_hex(unsigned long int n, char *prefix, int uppercase, int width)
{
	char buffer[20];
	int i = 0, len = 0;
	const char *digits = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	while (n > 0)
	{
		buffer[i++] = digits[n % 16];
		n /= 16;
	}
	buffer[i] = '\0';

	len += _puts(prefix);
	len += _puts("0");
	len += _puts(digits);
	while (i < width)
	{
		_putchar('0');
		i++;
	}
	while (i-- > 0)
	{
		_putchar(buffer[i]);
		len++;
	}

	return (len);
}
