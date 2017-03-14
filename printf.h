/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:05:27 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/14 13:54:56 by tfontain         ###   ########.fr       */
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

typedef ssize_t		(*t_ptft)(uintmax_t d, int fd);

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_vdprintf(int fd, const char *format, va_list ap);

t_size				ft_flag(const char *s, uintmax_t data, int fd, int *flag);
int					ft_issigned(char format_c);
int					ft_whichsign(const char *s, intmax_t i);
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

ssize_t				ft_typeint(const char *t, uintmax_t data, int fd);
ssize_t				ft_typeuint(const char *t, uintmax_t data, int fd);

#endif
