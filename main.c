#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
	// ft_printf("Bonjoir %c %s\n", 't', "0123456789");


	int i = 160;

	ft_printf("%p : [%#x][%#X], %u, %%\n", &i, i, i, i);
	printf("%p : [%#x][%#X], %u, %%\n", &i, i, i, i);

	ft_printf("[%20d]\n", 45);
	printf("[%20d]\n", 45);

	return (0);
}