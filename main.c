/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:15:26 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/23 12:33:38 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <mlx.h>
#include "so_long.h"

void    run_game(t_game *game, int x, int y, char *argv)
{
      creat_grid(argv, x, y, game->matrix);
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
    run_game(&game, x, y, argv[1]);
    
  

    return (0);
}
