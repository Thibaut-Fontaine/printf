/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfontain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 00:42:43 by tfontain          #+#    #+#             */
/*   Updated: 2017/03/11 17:21:36 by tfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./printf.h"
#include <stdio.h>
#include "./libft/includes/libft.h"
#include <sys/types.h>
#include <limits.h>
#include "./libft/includes/libft.h"

#include <locale.h> //

int					main()
{
	char			*s = "aaaaaaaaaabbbbbbbbbbccccccccccdssseeeeeeeeeeeeeffffffffgggggggghhhhhhhhhiiiiiiiiiiijjjjjjjjjjkkkkkkkllllllllllmmmmmmmnnnnnnnnnnoooooooooppppppppppppqqqqqqqqrrrrrrrrrrsssssssssstttttttttttuuuuuuuuvvvvvvvvvvvvvvwwwwwwwwwwwxxxxxxxxxxxxxxxyyyyyyyyyyyyyyzzzzzzzzzzzzzzzzzzzzzzzzzz";

	wchar_t			*ls = L"œ∑´®†¥¨ˆøπø∆˙©ƒ∂´∑´®†¥˙∆˜∫√ç∂∂∆˜∫ √ç≈∂∂ƒ©√ç∂®©˙∫√ç≈ßß˙∆˚¬øπøˆ¨¥†®®ƒ©˙∆˙©ƒ∂ß∂†¥¨ˆøπøˆ¨¥¨ˆøπøˆ¨¥†®´∑œåß∂≈çƒ©˙∆˚¬˚µ˜∫√ç≈Ωß∂®†©˙∫√ç≈∂ƒ©˙∫√ç∂ƒgcbhewnfjdowaf bawdfn dnfmwaegnfcjemw gfncojwaems gfkwea;,gfcdw,smxnbhxhujikj˙√ƒ©˙∆˜∫©√ƒ˙∆˜∫©√˚µ˜ ∫˙∆˚ø¬";
	printf("string  : %s\nwstring : %S\npointeur : %p\n%d", s, ls, ls, 999666777);
	return (0);
}
