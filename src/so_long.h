/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:50 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/31 12:55:45 by vcodrean         ###   ########.fr       */
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
typedef struct  s_mlx
{
    void    *mlx;
    void    *win;
    void   *img_w;
    void   *img_s;
    void   *img_chr;
    void    *cell;
    void    *wall;
    void   *img_col;
    void   *img_exit;
    void   *img_enemy;
} t_mlx;

typedef struct s_matrix
{
    int pos_x;
    int pos_y;
    char value;
    int border;
    
}   t_matrix;

typedef struct s_sprite
{
    int		steps;
	int		steps_flag;
	int		pos;
	void	*player_front;
	void	*player_back;
	void	*player_right;
	void	*player_left;
}   t_sprite;

typedef struct s_lama
{
	int		x;
	int		y;
}	t_lama;

typedef struct s_game
{
    t_matrix    **matrix;
    t_mlx       mlx;
    t_lama      lama;
    int         collectibles;
    int         exit;
    int         player;
    t_sprite    sprite;
    int			frames;
	int			steps;
    
} t_game;

//main
int     main(int argc, char **argv);

//map
void    valid_map(char *map);
void    find_map_size(char *map, int *x, int *y);
void    find_map_size_y(char *map, int x, int *y);
 int	check_cur(t_game *game, int i, int j);
 void	fill(t_game *game, int i, int j);
 int	check_collect(t_game *game, int x, int y);
 int	complete_path(t_game *game, int x, int y);
int    valid_path(int x, int y, t_game  *game);

//matrix NEO IS ALIVE
void    creat_grid(char *map, int x, int y, t_matrix **matrix);
void    grid_corners(int x, int y, t_matrix **matrix);
void    borders(int x, int y, t_matrix **matrix);
void    read_map(int x, int y, t_game *game);
void    free_memory(t_matrix **matrix);
void    read_grid(int x, int y, t_game *game);

//Errors
void    map_error(int num);
void    matrix_error(t_matrix   **matrix);
void    error_free(int num, t_matrix **matrix);

//work with img
void    set_img(t_mlx *mlx);
void    put_img(t_game  *game,int x, int y);
void    image(t_game *game,int  x_pos, int y_pos);

//hooks
int hook_loop(t_game *game);
int	close_esc(t_mlx *mlx);

//movements
void    set_xpm(t_game *game);
void	map_xpm(t_game *game);
void set_player(t_game *game);
void *valid_xpm(t_game *game, char *str);


int	movement(t_game *game, int x, int y);
void	key_a(t_game *game);
void	key_d(t_game *game);
void	key_w(t_game *game);
void	key_s(t_game *game);
int	key_event(int key_code, t_game *game);


#endif
