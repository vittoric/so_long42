/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:50 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/23 18:46:52 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
//# include <mlx.h>
# include "libft/libft.h"

//structs

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

#endif
