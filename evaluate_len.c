/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   evaluate_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 18:01:28 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/18 12:05:05 by tfontain         ###   ########.fr       */
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
		return (ft_evaluatepint((long int)data));
	if (*t == 'd' || *t == 'i')
	{
		if (*(t - 1) == 'h')
		{
			if (*(t - 2) == 'h')
				return (ft_evaluatepint((char)data));
			else
				return (ft_evaluatepint((short int)data));
		}
		if (*(t - 1) == 'l' || *(t - 1) == 'j' || *(t - 1) == 'z')
			return (ft_evaluatepint((long int)data));
		return (ft_evaluatepint((int)data));
	}
	return (0);
}

size_t			ft_evaluate_uint(const char *t, uintmax_t data)
{
	if (*t == 'U' || *t == 'O')
		return (ft_evaluatepbase((unsigned long int)data, *t == 'U' ? 10 : 8));
	if (*t == 'u' || *t == 'o' || *t == 'x' || *t == 'X')
	{
		if (*(t - 1) == 'h')
		{
			if (*(t - 2) == 'h')
				return (ft_evaluatepbase((unsigned char)data,
							*t == 'X' || *t == 'x' ? 16 :
							((*t == 'u') * 10 + (*t == 'o') * 8)));
			else
				return (ft_evaluatepbase((unsigned short int)data,
							*t == 'X' || *t == 'x' ? 16 :
							((*t == 'u') * 10 + (*t == 'o') * 8)));
		}
		if (*(t - 1) == 'l' || *(t - 1) == 'j' || *(t - 1) == 'z')
			return (ft_evaluatepbase((unsigned long int)data,
						*t == 'X' || *t == 'x' ? 16 :
						((*t == 'u') * 10 + (*t == 'o') * 8)));
		return (ft_evaluatepbase((unsigned int)data, *t == 'X' || *t == 'x' ?
					16 : ((*t == 'u') * 10 + (*t == 'o') * 8)));
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
	return (0);
}

size_t			ft_evaluate_string(const char *t, uintmax_t data)
{
	size_t		ret;
	wchar_t		*pt;

	if (*t == 's' && *(t - 1) != 'l')
		return (ft_strlen((char*)data));
	pt = (wchar_t*)data;
	ret = 0;
	while (*pt)
	{
		ret += ft_evaluate_char(t, *pt);
		++pt;
	}
	return (ret);
}

size_t			ft_evaluate_len(const char *t, uintmax_t data, int precision)
{
	size_t		r;

	if (*t == 'U' || *t == 'u' || *t == 'o' || *t == 'O' || *t == 'x'
			|| *t == 'X')
		return ((int)(r = ft_evaluate_uint(t, data)) < precision ?
				precision : r);
	else if (*t == 'd' || *t == 'i' || *t == 'D')
		return ((int)(r = ft_evaluate_int(t, data)) < precision ?
				precision : r);
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
