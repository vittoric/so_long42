/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 15:15:26 by vcodrean          #+#    #+#             */
/*   Updated: 2023/04/02 18:11:43 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_esc(t_mlx *mlx)
{
	mlx_clear_window(mlx->mlx, mlx->win);
	mlx_destroy_window(mlx->mlx, mlx->win);
	exit(0);
	return (0);
}

int	hook_loop(t_game *game)
{
	print_steps(game);
	mlx_key_hook(game->mlx.win, key_event, game);
	mlx_hook(game->mlx.win, 17, (1L << 17), close_esc, &game->mlx);
	mlx_loop(game->mlx.mlx);
	return (0);
}

void	run_game(t_game *game, int x, int y, char *argv)
{
	creat_grid(argv, x, y, game->matrix);
	fill_value_aux(argv, x, y, game->matrix);
	grid_corners(x, y, game->matrix);
	borders(x, y, game->matrix);
	read_map(x, y, game);
	read_grid(x, y, game);
	valid_path(x, y, game);
	game->mlx.mlx = mlx_init();
	game->mlx.win = mlx_new_window(game->mlx.mlx, (y * 110), (x * 110), \
	"so_llama_vcodrean");
	set_xpm(game);
	game->steps = 0;
	game->frames = 0;
}

int	main(int argc, char **argv)
{
	int		x;
	int		y;
	t_game	game;

	x = 0;
	y = 0;
	if (argc != 2)
	{
		ft_printf("Error\nWrong number of argc\n");
		return (1);
	}
	valid_map(argv[1]);
	find_map_size(argv[1], &x, &y);
	game.matrix = malloc(sizeof(t_matrix *) * x * y);
	game.matrix[x] = 0;
	if (!game.matrix)
		return (0);
	run_game(&game, x, y, argv[1]);
	put_img(&game, x, y);
	hook_loop(&game);
	return (0);
}
