/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:42:43 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/13 08:02:03 by tfontain         ###   ########.fr       */
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
	ft_printf("%+d\n", 50);
	printf("%+d\n", 50);
	return (0);
}
