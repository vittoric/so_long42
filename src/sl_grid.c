/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcodrean <vcodrean@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 12:33:27 by vcodrean          #+#    #+#             */
/*   Updated: 2023/04/06 16:53:30 by vcodrean         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	creat_grid(char *map, int x, int y, t_matrix **matrix)
{
	char	*str;
	int		map_fd;
	int		rowcol[2];

	map_fd = open(map, O_RDONLY);
	if (map_fd == -1)
		map_error(1);
	rowcol[0] = 0;
	while (rowcol[0] < x)
	{
		str = get_next_line(map_fd);
		rowcol[1] = 0;
		matrix[rowcol[0]] = malloc(sizeof(t_matrix) * y);
		if (!matrix[rowcol[0]])
			matrix_error(matrix, x);
		while (rowcol[1] < y)
		{
			matrix[rowcol[0]][rowcol[1]].pos_x = rowcol[0];
			matrix[rowcol[0]][rowcol[1]].pos_y = rowcol[1];
			matrix[rowcol[0]][rowcol[1]].value = str[rowcol[1]];
			rowcol[1]++;
		}
		free(str);
		rowcol[0]++;
	}
}

void	fill_value_aux(char *map, int x, int y, t_matrix **matrix)
{
	int	row;
	int	col;

	creat_grid(map, x, y, matrix);
	row = 0;
	while (row < x)
	{
		col = 0;
		while (col < y)
		{
			matrix[row][col].value_aux = matrix[row][col].value;
			col++;
		}
		row++;
	}
}

void	grid_corners(int x, int y, t_matrix **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (matrix[i][j].pos_x == 0 || matrix[i][j].pos_x == x - 1 || \
				matrix[i][j].pos_y == 0 || matrix[i][j].pos_y == y - 1)
				matrix[i][j].border = 1;
			else
				matrix[i][j].border = 0;
			j++;
		}
		i++;
	}
}

void	borders(int x, int y, t_matrix **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (matrix[i][j].border == 1)
				if (matrix[i][j].value != '1')
					error_free(0, matrix, x);
			j++;
		}
		i++;
	}
}

void	read_map(int x, int y, t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < x)
	{
		j = 0;
		while (j < y)
		{
			if (game->matrix[i][j].value != 'C' && \
				game->matrix[i][j].value != 'P' && \
				game->matrix[i][j].value != 'E' && \
				game->matrix[i][j].value != '0' && \
				game->matrix[i][j].value != '1')
				error_free(1, game->matrix, x);
			j++;
		}
		i++;
	}
}
