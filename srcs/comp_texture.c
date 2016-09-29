/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:47:42 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 20:49:50 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	comp_texture(t_e *e, t_rc *rc, t_lxpm *x)
{
	if (x)
	{
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
			if (rc->tex.y < 0)
				;
			else
				draw_texture(e->mlx, x, rc);
			rc->pix.y++;
		}
	}
}

void	wolf_3d(t_e *e)
{
	ray_casting(e);
}
