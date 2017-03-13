# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfontain <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/05 04:52:55 by tfontain          #+#    #+#              #
#    Updated: 2017/03/13 02:35:32 by tfontain         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = clang
HEADER = ./printf.h
FLAG = -Wall -Wextra -Werror
OPTION = -c -I $(HEADER)
SRC = ./cast.c ./funcs.c ./gettype.c ./main_funcs.c ./putint.c ./vd_printf.c

OBJ = $(addsuffix .o,$(basename $(SRC)))

.PHONY : all clean fclean re

all : $(NAME)

$(NAME) : $(OBJ)
		make -C libft/
		cp libft/libft.a ./$(NAME)
		ar rc $(NAME) $(OBJ)
		ranlib $(NAME)

%.o : %.c
	$(CC) $(FLAG) $(OPTION) -c $< -o $@

clean :
		make -C libft/ clean
		rm -f $(OBJ)
fclean : clean
		make -C libft/ fclean
		rm -f $(NAME)

re : fclean all
