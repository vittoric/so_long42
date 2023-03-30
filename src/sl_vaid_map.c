/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_vaid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:50:16 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/22 15:33:12 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    valid_map(char *map)
{
    int i;
    
    i = strlen(map) - 1;
    if (map[i] == 'r')
        i--;
    else
        map_error(0);
    if (map[i] == 'e')
        i--;
    else
        map_error(0);
    if (map[i] == 'b')
        i--;
    else
        map_error(0);
    if (map[i] == '.')
        i--;
    else
        map_error(0);
}