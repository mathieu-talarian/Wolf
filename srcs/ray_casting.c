/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 15:59:26 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/27 21:00:40 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "wolf.h"

void		init_rc(t_e *e, t_rc *rc)
{
	rc->pix.y = 0;
	rc->cam.x = 2 * rc->pix.x / (double)RESO_X - 1;
	rc->raypos.x = e->D.pos.x;
	rc->raypos.y = e->D.pos.y;
	rc->raydir.x = e->D.dirx + e->D.planex * rc->cam.x;
	rc->raydir.y = e->D.diry + e->D.planey * rc->cam.x;
	rc->map.x = (int)rc->raypos.x;
	rc->map.y = (int)rc->raypos.y;
	rc->deltadist.x = sqrt(1 + (carre(rc->raydir.y)) / (carre(rc->raydir.x)));
	rc->deltadist.y = sqrt(1 + (carre(rc->raydir.x)) / (carre(rc->raydir.y)));
	rc->hit = 0;
}

void		calc_map(t_rc *rc)
{
	if (rc->raydir.x < 0)
	{
		rc->step.x = -1;
		rc->sidedist.x = (rc->raypos.x - rc->map.x) * rc->deltadist.x;
	}
	else
	{
		rc->step.x = 1;
		rc->sidedist.x = (rc->map.x + 1.0 - rc->raypos.x) * rc->deltadist.x;
	}
	if (rc->raydir.y < 0)
	{
		rc->step.y = -1;
		rc->sidedist.y = (rc->raypos.y - rc->map.y) * rc->deltadist.y;
	}
	else
	{
		rc->step.y = 1;
		rc->sidedist.y = (rc->map.y + 1.0 - rc->raypos.y) * rc->deltadist.y;
	}
}

void		calc_dist(t_e *e, t_rc *rc)
{
	while (rc->hit == 0)
	{
		if (rc->sidedist.x < rc->sidedist.y)
		{
			rc->sidedist.x += rc->deltadist.x;
			rc->map.x += rc->step.x;
			rc->side = 0;
		}
		else
		{
			rc->sidedist.y += rc->deltadist.y;
			rc->map.y += rc->step.y;
			rc->side = 1;
		}
		if (mapping(&e->map, rc->map.x, rc->map.y) > 0) 
			rc->hit = 1;
	}
}

void		calc_line(t_rc *rc)
{
	if (rc->side == 0) 
		rc->walldist = (rc->map.x - rc->raypos.x + (1 - rc->step.x) / 2) / \
					rc->raydir.x;
	else
		rc->walldist = (rc->map.y - rc->raypos.y + (1 - rc->step.y) / 2) / \
					rc->raydir.y;
	if (rc->walldist <= 0)
		rc->walldist = 1;
	rc->lineheight = (int)(RESO_Y / rc->walldist);
	rc->drawstart = -rc->lineheight / 2 + RESO_Y / 2;
	if(rc->drawstart < 0)
		rc->drawstart = 0;
	rc->drawend = rc->lineheight / 2 + RESO_Y / 2;
	if(rc->drawend >= RESO_Y)
		rc->drawend = RESO_Y - 1;
}


void		ray_casting(t_e *e)
{
	t_rc	rc;
	t_hsv	hsv;
	rc.pix.x = -1;
	skybox();
	while (++rc.pix.x < RESO_X)
	{
		init_rc(e, &rc);
		calc_map(&rc);
		calc_dist(e, &rc);
		calc_line(&rc);
		textures(e, &rc);
//		else
//		{
//			if (mapping(&e->map, rc.map.x, rc.map.y) == 3)
//				hsv.h = 240;
//			if (mapping(&e->map, rc.map.x, rc.map.y) == 4)
//				hsv.h = 60;
//			if (rc.side == 1)
//				hsv.s = 0.5;
//			else
//				hsv.s = 1;
//			wall(e, rc.pix.x, rc.drawstart, rc.drawend, hsv);
//		}
		draw_floor(e, rc);
	}
}
