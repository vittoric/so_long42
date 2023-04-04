/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_spets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 15:25:54 by vcodrean          #+#    #+#             */
/*   Updated: 2023/04/04 16:45:55 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_steps(t_game *game)
{
	char	*str;

	str = ft_itoa(game->steps);
	ft_printf("Steps: %d\n", game->steps);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.wall, 0, 0);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, \
	game->mlx.wall, 110, 0);
	mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, \
	game->mlx.footprints, 0, 0);
	mlx_string_put(game->mlx.mlx, game->mlx.win, 90, 13, 0xFFFFFF, str);
	free(str);
}

void	win_game(int fd)
{
	ft_putstr_fd(ROSE"\n-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-", fd);
	ft_putstr_fd("\n¡¡You just climb the mountain!!\n", fd);
	ft_putstr_fd("-º-º-º-º-º-º-º-º-º-º-º-º-º-º-º-\n"CYAN, fd);
}
