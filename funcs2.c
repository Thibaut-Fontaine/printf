/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 05:50:07 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/25 06:43:47 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** ce magnifique fichier a pour but ultime d'entasser les morceaux de fonctions
** separes cruellement du reste de leur environnement naturel par la norme.
*/

// a refaire

t_datas			ft_flagtag_calculate(const char *s)
{
	const char	*t;
	size_t		r;
	int			precision;
	t_datas		dd;

	r = 0;
	t = ft_gettype(s);
	if (*t != 'o')
	{
		dd.fd = -1;
		return (dd);
	}
	precision = ft_getprecision(s, *t);
	while (s[r] == '#' || s[r] == '0' || s[r] == '-' || s[r] == '+'
			|| s[r] == ' ')
		++r;
	r = ft_atoi(s + r);
	dd.data = (uintmax_t)t;
	dd.fd = r;
	dd.precision = precision;
	return (dd);
}
