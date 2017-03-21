/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:42:43 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/21 16:18:50 by tfontain         ###   ########.fr       */
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
	char d1 = -17;
	short d2 = -7987;
	int	 d3 = -98444517;
	long int d4 = -984155415145641564;

// 1 positif et 0 negatif

	printf("|%d, %d, %d, %d|", ft_whichsign("%hhd", d1), ft_whichsign("%hd", d2), ft_whichsign("%d", d3), ft_whichsign("%ld", d4));
	return (0);
}




