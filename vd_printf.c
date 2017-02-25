/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vd_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:08:13 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/25 23:33:47 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** sSpdDioOuUxXcC
** %%
** flags #0-+ et espace
** precision (.)
** taille min de champ
** flags hh h l ll j z
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
** s : ft_putstr
** S : ft_putwstr
** p : pointer
** d : ft_putnbr
** D : long d
** i : ft_putnbr
** o : unsigned decimal to octal
** O : long o
** u : unsigned decimal to unsigned decimal
** U : long U
** x : unsigned decimal to hexa, using abcdef
** X : same, using ABCDEF
** c : decimal to char
** C : long c
*/

void		(*ft_type(const char *s))()
{
	while (*s)
	{
		// si s renvoyer putstr, si S renvoer putwstr, etc
		++s;
	}
	return (&ft_putstr_fd);
}

/*
** parse, puis affiche une conversion. utilise les deux fonctions ci-dessus ^
** renvoie le nombre de caracteres lus sur format (t.conv)
** ainsi que le nombre de caracteres ecrits. (t.print)
*/

t_size			ft_convert_print(const char *s, uintmax_t data, int fd)
{
	t_size		t;

	t.print = 0;
	t.conv = 2;

	ft_type(s)(data, fd);
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
				ft_putchar_fd('%', fd);
			else
			{
				tmp = ft_convert_print(format + i, va_arg(ap, uintmax_t), fd);
				i += tmp.conv;
				ret += tmp.print;
			}
		}
		else
		{
			ft_putchar_fd(format[i], fd);
			++i;
		}
	}
	return (ret);
}
