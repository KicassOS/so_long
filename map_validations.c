/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:31:28 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/24 13:46:46 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* returns 1 if the file ends with .ber, 0 if not */
char	ft_check_file_format(char *map_name)
{
	char	*extension;
	int		returned;

	extension = ft_substr(map_name, ft_strlen(map_name) - 4, 4);
	returned = ft_strncmp(extension, ".ber", 4);
	free(extension);
	if (returned == 0)
		return (1);
	return (0);
}

/* returns 1 if the characters 0, 1, C, E and P are present, 0 if not */
char	ft_check_nodes_present(char *map_contents)
{
	int		i;
	char	required[5];

	i = 0;
	ft_strlcpy(required, "\0\0\0\0\0", 5);
	while (map_contents[i])
	{
		if (map_contents[i] == '1')
			required[0] = '1';
		else if (map_contents[i] == 'C')
			required[1] = 'C';
		else if (map_contents[i] == 'E')
			required[2] = 'E';
		else if (map_contents[i] == 'P')
			required[3] = 'P';
		i++;
	}
	if (ft_strncmp(required, "1CEP", 4) == 0)
		return (1);
	return (0);
}

/* returns 1 if only 0, 1, C, E and P are present, 0 if not */
char	ft_map_no_other_nodes(char *map_contents)
{
	int		i;
	char	current;

	i = 0;
	while (map_contents[i])
	{
		current = map_contents[i];
		if (current != '0' && current != '1' && current != 'C'
			&& current != 'E' && current != 'P' && current != '\n')
			return (0);
		i++;
	}
	return (1);
}

/* returns 1 if the map is rectangular, returns 0 if not
** a single line is considered a rectangle, and so is a single column */
char	ft_map_is_rectangular(char *map_contents)
{
	int	width;
	int	current;

	current = 0;
	while (*map_contents && *map_contents != '\n')
	{
		current++;
		map_contents++;
	}
	width = current;
	while (*map_contents)
	{
		if (*map_contents == '\n' && width != current)
			return (0);
		if (*map_contents == '\n' && width == current)
		{
			current = 0;
			map_contents++;
			continue ;
		}
		map_contents++;
		current++;
	}
	return (1);
}

/* returns 1 if the map's height and width are at least 3 blocks
** 0 if they're not */
char	ft_map_minimum_size(char *map_contents)
{
	int	width;
	int	height;
	
	width = ft_get_map_width(map_contents);
	height = ft_get_map_height(map_contents);
	if (width < 3 || height < 3)
		return (0);
	return (1);
}
