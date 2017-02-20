/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:05:27 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/20 16:41:05 by tfontain         ###   ########.fr       */
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

#endif
