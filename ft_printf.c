/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:46:09 by akunimot          #+#    #+#             */
/*   Updated: 2024/05/10 21:20:24 by akunimot         ###   ########.fr       */
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

void	set_each_flg(char c, t_flg *flgs)
{
	if (c == '-')
		flgs->hyphen = true;
	else if (c == '.')
		flgs->dot = true;
	else if (c == '0')
		flgs->zero = true;
	else if (c == ' ')
		flgs->space = true;
	else if (c == '#')
		flgs->shape = true;
	else if (c == '+')
		flgs->plus = true;
}

bool	error_flg(t_flg flgs)
{
	return ((flgs.hyphen && flgs.zero) || (flgs.plus && flgs.space)
		|| (flgs.plus && flgs.shape) || (flgs.space && flgs.shape));
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

t_flg	set_flgs(const char *str, int *i)
{
	t_flg	flgs;

	init_flgs(&flgs);
	while (!flgs.error)
	{
		while (is_flg(str[*i++]))
			set_each_flg(str[*i], &flgs);
		if (error_flg(flgs))
			flgs.error = true;
		else if (ft_isdigit(str[*i]))
		{
			flgs.width = ft_atoi(str);
			*i += ft_intlen(flgs.width);
		}
		else if (is_format(str[*i++]))
			flgs.format = str[*i];
		error_flg_format(&flgs);
		break ;
	}
	return (flgs);
}

int	ft_printf_flgs(const char *str, t_flg *flg, int *i)
{
	printf("%s", str);
	printf("%d", *i);
	printf("flg.error :%d\n", flg->error);
	printf("flg.hyphen:%d\n", flg->hyphen);
	printf("flg.dot   :%d\n", flg->dot);
	printf("flg.plus  :%d\n", flg->plus);
	printf("flg.space :%d\n", flg->space);
	printf("flg.shape :%d\n", flg->shape);
	printf("flg.zero  :%d\n", flg->zero);
	printf("flg.width :%d\n", flg->width);
	printf("flg.format:%c\n", flg->format);
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		ret;
	va_list	args;
	t_flg	flgs;

	i = 0;
	ret = 0;
	printf("test");
	va_start(args, str);
	while (str[i])
	{
		printf("test");
		if (str[i] == '%' && !str[i + 1])
			break ;
		else if (str[i] == '%' && str[i + 1])
		{
			flgs = set_flgs(str, &i);
			if (flgs.error)
				return (-1);
			ret += ft_printf_flgs(str, &flgs, &i);
		}
		else
			ret += ft_printf_char(str[i++]);
		break ;
	}
	va_end(args);
	return (ret);
}
