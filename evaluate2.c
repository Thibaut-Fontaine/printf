/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:54:50 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/23 04:19:19 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

size_t			ft_evaluatepint(intmax_t data)
{
	size_t		r;

	if (data == 0)
		return (1);
	r = 0;
	if (data < 0)
	{
		data = -data;
		++r;
	}
	while (data)
	{
		data /= 10;
		++r;
	}
	return (r);
}

size_t			ft_evaluatepbase(uintmax_t data, int base)
{
	size_t		r;

	if (data == 0)
		return (1);
	r = 0;
	while (data)
	{
		data /= base;
		++r;
	}
	return (r);
}

size_t			ft_evaluintret(const char *t, uintmax_t data)
{
	return (ft_evaluatepbase((unsigned long int)data, *t == 'X'
				|| *t == 'x' ? 16 : ((*t == 'u') * 10 + (*t == 'o') * 8)));
}
