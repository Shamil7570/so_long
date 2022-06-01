/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:42:49 by medeana           #+#    #+#             */
/*   Updated: 2021/12/19 15:28:19 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	(void)argc;
	init(&game);
	read_map(argv[1], &game);
	valid_char(&game);
	valid_map(&game);
	initialization(&game);
	check_char(&game);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.col * 70,
			game.row * 70, "So_Long");
	img(&game);
	mlx_loop_hook(game.mlx, put_img, &game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_hook(game.win, 17, 0, f_exit, &game);
	mlx_loop(game.mlx);
}
