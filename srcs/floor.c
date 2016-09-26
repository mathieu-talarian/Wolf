/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:21:58 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/26 19:15:00 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		todraw(t_e *e, t_rc *rc, t_lxpm *x)
{
	int y;
	double floorx;
	double fl_lineh;
	double floordist;
//	if (rc->side == 0) 
//		rc->wallx = rc->raypos.y + (double)(rc->walldist * rc->raydir.y);
//	else
//	rc->wallx = rc->raypos.x + (double)(rc->walldist * rc->raydir.x);
//	rc->wallx -= floor(rc->wallx);
//	rc->tex.x = (int)(rc->wallx * (double)x->x);
	rc->tex.x = x->x;
//	if (rc->side == 0 && rc->raydir.x > 0) 
//		rc->tex.x = x->x - rc->tex.x - 1;
//	if (rc->side == 1 && rc->raydir.y < 0) 
//		rc->tex.x = x->x - rc->tex.x - 1;
	rc->pix.y = rc->drawend;
	fl_lineh = RESO_Y - 1 - rc->drawend;
	printf("%f\n", fl_lineh);
	while (rc->pix.y < RESO_Y - 1)
	{
		rc->mult = rc->pix.y * 2 - RESO_Y + fl_lineh;
		rc->tex.y = (((int)rc->mult * x->y) / fl_lineh) / 2;
		if (rc->tex.y < 0);
		else
			if (x)
				draw_texture(e->mlx, x, rc);
		rc->pix.y++;
	}
}

void		draw_floor(t_e *e, t_rc rc)
{
	if (rc.drawend != RESO_Y - 1)
		todraw(e, &rc, return_xpm(&e->lxpm, "./image/floor.xpm"));
}
