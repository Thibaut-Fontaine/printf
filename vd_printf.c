/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:08:13 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/23 03:12:49 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** sSpdDioOuUxXcC
** %%
** flags #0-+ et espace
** precision (.)
** taille min de champ
** modifs hh h l ll j z
** /
** dans l'ordre :
** -> caractere %
** -> caractere d'attribut : #, 0, -, + et espace
** -> largeur minimale de champ : (int) qui definit espaces avant d'afficher
** si le int est neg, revient a avoir le - dans le caractere d'attribut
** -> precision : voir man. fait varier le nbr de caracs qui s'affichent
** -> modificateur de longueur : modifie la taille de la zone mem. a convertir
** -> indicateur de conversion : definie de type a convertir
*/

/*
** flags :
** '#' -> 0 pour o et 0x / 0X pour x et X
** '0' -> afficher des zeros plutot que des espaces
** '-' -> affiche tout colle a gauche plutot qu'a droite et annule le 0
** '+' -> affiche un + si la conversion signee est positive, annule l'espace
** ' ' -> affiche un espace si la conversion est signee
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
**  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
** - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - -
*/

/*
** return the precision for the actual conversion, or return -1 if there is no.
*/

int				ft_getprecision(const char *s, char type)
{
	while (*s && *s != '.' && *s != type)
		++s;
	if (*s != '.')
		return (-1);
	return (ft_atoi(s + 1));
}

/*
** affiche un nombre d'espaces ou de 0 correspondants a la largeur de champ
** s pt sur largeur min. de champ, n nombre de caracs. deja ecrits
*/

size_t			ft_field(const char *s, size_t n, int flag, int fd)
{
	int			i;
	size_t		t;

	i = ft_atoi(s);
	n = ((size_t)i > n ? i - n : 0);
	flag = (flag == 2 ? '0' : ' ');
	t = 0;
	while (n--)
		t += ft_putchar_fdr(flag, fd);
	return (t);
}

/*
** parse, puis affiche une conversion.
** renvoie le nombre de caracteres lus sur format (t.conv)
** ainsi que le nombre de caracteres ecrits. (t.print)
*/

t_size			ft_convert_print(const char *s, uintmax_t data, int fd)
{
	t_size		t;
	int			flag;
	const char	*type;
	int			precision;

	t.print = 0;
	type = ft_gettype(s);
	t.conv = type - s;
	if (*type == '\0')
		return (t);
	t = ft_flag0m(s, data, &flag);
	if ((precision = ft_getprecision(s, *type)) != -1 && flag != 1)
		flag = 0;
	if (flag == 1)
	{
		ft_flag(s, data, fd);
		if ((*type == 'd' || *type == 'D' || *type == 'i')
				&& ft_whichsign(s, data) == 0)
			ft_putchar_fdr('-', fd);
		if ((*type == 'd' || *type == 'D' || *type == 'i')
				&& ft_whichsign(s, data) == 1 && ft_strchr(s, '+') != NULL
				&& ft_strchr(s, '+') < type)
			ft_putchar_fdr('+', fd);
		if ((*type == 'x' || * type == 'X') && data != 0
				&& ft_strchr(s, '#') != NULL && ft_strchr(s, '#') < type)
		{
			ft_putchar_fdr('0', fd);
			ft_putchar_fdr(*type, fd);
		}
		t.print += ft_printdata(type, data, fd, precision);
		t.print += ft_field(s + t.conv, t.print, flag, fd);
	}
	else
	{
		if (flag == 2 && (*type == 'd' || *type == 'D' || *type == 'i')
				&& ft_whichsign(s, data) == 0)
			ft_putchar_fdr('-', fd);
		if (flag == 2 && (*type == 'd' || *type == 'D' || *type == 'i')
				&& ft_whichsign(s, data) == 1 && ft_strchr(s, '+') != NULL
				&& ft_strchr(s, '+') < type)
			ft_putchar_fdr('+', fd);
		if (flag == 2 && (*type == 'x' || * type == 'X') && data != 0
				&& ft_strchr(s, '#') != NULL && ft_strchr(s, '#') < type)
		{
			ft_putchar_fdr('0', fd);
			ft_putchar_fdr(*type, fd);
		}
		t.print += ft_field(s + t.conv, (ft_evaluate_len(type, data, precision) + t.print + ((precision != -1) * ft_issigned(*type) * !ft_whichsign(type, data))), flag, fd);
		ft_flag(s, data, fd);
		if (flag == 0 && (*type == 'd' || *type == 'D' || *type == 'i')
				&& ft_whichsign(s, data) == 0)
			ft_putchar_fdr('-', fd);
		if (flag == 0 && (*type == 'd' || *type == 'D' || *type == 'i')
				&& ft_whichsign(s, data) == 1 && ft_strchr(s, '+') != NULL
				&& ft_strchr(s, '+') < type)
			ft_putchar_fdr('+', fd);
		if (flag == 0 && (*type == 'x' || * type == 'X') && data != 0
				&& ft_strchr(s, '#') != NULL && ft_strchr(s, '#') < type)
		{
			ft_putchar_fdr('0', fd);
			ft_putchar_fdr(*type, fd);
		}
		t.print += ft_printdata(type, data, fd, precision);
		if ((precision != -1) && ft_issigned(*type) && !ft_whichsign(type, data))
			t.print += 1;
	}
	t.conv = type - s + 1;
	return (t);
}

/*
** si '%' est rencontre, appelle ft_convert_print, sinon ecrit le carac.
*/

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	size_t		i;
	size_t		ret;
	t_size		tmp;
	char		*chr;

	i = 0;
	ret = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			if ((chr = ft_strchr(format + i + 1, '%')) != NULL // si %...% avec aucun indic. de conv entre les deux
					&& chr < ft_gettype(format + i))
			{
				tmp.conv = chr - (format + i);
				chr = ft_memdup(format + i, tmp.conv);
				chr[tmp.conv + 1] = '\0';
				chr[tmp.conv] = 'c';
				tmp = ft_convert_print(chr, '%', fd);
				free(chr);
				ret += tmp.print;
				i += tmp.conv;
			}
			else
			{
				tmp = ft_convert_print(format + i, va_arg(ap, uintmax_t), fd);
				i += tmp.conv;
				ret += tmp.print;
			}
		}
		else
			ret += ft_putchar_fdr(format[i++], fd);
	}
	return (ret);
}
