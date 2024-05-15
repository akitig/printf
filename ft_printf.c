/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:46:09 by akunimot          #+#    #+#             */
/*   Updated: 2024/05/15 20:12:11 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_flg(char c)
{
	if (c == '-' || c == '.' || c == '0' || c == ' ' || c == '#' || c == '+')
		return (true);
	return (false);
}

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
void	error_flg(t_flg *flgs)
{
	if ((flgs->hyphen && flgs->zero) || (flgs->plus && flgs->space)
		|| (flgs->plus && flgs->shape) || (flgs->space && flgs->shape))
	{
		printf("error flg");
		flgs->error = true;
	}
}
void	set_each_flg(char *str, t_flg *flgs)
{
	if (*str == '-')
		flgs->hyphen = true;
	else if (*str == '.')
		flgs->dot = true;
	else if (*str == '0')
		flgs->zero = true;
	else if (*str == ' ')
		flgs->space = true;
	else if (*str == '#')
		flgs->shape = true;
	else if (*str == '+')
		flgs->plus = true;
	error_flg(flgs);
}

void	init_flgs(t_flg *flgs)
{
	flgs->error = false;
	flgs->hyphen = false;
	flgs->dot = false;
	flgs->plus = false;
	flgs->space = false;
	flgs->shape = false;
	flgs->zero = false;
	flgs->width = -1;
	flgs->format = '\0';
}

int	ft_intlen(int width)
{
	int	len;

	if (width < 0)
		return (0);
	else
	{
		len = 1;
		while (width)
		{
			width /= 10;
			len++;
		}
	}
	return (len);
}

void	error_flg_format(t_flg *flgs)
{
	if ((flgs->format == 's' && flgs->zero == true))
		flgs->error = true;
}

t_flg	set_flgs(char *str)
{
	t_flg	flgs;

	init_flgs(&flgs);
	while (!flgs.error)
	{
		if (*str == '%')
		{
			flgs.format = '%';
			return (flgs);
		}
		while (is_flg(*str))
			set_each_flg(str, &flgs);
		if (ft_isdigit(*str))
		{
			flgs.width = ft_atoi(str);
			str += ft_intlen(flgs.width);
		}
		if (is_format(*str))
		{
			flgs.format = *str;
			str++;
		}
		error_flg_format(&flgs);
		break ;
	}
	return (flgs);
}

int	ft_printf_flgs(va_list args, t_flg *flg)
{
	int	printf_len;

	printf_len = 0;
	if (flg->format == 'c')
		printf_len += ft_printf_char(va_arg(args, int));
	else if (flg->format == 's')
		printf_len += ft_printf_str(va_arg(args, char *));
	else if (flg->format == 'p')
		printf_len += ft_printf_ptr(va_arg(args, unsigned long long));
	else if (flg->format == 'd' || flg->format == 'i')
		printf_len += ft_printf_int(va_arg(args, int));
	else if (flg->format == 'u')
		printf_len += ft_printf_uint(va_arg(args, unsigned int));
	else if (flg->format == 'x' || flg->format == 'X')
		printf_len += ft_printf_x(va_arg(args, int), flg->format);
	else if (flg->format == '%')
		printf_len += ft_printf_char('%');
	return (printf_len);
	// printf("%d\n", *i);
	// printf("flg.error :%d\n", flg->error);
	// printf("flg.hyphen:%d\n", flg->hyphen);
	// printf("flg.dot   :%d\n", flg->dot);
	// printf("flg.plus  :%d\n", flg->plus);
	// printf("flg.space :%d\n", flg->space);
	// printf("flg.shape :%d\n", flg->shape);
	// printf("flg.zero  :%d\n", flg->zero);
	// printf("flg.width :%d\n", flg->width);
	// printf("flg.format:%c\n", flg->format);
	// return (1);
}

void	ft_list_printf(t_flg flg)
{
	printf("flg.error :%d\n", flg.error);
	printf("flg.hyphen:%d\n", flg.hyphen);
	printf("flg.dot   :%d\n", flg.dot);
	printf("flg.plus  :%d\n", flg.plus);
	printf("flg.space :%d\n", flg.space);
	printf("flg.shape :%d\n", flg.shape);
	printf("flg.zero  :%d\n", flg.zero);
	printf("flg.width :%d\n", flg.width);
	printf("flg.format:%c\n", flg.format);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	va_list	args;
	t_flg	flgs;
	char	*first;

	ret = 0;
	va_start(args, str);
	init_flgs(&flgs);
	while (*str && !flgs.error)
	{
		if (*str == '%')
		{
			first = (char *)str;
			if (*(str))
			{
				str++;
				flgs = set_flgs((char *)str);
				ret += ft_printf_flgs(args, &flgs);
				while (is_flg(*str))
					str++;
			}
			else
			{
				ret += ft_printf_char('%');
				str++;
			}
		}
		else
			ret += ft_printf_char(*str);
		if (*str)
			str++;
	}
	va_end(args);
	return (ret);
}
