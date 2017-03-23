/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:42:43 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/23 03:03:25 by tfontain         ###   ########.fr       */
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
	int		r1;
	int		r2;
	r1 = ft_printf("%.3d|_mine__|\n", -42);
	r2 = printf("%.3d|_their_|\n", -42);
	printf("%d %d\n", r1, r2);
	r1 = ft_printf("%4.2d|_mine__|\n", -1);
	r2 = printf("%4.2d|_their_|\n", -1);
	printf("%d %d\n", r1, r2);
	return (0);
}




