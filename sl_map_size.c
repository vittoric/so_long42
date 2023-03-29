/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:14:10 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/29 15:24:02 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    find_map_size(char *map, int *x, int *y)
{
    int		map_fd;
    char 	*line;
	int		i;

    i = 0;
    map_fd = open(map, O_RDONLY);
   /* if (map_fd == -1)
        map_error(1);*/
	line = get_next_line(map_fd);
	//*x = strlen(line);
    while (line != 0)

    {
        printf("%s", line);
		i++;
        free(line);
		line = get_next_line(map_fd);
    }
    free(line);
	*x = i;  
    close(map_fd);
    find_map_size_y(map, *x, y);
}

void    find_map_size_y(char *map, int x, int *y)
{
    char 	*line;
    int		map_fd;
    int     i;
    int     temp;

    map_fd = open(map, O_RDONLY);
    if (map_fd == -1)
        map_error(1);
    temp = 0;
    i = 0;
    while (i < x)
    {
        line = get_next_line(map_fd);
        *y = ft_strlen(line);
        free(line);
        if (i == 0)
            temp = *y;
        else if (*y != temp)
            map_error(2);
        temp = *y;
        i++;
    }
    *y = *y - 1;
    close(map_fd);
}