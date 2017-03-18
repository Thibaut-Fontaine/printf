/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:08:13 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/18 10:14:45 by tfontain         ###   ########.fr       */
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

//
//
// MANQUE :
// la precision des ints et la largeur de champ quand le flag n'est pas '-'
//
//

t_size			ft_convert_print(const char *s, uintmax_t data, int fd)
{
	t_size		t;
	int			flag;
	const char	*type;
	int			precision;
	int			field;

	t.print = 0;
	type = ft_gettype(s);
	t.conv = type - s;
	if (*type == '\0')
		return (t);
	t = ft_flag(s, data, fd, &flag);
	precision = ft_getprecision(s, *type);
	if (flag == 1)
	{
		t.print = ft_printdata(type, data, fd, precision);
		t.print += ft_field(s + t.conv, t.print, flag, fd);
	}
	else
	{
		field = t.print;
		field += ft_evaluate_len(type, data, precision);
		t.print += ft_field(s + t.conv, field, flag, fd);
		t.print += ft_printdata(type, data, fd, precision);
	}
	// largeur de champ en correspondance avec les flags : justifier d / g et 0
	// precision : minimum pour les d i o u x X et maximum pour s S (tronquer)
	//t.print += ft_printdata(type, data, fd);
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
			if ((chr = ft_strchr(format + i + 1, '%')) != NULL
					&& chr < ft_gettype(format + i))
			{
				ret += ft_putchar_fdr('%', fd);
				i += chr - (format + i) + 1;
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
