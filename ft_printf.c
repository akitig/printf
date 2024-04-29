/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:46:09 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/30 05:14:01 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_format(va_list args, const char format, const char *op)
{
	int	printf_len;

	(void)op;
	printf_len = 0;
	if (format == 'c')
		printf_len += ft_printf_char(va_arg(args, int));
	else if (format == 's')
		printf_len += ft_printf_str(va_arg(args, char *));
	else if (format == 'p')
		printf_len += ft_printf_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		printf_len += ft_printf_int(va_arg(args, int));
	else if (format == 'u')
		printf_len += ft_printf_uint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		printf_len += ft_printf_x(va_arg(args, int), format);
	else if (format == '%')
		printf_len += ft_printf_char('%');
	return (printf_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	char	*op;
	int		ret;
	va_list	args;

	ret = 0;
	va_start(args, str);
	while (*str != 0)
	{
		if (*str == '%')
		{
			i = 0;
			while (ft_isalnum(str[i]))
				i++;
			op = ft_substr(str, 0, i);
			ret += ft_printf_format(args, op[0], op);
			str += i;
		}
		else
			ret += ft_printf_char(str[i]);
		str++;
	}
	va_end(args);
	return (ret);
}
