# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akaseris <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/08 16:05:02 by akaseris          #+#    #+#              #
#    Updated: 2018/02/28 13:38:21 by akaseris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

FT = ft_printf ft_assign ft_alpha ft_handle ft_process ft_form ft_snb1 ft_snb2 \
		ft_unb1 ft_unb2 ft_printbuf ft_sprint

LIB = libft/libft.a

SRC = src/
INC = includes/
LIBPATH = libft/
OBJ = objects/

FLAGS = -Wall -Werror -Wextra

FT_C = $(patsubst %,$(SRC)%.c,$(FT))
FT_O = $(patsubst %,%.o,$(FT))
FT_O_OBJ = $(patsubst %,$(OBJ)%.o,$(FT))

.PHONY: all clean fclean re

all: $(NAME)

$(LIB):
	make -C $(LIBPATH) all
	cp $(LIB) $(NAME)

$(FT_O_OBJ): $(LIB)
	gcc -I $(INC) $(FLAGS) -c $(FT_C)
	mkdir $(OBJ) 2> /dev/null || true
	mv $(FT_O) $(OBJ)

$(NAME): $(FT_O_OBJ)
	ar rc $(NAME) $(FT_O_OBJ)
	ranlib $(NAME)

clean:
	make -C $(LIBPATH) clean
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -f $(LIB)
	/bin/rm -f $(NAME)

re: fclean all
