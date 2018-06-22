# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 16:54:43 by cbrill            #+#    #+#              #
#    Updated: 2018/06/17 17:52:35 by cbrill           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = main.c read.c solve.c board.c util.c

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

LIBFT =	src/libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) -I $(SRC_PATH) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
	@$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
	@make -C $(LPATH)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

just: re clean

.PHONY : all, re, clean, flcean, just
