/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typeint.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 08:45:23 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/11 17:19:56 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** renvoie un pointeur sur fonction du genre ssize_t (type i, int fd)
** exemple :
**			ssize_t ft_putuint32_fd(uint32_t i, int fd);
*/

ssize_t				ft_putint_fdr(intmax_t i, int fd)
{
	return (ft_putnbr_fdr(i, fd));
}
ssize_t				ft_putuint_fdr(uintmax_t i, int fd)
{
	return (ft_putnbr_fdr(i, fd));
}
ssize_t				ft_putoct_fdr(uintmax_t i, int fd)
{
	return (ft_putnbr_fdr(i, fd));
}
ssize_t				ft_puthex_fdr(uintmax_t i, int fd)
{
	return (ft_putnbr_fdr(i, fd));
}
ssize_t				ft_puthexx_fdr(uintmax_t i, int fd)
{
	return (ft_putnbr_fdr(i, fd));
}

/*
ssize_t		(*ft_typeint(const char *f))()
{
	if (*f == 'D')
		return (&ft_putint64_fd);
	if (*f == 'd' || *f == 'i')
	{
		if (*(f - 1) == 'h')
		{
			if (*(f - 2) == 'h')
				return (&ft_putint8_fd);
			else
				return (&ft_putint16_fd);
		}
		if (*(f - 1) == '%')
			return (&ft_putint32_fd);
		if (*(f - 1) == 'l' || *(f - 1) == 'j' || *(f - 1) == 'z')
			return (&ft_putint64_fd);
	}
}

ssize_t		(*ft_typeuint(const char *f))()
{
	if (*f == 'U')
		return (&ft_putuint64_fd);
	if (*f == 'u')
	{
		if (*(f - 1) == 'h')
		{
			if (*(f - 2) == 'h')
				return (&ft_putuint8_fd);
			else
				return (&ft_putuint16_fd);
		}
		if (*(f - 1) == '%')
			return (&ft_putuint32_fd);
		if (*(f - 1) == 'l' || *(f - 1) == 'j' || *(f - 1) == 'z')
			return (&ft_putuint64_fd);
	}
}

ssize_t		(*ft_typeoct(const char *f))()
{
	if (*f == 'O')
		return (&ft_putoct64_fd);
	if (*f == 'o')
	{
		if (*(f - 1) == 'h')
		{
			if (*(f - 2) == 'h')
				return (&ft_putoct8_fd);
			else
				return (&ft_putoct16_fd);
		}
		if (*(f - 1) == '%')
			return (&ft_putoct32_fd);
		if (*(f - 1) == 'l' || *(f - 1) == 'j' || *(f - 1) == 'z')
			return (&ft_putoct64_fd);
	}
}

ssize_t		(*ft_typehex(const char *f))()
{
	if (*f == 'x')
	{
		if (*(f - 1) == 'h')
		{
			if (*(f - 2) == 'h')
				return (&ft_puthex8_fd);
			else
				return (&ft_puthex16_fd);
		}
		if (*(f - 1) == '%')
			return (&ft_puthex32_fd);
		if (*(f - 1) == 'l' || *(f - 1) == 'j' || *(f - 1) == 'z')
			return (&ft_puthex64_fd);
	}
}

ssize_t		(*ft_typehexx(const char *f))()
{
	if (*f == 'X')
	{
		if (*(f - 1) == 'h')
		{
			if (*(f - 2) == 'h')
				return (&ft_putheX8_fd);
			else
				return (&ft_putheX16_fd);
		}
		if (*(f - 1) == '%')
			return (&ft_putheX32_fd);
		if (*(f - 1) == 'l' || *(f - 1) == 'j' || *(f - 1) == 'z')
			return (&ft_putheX64_fd);
	}
}*/
