# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaseris <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:05:02 by akaseris          #+#    #+#              #
#    Updated: 2018/01/26 14:24:52 by akaseris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FT = ft_printf

FLAGS = -Wall -Werror -Wextra

FT_C = $(patsubst %,%.c,$(FT))

FT_O = $(patsubst %,%.o,$(FT))

.PHONY: all clean fclean re

all: $(NAME)

$(FT_O): 
	gcc $(FLAGS) -c $(FT_C)

$(NAME): $(FT_O)
		ar rc $(NAME) $(FT_O)
		ranlib $(NAME)

clean:
	/bin/rm -f $(FT_O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

