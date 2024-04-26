/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:46:09 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/27 07:23:39 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

void	ft_printf_format(va_list args, char format)
{
	if (format == 'd')
		printf("%d\n", va_arg(args, int));
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
	printf("printf    :%c\n", 'c');
	ft_printf("ft_printf :%c\n", 'c');
	printf("printf    :%s\n", "abcde");
	ft_printf("ft_printf :%s\n", "abcde");
	printf("printf    : %p\n", "abcde");
	ft_printf("ft_printf :%p\n", "abcde");
	printf("printf    : %d\n", INT_MAX);
	ft_printf("ft_printf : %d\n", INT_MAX);
	printf("printf    : %i\n", INT_MAX);
	ft_printf("ft_printf : %i\n", INT_MAX);
	printf("printf    : %u\n", UINT_MAX);
	ft_printf("ft_printf : %u\n", UINT_MAX);
	printf("printf    : %x\n", 3);
	ft_printf("ft_printf : %x\n", 3);
	printf("printf    : %X\n", 3);
	ft_printf("ft_printf : %X\n", 3);
	printf("printf    : %%");
	ft_printf("ft_printf : %%");
}