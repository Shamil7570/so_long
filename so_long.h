/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: medeana <medeana@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 19:23:35 by medeana           #+#    #+#             */
/*   Updated: 2021/12/19 16:47:41 by medeana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

# define IMG_P "./assets/ghost.xpm"
# define IMG_P2 "./assets/ghost2.xpm"
# define IMG_W "./assets/box.xpm"
# define IMG_E "./assets/R.I.P.xpm"
# define IMG_E2 "./assets/R.I.P2.xpm"
# define IMG_EM "./assets/black.xpm"
# define IMG_C "./assets/coll3.xpm"
# define BUFFER_SIZE 	1
# define W 				13
# define A 				0
# define D 				2
# define S 				1
# define ESC 			53
# define UP				126
# define DOWN			125
# define LEFT			123
# define RIGHT			124

typedef struct s_image{
	int		h;
	int		w;
	void	*player;
	void	*exit;
	void	*wall;
	void	*collectible;
	void	*empty;
}				t_image;

typedef struct s_game{
	t_image	img;
	void	*mlx;
	void	*win;
	char	**map;
	int		col;
	int		row;
	int		score;
	int		player;
	int		exit;
	int		coll;
	int		x;
	int		x2;
	int		y;
	int		y2;
}				t_game;

void	init(t_game *game);
int		key_hook(int keycode, t_game *game);
int		put_img(t_game *game);
void	img(t_game *game);
void	read_map(char *av, t_game *game);
void	check_map(t_game *game, int col, int row);
void	check_char(t_game *game);
void	check(t_game *game, int col, int row);
void	move_left(t_game *game);
void	init_x_y(t_game *game);
void	move_up(t_game *game);
void	move_right(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
int		end_game(t_game *game);
void	init_coll(t_game *game);
void	init_end_game(t_game *game);
void	initialization(t_game *game);
int		f_exit(t_game *game);
void	valid_map(t_game *game);
void	valid_char(t_game *game);
void	valid_char2(t_game *game, int col, int row);
int		end_game2(t_game *game);

char	*ft_strdup(const char *src);
void	ft_strcpy(char *dest, char *src);
size_t	ft_strlen(char *str);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
char	*get_next_line(int fd);
char	*ft_remainder(char *remainder, char *line);
char	*read_file(int fd, char *remainder);
char	**ft_split(char const *s, char c);
char	*ft_substr(char *str, unsigned int start, size_t lenght);
char	*ft_itoa(int n);

#endif