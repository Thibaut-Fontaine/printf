/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:05:27 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/07 21:35:27 by tfontain         ###   ########.fr       */
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

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_vdprintf(int fd, const char *format, va_list ap);

int					ft_issigned(char format_c);
int					ft_whichsign(intmax_t i);
const char			*ft_gettype(const char *s);
void				(*ft_type(const char *f))();

#endif
