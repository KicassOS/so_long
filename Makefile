# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 19:22:49 by pszleper          #+#    #+#              #
#    Updated: 2022/07/31 13:47:41 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = so_long

HEADER = src/so_long.h Libft/libft.h

SRC = $(addprefix src/, so_long.c utils.c map_validations.c error_handling.c \
	map_validations_two.c map_reading.c map_utils.c mlx_utils.c wall_checker.c \
	mlx_events.c)

OBJECTS = $(addprefix objects/, so_long.o utils.o map_validations.o error_handling.o \
	map_validations_two.o map_reading.o map_utils.o mlx_utils.o wall_checker.o \
	mlx_events.o)

all: libmlx_Linux.a libft.a $(NAME)

$(NAME): libmlx_Linux.a libft.a $(OBJECTS)
	$(CC) $(OBJECTS) libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

objects/%.o: src/%.c
	mkdir -p objects
	$(CC) $(FLAGS) $(HEADER) -I/usr/include -Imlx_linux $< -c
	mv *.o objects/

libmlx_Linux.a:
	make -C mlx_linux
	cp mlx_linux/libmlx_Linux.a .
	cp mlx_linux/mlx.h ./src

libft.a:
	make -C Libft
	cp Libft/libft.a ./src
	cp Libft/libft.h ./src
	mv Libft/libft.a .

clean:
	rm -f *.o
	rm -f objects/*.o
	make -C Libft fclean

fclean: clean
	rm -f $(NAME)
	rm -f libft.a

re: fclean all