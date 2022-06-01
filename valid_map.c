/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:02:03 by medeana           #+#    #+#             */
/*   Updated: 2021/12/19 14:49:09 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	valid_map(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	while (game->map[col])
	{
		row = 0;
		while (game->map[col][row])
			row++;
		if (game->map[col][row] != game->map[0][row])
		{
			printf("Error!");
			exit(0);
		}
		col++;
	}
}

void	valid_char(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	while (game->map[col])
	{
		row = 0;
		while (game->map[col][row])
		{
			if (game->map[0][row] != '1' || game->map[col][0] != '1')
			{
				printf("Error!");
				exit(0);
			}
			row++;
		}
		col++;
	}
	valid_char2(game, col, row);
}

void	valid_char2(t_game *game, int col, int row)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][row - 1] != '1' || game->map[col - 1][j] != '1')
			{
				printf("Error!");
				exit(0);
			}
			j++;
		}
		i++;
	}
}

void	check_char(t_game *game)
{
	if (game->player != 1)
	{
		write(1, "Error!\n", 7);
		exit(0);
	}
	if (game->exit < 1)
	{
		write(1, "Error!\n", 7);
		exit(0);
	}
	if (game->coll < 1)
	{
		write(1, "Error!\n", 7);
		exit(0);
	}	
}
