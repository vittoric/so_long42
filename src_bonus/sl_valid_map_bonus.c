/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_vaid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:50:16 by vcodrean          #+#    #+#             */
/*   Updated: 2023/04/04 15:54:30 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(char *map, char *ext)
{
	int	i;
	int	j;

	i = ft_strlen(map) - ft_strlen(ext);
	j = 0;
	while (map[i + j] && ext[j])
	{
		if (map[i + j] == ext[j])
			j++;
		else
		{
			map_error(0);
			exit(1);
		}
	}
}

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
