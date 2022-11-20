/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:39:53 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/19 17:02:30 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* checks if argc == 2, and the map file format; then opens the map file and 
** inputs its' contents into map_contents which it returns */
char	*ft_check_errors(int argc, char **argv, t_program *program)
{
	char	*map_contents;

	if (argc != 2)
	{
		ft_printf("Error\nSo_long expects 1 argument, but got %d", argc - 1);
		exit(SO_LONG_ERROR);
	}
	if (!ft_check_file_format(argv[1]))
	{
		ft_print_error("Invalid file format, file must have a .ber extension");
		exit(0);
	}
	map_contents = ft_read_map_file(program, argv[1]);
	program->map_contents_alloc = 1;
	if (!ft_map_is_valid(map_contents))
	{
		ft_free_program(program);
		ft_printf("Map is not valid\n");
		exit(SO_LONG_ERROR);
	}
	return (map_contents);
}

void	ft_init_program(int argc, char **argv, t_program *p)
{
	p->map_alloc = 0;
	p->map_contents_alloc = 0;
	p->wall_alloc = 0;
	p->player_alloc = 0;
	p->key_alloc = 0;
	p->door_alloc = 0;
	p->floor_alloc = 0;
	p->map_contents = ft_check_errors(argc, argv, p);
	p->m_w = ft_get_map_width(p->map_contents);
	p->m_h = ft_get_map_height(p->map_contents);
	p->map = ft_load_game_map(p, p->map_contents);
	ft_init_mlx(p);
	ft_create_images(p);
	p->i_s = IMAGE_SIZE;
	p->coins = 0;
	p->movements = 0;
}

int	main(int argc, char **argv)
{
	t_program program;

	ft_init_program(argc, argv, &program);
	/* mlx_loop(program.mlx);
	mlx_hook(program.window, KeyPress, KeyPressMask, ft_handle_input, (void *) &program);
	mlx_hook(program.window, \
	DestroyNotify, ButtonPressMask, ft_close_game, (void *) &program);
	mlx_hook(program.window, Expose, ExposureMask, ft_render_map, (void *) &program);
	mlx_loop(program.mlx);
	ft_free_program(&program); */
	return (0);
}
