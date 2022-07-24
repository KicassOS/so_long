/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:57:20 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/24 23:47:39 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_close(void **mlx_ptr, void **mlx_win, char *map_contents)
{
	mlx_destroy_window(*mlx_ptr, *mlx_win);
	mlx_destroy_display(*mlx_ptr);
	ft_free_void(mlx_ptr);
	ft_free_void((void *) &map_contents);
}
