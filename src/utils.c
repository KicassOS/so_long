/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:32:41 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/25 10:51:33 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/* frees the allocated memory at ptr, and sets it to NULL to prevent segfaults
** caused by any further accidental access of the memory stored at ptr */
void	ft_free_void(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

/* prints the error message and exits */
void	ft_print_error(char *error_message)
{
	ft_printf("Error\n%s\n", error_message);
	exit(SO_LONG_ERROR);
}

/* opens the file file_name with specified flags, handles potential errors
** and prints an appropriate error message */
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
