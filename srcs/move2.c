/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/08 19:45:00 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/08 23:56:33 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	turn_left(t_draw *draw, t_map *map)
{
	double olddirx;
	double oldplanex;
	double rotspeed;

	rotspeed = 0.2;
	olddirx = E.dirx;
	oldplanex = E.planex;
	E.dirx = E.dirx * cos(-rotspeed) - E.diry * sin(-rotspeed);
	E.diry = olddirx * sin(-rotspeed) + E.diry * cos(-rotspeed);
	E.planex = E.planex * cos(-rotspeed) - E.planey * sin(-rotspeed);
	E.planey = oldplanex * sin(-rotspeed) + E.planey * cos(-rotspeed);
}

void	turn_right(t_draw *draw, t_map *map)
{
	double olddirx;
	double oldplanex;
	double rotspeed;

	rotspeed = 0.2;
	olddirx = E.dirx;
	oldplanex = E.planex;
	olddirx = E.dirx;
	oldplanex = E.planex;
	E.dirx = E.dirx * cos(rotspeed) - E.diry * sin(rotspeed);
	E.diry = olddirx * sin(rotspeed) + E.diry * cos(rotspeed);
	E.planex = E.planex * cos(rotspeed) - E.planey * sin(rotspeed);
	E.planey = oldplanex * sin(rotspeed) + E.planey * cos(rotspeed);
}
