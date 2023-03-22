/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_vaid_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 11:50:16 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/22 13:35:58 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    map_error(int num)
{
    if (num == 0)
        {
            printf("Error\nBad file format\nUse only < .ber >\n");
            exit(0);
        }
    if (num == 1)
        {
            printf("Error\nFailed to open map file\n");
            exit(0);
        }
    if (num == 2)
        {
            printf("Error\nBad \n");
            exit(0);
        }
}

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