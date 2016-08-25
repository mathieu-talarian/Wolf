# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/25 17:03:58 by mmoullec          #+#    #+#              #
#    Updated: 2016/08/25 17:05:12 by mmoullec         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wolf

all:
	gcc *.c -o $(NAME) -L./libft -I./libft -lft -lmlx -framework Appkit -framework OpenGL -lm

run: all
	./$(NAME)
