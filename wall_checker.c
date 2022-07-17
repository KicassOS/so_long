/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:31:31 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/17 04:54:59 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* returns 1 if the first line of the map only contains walls, 0 if not
** the function assumes that the map is valid */
char	ft_first_line_only_walls(char *map_contents)
{
	while (*map_contents)
	{
		if (*map_contents == '\n')
			break ;
		if (*map_contents != '1')
			return (0);
		map_contents++;
	}
	return (1);
}

/* returns 1 if the last line of the map only contains walls, 0 if not
** the function assumes that the map is valid */
char	ft_last_line_only_walls(char *map_contents)
{
	int	i;

	i = ft_strlen(map_contents) - 1;
	if (map_contents[i] == '\n')
		i--;
	while (map_contents[i])
	{
		if (map_contents[i] == '\n')
			break ;
		if (map_contents[i] != '1')
			return (0);
		i--;
	}
	return (1);
}

/* returns 1 if the leftmost column of the map contains only walls, 0 if not
** the function assumes that the map is valid */
char	ft_left_column_only_walls(char *map_contents)
{
	int	i;

	i = 0;
	if (map_contents[i] != '1')
		return (0);
	i++;
	while (map_contents[i])
	{
		if (map_contents[i] == '\n')
			if (map_contents[i + 1] && map_contents[i + 1] != '1')
				return (0);
		i++;
	}
	return (1);
}

/* returns 1 if the rightmost column of the map contains only walls, 0 if not
** the function assumes that the map is valid */
char	ft_right_column_only_walls(char *map_contents)
{
	int	i;

	i = 0;
	while (map_contents[i])
	{
		if (map_contents[i] == '\n')
			if (map_contents[i - 1] != '1')
				return (0);
		i++;
	}
	if (map_contents[i - 1] == '\n')
		if (map_contents[i - 2] != '1')
			return (0);
	else if (map_contents[i - 1] != '1')
		return (0);
	return (1);
}

/* returns 1 if the map is surrounded by walls, 0 if it isn't */
char	ft_surrounded_by_walls(char *map_contents)
{
	if (ft_first_line_only_walls(map_contents)
		&& ft_last_line_only_walls(map_contents)
		&& ft_left_column_only_walls(map_contents)
		&& ft_right_column_only_walls(map_contents))
		return (1);
	return (0);
}
