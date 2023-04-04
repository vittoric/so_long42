/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:50 by vcodrean          #+#    #+#             */
/*   Updated: 2023/04/04 16:46:03 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "../gnl/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

# define XPM_ROUTE		"./xpm/"

//structs
typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*img_w;
	void	*img_s;
	void	*img_chr;
	void	*cell;
	void	*wall;
	void	*footprints;
	void	*img_col;
	void	*img_exit;
	void	*img_enemy;
}	t_mlx;

typedef struct s_matrix
{
	int		pos_x;
	int		pos_y;
	char	value;
	char	value_aux;
	int		border;

}	t_matrix;

typedef struct s_sprite
{
	int		steps;
	int		steps_flag;
	int		pos;
	void	*player_front;
	void	*player_back;
	void	*player_right;
	void	*player_left;
}	t_sprite;

typedef struct s_lama
{
	int		x;
	int		y;
}	t_lama;

typedef struct s_game
{
	t_matrix	**matrix;
	t_mlx		mlx;
	t_lama		lama;
	int			collectibles;
	int			exit;
	int			player;
	t_sprite	sprite;
	int			frames;
	int			steps;
}	t_game;

//main
int		main(int argc, char **argv);

//map
//void    valid_map(char *map);
void	valid_map(char *map, char *ext);
void	find_map_size(char *map, int *x, int *y);
void	find_map_size_y(char *map, int x, int *y);
int		check_cur(t_game *game, int i, int j);
void	fill(t_game *game, int i, int j);
int		check_collect(t_game *game, int x, int y);
int		complete_path(t_game *game, int x, int y);
int		valid_path(int x, int y, t_game *game);

//matrix NEO IS ALIVE
void	creat_grid(char *map, int x, int y, t_matrix **matrix);
void	grid_corners(int x, int y, t_matrix **matrix);
void	borders(int x, int y, t_matrix **matrix);
void	read_map(int x, int y, t_game *game);
void	free_memory(t_matrix **matrix);
void	read_grid(int x, int y, t_game *game);

//Errors
void	map_error(int num);
void	matrix_error(t_matrix **matrix);
void	error_free(int num, t_matrix **matrix);

//work with img
void	put_img(t_game *game, int x, int y);
void	image(t_game *game, int x_pos, int y_pos);

//hooks
int		hook_loop(t_game *game);
int		close_esc(t_mlx *mlx);

//movements
void	set_xpm(t_game *game);
void	map_xpm(t_game *game);
void	set_player(t_game *game);
void	*valid_xpm(t_game *game, char *str);

int		movement(t_game *game, int x, int y);
void	key_a(t_game *game);
void	key_d(t_game *game);
void	key_w(t_game *game);
void	key_s(t_game *game);
int		key_event(int key_code, t_game *game);

void	print_steps(t_game *game);
void	fill_value_aux(char *map, int x, int y, t_matrix **matrix);

void	win_game(int fd);

//===SETTINGS 	COLORS===/
//===Color font code===/
# define BLACK   "\x1B[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1B[37m"
# define ORANGE  "\x1B[38;2;255;128;0m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LBLUE   "\x1B[38;2;53;149;240m"
# define LGREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
# define RESET   "\x1b[0m"
//===Color background code===/
# define BG_BLACK   "\x1B[40m"
# define BG_RED     "\x1B[41m"
# define BG_GREEN   "\x1B[42m"
# define BG_YELLOW  "\x1B[43m"
# define BG_BLUE    "\x1B[44m"
# define BG_MAGENTA "\x1B[45m"
# define BG_CYAN    "\x1B[46m"
# define BG_WHITE   "\x1B[47m"
# define BG_ORANGE  "\x1B[48;2;255;128;0m"
# define BG_LBLUE   "\x1B[48;2;53;149;240m"
# define BG_LGREEN  "\x1B[48;2;17;245;120m"
# define BG_GRAY    "\x1B[48;2;176;174;174m"
# define BG_ROSE    "\x1B[48;2;255;151;203m"

#endif
