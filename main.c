/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akunimot <akunimot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:29:08 by akunimot          #+#    #+#             */
/*   Updated: 2024/05/13 21:36:45 by akunimot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main(void)
{
	int ret;
	int ft_ret = 0;
	printf("format c : 'c'\n");
	ret = printf("%c", 'c');
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf("%c", 'c');
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	printf("format s : \"abcde\"\n");
	ret = printf("%s", "abcde");
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf("%s", "abcde");
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	// (" NULL %s NULL ", NULL)
	printf("format s : \n");
	ret = printf(" NULL %s NULL ", NULL);
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf(" NULL %s NULL ", NULL);
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	printf("format p : \"abcde\"\n");
	ret = printf("%p", "abcde");
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf("%p", "abcde");
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	printf("format d : 12345\n");
	ret = printf("%d", 12345);
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf("%d", 12345);
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	printf("format i : 12345\n");
	ret = printf("%i", 12345);
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf("%i", 12345);
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	printf("format u : UINT_MAX\n");
	ret = printf("%u", UINT_MAX);
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf("%u", UINT_MAX);
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	printf("format x : 3\n");
	ret = printf("%x", 3);
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf("%x", 3);
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	printf("format x : 3\n");
	ret = printf(" %x", 3);
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf(" %x", 3);
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	printf("format X : 3\n");
	ret = printf("%X", 3);
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf("%X", 3);
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	printf("format X : 3\n");
	ret = printf(" %X", 3);
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf(" %X", 3);
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	printf("fotmat percent : percent\n");
	ret = printf("%%");
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf("%%");
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);

	printf("fotmat percent : percent\n");

	ret = printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&");
	printf("\n");
	fflush(NULL);
	ft_ret = ft_printf("%sx", "{} al$#@@@^&$$^#^@@^$*((&");
	fflush(NULL);
	printf("\n");
	printf("%d %d\n\n", ret, ft_ret);
}