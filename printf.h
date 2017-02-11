/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:05:27 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/11 04:46:20 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "./libft/includes/libft.h"
# include <stdarg.h>

# ifndef _FD_
#  define _FD_ file_descriptor_printf
# endif

typedef struct		s_size
{
	size_t			print;
	size_t			conv;
}					t_size;

int					ft_printf(const char *format, ...);
int					ft_oprintf(int fd, const char *format, ...);
int					ft_vprintf(const char *format, va_list ap);
int					ft_voprintf(int fd, const char *format, va_list ap);
int					ft_output(int *fd);

#endif
