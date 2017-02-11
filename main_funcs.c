/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_funcs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 03:30:16 by tfontain          #+#    #+#             */
/*   Updated: 2017/02/11 04:00:55 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** this file define all the functions who can be used directly by the user,
** except ft_voprintf, who is defined in the file vo_printf.c
*/

/*
** write on the std output
*/

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_vprintf(format, ap);
	va_end(ap);
	return (ret);
}

/*
** write on a specifical file descriptor
*/

int				ft_oprintf(int fd, const char *format, ...)
{
	va_list		ap;
	int			ret;

	va_start(ap, format);
	ret = ft_voprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

/*
** write on the std output, but need va_list to be started. it dosnt close it.
*/

int				ft_vprintf(const char *format, va_list ap)
{
	return (ft_voprintf(STDOUT_FILENO, format, ap));
}
