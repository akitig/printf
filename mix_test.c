#include "printf/ft_printf.h"
#include <assert.h>
#include <limits.h>
#include <stdio.h>

// -0. #+
int	main(void)
{
	// c
	puts("c");
	ft_printf("%-5c", 'a');
	// ft_printf("\n%05c", 'a');
	// ft_printf("\n%.5c", 'a');
	// ft_printf("\n% 5c", 'a');
	// ft_printf("\n%#5c", 'a');
	// ft_printf("\n%+5c", 'a');
	ft_printf("\n");

	// s
	puts("s");
	ft_printf("\n%-5s", "123");
	// ft_printf("\n%05s", "123");
	ft_printf("\n%.5s", "123");
	// ft_printf("\n% 5s", "123");
	// ft_printf("\n%#5s", "123");
	// ft_printf("\n%+5s", "123");
	ft_printf("\n");

	// p
	puts("p");
	ft_printf("%-5p", "123");
	// ft_printf("\n%05p", "123");
	// ft_printf("\n%.5p", "123");
	// ft_printf("\n% 5p", "123");
	// ft_printf("\n%#5p", "123");
	// ft_printf("\n%+5p", "123");
	ft_printf("\n");

	// d
	puts("d");
	ft_printf("%-5d\n", 123);
	ft_printf("%05d\n", 123);
	ft_printf("%.5d\n", 123);
	ft_printf("% 5d\n", 123);
	// ft_printf("%#5d\n", 123);
	ft_printf("%+5d\n", 123);
	ft_printf("\n");

	// i
	puts("i");
	ft_printf("%-5i\n", 123);
	ft_printf("%05i\n", 123);
	ft_printf("%.5i\n", 123);
	ft_printf("% 5i\n", 123);
	// ft_printf("%#5i\n", 123);
	ft_printf("%+5i\n", 123);
	ft_printf("\n");

	// u
	puts("u");
	ft_printf("%-5u\n", 123);
	ft_printf("%05u\n", 123);
	ft_printf("%.5u\n", 123);
	// ft_printf("% 5u\n", 123);
	// ft_printf("%#5u\n", 123);
	// ft_printf("%+5u\n", 123);
	ft_printf("\n");

	// x
	puts("x");
	ft_printf("%-5x\n", 123);
	ft_printf("%05x\n", 123);
	ft_printf("%.5x\n", 123);
	// ft_printf("% 5x\n", 123);
	ft_printf("%#5x\n", 123);
	// ft_printf("%+5x\n", 123);
	ft_printf("\n");

	// X
	puts("X");
	ft_printf("%-5X\n", 123);
	ft_printf("%05X\n", 123);
	ft_printf("%.5X\n", 123);
	// ft_printf("% 5X\n", 123);
	ft_printf("%#5X\n", 123);
	// ft_printf("%+5X\n", 123);
	ft_printf("\n");

	// %
	puts("%");
	ft_printf("%%-5X\n");
	//	ft_printf("%%%05X\n");
	ft_printf("%%%%.5X\n");
	//	ft_printf("%%%%% 5X\n");
	ft_printf("%%%%%%#5X\n");
	//	ft_printf("%%%%%%%+5X\n");
	ft_printf("\n");
}