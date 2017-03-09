/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 21:29:39 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/09 06:38:28 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** toutes les fonctions d'ecriture presentes retournent le nombre de caracteres
** ecrits, -1 si erreur (si write retourne -1) ou si le format est non specifie
** le type de retour est donc ssize_t (4 bytes signe)
*/

const char				*ft_gettype(const char *s)
{
	size_t				n;

	n = 0;
	while (s[n] && s[n] != 's' && s[n] != 'S' && s[n] != 'p' && s[n] != 'd' &&
			s[n] != 'D' && s[n] != 'i' && s[n] != 'o' && s[n] != 'O' &&
			s[n] != 'u' && s[n] != 'U' && s[n] != 'x' && s[n] != 'X' &&
			s[n] != 'c' && s[n] != 'C')
		++n;
	return (s + n);
}

/*
** renvoie un pointeur sur fonction de type ssize_t()
*/

ssize_t					(*ft_typeint(const char *f))()
{
	if (*f == 'D' || ((*f == 'd' || *f == 'i') && *(f - 1) == 'l'))
		return (&ft_putnbr_fd); // changer pour le long int
	if ((*f == 'd' || *f == 'i') && *(f - 1) == 'h' && *(f - 2) == 'h')
		return (&ft_putnbr_fd); // unsigned char / char -> en nbr
	if ((*f == 'd' || *f == 'i') && *(f - 1) == 'h')
		return (&ft_putnbr_fd); // short int
	if ((*f == 'd' || *f == 'i') && *(f - 1) == 'z')
		return (&ft_putnbr_fd); // size_t or ssize_t
	if ((*f == 'd' || *f == 'i') && *(f - 1) == 'j')
		return (&ft_putnbr_fd); // intmax_t or uintmax_t
	if (*f == 'd' || *f == 'i')
		return (&ft_putnbr_fd); // int
	return (NULL);
}

/*
** renvoie le pt sur fonction correspondant au type et au modif. de longueur
*/

ssize_t					(*ft_type(const char *f))()
{
	if (*f == 'S' || (*f == 's' && *(f - 1) == 'l'))
		return (&ft_putwstr_fd);
	if (*f == 's')
		return (&ft_putstr_fd);
	if (*f == 'C' || (*f == 'c' && *(f - 1) == 'l'))
		return (&ft_putwchar_fd);
	if (*f == 'c')
		return ((void*)&ft_putchar_fd);
	if (*f == 'd' || *f == 'i' || *f == 'D')
		return (ft_typeint(f));
	if (*f == 'p')
		return (&ft_putadr_fd);
	if (*f == 'O' || (*f == 'o' && *(f - 1) == 'l'))
		return (NULL); // long octal
	if (*f == 'o')
		return (NULL); // to octal
	if (*f == 'U' || (*f == 'u' && *(f - 1) == 'l'))
		return (NULL); // long decimal non-signe
	if (*f == 'u')
		return (NULL); // decimal non-signe
	if (*f == 'X' || (*f == 'x' && *(f - 1) == 'l'))
		return (NULL); // hexa in bigs chars
	if (*f == 'x')
		return (NULL); // hexa in big chars
	return (NULL);
}
