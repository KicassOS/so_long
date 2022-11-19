/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:03:01 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/19 05:34:55 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy_images(t_program *program)
{
	mlx_destroy_image(program->mlx, program->floor_image);
	mlx_destroy_image(program->mlx, program->player_image);
	mlx_destroy_image(program->mlx, program->wall_image);
	mlx_destroy_image(program->mlx, program->key_image);
	mlx_destroy_image(program->mlx, program->door_image);
}

void	ft_free_everything(t_program *program)
{
	ft_destroy_images(program);
	free(program->map_contents);
	ft_free_map(program, program->map);
	exit(0);
}

void	ft_free_map(t_program *program, char **map)
{
	int	i;

	i = 0;
	while (i < program->m_w)
	{
		free(map[i]);
		i++;
	}
}

void	ft_free_program(t_program *program)
{
	ft_destroy_images(program);
	free(program->map_contents);
	ft_free_map(program, program->map);
}
