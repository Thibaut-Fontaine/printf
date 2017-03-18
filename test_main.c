/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:42:43 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/18 09:50:48 by tfontain         ###   ########.fr       */
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

	int		a;
	printf("%10o", 123);
	return (0);
}




