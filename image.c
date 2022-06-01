/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:53:37 by medeana           #+#    #+#             */
/*   Updated: 2021/12/19 14:36:55 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img(t_game *game)
{
	game->img.player = mlx_xpm_file_to_image(game->mlx, IMG_P,
			&game->img.h, &game->img.w);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, IMG_W,
			&game->img.h, &game->img.w);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, IMG_E,
			&game->img.h, &game->img.w);
	game->img.empty = mlx_xpm_file_to_image(game->mlx, IMG_EM,
			&game->img.h, &game->img.w);
	game->img.collectible = mlx_xpm_file_to_image(game->mlx, IMG_C,
			&game->img.h, &game->img.w);
}

void	check_map(t_game *game, int col, int row)
{
	if (game->map[col][row] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.wall, row * 70, col * 70);
	if (game->map[col][row] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.player, row * 70, col * 70);
	if (game->map[col][row] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.empty, row * 70, col * 70);
	if (game->map[col][row] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.collectible, row * 70, col * 70);
	if (game->map[col][row] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->img.exit, row * 70, col * 70);
}

int	put_img(t_game *game)
{
	int	col;
	int	row;

	col = 0;
	while (game->map[col])
	{
		row = 0;
		while (game->map[col][row])
		{
			check_map(game, col, row);
			row++;
		}
		col++;
	}
	return (0);
}
