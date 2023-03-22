/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:15:26 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/22 16:54:07 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include "so_long.h"

void    creat_matrix(char *map, int x, int y, t_matrix **matrix)
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
        //matrix[rowcol[1]] = hacer un malloc??
        //ontrol de errores si falla la matriz
        while (rowcol[1] < y)
        {
            matrix[rowcol[0]][rowcol[1]].pos_x = rowcol[0];
            matrix[rowcol[0]][rowcol[1]].pos_x = rowcol[1];
            matrix[rowcol[0]][rowcol[1]].value = str[rowcol[1]];
            rowcol[1]++;
            printf("MATRIZ y %d\n", rowcol[0]);
        }
        rowcol[0]++;
        printf("MATRIZ x %d\n", rowcol[0]);
    }
    
}

int	main(int argc, char **argv)
{
	int		x;
	int		y;
    t_game game;
  
    if (argc != 2)
    {
        //cambiar por el ft_printf
        printf("Error\nWrong number of argc\n");
        return (1);	
    }
    valid_map(argv[1]);
    find_map_size(argv[1], &x, &y);
    
    //cambiar por el ft_printf
    printf("X ES :%d\n", x);
	printf("Y ES :%d\n", y);
    
    creat_matrix(*argv, x, y, game.matrix);

    return (0);
}
