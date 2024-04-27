/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:46:09 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/27 09:02:10 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_printf_format(va_list args, char format)
{
	if (format == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else
		(void)args;
}

int	ft_printf(const char *str, ...)
{
	int		i;
	va_list	args;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ft_printf_format(args, str[i + 1]);
		}
		i++;
	}
	return (0);
}

int	main(void)
{
	printf("format c : 'c'\n");
	printf("%c", 'c');
	printf("\n");
	ft_printf("%c", 'c');
	printf("\n");

	printf("format s : \"abcde\"\n");
	printf("%s", "abcde");
	printf("\n");
	ft_printf("%s", "abcde");
	printf("\n");

	printf("format p : \"abcde\"\n");
	printf("%p", "abcde");
	printf("\n");
	ft_printf("%p", "abcde");
	printf("\n");

	printf("format d : 12345\n");
	printf("%d", 12345);
	printf("\n");
	ft_printf("%d", 12345);
	printf("\n");

	printf("format i : 12345\n");
	printf("%i", 12345);
	printf("\n");
	ft_printf("%i", 12345);
	printf("\n");

	printf("format u : UINT_MAX\n");
	printf("%u", UINT_MAX);
	printf("\n");
	ft_printf("%u", UINT_MAX);
	printf("\n");

	printf("format x : 3\n");
	printf("%x", 3);
	printf("\n");
	ft_printf("%x", 3);
	printf("\n");

	printf("format X : 3\n");
	printf("%X", 3);
	printf("\n");
	ft_printf("%X", 3);
	printf("\n");

	printf("fotmat percent : percent\n");
	printf("%%");
	printf("\n");
	ft_printf("%%");
	printf("\n");

	// printf("printf    :%c\n", 'c');
	// ft_printf("ft_printf :%c\n", 'c');
	// printf("printf    :%s\n", "abcde");
	// ft_printf("ft_printf :%s\n", "abcde");
	// printf("printf    : %p\n", "abcde");
	// ft_printf("ft_printf :%p\n", "abcde");
	// printf("printf    : %d\n", INT_MAX);
	// ft_printf("ft_printf : %d\n", INT_MAX);
	// printf("printf    : %i\n", INT_MAX);
	// ft_printf("ft_printf : %i\n", INT_MAX);
	// printf("printf    : %u\n", UINT_MAX);
	// ft_printf("ft_printf : %u\n", UINT_MAX);
	// printf("printf    : %x\n", 3);
	// ft_printf("ft_printf : %x\n", 3);
	// printf("printf    : %X\n", 3);
	// ft_printf("ft_printf : %X\n", 3);
	// printf("printf    : %%");
	// ft_printf("ft_printf : %%");
}