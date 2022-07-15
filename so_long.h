/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:54:17 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/15 01:13:19 by pszleper         ###   ########.fr       */
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

void	ft_free_void(void **ptr);

char	ft_map_is_valid(char *map_name, char *map_contents);

void	ft_close(void **mlx_ptr, void **mlx_win);

#endif