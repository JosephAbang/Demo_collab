#include <stdio.h>
#include "main.h"

int main(void)
{
        int len;

        len = _printf("Hello, world!");
        printf("Return value: %d\n", len);

        len = _printf("%c", 'H');
        printf("Return value: %d\n", len);

        len = _printf("%%");
        printf("Return value: %d\n", len);

        return (0);
}
