/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:42:43 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/23 03:21:45 by tfontain         ###   ########.fr       */
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


	ft_printf("%#o\n", 0);
	printf("%#o\n", 0);
	printf("%d %d\n", r1, r2);
	return (0);
}




