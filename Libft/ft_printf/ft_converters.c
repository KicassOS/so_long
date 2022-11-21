/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:44:48 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 05:24:26 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_puthex_upper(unsigned int to_convert)
{
	int		printed_chars;
	char	base[17];
	char	output[9];
	int		i;

	printed_chars = 0;
	i = 8;
	ft_strlcpy(base, "0123456789ABCDEF", 17);
	while (i-- >= 0)
	{
		output[i] = base[to_convert % 16];
		to_convert /= 16;
	}
	output[8] = '\0';
	printed_chars = ft_putstr_hex(output);
	return (printed_chars);
}

int	ft_puthex_lower(unsigned int to_convert)
{
	int		printed_chars;
	char	base[17];
	char	output[9];
	int		i;

	printed_chars = 0;
	i = 8;
	ft_strlcpy(base, "0123456789abcdef", 17);
	while (i-- >= 0)
	{
		output[i] = base[to_convert % 16];
		to_convert /= 16;
	}
	output[8] = '\0';
	printed_chars = ft_putstr_hex(output);
	return (printed_chars);
}
