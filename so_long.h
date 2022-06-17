/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <pszleper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:54:17 by pszleper          #+#    #+#             */
/*   Updated: 2022/06/17 22:07:17 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define MLX_ERROR -1
# include <fcntl.h>
# include <unistd.h>
# include "libft.h"
# include "mlx.h"

void	ft_close(void **mlx_ptr, void **mlx_win);

#endif