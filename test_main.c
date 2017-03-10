/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:42:43 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/10 15:06:41 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"
#include <stdio.h>
#include "./libft/includes/libft.h"
#include <sys/types.h>
#include <limits.h>
#include "./libft/includes/libft.h"

int				main()
{
	unsigned char	i = 'y';
	int				n = 666;
	char	*s = "ceci est une chaine ascii";
	wchar_t	*ls = L"©˙∆ ca c'est une string pour unicode œ∑´®†¥πø√∫ƒ© !";
	wchar_t			lc = L'ø';

	ft_printf("|||%c -> %c -> %c oh yeah\n", i, n, k);
	return (0);
}
