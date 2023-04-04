/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_key_event.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 12:29:42 by vcodrean          #+#    #+#             */
/*   Updated: 2023/04/02 17:44:03 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_event(int key_code, t_game *game)
{
	if (game->frames == 8)
		game->frames = 0;
	if (key_code == 0 || key_code == 123)
		if (movement(game, 0, -1) == 0)
			key_a(game);
	if (key_code == 1 || key_code == 125)
		if (movement(game, 1, 0) == 0)
			key_s(game);
	if (key_code == 2 || key_code == 124)
		if (movement(game, 0, 1) == 0)
			key_d(game);
	if (key_code == 13 || key_code == 126)
		if (movement(game, -1, 0) == 0)
			key_w(game);
	if (key_code == 53)
		close_esc(&game->mlx);
	return (0);
}
