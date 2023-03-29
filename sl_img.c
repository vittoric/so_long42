/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_img.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:05:01 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/29 18:25:16 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    image(t_game *game,int x_pos,int y_pos)
{
    mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img_s, (y_pos * 110), (x_pos * 110));
    
    if (game->matrix[x_pos][y_pos].value == 'P')
    {
        mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img_chr, (y_pos * 110), (x_pos * 110));
    }
    else if (game->matrix[x_pos][y_pos].value == 'E')
        mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img_exit, (y_pos * 110), (x_pos * 110));
    else if (game->matrix[x_pos][y_pos].value == 'C')
        mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img_col, (y_pos * 110), (x_pos * 110));
}

void    put_img(t_game  *game,int x, int y)
{
    int x_pos;
    int y_pos;
    
    x_pos = 0;
    while (x_pos < x)
    {
        y_pos = 0;
        while (y_pos < y)
        {//ft_printf("pos de x y en value: %c\n, X=%d  Y=%d\n" , game->matrix[x_pos][y_pos].value, x_pos, y_pos);
            if (game->matrix[x_pos][y_pos].value == '1')
                mlx_put_image_to_window(game->mlx.mlx, game->mlx.win, game->mlx.img_w, (y_pos * 110), (x_pos * 110));
            else if (game->matrix[x_pos][y_pos].value != '1')
            {
               image(game, x_pos, y_pos);
            }
            y_pos++;
        }
        x_pos++;
    }    
}

void    set_img(t_mlx *mlx)
{
    int px = 110;
    mlx->img_w = mlx_xpm_file_to_image(mlx->mlx, "./wall.xpm", &px, &px);
    mlx->img_s = mlx_xpm_file_to_image(mlx->mlx, "./grass.xpm", &px, &px);
    mlx->img_chr = mlx_xpm_file_to_image(mlx->mlx, "./character.xpm", &px, &px);
    mlx->img_exit = mlx_xpm_file_to_image(mlx->mlx, "./exit.xpm", &px, &px);
    mlx->img_col = mlx_xpm_file_to_image(mlx->mlx, "./coll.xpm", &px, &px);
}


 