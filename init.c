/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:36:07 by medeana           #+#    #+#             */
/*   Updated: 2021/12/19 14:38:06 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init(t_game *game)
{
	game->col = 0;
	game->row = 0;
	game->coll = 0;
	game->score = 0;
	game->exit = 0;
	game->x = 0;
	game->y = 0;
	game->x2 = 0;
	game->y2 = 0;
}

void	init_x_y(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	while (game->map[col])
	{
		row = 0;
		while (game->map[col][row])
		{
			if (game->map[col][row] == 'P')
			{
				game->player++;
				game->x = row;
				game->y = col;
			}
			row++;
		}
		col++;
	}
}

void	init_coll(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	while (game->map[col])
	{
		row = 0;
		while (game->map[col][row])
		{
			if (game->map[col][row] == 'C')
				game->coll++;
			row++;
		}
		col++;
	}
}

void	init_end_game(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	while (game->map[col])
	{
		row = 0;
		while (game->map[col][row])
		{
			if (game->map[col][row] == 'E')
			{
				game->exit++;
				game->x2 = row;
				game->y2 = col;
			}
			row++;
		}
		col++;
	}
}

void	initialization(t_game *game)
{
	init_x_y(game);
	init_coll(game);
	init_end_game(game);
}
