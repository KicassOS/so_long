/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:51:27 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/24 21:27:14 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_get_map_length(char *map_name)
{
	int		fd;
	char	*line;
	size_t	length;

	length = 0;
	fd = ft_open(map_name, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		length += ft_strlen(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (length);
}

char	*ft_read_map_file(char *map_name)
{
	char	*map_contents;
	int		fd;
	int		i;
	int		j;
	char	*line;

	map_contents = ft_calloc(ft_get_map_length(map_name) + 1, 1);
	fd = ft_open(map_name, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		j = 0;
		while (line[j])
		{
			map_contents[i] = line[j];
			i++;
			j++;
		}
		line = get_next_line(fd);
	}
	return (map_contents);
}
