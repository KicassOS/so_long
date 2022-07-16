/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:54:17 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/16 17:24:49 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX_ERROR -1
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"

# define WINDOW_WIDTH 1280
# define WINDOW_HEIGHT 720

/* utils.c */
void	ft_free_void(void **ptr);
void	ft_print_error(char *error_message);

/* map_validations.c */
char	ft_check_file_format(char *map_name);
char	ft_check_nodes_present(char *map_contents);
char	ft_map_is_rectangular(char *map_contents);
char	ft_map_no_other_nodes(char *map_contents);
char	ft_map_minimum_size(char *map_contents);

/* error_handling.c */
char	ft_check_errors_main(int argc, char *map_name, char *map_contents);
char	ft_map_is_valid(char *map_name, char *map_contents);
char	ft_map_is_valid_second(char *map_name, char *map_contents);

/* mlx_utils.c */
void	ft_close(void **mlx_ptr, void **mlx_win);

#endif