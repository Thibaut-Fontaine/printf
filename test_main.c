/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:42:43 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/11 11:42:52 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"
#include <stdio.h>
#include "./libft/includes/libft.h"
#include <sys/types.h>
#include <limits.h>
#include "./libft/includes/libft.h"

#include <locale.h> //

int				main()
{
	unsigned char	i = 214;
	size_t			ret;
	size_t			ret2;

	setlocale(LC_ALL, "");
	ret = printf("salut");
	ret2 = ft_printf("salut");
	
	printf("\n%zu %zu\n", ret, ret2);
	return (0);
}
