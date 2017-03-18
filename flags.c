/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 10:38:15 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/18 10:06:58 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"
// virer les statics qui sont dans les fonctions !
// (a cause d'un possible rappel de printf)
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

static size_t		ft_flags(t_bool h, char tt, int fd)
{
	static t_bool	t = FALSE;

	if (t != TRUE && h != TRUE && ft_issigned(tt))
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
** dans *flag : 1 si flag '-', 2 si flag '0', ret 0 sinon
** dans t.print : le nombre de caracteres ecrits.
** dans t.conv : le nombre de caracteres "passes"
*/

t_size				ft_flag(const char *s, uintmax_t data, int fd, int *flag)
{
	t_size			ret;
	char			t;
	t_bool			h;

	*flag = 0;
	ret.conv = 0;
	ret.print = 0;
	h = FALSE;
	t = *ft_gettype(s);
	while (++s && ++ret.conv)
	{
		if (*s == '#')
			ret.print += ft_flagtag(t, fd);
		else if (*s == '0')
			*flag != 1 && (*flag = 2);
		else if (*s == '-')
			*flag = 1;
		else if (*s == ' ')
			ret.print += ft_flags(h, t, fd);
		else if (*s == '+')
			ft_issigned(t) && (ret.print += ft_flagp(s, data, &h, fd));
		else
			break ;
	}
	return (ret);
}
