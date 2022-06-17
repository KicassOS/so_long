/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:39:53 by pszleper          #+#    #+#             */
/*   Updated: 2022/06/17 20:47:28 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	void	*mlx_ptr;
	void	*mlx_win;

	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 1920, 1080, "So_long");
	(void) mlx_win;
	sleep(2);
	ft_close(mlx_ptr, mlx_win);
	return (0);
}

void	ft_close(void *mlx_ptr, void *mlx_win)
{
	mlx_destroy_window(mlx_ptr, mlx_win);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}