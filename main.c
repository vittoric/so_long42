/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:15:26 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/27 15:13:43 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void    run_game(t_game *game, int x, int y, char *argv)
{
    creat_grid(argv, x, y, game->matrix);
    grid_corners(x, y, game->matrix);
    borders(x, y, game->matrix);
    read_map(x, y, game);
    read_grid(x, y, game);
}

int	main(int argc, char **argv)
{
	int		x = 0;
	int		y = 0;
    t_game game;
  
    if (argc != 2)
    {
        //cambiar por el ft_printf
        ft_printf("Error\nWrong number of argc\n");
        return (1);	
    }
    valid_map(argv[1]);    
    find_map_size(argv[1], &x, &y);
    game.matrix = malloc(sizeof(t_matrix *) * x + 1);
    game.matrix[x] = 0;
    if (!game.matrix)
		return (0);
    
    //cambiar por el ft_printf
    printf("X ES :%d\n", x);
	printf("Y ES :%d\n", y);
    run_game(&game, x, y, argv[1]);
    
  

    return (0);
}
