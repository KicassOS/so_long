/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 21:41:47 by pszleper          #+#    #+#             */
/*   Updated: 2022/08/20 00:00:28 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_is_space(char c)
{
	return (c == '\f' || c == '\n' || c == '\r' || c == '\t' || c == '\v'
		|| c == ' ');
}