# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 17:03:58 by mmoullec          #+#    #+#              #
#    Updated: 2016/09/06 16:46:30 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf

all:
	gcc ./srcs/*.c -o $(NAME) -L./libft -I./libft -lft -lmlx -framework Appkit -framework OpenGL -lm -L./minilibx_macos -I./minilibx_macos -I./includes

run: all
	./$(NAME) map.wolf
