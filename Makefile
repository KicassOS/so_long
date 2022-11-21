# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 19:22:49 by pszleper          #+#    #+#              #
#    Updated: 2022/11/21 19:17:45 by pszleper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = so_long

HEADER = ./include/so_long.h ./include/libft.h

SRC = $(addprefix src/, so_long.c utils.c map_validations.c \
	map_validations_two.c map_reading.c map_utils.c mlx_utils.c wall_checker.c \
	map_rendering.c input_handling.c free_game.c map_loading.c)

OBJECTS = $(addprefix objects/, so_long.o utils.o map_validations.o \
	map_validations_two.o map_reading.o map_utils.o mlx_utils.o wall_checker.o \
	map_rendering.o input_handling.o free_game.o map_loading.o)

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

libft.a:
	make -C Libft
	mv Libft/libft.a .

clean:
	rm -f */*.o
	make -C Libft clean
	rm -f */*.h.gch

fclean: clean
	make -C Libft fclean
	rm -f $(NAME)
	rm -f libft.a
	rm -f src/libft.a

re: fclean all