/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 15:41:06 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/26 19:15:01 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	comp_texture(t_e *e, t_rc *rc, t_lxpm *x)
{
	if (rc->side == 0) 
		rc->wallx = rc->raypos.y + (double)(rc->walldist * rc->raydir.y);
	else
		rc->wallx = rc->raypos.x + (double)(rc->walldist * rc->raydir.x);
	rc->wallx -= floor(rc->wallx);
	rc->tex.x = (int)(rc->wallx * (double)x->x);
	if (rc->side == 0 && rc->raydir.x > 0) 
		rc->tex.x = x->x - rc->tex.x - 1;
	if (rc->side == 1 && rc->raydir.y < 0) 
		rc->tex.x = x->x - rc->tex.x - 1;
	rc->pix.y = rc->drawstart;
	while (rc->pix.y < rc->drawend)
	{
		rc->mult = rc->pix.y * 2 - RESO_Y + rc->lineheight;
		rc->tex.y = (((int)rc->mult * x->y) / rc->lineheight) / 2;
		if (rc->tex.y < 0);
		else
			if (x)
			draw_texture(e->mlx, x, rc);
		rc->pix.y++;
	}
}

void	wolf_3d(t_e *e)
{
	ray_casting(e);
}
