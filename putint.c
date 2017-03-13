/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putint.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:45:23 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/13 11:56:12 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** renvoie un pointeur sur fonction du genre ssize_t (type i, int fd)
** exemple :
**			ssize_t ft_putuint32_fd(uint32_t i, int fd);
*/

ssize_t				ft_putint_fdr(intmax_t i, int fd)
{
	ssize_t			r;

	r = 0;
	if (i < 0)
	{
		r += ft_putchar_fdr('-', fd);
		i = -i;
	}
	if (i >= 10)
		r += ft_putint_fdr(i / 10, fd) + ft_putint_fdr(i % 10, fd);
	else
		r += ft_putchar_fdr(i + '0', fd);
	return (r);
}

ssize_t				ft_putuint_fdr(uintmax_t i, int fd)
{
	return (i != 0 ? ft_putuint_fdr(i / 10, fd) +
			ft_putchar_fdr(i % 10 + '0', fd) : 0);
}

ssize_t				ft_putoct_fdr(uintmax_t i, int fd)
{
	return (i != 0 ? ft_putoct_fdr(i / 8, fd) +
			ft_putchar_fdr(i % 8 + '0', fd) : 0);
}

ssize_t				ft_puthex_fdr(uintmax_t i, int fd)
{
	return (i != 0 ? ft_puthex_fdr(i / 16, fd) + ft_putchar_fdr((i % 16 < 10) *
				(i % 16 + 48) + !(i % 16 < 10) * (i % 16 + 87), fd) : 0);
}

ssize_t				ft_puthexx_fdr(uintmax_t i, int fd)
{
	return (i != 0 ? ft_puthexx_fdr(i / 16, fd) +
			ft_putchar_fdr((i % 16 < 10) * (i % 16 + 48) + !(i % 16 < 10) *
				(i % 16 + 55), fd) : 0);
}
