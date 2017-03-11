/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettype.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 21:29:39 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/11 18:20:56 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** toutes les fonctions d'ecriture presentes retournent le nombre de caracteres
** ecrits, -1 si erreur (si write retourne -1) ou si le format est non specifie
** le type de retour est donc ssize_t (4 bytes signe)
** -
** see also the folder ./put_funcs/
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
** du genre :
**				ssize_t ft_putuint32_fd(uint32_t i, int fd);
*/

ssize_t					(*ft_typeinteger(const char *f))()
{
	if (*f == 'U' || *f == 'u')
		return (&ft_putuint_fdr);
	if (*f == 'o' || *f == 'O')
		return (&ft_putoct_fdr);
	if (*f == 'x')
		return (&ft_puthex_fdr);
	if (*f == 'X')
		return (&ft_puthexx_fdr);
	else
		return (&ft_putint_fdr);
}

/*
** renvoie le pt sur fonction correspondant au type et au modif. de longueur
*/

ssize_t					(*ft_type(const char *f))()
{
	if (*f == 'S' || (*f == 's' && *(f - 1) == 'l'))
		return (&ft_putwstr_fdr);
	if (*f == 's')
		return (&ft_putstr_fdr);
	if (*f == 'C' || (*f == 'c' && *(f - 1) == 'l'))
		return (&ft_putwchar_fdr);
	if (*f == 'c')
		return ((void*)&ft_putchar_fdr);
	if (*f == 'd' || *f == 'i' || *f == 'D' || *f == 'U' || *f == 'u'
			|| *f == 'o' || *f == 'O' || *f == 'x' || *f == 'X')
		return (ft_typeinteger(f));
	if (*f == 'p')
		return (&ft_putadr_fdr);
	return (NULL);
}

/*
** faire un cast specifique a chaque longueur
*/

ssize_t					ft_printdata(const char *t, uintmax_t data, int fd)
{
	if (*t == 'U' || *t == 'u' || *t == 'o' || *t == 'O' || *t == 'x'
			|| *t == 'X')
		return (ft_type(t)(data, fd));
	else if (*t == 'd' || *t == 'i' || *t == 'D')
		return (ft_type(t)(data, fd));
	else
		return (ft_type(t)(data, fd));
}
