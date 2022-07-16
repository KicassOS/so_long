/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:32:02 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/16 17:23:07 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	ft_check_errors_main(int argc, char *map_name, char *map_contents)
{
	if (argc < 2)
	{
		ft_printf("Error\nSo_long expects 1 argument, but got %d\n", argc);
		return (0);
	}
	if (!ft_map_is_valid(map_name, map_contents))
		return (0);
	return (1);
}

char	ft_map_is_valid_second(char *map_name, char *map_contents)
{
	if (!ft_map_minimum_size(map_contents))
	{
		ft_print_error("The map is impossible to play as it's size is too small");
		return (0);
	}
	return (1);
}

/* returns 1 if the map is valid, 0 if it isn't */
char	ft_map_is_valid(char *map_name, char *map_contents)
{
	if (!ft_check_file_format(map_name))
	{
		ft_print_error("Invalid file format, must end with .ber");
		return (0);
	}
	if (!ft_check_nodes_present(map_contents))
	{
		ft_print_error("Not all nodes (0, 1, C, E, P) are present");
		return (0);
	}
	if (!ft_map_is_rectangular(map_contents))
	{
		ft_print_error("The map is not rectangular");
		return (0);
	}
	if (!ft_map_no_other_nodes(map_contents))
	{
		ft_print_error("The map contains nodes other than 0, 1, C, E, P");
		return (0);
	}
	if (!ft_map_is_valid_second(map_name, map_contents))
		return (0);
	return (1);
}
