/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 15:32:02 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/24 14:38:52 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_errors_main(char *map_contents)
{
	if (!ft_map_is_valid(map_contents))
		exit(MLX_ERROR);
}
