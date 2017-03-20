/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:42:43 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/20 22:06:06 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft/includes/libft.h"
#include "./printf.h"
#include <stdio.h>
#include <sys/types.h>
#include <limits.h>

#include <locale.h> //

int					main()
{
	setlocale(LC_ALL, "");

	int		r1;
	int		r2;

	//unsigned long long int	i = 9223372036854775808;

	//printf("%lld\n", i);
	r1 = ft_printf("%lld|\n", -9223372034775807);
	r2 = printf("%lld|\n", -9223372036855807);
	printf("myprintf ret = %d\noriginal ret = %d\n", r1, r2);
	return (0);
}




