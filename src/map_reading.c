/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 14:51:27 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 18:53:50 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/* returns the map file's length as a size_t, this is used to allocate the
** right number of bytes for the map_contents in ft_read_map_file */
size_t	ft_get_map_length(char *map_name, t_program *p)
{
	int		fd;
	char	*line;
	size_t	length;

	length = 0;
	fd = ft_open(map_name, O_RDONLY, p);
	line = get_next_line(fd, p);
	while (line)
	{
		length += ft_strlen(line);
		ft_free_void((void *) &line);
		line = get_next_line(fd, p);
	}
	ft_free_void((void *) &line);
	close(fd);
	return (length);
}

char	*ft_alloc_map_contents(t_program *p, char *m_name)
{
	char	*map_contents;

	map_contents = ft_calloc(ft_get_map_length(m_name, p) + 1, sizeof(char));
	if (map_contents == NULL)
	{
		ft_printf("Error\nCould not allocate memory for map_contents\n");
		ft_close(p, SO_LONG_ERROR);
	}
	return (map_contents);
}

/* opens the map file and allocates the memory for map_contents
** then, it reads the map using get_next_line and fills the allocated
** memory with the map's contents which it returns */
char	*ft_read_map_file(t_program *program, char *map_name)
{
	char	*map_contents;
	int		fd;
	int		i;
	int		j;
	char	*line;

	map_contents = ft_alloc_map_contents(program, map_name);
	fd = ft_open(map_name, O_RDONLY, program);
	line = get_next_line(fd, program);
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
		line = get_next_line(fd, program);
	}
	ft_free_void((void *) &line);
	return (map_contents);
}
