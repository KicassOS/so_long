/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 06:06:59 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 08:59:00 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_handle_input(int	key, t_program *p)
{
	if (key == W_KEY || key == UP_ARROW)
		ft_move(p, p->player_pos->x, p->player_pos->y - 1);
	else if (key == A_KEY || key == LEFT_ARROW)
		ft_move(p, p->player_pos->x -1, p->player_pos->y);
	else if (key == S_KEY || key == DOWN_ARROW)
		ft_move(p, p->player_pos->x, p->player_pos->y + 1);
	else if (key == D_KEY || key == RIGHT_ARROW)
		ft_move(p, p->player_pos->x + 1, p->player_pos->y);
	else if (key == ESC_KEY || key == Q_KEY)
		ft_close(p, EXIT_FAILURE);
	return (0);
}

void	ft_move(t_program *p, int new_x, int new_y)
{
	int	last_x;
	int	last_y;

	last_x = p->player_pos->x;
	last_y = p->player_pos->y;
	if (p->map[new_x][new_y] == 'E' && p->coins == 0)
		ft_victory(p);
	else if (p->map[new_x][new_y] == '0' || p->map[new_x][new_y] == 'C')
	{
		p->map[last_x][last_y] = '0';
		if (p->map[new_x][new_y] == 'C')
			p->coins--;
		p->player_pos->x = new_x;
		p->player_pos->y = new_y;
		p->map[new_x][new_y] = 'P';
		p->movements++;
		ft_render_map(p);
	}
}

void	ft_search_for_player(t_program *p, t_position *pos)
{
	int	x;
	int	y;

	x = 0;
	while (x < p->m_w)
	{
		y = 0;
		while (y < p->m_h)
		{
			if (p->map[x][y] == 'P')
			{
				pos->x = x;
				pos->y = y;
				p->player_pos = pos;
				return ;
			}
			y++;
		}
		x++;
	}
	pos->x = 1;
	pos->y = 1;
	p->player_pos = pos;
}

void	ft_find_player(t_program *p)
{
	t_position	*pos;

	pos = malloc(sizeof(t_position));
	if (pos == NULL)
	{
		ft_printf("Error\nCould not allocate position\n");
		ft_close(p, SO_LONG_ERROR);
	}
	p->playpos_alloc = 1;
	ft_search_for_player(p, pos);
}
