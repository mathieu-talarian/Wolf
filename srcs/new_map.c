/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:42:35 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 20:31:24 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#define F e->draw.d

void	new_map(t_e *e)
{
	int i;

	i = 1;
	mlx_img_to_black(e->mlx);
	while (i == 1)
	{
		free_map_list(&e->map);
		if (!parsing_map("./map/map2.wolf", &e))
			exit(0);
		F.pos.x = 10;
		F.pos.y = 31;
		e->i = 1;
		i = 0;
	}
}

void	new_map2(t_e *e)
{
	int i;

	i = 1;
	mlx_img_to_black(e->mlx);
	while (i == 1)
	{
		free_map_list(&e->map);
		if (!parsing_map("./map/map.wolf", &e))
			exit(0);
		F.pos.x = 13;
		F.pos.y = 2;
		e->i = 0;
		i = 0;
	}
}
