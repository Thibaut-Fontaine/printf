/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:42:43 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/14 14:01:24 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"
#include <stdio.h>
#include "./libft/includes/libft.h"
#include <sys/types.h>
#include <limits.h>
#include "./libft/includes/libft.h"

#include <locale.h> //

int					main()
{
	int			r1;
	int			r2;

	r1 = printf("%040d\n", 1);
	r2 = ft_printf("%040d\n", 1);
	
	printf("%d %d\n", r1, r2);
	return (0);
}
