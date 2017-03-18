/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 08:58:23 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/18 12:55:52 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** return 1 if the conversion is signed, take the conversion char in the format
*/

int			ft_issigned(char c)
{
	if (c == 'd' || c == 'D' || c == 'i')
		return (1);
	return (0);
}

int			ft_whichsign(const char *s, intmax_t i)
{
	s = ft_gettype(s);
	if (*s == 'D')
		return ((long int)i >= 0);
	if (*(s - 1) == 'h')
	{
		if (*(s - 2) == 'h')
			return ((char)i >= 0);
		else
			return ((short int)i >= 0);
	}
	if (*(s - 1) == 'l' || *(s - 1) == 'j' || *(s - 1) == 'z')
		return ((long int)i >= 0);
	return ((int)i >= 0);
}

size_t		ft_putnc(char c, size_t i, int fd)
{
	size_t	ret;

	ret = 0;
	while (i--)
		ret += ft_putchar_fdr(c, fd);
	return (ret);
}

size_t		ft_diff(uintmax_t a, uintmax_t b)
{
	return (a > b ? a - b : b - a);
}
