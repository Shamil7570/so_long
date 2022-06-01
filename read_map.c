/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:56:47 by medeana           #+#    #+#             */
/*   Updated: 2021/12/19 15:27:47 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(char *av, t_game *game)
{
	char	*line;
	char	*tmp;
	int		fd;

	fd = open(av, O_RDONLY);
	if (fd < 0)
		exit(0);
	tmp = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = ft_strjoin(tmp, line);
		free(line);
		game->row++;
	}
	game->map = ft_split(tmp, '\n');
	game->col = ft_strlen(game->map[0]);
	free(tmp);
}
