/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:12:46 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 18:49:23 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include <stdarg.h>

int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_is_space(char c);

size_t	ft_strlen(const char *s);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);

int		ft_atoi(const char *str);

int		ft_tolower(int c);
int		ft_toupper(int c);

void	*ft_calloc(size_t count, size_t size);
char	*ft_strdup(const char *s1);

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	**ft_split_whitespace(char *s);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **alst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* get_next_line.c */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd, void *program);
char	*ft_update_nl_pos(char **line, int position, void *program);
char	*ft_output(char **line, int position, int bytes_read, void *program);
char	*ft_strndup(char *input, int n, void *program);
char	*ft_handle_alloc_error(void *program);

/* get_next_line_utils.c */
int		ft_strchr_flag(char *s, int c, int flag);
void	ft_free(void **p);
char	*ft_strnjoin(char *s1, char *s2, int n, void *program);

/* ft_printf.c */
int		ft_printf(const char *format, ...);

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
int		ft_strncmp(char *s1, char *s2, size_t n);
int		ft_abs_value(int n);

#endif
