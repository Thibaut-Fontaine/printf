/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 08:58:23 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/01 09:32:13 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"

/*
** return 1 if the conversion is signed, take the conversion char in the format
*/

int			ft_issigned(char c)
{
	if (c == 'd' || c == 'D' || c == 'i')
		return (1);
	return (0);
}

/*
** return 1 if the sign is '+', 0 for '-'
** works for short int, int, long, etc. For any int.
*/

int			ft_whichsign(intmax_t i)
{
	ft_endian(i, TRUE);
	return (!!(i & (1u << 1)));
}
