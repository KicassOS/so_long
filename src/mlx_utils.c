/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:57:20 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/19 00:12:43 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* function for destroying the window, the display and freeing any
** allocated memory */
void	ft_close(t_program *program)
{
	mlx_destroy_window(program->mlx, program->window);
}

int	ft_esc_close(void *param)
{
	ft_close(param);
	return (0);
}

void	*ft_new_sprite(t_program *p, char *path)
{
	void	*sprite;

	sprite = mlx_xpm_file_to_image(p->mlx, path, &p->i_s, &p->i_s);
	if (sprite == NULL)
	{
		ft_print_error("Sprite could not be created");
		ft_destroy_images(p);
		exit(SO_LONG_ERROR);
	}
	return (sprite);
}

void	ft_create_images(t_program *p)
{
	p->wall_image = ft_new_sprite(p, "assets/images/wall.xpm");
	p->player_image = ft_new_sprite(p, "assets/images/player.xpm");
	p->key_image = ft_new_sprite(p, "assets/images/key.xpm");
	p->floor_image = ft_new_sprite(p, "assets/images/floor.xpm");
	p->door_image = ft_new_sprite(p, "assets/images/door.xpm");
}