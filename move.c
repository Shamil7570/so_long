/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:21:42 by medeana           #+#    #+#             */
/*   Updated: 2021/12/19 15:02:04 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_game *game)
{
	int	end;
	int	end2;

	end = end_game(game);
	end2 = end_game2(game);
	init_x_y(game);
	if (end == 0 && end2 == 0)
	{	
		if (keycode == W || keycode == UP)
			move_up(game);
		if (keycode == A || keycode == LEFT)
			move_left(game);
		if (keycode == S || keycode == DOWN)
			move_down(game);
		if (keycode == D || keycode == RIGHT)
			move_right(game);
	}
	if (keycode == ESC)
		exit(0);
	return (0);
}

void	move_up(t_game *game)
{
	if (game->map[game->y - 1][game->x] != '1'
		&& game->map[game->y - 1][game->x] != 'E')
	{
		if (game->map[game->y - 1][game->x] == 'C')
			game->coll--;
		game->map[game->y][game->x] = '0';
		game->map[game->y - 1][game->x] = 'P';
		game->score++;
		printf("score == %d\n", game->score);
	}
}

void	move_right(t_game *game)
{
	game->img.player = mlx_xpm_file_to_image(game->mlx, IMG_P,
			&game->img.h, &game->img.w);
	mlx_put_image_to_window(game->mlx, game->win, game->img.player,
		game->row * 70, game->col * 70);
	if (game->map[game->y][game->x + 1] != '1'
		&& game->map[game->y][game->x + 1] != 'E')
	{
		if (game->map[game->y][game->x + 1] == 'C')
			game->coll--;
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x + 1] = 'P';
		game->score++;
		printf("score == %d\n", game->score);
	}
}

void	move_left(t_game *game)
{
	game->img.player = mlx_xpm_file_to_image(game->mlx, IMG_P2,
			&game->img.h, &game->img.w);
	mlx_put_image_to_window(game->mlx, game->win, game->img.player,
		game->row * 70, game->col * 70);
	if (game->map[game->y][game->x - 1] != '1'
		&& game->map[game->y][game->x - 1] != 'E')
	{
		if (game->map[game->y][game->x - 1] == 'C')
			game->coll--;
		game->map[game->y][game->x] = '0';
		game->map[game->y][game->x - 1] = 'P';
		game->score++;
		printf("score == %d\n", game->score);
	}
}

void	move_down(t_game *game)
{
	if (game->map[game->y + 1][game->x] != '1'
		&& game->map[game->y + 1][game->x] != 'E')
	{
		if (game->map[game->y + 1][game->x] == 'C')
			game->coll--;
		game->map[game->y][game->x] = '0';
		game->map[game->y + 1][game->x] = 'P';
		game->score++;
		printf("score == %d\n", game->score);
	}
}
