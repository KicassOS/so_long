/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 18:31:31 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/16 18:35:27 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* returns 1 if the current line contains only walls, 0 if not */
char	ft_line_only_walls(char *map_contents)
{
	while (*map_contents)
	{
		if (*map_contents == '\n')
			break ;
		if (*map_contents != '0')
			return (0);
	}
	return (1);
}

/* returns 1 if the "which" starting at index i contains only walls
** which is either "Left" or "Right" */
char	ft_column_only_walls(char *map_contents, int i, int map_width, char *which)
{
	int	i;

	i = 0;
	if (ft_strncmp(which, "Left", 4) == 0)
	{
		while ()
	}
	else
	{

	}
}

char	ft_surrounded_walls(char *map_contents)
{
	int	i;
	int width;

	width = 0;
	i = 0;
	while (map_contents[i] && map_contents[i] != '\n')
	{
		i++;
		width++;
	}
	i = 0;
	ft_column_only_walls()
	while (*map_contents)
	{

		map_contents++;
	}
	return (1);
}
