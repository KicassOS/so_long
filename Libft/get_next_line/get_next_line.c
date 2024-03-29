/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 16:24:56 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 18:53:04 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"
#include "../libft.h"

char	*ft_handle_alloc_error(void *program)
{
	ft_print_error("Could not allocate memory for get_next_line");
	ft_close(program, SO_LONG_ERROR);
	return (NULL);
}

// buffer is used to store the result of read
// bytes_read is fed into strndup and strnjoin to prevent segfaults
// and is also used for error checking
// line stores the past reads who didnt contain a NL
// position is -1 if no '\n' is found and is -2 if line is NULL
// it is used to determine if we've read the whole line or not
char	*get_next_line(int fd, void *program)
{
	static char	*line;
	char		*buffer;
	long long	position;
	long long	bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = NULL;
	position = ft_strchr_flag(line, '\n', 0);
	bytes_read = 0;
	while (position == -1 && position != -2)
	{
		buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer)
			return (ft_handle_alloc_error(program));
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
			break ;
		line = ft_strnjoin(line, buffer, bytes_read, program);
		position = ft_strchr_flag(line, '\n', 1);
		ft_free((void **)&buffer);
	}
	ft_free((void **)&buffer);
	return (ft_output(&line, position, bytes_read, program));
}

// stores characters until EOF or NL is found
// calls ft_update_nl if the NL is found and the whole line hasn't been read
char	*ft_output(char **line, int position, int bytes_read, void *program)
{
	char	*current_line;

	if (((bytes_read == 0 || bytes_read == -1) && !*line) || position == -5)
	{
		if (*line)
			return (*line);
		return (NULL);
	}
	if (position == -1)
		position = ft_strlen(*line);
	else
		position++;
	current_line = ft_strndup(*line, position, program);
	if (position == (int) ft_strlen(*line))
		ft_free((void **)line);
	else
		*line = ft_update_nl_pos(line, position, program);
	return (current_line);
}

// glues the remainder of the line to what was previously allocated
char	*ft_update_nl_pos(char **line, int position, void *program)
{
	char	*tmp;
	int		len;

	len = ft_strlen(*line) - position;
	tmp = ft_strndup(*line + position, len, program);
	ft_free((void **)line);
	*line = tmp;
	return (*line);
}

// same as libft, but only copies n characters
// once again to be safe against segfaults
char	*ft_strndup(char *input, int n, void *program)
{
	char	*output;
	int		len;
	int		i;

	i = 0;
	len = n;
	output = malloc(len + 1);
	if (!output)
		return (ft_handle_alloc_error(program));
	while (input && input[i] && i < n)
	{
		output[i] = input[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}
