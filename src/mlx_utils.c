/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:57:20 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/18 06:03:59 by pszleper         ###   ########.fr       */
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