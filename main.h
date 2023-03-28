#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

/**
 * struct printer: struct for format specifier
 * @spec: format specifier character
 * @printer: function pointer to printer function
 */

typedef struct printer
{
	char spec;
	int (*func)(va_list args);
} printer_t;

int print_char(va_list arg);
int print_str(va_list arg);
int print_percent(va_list arg);
int _printf(const char *format, ...);
int (*get_printer(char c))(va_list);
int print_integer(va_list args);



#endif /* MAIN_H */
