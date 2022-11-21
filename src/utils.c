/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:32:41 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 08:20:10 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*
** frees the allocated memory at ptr, and sets it to NULL to prevent segfaults
** caused by any further accidental access of the memory stored at ptr 
*/
void	ft_free_void(void **ptr)
{
	free(*ptr);
	*ptr = NULL;
}

/*
** prints the error message
*/
void	ft_print_error(char *error_message)
{
	ft_printf("Error\n%s\n", error_message);
}

/*
**opens the file file_name with specified flags, handles potential errors
** and prints an appropriate error message
*/
int	ft_open(char *file_name, int flags,t_program *p)
{
	int	fd;

	fd = open(file_name, flags);
	if (fd == -1)
	{
		ft_printf("Error\nFile could not be opened\n");
		ft_close(p, SO_LONG_ERROR);
	}
	return (fd);
}
/*
** prints the number of movements the player made to the shell and the window
*/
void	ft_print_movements(t_program *program)
{
	char	*movements;
	char	*sentence;

	movements = ft_itoa(program->movements);
	sentence = ft_strjoin("Movements: ", movements);
	ft_printf("%s\n", sentence);
	mlx_string_put(program->mlx, program->window, 45, 38, 0, sentence);
	free(movements);
	free(sentence);
}
