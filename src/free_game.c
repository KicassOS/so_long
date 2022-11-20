/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 06:03:01 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/20 19:10:33 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy_images(t_program *program)
{
	if (program->floor_alloc == 1)
		mlx_destroy_image(program->mlx, program->floor_image);
	if (program->player_alloc == 1)
		mlx_destroy_image(program->mlx, program->player_image);
	if (program->wall_alloc == 1)
		mlx_destroy_image(program->mlx, program->wall_image);
	if (program->key_alloc == 1)
		mlx_destroy_image(program->mlx, program->key_image);
	if (program->door_alloc == 1)
		mlx_destroy_image(program->mlx, program->door_image);
}

void	ft_free_map(t_program *p)
{
	int	i;

	i = 0;
	if (p->map_alloc == 0)
		return ;
	while (i < p->m_w)
	{
		free(p->map[i]);
		i++;
	}
	free(p->map);
}

void	ft_free_program(t_program *program)
{
	ft_destroy_images(program);
	if (program->map_contents_alloc == 1)
		free(program->map_contents);
	if (program->map_alloc == 1)
		ft_free_map(program);
	if (program->win_created == 1)
		mlx_destroy_display(program->mlx);
	if (program->mlx_alloc == 1)
		free(program->mlx);
}
