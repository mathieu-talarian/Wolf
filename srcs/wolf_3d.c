/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 15:41:06 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/22 19:34:18 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	comp_texture(t_e *e, t_rc *rc, t_lxpm *x, t_hsv hsv)
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
	for (rc->pix.y = rc->drawstart; rc->pix.y < rc->drawend; rc->pix.y++)
	{
		rc->mult = rc->pix.y * 256 - RESO_Y * 128 + rc->lineheight * 128;
		rc->tex.y = ((rc->mult * x->y) / rc->lineheight) / 256;
		draw_texture(e->mlx, x, rc, hsv);
	}
}

void	wolf_3d(t_e *e)
{
	ray_casting(e);
}
