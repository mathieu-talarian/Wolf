/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 19:32:05 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/10 16:25:25 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	move_forward(t_draw *draw, t_map *map)
{
	if (mapping(&map, (int)(E.pos.x + E.dirx * E.movespeed * E.acceleration), (int)E.pos.y) <= 0)
		E.pos.x += E.dirx * E.movespeed * E.acceleration;
	if (mapping(&map, (int)E.pos.x, (int)(E.pos.y + E.diry * E.movespeed * E.acceleration)) <= 0)
		E.pos.y += E.diry * E.movespeed * E.acceleration;
}

void	move_backward(t_draw *draw, t_map *map)
{
	if (mapping(&map, (int)(E.pos.x - E.dirx * E.movespeed), (int)E.pos.y) <= 0)
		E.pos.x -= E.dirx * E.movespeed;
	if (mapping(&map, (int)E.pos.x, (int)(E.pos.y - E.diry * E.movespeed)) <= 0)
		E.pos.y -= E.diry * E.movespeed;
}

void	straf_left(t_draw *draw, t_map *map)
{
	t_vect	oldpos;
	
	oldpos.x = E.pos.x;
	oldpos.y = E.pos.y;
	if (mapping(&map, (int)(E.pos.x -= E.planex * E.movespeed), (int)E.pos.y) <= 0)
		E.pos.x -= E.planex * E.movespeed;
	else 
		E.pos.x = oldpos.x;
	if (mapping(&map, (int)E.pos.x, (int)(E.pos.y -= E.planey * E.movespeed)) <= 0)
		E.pos.y -= E.planey * E.movespeed;
	else 
		E.pos.y = oldpos.y;
}

void	straf_right(t_draw *draw, t_map *map)
{
	t_vect	oldpos;
	
	oldpos.x = E.pos.x;
	oldpos.y = E.pos.y;
	if (mapping(&map, (int)(E.pos.x += E.planex * E.movespeed), (int)E.pos.y) <= 0)
		E.pos.x += E.planex * E.movespeed;
	else 
		E.pos.x = oldpos.x;
	if (mapping(&map, (int)E.pos.x, (int)(E.pos.y += E.planey * E.movespeed)) <= 0)
		E.pos.y += E.planey * E.movespeed;
	else 
		E.pos.y = oldpos.y;
}
