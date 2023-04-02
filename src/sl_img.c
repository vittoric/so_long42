/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:05:01 by vcodrean          #+#    #+#             */
/*   Updated: 2023/04/02 19:21:59 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*valid_xpm(t_game *game, char *str)
{
	char	*route;
	void	*img;
	int		px;

	px = 110;
	route = ft_strjoin(XPM_ROUTE, str);
	img = mlx_xpm_file_to_image(game->mlx.mlx, route, &px, &px);
	if (!img)
		map_error(3);
	free(route);
	return (img);
}

void	set_player(t_game *game)
{
	game->sprite.player_front = valid_xpm(game, "front.xpm");
	game->sprite.player_back = valid_xpm(game, "back.xpm");
	game->sprite.player_left = valid_xpm(game, "left.xpm");
	game->sprite.player_right = valid_xpm(game, "character.xpm");
}

void	map_xpm(t_game *game)
{
	game->mlx.cell = valid_xpm(game, "grass.xpm");
	game->mlx.footprints = valid_xpm(game, "lamasteps.xpm");
	game->mlx.wall = valid_xpm(game, "wall.xpm");
	game->mlx.img_col = valid_xpm(game, "coll.xpm");
	game->mlx.img_exit = valid_xpm(game, "exit.xpm");
}

void	set_xpm(t_game *game)
{
	set_player(game);
	map_xpm(game);
}

void	image(t_game *game, int x_pos, int y_pos)
{
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.cell, \
	(y_pos * 110), (x_pos * 110));
	if (game->matrix[x_pos][y_pos].value == 'P')
	{
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, \
		game->sprite.player_front, (y_pos * 110), (x_pos * 110));
		game->lama.x = x_pos;
		game->lama.y = y_pos;
	}
	else if (game->matrix[x_pos][y_pos].value == 'E')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, \
		game->mlx.img_exit, (y_pos * 110), (x_pos * 110));
	else if (game->matrix[x_pos][y_pos].value == 'C')
		mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, \
		game->mlx.img_col, (y_pos * 110), (x_pos * 110));
}

void	put_img(t_game *game, int x, int y)
{
	int	x_pos;
	int	y_pos;

	x_pos = 0;
	while (x_pos < x)
	{
		y_pos = 0;
		while (y_pos < y)
		{
			if (game->matrix[x_pos][y_pos].value == '1')
				mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, \
				game->mlx.wall, (y_pos * 110), (x_pos * 110));
			else if (game->matrix[x_pos][y_pos].value != '1')
				image(game, x_pos, y_pos);
			y_pos++;
		}
		x_pos++;
	}
}
