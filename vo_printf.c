/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vo_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:08:13 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/11 06:17:30 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

// sSpdDioOuUxXcC
// %%
// flags #0-+ et espace
// precision (.)
// taille min de champ
// flags hh h l ll j z

// dans l'ordre :
// -> caractere %
// -> caractere d'attribut : #, 0, -, + et espace
// -> largeur de champ : (int) qui definit espaces a gauche avant d'afficher
// si le int est neg, revient a avoir le - dans le caractere d'attribut
// -> precision : voir man. fait varier le nbr de caracs qui s'affichent
// -> modificateur de longueur : modifie la taille de la zone mem. a convertir
// -> indicateur de conversion : definie de type a convertir

int _FD_ = -1;

ft_printer()
{
}

ft_parser(const char *s)
{
	
}

/*
** parse, puis affiche. utilise les deux fonctions ci-dessus ^
*/

t_size			ft_convert_then_print(const char *s, uintmax_t data)
{
	t_size		t;
	size_t		i;

	i = 0;
	t.print = 0;
	t.conv = 0;
	//ft_parser(s);
	return (t);
}

/*
** si '%' est rencontre, appelle ft_convert_then_print, sinon ecrit le carac.
*/

int				ft_voprintf(int fd, const char *format, va_list ap)
{
	size_t		i;
	size_t		ret;
	t_size		tmp;

	i = 0;
	ret = 0;
	_FD_ = fd;
	while (format[i] != 0)
	{
		if (format[i] == '%')
		{
			tmp = ft_convert_then_print(format + i, va_arg(ap, uintmax_t));
			i += tmp.conv;
			ret += tmp.print;
		}
		else
		{
			ft_putchar(format[i]);
			++i;
		}
	}
	return (ret);
}
