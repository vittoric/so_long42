/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movements_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 17:43:30 by vcodrean          #+#    #+#             */
/*   Updated: 2023/04/06 17:01:48 by vcodrean         ###   ########.fr       */
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
		return (1);
	else
	{
		game->lama.x = new_x;
		game->lama.y = new_y;
		return (0);
	}
}

void	key_a(t_game *game)
{
	int	i;

	i = game->frames;
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
	game->sprite.player_left[i], (game->lama.y * 110), (game->lama.x * 110));
	game->frames++;
	game->steps += 1;
	print_steps(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'E')
		win_game(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'W')
		lose_game(game);
}

void	key_d(t_game *game)
{
	int	i;

	i = game->frames;
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
	game->frames++;
	game->steps += 1;
	print_steps(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'E')
		win_game(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'W')
		lose_game(game);
}

void	key_w(t_game *game)
{	
	int	i;

	i = game->frames;
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
	game->sprite.player_back[i], (game->lama.y) * 110, (game->lama.x * 110));
	game->frames++;
	game->steps++;
	print_steps(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'E')
		win_game(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'W')
		lose_game(game);
}

void	key_s(t_game *game)
{
	int	i;

	i = game->frames;
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
	game->sprite.player_front[i], (game->lama.y * 110), (game->lama.x * 110));
	game->frames++;
	game->steps += 1;
	print_steps(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'E')
		win_game(game);
	if (game->matrix[game->lama.x][game->lama.y].value == 'W')
		lose_game(game);
}
