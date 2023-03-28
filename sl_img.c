/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:05:01 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/28 12:05:34 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    put_img(t_game  *game,int x, int y)
{
    int x_pos;
    int y_pos;
    
    x_pos = 0;
    while (x_pos < x)
    {
        y_pos = 0;
        while (y_pos < y)
        {
            if (game->matrix[x_pos][y_pos].value == '1')
                mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img_w, (y_pos * 32), (x_pos * 32));
            else if (game->matrix[x_pos][y_pos].value != '1')
                mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img_s, (y_pos * 32), (x_pos * 32));
            y_pos++;
        }
        x_pos++;
    }    
}

void    set_img(t_mlx *mlx)
{
    int px = 32;
    mlx->img_w = mlx_xpm_file_to_image(mlx->mlx, "./woods.xpm", &px, &px);
    mlx->img_s = mlx_xpm_file_to_image(mlx->mlx, "./grass.xpm", &px, &px);
}
