/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:32:02 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/16 18:33:29 by pszleper         ###   ########.fr       */
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
