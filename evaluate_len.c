/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:01:28 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/16 20:41:14 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** evaluate the len of the caracs who will be write from data,
** including the precision.
*/

ssize_t			ft_evaluate_int(const char *t, uintmax_t data)
{
	if (*t == 'D')
		return (ft_type(t)((long int)data, fd));
	if (*t == 'd' || *t == 'i')
	{
		if (*(t - 1) == 'h')
		{
			if (*(t - 2) == 'h')
				return (ft_type(t)((char)data, fd));
			else
				return (ft_type(t)((short int)data, fd));
		}
		if (*(t - 1) == 'l' || *(t - 1) == 'j' || *(t - 1) == 'z')
			return (ft_type(t)((long int)data, fd));
		return (ft_type(t)((int)data, fd));
	}
	return (0);
}

size_t			ft_evaluate_uint(const char *t, uintmax_t data)
{
	if (*t == 'U' || *t == 'O')
		return (ft_type(t)((unsigned long int)data, fd));
	if (*t == 'u' || *t == 'o' || *t == 'x' || *t == 'X')
	{
		if (*(t - 1) == 'h')
		{
			if (*(t - 2) == 'h')
				return (ft_type(t)((unsigned char)data, fd));
			else
				return (ft_type(t)((unsigned short int)data, fd));
		}
		if (*(t - 1) == 'l' || *(t - 1) == 'j' || *(t - 1) == 'z')
			return (ft_type(t)((unsigned long int)data, fd));
		return (ft_type(t)((unsigned int)data, fd));
	}
	return (0);
}

size_t			ft_evaluate_char(const char *t, uintmax_t data)
{
	if ((*t == 'c' && *(t - 1) != 'l') || data <= 127)
		return (1);
	if (data <= 2047)
		return (2);
	if (data <= 65535)
		return (3);
	if (data <= 1114111)
		return (4);
}

size_t			ft_evaluate_string(const char *t, uintmax_t data)
{
	size_t		ret;
	wchar_t		*pt;

	if (*t == 's' && *(t - 1) != 'l') // s
		return (ft_strlen((char*)data));
	pt = (wchar_t*)data;
	ret = 0;
	ft_evaluate_char(t, *((wchar_t*)data));
}

size_t			ft_evaluate_len(const char *t, uintmax_t data, int precision)
{
	if (*t == 'U' || *t == 'u' || *t == 'o' || *t == 'O' || *t == 'x'
			|| *t == 'X')
		return (ft_evaluate_uint(t, data)); // UINT
	else if (*t == 'd' || *t == 'i' || *t == 'D')
		return (ft_evaluate_int(t, data)); // INT
	else if (*t == 'S' || *t == 's')
	{
		if (precision != -1)
			return (precision);
		return (ft_evaluate_string(t, data));
	}
	else if (*t == 'c' || *t == 'C')
		return (ft_evaluate_char(t, data));
	else if (*t == 'p')
		return (ft_evaluate_uint("X", data) + 2);
	else
		return (0);
}
