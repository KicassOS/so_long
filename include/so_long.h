/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pszleper < pszleper@student.42.fr >        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 18:54:17 by pszleper          #+#    #+#             */
/*   Updated: 2022/11/21 15:19:17 by pszleper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>

# define IMAGE_SIZE 42
# define SO_LONG_ERROR 42

# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100

# define Q_KEY 113
# define ESC_KEY 65307

# define UP_ARROW 65362
# define LEFT_ARROW 65361
# define DOWN_ARROW 65364
# define RIGHT_ARROW 65363

typedef struct s_position
{
	int	x;
	int	y;
}	t_position;

typedef struct s_program {
	void		*mlx;
	void		*window;
	char		*map_contents;
	char		**map;
	t_position	*player_pos;
	int			m_h;
	int			m_w;
	int			i_s;
	int			movements;
	int			coins;
	void		*wall_image;
	void		*player_image;
	void		*key_image;
	void		*door_image;
	void		*floor_image;
	char		map_alloc;
	char		map_contents_alloc;
	char		wall_alloc;
	char		player_alloc;
	char		key_alloc;
	char		door_alloc;
	char		floor_alloc;
	char		mlx_alloc;
	char		win_created;
	char		playpos_alloc;
}	t_program;

/* utils.c */
void	ft_free_void(void **ptr);
void	ft_print_error(char *error_message);
int		ft_open(char *file_name, int flags, t_program *p);
void	ft_print_movements(t_program *program);

/* map_utils.c */
int		ft_get_map_width(char *map_contents);
int		ft_get_map_height(char *map_contents);
char	ft_is_map_node(char c);
int		ft_count_coins(t_program *program);

/* map_validations.c */
char	ft_check_file_format(char *map_name);
char	ft_check_nodes_present(char *map_contents);
char	ft_map_is_rectangular(char *map_contents);
char	ft_map_no_other_nodes(char *map_contents);
char	ft_map_minimum_size(char *map_contents);

/* map_validations_two.c */
char	ft_map_is_valid(char *map_contents, t_program *program);
char	ft_map_is_valid_second(char *map_contents, t_program *program);
char	ft_only_one_starting_pos(char *map_contents);

/* wall_checker.c */
char	ft_first_line_only_walls(char *map_contents);
char	ft_last_line_only_walls(char *map_contents);
char	ft_left_column_only_walls(char *map_contents);
char	ft_right_column_only_walls(char *map_contents);
char	ft_surrounded_by_walls(char *map_contents);

/*map_reading.c */
size_t	ft_get_map_length(char *map_name, t_program *p);
char	*ft_read_map_file(t_program *program, char *map_name);
char	**ft_load_game_map(t_program *p, char *map_contents);

/* mlx_utils.c */
void	ft_close(t_program *program, char exit_code);
void	ft_create_images(t_program *p);
void	ft_init_mlx(t_program *p);

/* mlx_events.c */
int		ft_handle_no_event(void	*param);

/* free_program.c */
void	ft_destroy_images(t_program *program);
void	ft_free_program(t_program *program);
void	ft_free_map(t_program *program);
int		ft_close_hook(t_program *program);
void	ft_victory(t_program *program);

/* map_rendering.c */
int		ft_render_map(t_program *program);
void	ft_check_tile(t_program *p, int x, int y);
void	ft_draw_sprite(t_program *program, void *img, int x, int y);

/* input_handling.c */
void	ft_find_player(t_program *p);
void	ft_move(t_program *p, int new_x, int new_y);
int		ft_handle_input(int	key, t_program *p);

#endif