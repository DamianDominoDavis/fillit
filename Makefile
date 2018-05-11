# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/01 19:50:07 by cbrill            #+#    #+#              #
#    Updated: 2018/05/10 20:22:58 by cbrill           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c ft_countch.c ft_strfill.c ft_stripch.c ft_stripnl.c ft_strnfill.c main.c tetromino.c ft_strshift.c

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT =	src/libft/libft.a



CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
		$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
		make -C ./src/libft/

clean:
		rm -f $(OBJ)
			make clean -C ./src/libft/

fclean: clean
		rm -f $(NAME)
			make fclean -C ./src/libft/

re: fclean all

just: all clean

do: just
		./$(NAME)

.PHONY : all, re, clean, flcean, just, do
