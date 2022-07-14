/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 00:31:28 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/14 19:08:07 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

char	ft_map_is_valid(char *map_name)
{
	if (!ft_check_file_format(map_name))
		return (0);
	return (1);
}