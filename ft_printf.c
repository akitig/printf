/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:46:09 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/27 13:20:35 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

int	ft_printf_char(char c, int fd)
{
	ft_putchar_fd(c, fd);
	return (1);
}

int	ft_printf_str(char *str, int fd)
{
	ft_putstr_fd(str, fd);
	return (ft_strlen(str));
}

int	ft_putptr(unsigned long long ptr)
{
	int	ptrlen;

	ptrlen = 0;
	if (ptr >= 16)
	{
		ptrlen += 2;
		ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
		ptrlen++;
	}
	return (ptrlen);
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int	ptrlen;

	ptrlen = 0;
	ptrlen += write(1, "0x", 2);
	if (ptr == 0)
		ptrlen += write(1, "0", 1);
	else
		ptrlen += ft_putptr(ptr);
	return (ptrlen);
}

int	ft_printf_format(va_list args, char format)
{
	int	printf_len;

	printf_len = 0;
	if (format == 'c')
		printf_len += ft_printf_char(va_arg(args, int), 1);
	else if (format == 's')
		printf_len += ft_printf_str(va_arg(args, char *), 1);
	else if (format == 'p')
		printf_len += ft_printf_ptr(va_arg(args, unsigned long long));
	else if (format == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'i')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (format == 'u')
		printf("%u", va_arg(args, int));
	else if (format == 'x')
		printf("%x", va_arg(args, int));
	else if (format == 'X')
		printf("%X", va_arg(args, int));
	else if (format == '%')
		ft_putchar_fd('%', 1);
	else
		(void)args;
	return (printf_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	args;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			ret = ft_printf_format(args, str[i + 1]);
		}
		i++;
	}
	return (ret);
}

int	main(void)
{
	int ret;
	int ft_ret;
	printf("format c : 'c'\n");
	ret = printf("%c", 'c');
	printf("\n");
	ft_ret = ft_printf("%c", 'c');
	printf("\n");
	printf("%d %d\n", ret, ft_ret);

	printf("format s : \"abcde\"\n");
	ret = printf("%s", "abcde");
	printf("\n");
	ft_ret = ft_printf("%s", "abcde");
	printf("\n");
	printf("%d %d\n", ret, ft_ret);

	printf("format p : \"abcde\"\n");
	ret = printf("%p", "abcde");
	printf("\n");
	ft_ret = ft_printf("%p", "abcde");
	printf("\n");
	printf("%d %d\n", ret, ft_ret);

	printf("format d : 12345\n");
	ret = printf("%d", 12345);
	printf("\n");
	ft_ret = ft_printf("%d", 12345);
	printf("\n");
	printf("%d %d\n", ret, ft_ret);

	printf("format i : 12345\n");
	ret = printf("%i", 12345);
	printf("\n");
	ft_ret = ft_printf("%i", 12345);
	printf("\n");
	printf("%d %d\n", ret, ft_ret);

	printf("format u : UINT_MAX\n");
	ret = printf("%u", UINT_MAX);
	printf("\n");
	ft_ret = ft_printf("%u", UINT_MAX);
	printf("\n");
	printf("%d %d\n", ret, ft_ret);

	printf("format x : 3\n");
	ret = printf("%x", 3);
	printf("\n");
	ft_ret = ft_printf("%x", 3);
	printf("\n");
	printf("%d %d\n", ret, ft_ret);

	printf("format X : 3\n");
	ret = printf("%X", 3);
	printf("\n");
	ft_ret = ft_printf("%X", 3);
	printf("\n");
	printf("%d %d\n", ret, ft_ret);

	printf("fotmat percent : percent\n");
	ret = printf("%%");
	printf("\n");
	ft_ret = ft_printf("%%");
	printf("\n");
	printf("%d %d\n", ret, ft_ret);
}