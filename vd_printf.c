/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:08:13 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/11 11:42:49 by tfontain         ###   ########.fr       */
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
** affiche les caracteres specifies par les flags en fonction du type demande
** valeur de renvoi :
** dans t.conv : 1 si flag '-', 2 si flag '0', ret 0 sinon
** dans t.print : le nombre de caracteres ecrits.
*/

t_size			ft_flag(const char *s, uintmax_t data, int fd)
{
	t_size		ret;
	char		t;
	t_bool		h;

	ret.conv = 0;
	ret.print = 0;
	h = FALSE;
	t = *ft_gettype(s);
	++s;
	while (*s == '#' || *s == '0' || *s == '-' || *s == '+' || *s == ' ')
	{
		if (*s == '#')
		{
			if (t == 'o' || t == 'x' || t == 'X')
			{
				ret.print += ft_putchar_fdr('0', fd);
				t != 'o' ? ret.print += ft_putchar_fdr(t, fd) : 0;
			}
		}
		else if (*s == '0' && ret.conv != 1)
			ret.conv = 2;
		else if (*s == '-')
			ret.conv = 1;
		else if (*s == ' ' && h != TRUE && ft_issigned(t))
			ret.print += ft_putchar_fdr(' ', fd);
		else if (*s == '+' && ft_issigned(t))
			ret.print += ft_putchar_fdr(ft_whichsign(data) ? 0
					: '+', fd * (h = TRUE));
		++s;
	}
	return (ret);
}

/*
** parse, puis affiche une conversion. utilise les fonctions ci-dessus ^
** renvoie le nombre de caracteres lus sur format (t.conv)
** ainsi que le nombre de caracteres ecrits. (t.print)
*/

t_size			ft_convert_print(const char *s, uintmax_t data, int fd)
{
	t_size		t;
	const char	*type;

	t.print = 0;
	t.conv = 2;
	if (*(type = ft_gettype(s)) == 0)
		return (t);
	t = ft_flag(s, data, fd);
	t.print += ft_type(type)(data, fd);
	
	//
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

	i = 0;
	ret = 0;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '%')
			{
				ret += ft_putchar_fdr('%', fd);
				i += 2;
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
