/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 14:42:27 by medeana           #+#    #+#             */
/*   Updated: 2021/12/19 14:58:59 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	end_game(t_game *game)
{
	if (game->coll == 0 && game->map[game->y + 1][game->x] == 'E')
	{
		game->img.exit = mlx_xpm_file_to_image(game->mlx, IMG_E2,
				&game->img.h, &game->img.w);
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			game->row * 70, game->col * 70);
		game->map[game->y][game->x] = '0';
		return (1);
	}
	if (game->coll == 0 && game->map[game->y][game->x - 1] == 'E')
	{
		game->img.exit = mlx_xpm_file_to_image(game->mlx, IMG_E2,
				&game->img.h, &game->img.w);
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			game->row * 70, game->col * 70);
		game->map[game->y][game->x] = '0';
		return (1);
	}
	return (0);
}

int	end_game2(t_game *game)
{
	if (game->coll == 0 && game->map[game->y][game->x + 1] == 'E')
	{
		game->img.exit = mlx_xpm_file_to_image(game->mlx, IMG_E2,
				&game->img.h, &game->img.w);
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			game->row * 70, game->col * 70);
		game->map[game->y][game->x] = '0';
		return (1);
	}
	if (game->coll == 0 && game->map[game->y - 1][game->x] == 'E')
	{
		game->img.exit = mlx_xpm_file_to_image(game->mlx, IMG_E2,
				&game->img.h, &game->img.w);
		mlx_put_image_to_window(game->mlx, game->win, game->img.exit,
			game->row * 70, game->col * 70);
		game->map[game->y][game->x] = '0';
		return (1);
	}
	return (0);
}

int	f_exit(t_game *game)
{
	(void)game;
	exit(0);
}
