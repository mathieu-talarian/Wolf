# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 17:03:58 by mmoullec          #+#    #+#              #
#    Updated: 2016/09/22 16:26:58 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=wolf3d
CC=clang
FL= -Wall -Werror -Wextra
FL2= -O2 -Ofast
LIB= -I./libft -I./minilibx_macos -I./includes
LFT= -lft -L./libft
LMLX= -lmlx -L./minilibx_macos -framework Appkit -framework OpenGL
SRCD= ./srcs/
SRCS=comp_texture.c\
do_wolf.c\
error.c\
exit.c\
fill_size.c\
fill_xpm.c\
floor.c\
free_map_list.c\
hsv_to_grb.c\
key_hook.c\
line.c\
line2.c\
lists.c\
main.c\
mapping.c\
math.c\
move.c\
move2.c\
new_map.c\
notextures.c\
open_door.c\
parsing_map.c\
ray_casting.c\
rc_wall.c\
rd.c\
rgb_to_hsv.c\
sky.c\
skybox.c\
tab_clr.c\
test_start.c\
texture.c\
xpmlisting.c
OBJD= ./obj/
OBJ = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./libft
	make -C ./minilibx_macos
	$(CC) -o $(NAME) $(FL) $(FL2) $(OBJ) $(LFT) $(LMLX)

%.o: $(SRCD)%.c
	$(CC) -o $@ -c $< $(FL) $(FL2) $(LIB)

clean:
	make clean -C ./libft
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
