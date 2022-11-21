/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_loading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 16:04:58 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 17:59:35 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_load_column(t_program *p, char *m_col, int col_num, char *m_cont)
{
	int	i;
	int	j;

	i = 0;
	j = col_num;
	while (i < p->m_h)
	{
		m_col[i] = m_cont[j];
		j += p->m_w + 1;
		i++;
	}
	return (m_col);
}

void	ft_free_incomplete_map(char **map, int i)
{
	while (i > 0)
	{
		free(map[i]);
		i--;
	}
	free(map[i]);
}

char	**ft_load_game_map(t_program *p, char *map_contents)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (p->m_w));
	if (map == NULL)
	{
		ft_printf("Error\nCould not allocate memory for map\n");
		ft_close(p, SO_LONG_ERROR);
	}
	while (i < p->m_w)
	{
		map[i] = malloc(sizeof(char) * (p->m_h));
		if (map[i] == NULL)
		{
			ft_printf("Error\nMemory for map could not be allocated\n");
			if (i > 0)
				ft_free_incomplete_map(map, --i);
			ft_close(p, SO_LONG_ERROR);
		}
		map[i] = ft_load_column(p, map[i], i, map_contents);
		i++;
	}
	p->map_alloc = 1;
	return (map);
}
