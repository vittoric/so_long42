/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:33:27 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/23 12:33:40 by vcodrean         ###   ########.fr       */
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
            matrix[rowcol[0]][rowcol[1]].pos_x = rowcol[1];
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