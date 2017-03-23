/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:38:15 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/23 06:34:05 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

// pour t == 'o' n'ecrire le 0 !!
// que si il n'y en a pas deja sur la sortie (juste avant)

static size_t		ft_flagtag(char t, int fd, t_bool *tag)
{
	size_t			r;

	r = 0;
	if (*tag != TRUE)
	{
		*tag = TRUE;
		if (t == 'o')
			r += ft_putchar_fdr('0', fd); //
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

/*
** affiche les caracteres specifies par les flags en fonction du type demande
** valeur de renvoi :
** dans *flag : 1 si flag '-', 2 si flag '0', ret 0 sinon
** dans t.print : le nombre de caracteres ecrits.
** dans t.conv : le nombre de caracteres "passes"
*/

void				ft_flag(const char *s, uintmax_t data, int fd)
{
	const char		*t;
	t_bool			h;
	t_bool			tag;
	t_bool			ss;

	h = FALSE;
	t = ft_gettype(s);
	tag = FALSE;
	ss = FALSE;
	while (++s)
	{
		if (*s == '#')
			ft_flagtag(*t, fd, &tag);
		else if (*s == '0' || *s == '-')
			;
		else if (*s == '+')
			h = TRUE;
		else if (*s == ' ')
			ft_whichsign(s, data) == 1 && ft_strchr(s, '+') == NULL
				&& ft_strchr(s, '+') < t ? ft_flags(h, *t, fd, &ss) : 0;
		else
			break ;
	}
}

t_size				ft_flag0m(const char *s, uintmax_t data, int *flag)
{
	t_size			r;
	const char		*t;
	t_bool			tag;
	t_bool			ss;
	t_bool			h;

	*flag = 0;
	r.conv = 0;
	r.print = 0;
	h = FALSE;
	tag = FALSE;
	ss = FALSE;
	t = ft_gettype(s);
	while (++s && ++r.conv)
	{
		if (*s == '#')
		{
			if (tag == FALSE)
			{
				tag = TRUE;
				if ((*t == 'x' || *t == 'X') && data != 0)
					r.print += 2;
				if (*t == 'o') // sauf si deja un '0'
					r.print += 1;
			}
		}
		else if (*s == '+')
		{
			if (h == FALSE)
			{
				h = TRUE;
				r.print += ft_whichsign(s, data) ? 1 : 0;
			}
		}
		else if (*s == ' ')
		{
			if (ss == FALSE && ft_whichsign(s, data) == 1 && h != TRUE
					&& ft_strchr(s, '+') == NULL && ft_strchr(s, '+') < t
					&& ft_issigned(*t))
			{
				ss = TRUE;
				r.print += 1;
			}
		}
		else if (*s == '0')
			*flag != 1 && (*flag = 2);
		else if (*s == '-')
			*flag = 1;
		else
			break ;
	}
	return (r);
}
