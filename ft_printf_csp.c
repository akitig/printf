/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_csp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:26:00 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/27 14:31:18 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		ptrlen += ft_putptr(ptr / 16);
		ft_putptr(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd((ptr + '0'), 1);
		else
			ft_putchar_fd((ptr - 10 + 'a'), 1);
	}
	ptrlen++;
	return (ptrlen);
}

int	ft_printf_ptr(unsigned long long ptr)
{
	int ptrlen;

	ptrlen = 0;
	ptrlen += write(1, "0x", 2);
	if (ptr == 0)
		ptrlen += write(1, "0", 1);
	else
		ptrlen += ft_putptr(ptr);
	return (ptrlen);
}