/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:39:53 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/24 21:13:50 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* checks if argc == 2, and the map file format; then opens the map file and 
** inputs its' contents into map_contents which it returns */
char	*ft_initialize(int argc, char **argv)
{
	char	*map_contents;

	if (argc != 2)
	{
		ft_printf("Error\nSo_long expects 1 argument, but got %d\n", argc - 1);
		exit(SO_LONG_ERROR);
	}
	if (!ft_check_file_format(argv[1]))
	{
		ft_print_error("Invalid file format, file must have a .ber extension");
		exit(0);
	}
	map_contents = ft_read_map_file(argv[1]);
	return (map_contents);
}

int	main(int argc, char **argv)
{
	void	*mlx_ptr;
	void	*mlx_win;
	char	*map_contents;

	map_contents = ft_initialize(argc, argv);
	ft_check_errors_main(map_contents);
	mlx_ptr = mlx_init();
	if (mlx_ptr == NULL)
		return (SO_LONG_ERROR);
	mlx_win = mlx_new_window(mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "So_long");
	if (mlx_win == NULL)
	{
		ft_free_void(&mlx_ptr);
		return (SO_LONG_ERROR);
	}
	sleep(2);
	ft_close(&mlx_ptr, &mlx_win);
	return (0);
}