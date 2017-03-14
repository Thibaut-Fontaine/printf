/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:38:15 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/14 10:59:36 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static size_t		ft_flagtag(char t, int fd)
{
	size_t			r;

	r = 0;
	if (t == 'o' || t == 'x' || t == 'X')
	{
		r += ft_putchar_fdr('0', fd);
		t != 'o' ? r += ft_putchar_fdr(t, fd) : 0;
	}
	return (r);
}

static size_t		ft_flags(int fd)
{
	static t_bool	t = FALSE;

	if (t != TRUE)
	{
		t = TRUE;
		return (ft_putchar_fdr(' ', fd));
	}
	return (0);
}

static size_t		ft_flagp(const char *s, uintmax_t data, t_bool *h, int fd)
{
	static t_bool	t = FALSE;

	if (t != TRUE)
	{
		t = TRUE;
		*h = TRUE;
		return (ft_putchar_fdr(ft_whichsign(s, data) ? '+' : 0, fd));
	}
	return (0);
}

/*
** affiche les caracteres specifies par les flags en fonction du type demande
** valeur de renvoi :
** dans t.conv : 1 si flag '-', 2 si flag '0', ret 0 sinon
** dans t.print : le nombre de caracteres ecrits.
*/

t_size				ft_flag(const char *s, uintmax_t data, int fd)
{
	t_size			ret;
	char			t;
	t_bool			h;

	ret.conv = 0;
	ret.print = 0;
	h = FALSE;
	t = *ft_gettype(s);
	while (++s)
	{
		if (*s == '#')
			ft_flagtag(t, fd);
		else if (*s == '0' && ret.conv != 1)
			ret.conv = 2;
		else if (*s == '-')
			ret.conv = 1;
		else if (*s == ' ' && h != TRUE && ft_issigned(t))
			ft_flags(fd);
		else if (*s == '+' && ft_issigned(t))
			ft_flagp(s, data, &h, fd);
		else
			break ;
	}
	return (ret);
}
