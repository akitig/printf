/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 05:46:09 by akunimot          #+#    #+#             */
/*   Updated: 2024/04/27 06:08:05 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "limits.h"
#include "stdio.h"

int	main(void)
{
	printf("%c\n", 'c');
	printf("%s\n", "abcde");
	printf("%p\n", "abcde");
	printf("%d\n", INT_MAX);
	printf("%i\n", INT_MAX);
	printf("%u\n", UINT_MAX);
	printf("%x\n", 3);
	printf("%X\n", 3);
	printf("%%");
}