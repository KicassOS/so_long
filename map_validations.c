/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:31:28 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/15 01:21:42 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

//returns 1 if the file ends with .ber, 0 if not
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

//returns 1 if the characters 0, 1, C, E and P are present, 0 if not
char	ft_check_nodes_present(char *map_contents)
{
	int		i;
	char	required[6];

	i = 0;
	ft_strlcpy(required, "\0\0\0\0\0\0", 6);
	while (map_contents[i])
	{
		if (map_contents[i] == '0')
			required[0] = '0';
		else if (map_contents[i] == '1')
			required[1] = '1';
		else if (map_contents[i] == 'C')
			required[2] = 'C';
		else if (map_contents[i] == 'E')
			required[3] = 'E';
		else if (map_contents[i] == 'P')
			required[4] = 'P';
		i++;
	}
	if (ft_strncmp(required, "01CEP", 5) == 0)
		return (1);
	return (0);
}

char	ft_map_is_valid(char *map_name, char *map_contents)
{
	if (!ft_check_file_format(map_name))
		return (0);
	if (!ft_check_nodes_present(map_contents))
		return (0);
	// if (!ft_map_is_rectangular(map_contents))
	// 	return (0);
	// if (!ft_map_no_other_nodes(map_contents))
	// 	return (0);
	return (1);
}
