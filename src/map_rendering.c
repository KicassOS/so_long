/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_rendering.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 05:00:13 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 18:02:20 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_render_map(t_program *p)
{
	int	x;
	int	y;

	x = 0;
	while (x < p->m_w)
	{
		y = 0;
		while (y < p->m_h)
		{
			ft_check_tile(p, x, y);
			y++;
		}
		x++;
	}
	ft_print_movements(p);
	return (0);
}

void	ft_check_tile(t_program *p, int x, int y)
{
	char	tile;

	tile = p->map[x][y];
	if (tile == '0')
		ft_draw_sprite(p, p->floor_image, x, y);
	else if (tile == '1')
		ft_draw_sprite(p, p->wall_image, x, y);
	else if (tile == 'C')
		ft_draw_sprite(p, p->key_image, x, y);
	else if (tile == 'E')
		ft_draw_sprite(p, p->door_image, x, y);
	else if (tile == 'P')
		ft_draw_sprite(p, p->player_image, x, y);
}

void	ft_draw_sprite(t_program *p, void *img, int x, int y)
{
	mlx_put_image_to_window(p->mlx, p->window, img, x * p->i_s, y * p->i_s);
}
