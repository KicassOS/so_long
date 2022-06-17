/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 20:17:09 by pszleper          #+#    #+#             */
/*   Updated: 2022/01/16 18:28:14 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_printf(const char *format, ...);

int		ft_strlcpy(char *dst, const char *src, size_t dstsize);

int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putstr_hex(char *str);
int		ft_putstr_address(char *str);

int		ft_putnbr_unsigned(unsigned int n);
int		ft_putnbr(int n);
int		ft_putaddress(void *ptr);
int		ft_putpointer(void *ptr);
int		ft_puthex_upper(unsigned int to_convert);
int		ft_puthex_lower(unsigned int to_convert);

int		ft_intlen(int n);
int		ft_unsigned_intlen(unsigned int n);
size_t	ft_strlen(char *str);
int		ft_strncmp(char *s1, char *s2, size_t n);

#endif
