/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:38:15 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/25 06:43:28 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

static size_t		ft_flagtag(const char *s, t_datas dd, t_bool *tag,
		int flag)
{
	size_t			r;
	const char		*t;
	int				precision;

	t = ft_gettype(s);
	if (*t != 'o')
		return (0);
	precision = ft_getprecision(s, *t);
	if (*tag != TRUE)
	{
		*tag = TRUE;
		if (dd.data == 0 && precision == -1)
			return (0);
		if (dd.data == 0 && precision == 0)
			return (ft_putchar_fdr('0', dd.fd));
		r = 0;
		while (s[r] == '#' || s[r] == '0' || s[r] == '-' || s[r] == '+'
				|| s[r] == ' ')
			++r;
		r = ft_atoi(s + r);
		if ((precision != -1 && (ft_evaluate_uint(t, dd.data) >=
						(size_t)precision)) || (precision == -1 &&
						((flag == 2 && ft_evaluate_uint(t, dd.data) >= r)
						|| flag != 2)))
			return (ft_putchar_fdr('0', dd.fd));
	}
	return (0);
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

void				ft_flag(const char *s, uintmax_t data, int fd, int flag)
{
	const char		*t;
	t_bool			h;
	t_bool			tag;
	t_bool			ss;
	t_datas			dd;

	h = FALSE;
	t = ft_gettype(s);
	tag = FALSE;
	ss = FALSE;
	while (++s)
	{
		if (*s == '#')
		{
			dd.fd = fd;
			dd.data = data;
			ft_flagtag(s, dd, &tag, flag);
		}
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
	t_bole			bb;
	int				p;
	size_t			rr;

	*flag = 0;
	r.conv = 0;
	r.print = 0;
	bb.h = FALSE;
	bb.tag = FALSE;
	bb.ss = FALSE;
	t = ft_gettype(s);
	while (++s && ++r.conv)
	{
		if (*s == '#')
		{
			if (bb.tag == FALSE)
			{
				bb.tag = TRUE;
				if ((*t == 'x' || *t == 'X') && data != 0)
					r.print += 2;
				else if (*t == 'o')
				{
					p = ft_getprecision(s, *t);
					if (data == 0 && p == -1)
						;
					else
					{
						rr = 0;
						if (data == 0 && p == 0)
							r.print += 1;
						else
						{
							while (s[rr] == '#' || s[rr] == '0' || s[rr] ==
									'-' || s[rr] == '+' || s[rr] == ' ')
								++rr;
							rr = ft_atoi(s + rr);
							if (p != -1)
							{
								if (ft_evaluate_uint(t, data) >= (size_t)p)
									r.print += 1;
							}
							else
							{
								if ((*flag == 2 && ft_evaluate_uint(t, data)
											>= rr) || *flag != 2)
									r.print += 1;
							}
						}
					}
				}
			}
		}
		else if (*s == '+')
		{
			if (bb.h == FALSE)
			{
				bb.h = TRUE;
				r.print += ft_whichsign(s, data) ? 1 : 0;
			}
		}
		else if (*s == ' ')
		{
			if (bb.ss == FALSE && ft_whichsign(s, data) == 1 && bb.h != TRUE
					&& ft_strchr(s, '+') == NULL && ft_strchr(s, '+') < t
					&& ft_issigned(*t))
			{
				bb.ss = TRUE;
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
