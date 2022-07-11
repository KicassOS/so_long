/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:39:53 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/11 22:35:08 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main()
{
	void	*mlx_ptr;
	void	*mlx_win;

	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	mlx_win = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "So_long");
	if (mlx_win == NULL)
	{
		ft_free_void(&mlx_ptr);
		return (MLX_ERROR);
	}
	sleep(2);
	ft_close(&mlx_ptr, &mlx_win);
	return (0);
}

void	ft_close(void **mlx_ptr, void **mlx_win)
{
	mlx_destroy_window(*mlx_ptr, *mlx_win);
	mlx_destroy_display(*mlx_ptr);
	ft_free_void(mlx_ptr);
}