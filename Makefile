# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psz <psz@student.42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/17 19:22:49 by pszleper          #+#    #+#              #
#    Updated: 2022/07/13 19:03:03 by psz              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

NAME = so_long

HEADER = so_long.h Libft/libft.h Libft/get_next_line/get_next_line.h \
		 Libft/ft_printf/ft_printf.h

SRC = so_long.c utils.c

OBJECTS = $(SRC:.c=.o)

all: libmlx_Linux.a libft.a $(NAME)

$(NAME): libmlx_Linux.a libft.a $(OBJECTS)
	$(CC) $(OBJECTS) libft.a -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

%.o: %.c
	$(CC) $(FLAGS) $(HEADER) -I/usr/include -Imlx_linux -O3 $< -c

libmlx_Linux.a:
	make -C mlx_linux
	cp mlx_linux/libmlx_Linux.a .
	cp mlx_linux/mlx.h .

libft.a:
	make -C Libft
	cp Libft/libft.a .

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all