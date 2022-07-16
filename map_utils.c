/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:36:59 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/16 18:44:50 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* returns the map width as an int, assuming that the map is valid
** it only scans the first line */
char	ft_get_map_width(char *map_contents)
{
	int	i;

	i = 0;
	while (map_contents[i] && map_contents[i] != '\n')
		i++;
	return (i);
}

/* returns the map height as an int, assuming that the map is valid */
char	ft_get_map_height(char *map_contents)
{
	int	height;

	height = 1;
	while (*map_contents)
	{
		if (*map_contents == '\n')
			height++;
		map_contents++;
	}
}
