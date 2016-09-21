# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 17:03:58 by mmoullec          #+#    #+#              #
#    Updated: 2016/09/21 10:33:13 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf
A = map.wolf
B = map2.wolf

all:
	gcc -g -Ofast -O3 ./srcs/*.c -o $(NAME) -L./libft -I./libft -lft -lmlx -framework Appkit -framework OpenGL -lm -L./minilibx_macos -I./minilibx_macos -I./includes

1: all
	cat $(A)
	./$(NAME) $(A)

2: all
	cat $(B)
	./$(NAME) $(B)
