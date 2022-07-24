/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:32:41 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/24 15:30:55 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_void(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

void	ft_print_error(char *error_message)
{
	ft_printf("Error\n%s\n", error_message);
	exit(SO_LONG_ERROR);
}

int	ft_open(char *file_name, int flags)
{
	int	fd;

	fd = open(file_name, flags);
	if (fd == -1)
	{
		perror("Error\nFile could not be opened\n");
		exit(SO_LONG_ERROR);
	}
	return (fd);
}
