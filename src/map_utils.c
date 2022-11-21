/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:36:59 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 05:45:23 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* returns the map width as an int, assuming that the map is valid
** it only scans the first line */
int	ft_get_map_width(char *map_contents)
{
	int	i;

	i = 0;
	while (map_contents[i] && map_contents[i] != '\n')
		i++;
	return (i);
}

/* returns the map height as an int, assuming that the map is valid */
int	ft_get_map_height(char *map_contents)
{
	int	height;

	height = 0;
	if (*map_contents && ft_is_map_node(*map_contents))
		height = 1;
	while (*map_contents)
	{
		if (*map_contents == '\n' && ft_is_map_node(*(map_contents + 1)))
			height++;
		map_contents++;
	}
	return (height);
}

/* returns 1 if the character c is a valid map character, 0 if not */
char	ft_is_map_node(char c)
{
	if (c == '0' || c == '1' || c == 'C' || c == 'E' || c == 'P')
		return (1);
	return (0);
}

int	ft_count_coins(t_program *p)
{
	int	coin_count;
	int	i;

	coin_count = 0;
	i = 0;
	while (p->map_contents[i])
	{
		if (p->map_contents[i] == 'C')
			coin_count++;
		i++;
	}
	return (coin_count);
}
