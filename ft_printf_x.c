/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 15:31:10 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/27 15:43:01 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_x(unsigned int uinbr, const char format)
{
	int	x_len;

	x_len = 0;
	if (uinbr >= 16)
	{
		x_len += ft_put_x(uinbr / 16, format);
		ft_put_x(uinbr % 16, format);
	}
	else
	{
		x_len++;
		if (uinbr <= 9)
			ft_putchar_fd((uinbr + '0'), 1);
		else if (format == 'x')
			ft_putchar_fd((uinbr - 10 + 'a'), 1);
		else if (format == 'X')
			ft_putchar_fd((uinbr - 10 + 'A'), 1);
	}
	return (x_len);
}

int	ft_printf_x(unsigned int uinbr, const char format)
{
	if (uinbr)
		return (ft_put_x(uinbr, format));
	else
		return (write(1, "0", 1));
}