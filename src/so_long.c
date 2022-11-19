/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:39:53 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/19 00:55:30 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_bind_events(t_program *program)
{
	mlx_hook(program->window, DestroyNotify, ButtonPressMask, &ft_esc_close, &program);
}

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
	if (!ft_map_is_valid(map_contents))
	{
		free(map_contents);
		ft_destroy_images(program);
		ft_print_error("Map is not valid");
		exit(SO_LONG_ERROR);
	}
	return (map_contents);
}

void	ft_init_program(int argc, char **argv, t_program *p)
{
	p->mlx = mlx_init();
	if (p->mlx == NULL)
		exit(SO_LONG_ERROR);
	ft_create_images(p);
	p->map_contents = ft_check_errors(argc, argv, p);
	p->m_w = ft_get_map_width(p->map_contents);
	p->m_h = ft_get_map_height(p->map_contents);
	p->map = ft_load_game_map(p, p->map_contents);
	p->window = mlx_new_window(p->mlx, 42 * p->m_w, 42 * p->m_h, "So_long");
	if (p->window == NULL)
	{
		ft_free_void(&p->mlx);
		ft_destroy_images(p);
		exit(SO_LONG_ERROR);
	}
	p->i_s = IMAGE_SIZE;
	p->coins = 0;
	p->movements = 0;
}

int	main(int argc, char **argv)
{
	t_program program;

	ft_init_program(argc, argv, &program);
	ft_bind_events(&program);
	mlx_put_image_to_window(program.mlx, program.window, program.player_image, 0, 0);
	mlx_put_image_to_window(program.mlx, program.window, program.key_image, 42, 0);
	mlx_put_image_to_window(program.mlx, program.window, program.door_image, 84, 0);
	mlx_put_image_to_window(program.mlx, program.window, program.floor_image, 0, 42);
	mlx_put_image_to_window(program.mlx, program.window, program.wall_image, 42, 42);
	mlx_loop_hook(&program.mlx, &ft_handle_no_event, &program);
	mlx_loop(program.mlx);
	ft_free_everything(&program);
	mlx_destroy_display(program.mlx);
	ft_free_void(program.mlx);
	ft_free_void((void *) program.map_contents);
	return (0);
}
