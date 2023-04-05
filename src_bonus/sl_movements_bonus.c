/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movements_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:43:30 by vcodrean          #+#    #+#             */
/*   Updated: 2023/04/05 15:17:34 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	movement(t_game *game, int x, int y)
{
	int		new_x;
	int		new_y;

	new_x = game->lama.x + x;
	new_y = game->lama.y + y;
	if (game->matrix[new_x][new_y].value == '1' ||
			(game->matrix[new_x][new_y].value == 'E'
				&& game->collectibles != 0))
	{
		ft_printf ("Colectables %d\n", game->collectibles);
		ft_printf ("Impossible movement\n");
		return (1);
	}
	else
	{
		game->lama.x = new_x;
		game->lama.y = new_y;
		return (0);
	}
}

void	key_a(t_game *game)
{
	//int	i;
	
	//i = game->frames;
	if (game->matrix[game->lama.x][game->lama.y].value == 'C')
	{
		game->collectibles--;
		game->matrix[game->lama.x][game->lama.y].value = '0';
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.cell,
		(game->lama.y * 110), (game->lama.x * 110));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.cell,
		((game->lama.y + 1) * 110), ((game->lama.x) * 110));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, \
	game->sprite.player_left, (game->lama.y * 110), (game->lama.x * 110));
	//game->frames += 1;
	game->steps += 1;
	print_steps(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'E')
	{
		win_game(1);
		close_esc(&game->mlx);
	}
	if (game->matrix[game->lama.x][game->lama.y].value == 'W')
	{
		lose_game(1);
		close_esc(&game->mlx);
	}
}

void	key_d(t_game *game)
{
	int	i;

	i = game->frames;
	if (game->frames == 2)
		game->frames = 0;
	if (game->matrix[game->lama.x][game->lama.y].value == 'C')
	{
		game->collectibles--;
		game->matrix[game->lama.x][game->lama.y].value = '0';
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.cell,
		(game->lama.y * 110), (game->lama.x * 110));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.cell,
		((game->lama.y - 1) * 110), ((game->lama.x) * 110));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, \
	game->sprite.player_right[i], (game->lama.y * 110), (game->lama.x * 110));
	game->frames += 1;
	printf("frames %d\n", game->frames);
	game->steps += 1;
	print_steps(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'E')
	{
		win_game(1);
		close_esc(&game->mlx);
	}
	if (game->matrix[game->lama.x][game->lama.y].value == 'W')
	{
		lose_game(1);
		close_esc(&game->mlx);
	}
}

void	key_w(t_game *game)
{	
//	int	i;

	//i = game->frames;
	if (game->matrix[game->lama.x][game->lama.y].value == 'C')
	{
		game->collectibles--;
		game->matrix[game->lama.x][game->lama.y].value = '0';
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.cell,
		(game->lama.y * 110), (game->lama.x * 110));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.cell,
		(game->lama.y * 110), ((game->lama.x + 1) * 110));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, \
	game->sprite.player_back, (game->lama.y) * 110, (game->lama.x * 110));
	//game->frames += 1;
	game->steps += 1;
	print_steps(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'E')
	{
		win_game(1);
		close_esc(&game->mlx);
	}
	if (game->matrix[game->lama.x][game->lama.y].value == 'W')
	{
		lose_game(1);
		close_esc(&game->mlx);
	}
}

void	key_s(t_game *game)
{
	//int	i;

	//i = game->frames;
	if (game->matrix[game->lama.x][game->lama.y].value == 'C')
	{
		game->collectibles--;
		game->matrix[game->lama.x][game->lama.y].value = '0';
	}
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.cell,
		(game->lama.y * 110), (game->lama.x * 110));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.cell,
		(game->lama.y * 110), ((game->lama.x - 1) * 110));
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, \
	game->sprite.player_front, (game->lama.y * 110), (game->lama.x * 110));
	//game->frames += 1;
	game->steps += 1;
	print_steps(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'E')
	{
		win_game(1);
		close_esc(&game->mlx);
	}
	if (game->matrix[game->lama.x][game->lama.y].value == 'W')
	{
		lose_game(1);
		close_esc(&game->mlx);
	}
}
