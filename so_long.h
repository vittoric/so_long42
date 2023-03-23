/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:44:50 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/23 12:32:57 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "gnl/get_next_line.h"
# include <mlx.h>
# include "libft.h"

//structs

typedef struct s_matrix
{
    int pos_x;
    int pos_y;
    char value;
    
}   t_matrix;

typedef struct s_game
{
    t_matrix    **matrix;
} t_game;

//main
int     main(int argc, char **argv);

//map
void    valid_map(char *map);
void    find_map_size(char *map, int *x, int *y);
void    find_map_size_y(char *map, int x, int *y);

//matrix NEO IS ALIVE
void    creat_grid(char *map, int x, int y, t_matrix **matrix);
void    free_memory(t_matrix **matrix);

//Errors
void    map_error(int num);
void    matrix_error(t_matrix   **matrix);

#endif
