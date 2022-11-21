/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:57:20 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 14:25:17 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* function for destroying the window, the display and freeing any
** allocated memory */
void	ft_close(t_program *program, char exit_code)
{
	ft_free_program(program);
	exit(exit_code);
}

void	*ft_new_sprite(t_program *p, char *path)
{
	void	*sprite;

	sprite = mlx_xpm_file_to_image(p->mlx, path, &p->i_s, &p->i_s);
	if (sprite == NULL)
	{
		ft_print_error("Sprite could not be created");
		ft_close(p, SO_LONG_ERROR);
	}
	return (sprite);
}

void	ft_create_images(t_program *p)
{
	p->wall_image = ft_new_sprite(p, "assets/images/wall.xpm");
	p->wall_alloc = 1;
	p->player_image = ft_new_sprite(p, "assets/images/player.xpm");
	p->player_alloc = 1;
	p->key_image = ft_new_sprite(p, "assets/images/key.xpm");
	p->key_alloc = 1;
	p->floor_image = ft_new_sprite(p, "assets/images/floor.xpm");
	p->floor_alloc = 1;
	p->door_image = ft_new_sprite(p, "assets/images/door.xpm");
	p->door_alloc = 1;
}

void	ft_init_mlx(t_program *p)
{
	p->mlx = mlx_init();
	if (p->mlx == NULL)
	{
		ft_print_error("Could not initialize mlx pointer.");
		ft_close(p, SO_LONG_ERROR);
	}
	p->mlx_alloc = 1;
	p->window = mlx_new_window(p->mlx, p->i_s * p->m_w, \
	p->i_s * p->m_h, "So_long");
	if (p->window == NULL)
	{
		ft_print_error("Could not create the window");
		ft_close(p, SO_LONG_ERROR);
	}
	p->win_created = 1;
}
