/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:46:09 by akunimot          #+#    #+#             */
/*   Updated: 2024/05/09 17:27:45 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_sign(char mark)
{
	if (mark == '-' || mark == '.' || mark == '0' || mark == ' ' || mark == '#'
		|| mark == '+')
		return (true);
	return (false);
}

// void	ft_set_format_sign_lim(char *option, char *format, char *sign, int *lim)
// {
// 	int	i;

// 	i = 0;
// 	while (is_sign(option[i]))
// 		i++;
// 	if (i != 0)
// 	{
// 		*sign = option[i - 1];
// 		option += i;
// 		*lim = ft_atoi(option);
// 		*format = option[ft_strlen(option) - 1];
// 	}
// 	else
// 	{
// 		sign = NULL;
// 		*lim = 0;
// 		*format = option[0];
// 	}
// }

// int	ft_printf_without_sign(va_list args, const char format)
// {
// 	int	printf_len;

// 	printf_len = 0;
// 	if (format == 'c')
// 		printf_len += ft_printf_char(va_arg(args, int));
// 	else if (format == 's')
// 		printf_len += ft_printf_str(va_arg(args, char *));
// 	else if (format == 'p')
// 		printf_len += ft_printf_ptr(va_arg(args, unsigned long long));
// 	else if (format == 'd' || format == 'i')
// 		printf_len += ft_printf_int(va_arg(args, int));
// 	else if (format == 'u')
// 		printf_len += ft_printf_uint(va_arg(args, unsigned int));
// 	else if (format == 'x' || format == 'X')
// 		printf_len += ft_printf_x(va_arg(args, int), format);
// 	else if (format == '%')
// 		printf_len += ft_printf_char('%');
// 	return (printf_len);
// }

// int	ft_printf_with_hyphen(va_list args, const char format, int lim)
// {
// 	int	printf_len;

// 	printf_len = ft_printf_without_sign(args, format);
// 	if (printf_len < lim)
// 	{
// 		printf_len += ft_printf_char(' ');
// 	}
// 	return (printf_len);
// }

// int	ft_intlen(int i)
// {
// 	int	len;

// 	len = 1;
// 	while (i)
// 	{
// 		i /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// int	ft_xlen(int i)
// {
// 	int	len;

// 	len = 1;
// 	while (i)
// 	{
// 		i /= 16;
// 		len++;
// 	}
// 	return (len);
// }

// int	ft_printf_with_dot(va_list args, const char format, int lim)
// {
// 	int	printf_len;
// 	int	want_len;

// 	printf_len = 0;
// 	if (format == 's')
// 		want_len = ft_strlen(va_arg(args, char *));
// 	else if (format == 'd' || format == 'i')
// 		want_len = ft_intlen(va_arg(args, int));
// 	else if (format == 'u')
// 		want_len = ft_uilen(va_arg(args, unsigned int));
// 	else if (format == 'x' || format == 'X')
// 		want_len = ft_xlen(va_arg(args, int));
// 	else
// 		return (0);
// 	if (want_len < lim)
// 		while (want_len + printf_len < lim)
// 			printf_len += ft_printf_char(' ');
// 	printf_len += ft_printf_without_sign(args, format);
// 	else
// 	{
// 		if (format == 'i')
// 		{
// 		}
// 	}
// 	return (printf_len);
// }

// int	ft_printf_with_sign(va_list args, const char format, char sign, int lim)
// {
// 	int	printf_len;
// 	int	i;

// 	i = 0;
// 	if (sign == '-')
// 		printf_len = ft_printf_with_hyphen(args, format, lim);
// 	else if (sign == '.')
// 		printf_len = ft_printf_with_dot(args, format, lim);
// 	printf_len = ft_printf_without_sign(args, format);
// 	return (printf_len);
// }

// int	ft_printf_with_op(const char *str, va_list args, int *i)
// {
// 	int		len;
// 	char	*option;
// 	int		lim;
// 	char	sign;
// 	char	format;

// 	len = 0;
// 	lim = 0;
// 	while (ft_isascii(str[*i]) && !ft_isalpha(str[*i]))
// 		(*i)++;
// 	option = ft_substr(str, 1, *i);
// 	printf("option:%s\n", option);
// 	ft_set_format_sign_lim(option, &format, &sign, &lim);
// 	printf("sign:%c lim:%d\n", sign, lim);
// 	if (!sign)
// 		len += ft_printf_without_sign(args, format);
// 	else
// 		len += ft_printf_with_sign(args, format, sign, lim);
// 	free(option);
// 	return (len);
// }

int	ft_printf_format(va_list args, const char format)
{
	int	printf_len;

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

bool	is_format(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	args;

	i = 0;
	ret = 0;
	va_start(args, str);
	while (str[i] != 0)
	{
		if (str[i] == '%' && !str[i + 1])
			break ;
		else if (str[i] == '%' && str[i + 1])
		{
			if (is_format(str[i + 1]))
				ret += ft_printf_format(args, str[i + 1]);
			i++;
		}
		else
			ret += ft_printf_char(str[i]);
		i++;
	}
	va_end(args);
	return (ret);
}
