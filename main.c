/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:15:26 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/22 11:58:20 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include "so_long.h"
int	main(int argc, char **argv)
{
	int		x;
	int		y;
    int		map_fd;
    char 	*line = NULL;
	int		i = 0;

    if (argc != 2)
    {
        printf("Error\nWrong number of argc\n");
        return (1);	
    }
    valid_map(argv[1]);

    map_fd = open(argv[1], O_RDONLY);
    if (map_fd == -1)
    {
        printf("Error\nFailed to open file\n");
        return (1);
    }
	line = get_next_line(map_fd);
	x = strlen(line);
    while (line != NULL)

    {
        printf("%s\n", line);
		i++;
        free(line);
		line = get_next_line(map_fd);
    }
	y = i;
	printf("X ES :%d\n", x);
	printf("Y ES :%d\n", y);
   //free(line);
    close(map_fd);

    return (0);
}
