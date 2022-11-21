/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations_two.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:14:22 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 17:46:22 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* returns 1 if there's only one P node in the map, 0 if not */
char	ft_only_one_starting_pos(char *map_contents)
{
	int count;

	count = 0;
	while (*map_contents)
	{
		if (*map_contents == 'P')
			count++;
		map_contents++;
	}
	if (count > 1 || count == 0)
		return (0);
	return (1);
}

/* second part of the map_validation process, returns 1 if the map is valid
** and 0 if it isn't */
char	ft_map_is_valid_second(char *map_contents, t_program *p)
{
	if (!ft_surrounded_by_walls(map_contents))
	{
		free(map_contents);
		ft_print_error("The map is not surrounded by walls");
		ft_close(p, SO_LONG_ERROR);
		return (0);
	}
	if (!ft_map_minimum_size(map_contents))
	{
		free(map_contents);
		ft_print_error("The map is impossible to play as it's size is too small");
		ft_close(p, SO_LONG_ERROR);
		return (0);
	}
	if (!ft_only_one_starting_pos(map_contents))
	{
		free(map_contents);
		ft_print_error("The map has multiple starting positions for the player");
		ft_close(p, SO_LONG_ERROR);
		return (0);
	}
	return (1);
}

/* returns 1 if the map is valid, 0 if it isn't */
char	ft_map_is_valid(char *map_contents, t_program *p)
{
	if (!ft_check_nodes_present(map_contents))
	{
		free(map_contents);
		ft_print_error("Not all nodes (1, C, E, P) are present");
		ft_close(p, SO_LONG_ERROR);
		return (0);
	}
	if (!ft_map_is_rectangular(map_contents))
	{
		free(map_contents);
		ft_print_error("The map is not rectangular");
		ft_close(p, SO_LONG_ERROR);
		return (0);
	}
	if (!ft_map_no_other_nodes(map_contents))
	{
		free(map_contents);
		ft_print_error("The map contains nodes other than 0, 1, C, E, P");
		ft_close(p, SO_LONG_ERROR);
		return (0);
	}
	if (!ft_map_is_valid_second(map_contents, p))
		return (0);
	return (1);
}
