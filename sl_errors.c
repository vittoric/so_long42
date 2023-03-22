/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:33:20 by vcodrean          #+#    #+#             */
/*   Updated: 2023/03/22 15:33:31 by vcodrean         ###   ########.fr       */
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
            printf("Error\nBad size of rows\n");
            exit(0);
        }
}