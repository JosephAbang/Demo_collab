#include "main.h"
#include <stdio.h>

int main(void)
{
	    int len;

	        len = _printf("%s\n", "Hello, world!");
		    printf("Return value: %d\n", len);

		        len = _printf("%c\n", 'H');
			    printf("Return value: %d\n", len);

			        len = _printf("%%\n");
				    printf("Return value: %d\n", len);

				        return (0);
}

