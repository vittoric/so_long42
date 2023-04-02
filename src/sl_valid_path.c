/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_valid_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 12:40:12 by vcodrean          #+#    #+#             */
/*   Updated: 2023/04/02 13:37:13 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

 int	check_cur(t_game *game, int i, int j)
{
	if (game->matrix[i][j].value_aux == 'P' &&
	(game->matrix[i + 1][j].value_aux == 'C'
	|| game->matrix[i + 1][j].value_aux == '0'
	|| game->matrix[i - 1][j].value_aux == 'C'
	|| game->matrix[i - 1][j].value_aux == '0'
	|| game->matrix[i][j + 1].value_aux == 'C'
	|| game->matrix[i][j + 1].value_aux == '0'
	|| game->matrix[i][j - 1].value_aux == 'C'
	|| game->matrix[i][j - 1].value_aux == '0'))
		return (1);
	return (0);
}
 void	fill(t_game *game, int i, int j)
{
	if (game->matrix[i][j].value_aux == '0' || game->matrix[i][j].value_aux == 'C')
		game->matrix[i][j].value_aux = 'P';
}

 int	check_collect(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (game->matrix[i][j].value_aux == 'C')
            {
				//error_found;
                ft_printf("Unable to reach all collectibles");
                exit(1);}
			j++;
		}
		i++;
	}
	return (1);
}

 int	complete_path(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if ((game->matrix[i][j].value_aux == 'E' && game->matrix[i + 1][j].value_aux == 'P')
			|| (game->matrix[i][j].value_aux  == 'E' && game->matrix[i - 1][j].value_aux == 'P')
			|| (game->matrix[i][j].value_aux  == 'E' && game->matrix[i][j + 1].value_aux == 'P')
			|| (game->matrix[i][j].value_aux  == 'E' && game->matrix[i][j - 1].value_aux == 'P'))
				return (1);
			j++;
		}
		i++;
	}
	//error_found;
    ft_printf("Unable to reach an exit");
    exit(1);
	return (0);
}

 int    valid_path(int x, int y, t_game  *game)
 {
    int i;
    int j;

    i = 0;
    while(i < x)
    {
        j = 0;
        while (j < y)
        {
            if (check_cur(game, i, j))
            {
                fill(game, i + 1, j);
				fill(game, i - 1, j);
				fill(game, i, j + 1);
				fill(game, i, j - 1);
				i = 0;
            }
            j++;
        }
        i++;
    }
    if (check_collect(game, x, y) && complete_path(game, x, y))
		return (1);
	return (0);
 }
 