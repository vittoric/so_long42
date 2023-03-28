/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:50 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/28 13:07:18 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>
# include "gnl/get_next_line.h"
# include "ft_printf/ft_printf.h"
# include "libft/libft.h"

//structs
typedef struct  s_mlx
{
    void    *mlx;
    void    *win;
    void   *img_w;
    void   *img_s;
} t_mlx;

typedef struct s_matrix
{
    int pos_x;
    int pos_y;
    char value;
    int border;
    
}   t_matrix;

typedef struct s_game
{
    t_matrix    **matrix;
    t_mlx       mlx;
    int         collectibles;
    int         exit;
    int         player;
    
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

#endif
