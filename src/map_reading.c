/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:51:27 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/18 17:53:02 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* returns the map file's length as a size_t, this is used to allocate the
** right number of bytes for the map_contents in ft_read_map_file */
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
		ft_free_void((void *) &line);
		line = get_next_line(fd);
	}
	ft_free_void((void *) &line);
	close(fd);
	return (length);
}

/* opens the map file and allocates the memory for map_contents
** then, it reads the map using get_next_line and fills the allocated
** memory with the map's contents which it returns */
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
		ft_free_void((void *) &line);
		line = get_next_line(fd);
	}
	ft_free_void((void *) &line);
	return (map_contents);
}
