/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:54:17 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/16 23:21:11 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX_ERROR -1
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"

# define WINDOW_WIDTH 800
# define WINDOW_HEIGHT 600

/* utils.c */
void	ft_free_void(void **ptr);
void	ft_print_error(char *error_message);

/* map_utils.c */
char	ft_get_map_width(char *map_contents);
char	ft_get_map_height(char *map_contents);

/* map_validations.c */
char	ft_check_file_format(char *map_name);
char	ft_check_nodes_present(char *map_contents);
char	ft_map_is_rectangular(char *map_contents);
char	ft_map_no_other_nodes(char *map_contents);
char	ft_map_minimum_size(char *map_contents);

/* map_validations_two.c */
char	ft_map_is_valid(char *map_name, char *map_contents);
char	ft_map_is_valid_second(char *map_name, char *map_contents);
char	ft_only_one_starting_pos(char *map_contents);

/* wall_checker.c */
char	ft_line_only_walls(char *map_contents);
char	ft_column_only_walls(char *map_contents, int i, int map_width, char *which);
char	ft_surrounded_walls(char *map_contents);

/* error_handling.c */
char	ft_check_errors_main(int argc, char *map_name, char *map_contents);

/* mlx_utils.c */
void	ft_close(void **mlx_ptr, void **mlx_win);

#endif