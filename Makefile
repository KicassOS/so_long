# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 19:22:49 by pszleper          #+#    #+#              #
#    Updated: 2022/07/24 14:44:41 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = so_long

HEADER = src/so_long.h Libft/libft.h Libft/get_next_line/get_next_line.h \
		 Libft/ft_printf/ft_printf.h

SRC = $(addprefix src/, so_long.c utils.c map_validations.c error_handling.c mlx_utils.c)

OBJECTS = $(SRC:.c=.o)

all: libmlx_Linux.a libft.a $(NAME)

$(NAME): libmlx_Linux.a libft.a $(OBJECTS)
	$(CC) $(OBJECTS) libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(HEADER) -I/usr/include -Imlx_linux -O3 $< -c

libmlx_Linux.a:
	make -C mlx_linux
	cp mlx_linux/libmlx_Linux.a .
	cp mlx_linux/mlx.h ./src

libft.a:
	make -C Libft
	cp Libft/libft.a ./src
	cp Libft/libft.h ./src

clean:
	rm -f *.o
	make -C Libft fclean

fclean: clean
	rm -f $(NAME)

re: fclean all