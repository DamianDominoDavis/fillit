# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cbrill <cbrill@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/05 16:54:43 by cbrill            #+#    #+#              #
#    Updated: 2018/06/07 18:01:18 by cbrill           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = ft_countch.c ft_stripch.c ft_stripnl.c main.c ft_strshift.c

OBJ = $(SRC:.c=.o)

SRC_PATH = src/

SRC_POS = $(addprefix $(SRC_PATH),$(SRC))

INC = -I includes

LIBFT =	src/libft/libft.a

LPATH = src/libft

LSRC = http://github.com/DamianDominoDavis/libft

TARGET = tet.txt

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME)
	@mkdir -p $(LPATH) includes src

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(FLAGS) $(INC) $(OBJ) -o $(NAME) $(LIBFT)

$(OBJ): $(LIBFT)
	@$(CC) $(FLAGS) -c $(SRC_POS)

$(LIBFT):
	@make -C $(LPATH)

libsync:
	@rm -rf $(LPATH)
	@git clone $(LSRC) $(LPATH)
	@rm -rf $(LPATH)/._git

clean: libclean
	@rm -f $(OBJ)

libclean:
	@make clean -C $(LPATH)

fclean: clean libfclean
	@rm -f $(NAME)

libfclean:
	@make fclean -C $(LPATH)

re: fclean all

just: re clean

do: just
		./$(NAME) $(TARGET)

.PHONY : all, re, libsync, clean, libclean, flcean, libfclean, just, do
