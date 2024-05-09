/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:26:43 by akunimot          #+#    #+#             */
/*   Updated: 2024/05/09 17:12:12 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>

// ft_printf.c
int		ft_printf_format(va_list args, const char format);
int		ft_printf(const char *str, ...);

// ft_printf_csp.c
int		ft_printf_char(char c);
int		ft_printf_str(char *str);

int		ft_putptr(unsigned long long ptr);
int		ft_printf_ptr(unsigned long long ptr);

int		ft_printf_percent(void);

// ft_printf_diu.c
int		ft_uilen(unsigned int uinbr);
char	*ft_uitoa(unsigned int uinbr);
int		ft_printf_uint(unsigned int uinbr);

int		ft_printf_int(int nbr);

// ft_printf_x.c
int		ft_put_x(unsigned int uinbr, const char format);
int		ft_printf_x(unsigned int uinbr, const char format);

#endif