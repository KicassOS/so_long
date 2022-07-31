/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:39:53 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/31 13:50:23 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bind_events(t_program *program)
{
	mlx_hook(program->window, 17, 0, &ft_esc_close, &program);
}

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
	t_program program;

	program.map_contents = ft_initialize(argc, argv);
	ft_check_errors_main(program.map_contents);
	program.mlx = mlx_init();
	if (program.mlx == NULL)
		return (SO_LONG_ERROR);
	program.window = mlx_new_window(program.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "So_long");
	if (program.window == NULL)
	{
		ft_free_void(&program.mlx);
		return (SO_LONG_ERROR);
	}
	ft_bind_events(&program);
	mlx_loop_hook(&program.mlx, &ft_handle_no_event, &program);
	mlx_loop(program.mlx);
	mlx_destroy_display(program.mlx);
	ft_free_void(program.mlx);
	ft_free_void((void *) program.map_contents);
	return (0);
}
