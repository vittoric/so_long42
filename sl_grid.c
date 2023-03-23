/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:33:27 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/23 19:11:25 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    creat_grid(char *map, int x, int y, t_matrix **matrix)
{
    char *str;
    int map_fd;
    int rowcol[2];

    map_fd = open(map, O_RDONLY);
    if (map_fd == -1)
        map_error(1);
    rowcol[0] = 0;
    while (rowcol[0] < x)
    {
        str = get_next_line(map_fd);
        rowcol[1] = 0;       
        matrix[rowcol[0]] = malloc(sizeof(t_matrix ) * y);
        if (!matrix[rowcol[0]])
            matrix_error(matrix);
        while (rowcol[1] < y)
        {
            matrix[rowcol[0]][rowcol[1]].pos_x = rowcol[0];
            matrix[rowcol[0]][rowcol[1]].pos_y = rowcol[1];
            matrix[rowcol[0]][rowcol[1]].value = str[rowcol[1]];
            rowcol[1]++;
            //borar esto
            printf("MATRIZ y %d\n", rowcol[0]);
        }
        free(str);
        rowcol[0]++;
        //borrar
        printf("MATRIZ x %d\n", rowcol[0]);
    }
    
}

void    grid_corners(int x, int y, t_matrix **matrix)
{
    int i;
    int j;
    
    i = 0;
    while (i < x)
    {
        j = 0;
        while (j < y)
        {
            if (matrix[i][j].pos_x == 0 || matrix[i][j].pos_x == x - 1 || matrix[i][j].pos_y == 0 || matrix[i][j].pos_y == y - 1)
               { matrix[i][j].border = 1;
                //printf("\npos_x %d pos_y %d  border: %d\n", matrix[i][j].pos_x, matrix[i][j].pos_y, matrix[i][j].border);
                }
            else
               { matrix[i][j].border = 0;
                //printf("\nbucle grid_corners");
                }
            j++;                
        }
        i++;
    }
}

void    borders(int x, int y, t_matrix **matrix)
{
    int i;
    int j;
    
    i = 0;
    while (i < x)
    {
        j = 0;
        while (j < y)
        {
            if (matrix[i][j].border == 1)
                if (matrix[i][j].value != 49)
                {printf("\nAQUI");
                    error_free(0, matrix);}
            j++;
        }
        i++;
    }
}

void    read_map(int x, int y, t_game *game)
{
    int i;
    int j;

    i = 0;
    while (i < x)
    {
        j = 0;
        while (j < y)
        {
            if (game->matrix[i][j].value != 'C' &&
                game->matrix[i][j].value != 'P' &&
                game->matrix[i][j].value != 'E'&&
                game->matrix[i][j].value != '0' &&
                game->matrix[i][j].value != '1')
                error_free(1, game->matrix);
            
        }
        
    }
}

void    read_grid(int x, int y, t_game *game)
{
    int i;
    int j;

    i = 0;
    game->collectibles = 0;
    game->player = 0;
    game->exit = 0;
    while (i < x)
    {
        j = 0;
        while (j < y)
        {
            if (game->matrix[j][i].value == 'C')
                game->collectibles++;
            if (game->matrix[j][i].value == 'P')
                game->player++;
            if (game->matrix[j][i].value == 'E')
                game->exit++;
            j++;
            printf("COL %d\nplayers %d\n exit %d\n", game->collectibles,game->player,game->exit);
        }
        i++;
    }
    //if (game->exit !=)
}