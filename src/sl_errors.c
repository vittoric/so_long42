/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:33:20 by vcodrean          #+#    #+#             */
/*   Updated: 2023/04/02 18:04:56 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_error(int num)
{
	if (num == 0)
	{
		ft_printf("\nError\nBad file format\nUse only < .ber >\n");
		exit(0);
	}
	if (num == 1)
	{
		ft_printf("\nError\nFailed to open map file\n");
		exit(0);
	}
	if (num == 2)
	{
		ft_printf("\nError\nBad size of rows\n");
		exit(0);
	}
	if (num == 3)
	{
		ft_printf("\nFailed to load XPM files\n");
		exit(0);
	}
}

void	free_memory(t_matrix **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}

void	error_free(int num, t_matrix **matrix)
{
	if (num == 0)
	{
		ft_printf("Error\nInvalid map\n");
		free_memory(matrix);
		exit(0);
	}
	if (num == 1)
	{
		ft_printf("Error\nInvalid character\n");
		free_memory(matrix);
		exit(0);
	}
}

void	matrix_error(t_matrix **matrix)
{
	ft_printf("Memory error\n");
	free_memory(matrix);
	exit(0);
}
