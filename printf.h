/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:05:27 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/11 17:18:54 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "./libft/includes/libft.h"
# include <stdarg.h>

typedef struct		s_size
{
	size_t			print;
	size_t			conv;
}					t_size;

typedef ssize_t		(*t_ptft)();

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_vdprintf(int fd, const char *format, va_list ap);

int					ft_issigned(char format_c);
int					ft_whichsign(intmax_t i);
const char			*ft_gettype(const char *s);
ssize_t				ft_printdata(const char *t, uintmax_t data, int fd);
t_ptft				ft_type(const char *f);

/*
** same than ssize_t	(*ft_type(const char *f))();
*/

ssize_t				ft_putint_fdr(intmax_t i, int fd);
ssize_t				ft_putuint_fdr(uintmax_t i, int fd);
ssize_t				ft_putoct_fdr(uintmax_t i, int fd);
ssize_t				ft_puthex_fdr(uintmax_t i, int fd);
ssize_t				ft_puthexx_fdr(uintmax_t i, int fd);

t_ptft				ft_typeint(const char *f);
t_ptft				ft_typeuint(const char *f);
t_ptft				ft_typeoct(const char *f);
t_ptft				ft_typehex(const char *f);
t_ptft				ft_typehexx(const char *f);

#endif
