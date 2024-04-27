/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:46:09 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/27 14:28:59 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
