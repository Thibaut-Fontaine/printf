/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:38:15 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/18 10:48:13 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

// pour t == 'o' n'ecrire le 0
// que si il n'y en a pas deja sur la sortie (juste avant)
static size_t		ft_flagtag(char t, int fd, t_bool *tag)
{
	size_t			r;

	r = 0;
	if (*tag != TRUE)
	{
		*tag = TRUE;
		if (t == 'o' || t == 'x' || t == 'X')
		{
			r += ft_putchar_fdr('0', fd);
			t != 'o' ? r += ft_putchar_fdr(t, fd) : 0;
		}
	}
	return (r);
}

static size_t		ft_flags(t_bool h, char tt, int fd, t_bool *ss)
{
	if (*ss != TRUE && h != TRUE && ft_issigned(tt))
	{
		*ss = TRUE;
		return (ft_putchar_fdr(' ', fd));
	}
	return (0);
}

static size_t		ft_flagp(const char *s, uintmax_t data, t_bool *h, int fd,
		t_bool *p)
{
	if (*p != TRUE)
	{
		*p = TRUE;
		*h = TRUE;
		return (ft_putchar_fdr(ft_whichsign(s, data) ? '+' : 0, fd));
	}
	return (0);
}

/*
** affiche les caracteres specifies par les flags en fonction du type demande
** valeur de renvoi :
** dans *flag : 1 si flag '-', 2 si flag '0', ret 0 sinon
** dans t.print : le nombre de caracteres ecrits.
** dans t.conv : le nombre de caracteres "passes"
*/

t_size				ft_flag(const char *s, uintmax_t data, int fd, int *flag)
{
	t_size			ret;
	char			t;
	t_bool			h;
	t_bool			tag;
	t_bool			ss;
	t_bool			p;

	*flag = 0;
	ret.conv = 0;
	ret.print = 0;
	h = FALSE;
	t = *ft_gettype(s);

	tag = FALSE;
	ss = FALSE;
	p = FALSE;
	while (++s && ++ret.conv)
	{
		if (*s == '#')
			ret.print += ft_flagtag(t, fd, &tag);
		else if (*s == '0')
			*flag != 1 && (*flag = 2);
		else if (*s == '-')
			*flag = 1;
		else if (*s == ' ')
			ret.print += ft_flags(h, t, fd, &ss);
		else if (*s == '+')
			ft_issigned(t) && (ret.print += ft_flagp(s, data, &h, fd, &p));
		else
			break ;
	}
	return (ret);
}
