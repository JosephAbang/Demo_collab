#include "main.h"
/**
 * binary_oct_hex_convert - convert a number into bi, oct or hex
 * @numero: Its the number given to convert
 * @base: base divided with bin 2, oct 8, hex 16.
 * @flag: flag
 * Return: The number of characteres printed
 */
int binary_oct_hex_convert(unsigned int numero, int base, int flag)
{
	char hexUpcase[] = "0123456789ABCDEF";
	char hexLowcase[] = "0123456789abcdef";
	char array[2021];
	char *ptr;
	int i = 2020, j = 0;

	ptr = &array[2020];
	*ptr = '\0';

	do {
		if (flag != 0)
			*--ptr = hexUpcase[numero % base];
		else
			*--ptr = hexLowcase[numero % base];
		numero = numero / base;
		i--;
	} while (numero != 0);

	for (j = i; array[j] != 0; j++)
	{
		_putchar(array[j]);
	}
	return (2020 - i);
}
