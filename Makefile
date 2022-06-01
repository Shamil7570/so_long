# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: medeana <medeana@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/19 14:12:25 by medeana           #+#    #+#              #
#    Updated: 2021/12/19 16:47:49 by medeana          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =      so_long
HEADER = so_long.h
LIST =     	ft_split.c \
			ft_substr.c \
			get_next_line_utils.c \
			get_next_line.c \
			image.c \
			init.c \
			move.c \
			read_map.c \
			so_long.c \
			valid_map.c \
			end_game.c

MINILIBX = libmlx.a

OBJ = $(LIST:.c=.o)

FLAGS = -Wall -Wextra -Werror -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit

all :	$(NAME)

$(NAME) : $(OBJ) $(HEADER)
	make -C mlx
	gcc $(FLAGS) $(LIST) -o $(NAME)

clean :
	rm -f $(OBJ)
	make clean -C mlx
fclean : clean
	rm -f $(NAME)
	rm -f $(MINILIBX)

re :	fclean all
.PHONY : all clean fclean re bonus