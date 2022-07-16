/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 22:32:41 by pszleper          #+#    #+#             */
/*   Updated: 2022/07/16 16:52:37 by pszleper         ###   ########.fr       */
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
}
