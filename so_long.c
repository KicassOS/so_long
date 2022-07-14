/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:39:53 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/14 19:15:11 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*mlx_win;

	if (argc != 2)
	{
		ft_printf("Error\nSo_long requires 1 argument, but got: %d\n", argc - 1);
		return (MLX_ERROR);
	}
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (MLX_ERROR);
	mlx_win = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "So_long");
	if (mlx_win == NULL)
	{
		ft_free_void(&mlx_ptr);
		return (MLX_ERROR);
	}
	ft_printf("map_is_valid%d\n",ft_map_is_valid(argv[1]));
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