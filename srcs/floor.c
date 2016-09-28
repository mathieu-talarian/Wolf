/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 17:21:58 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/28 20:34:05 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_lxpm		*find_text(t_e *e, double x, double y)
{
	int i;

	i = mapping(&e->map, (int)x, (int)y);
	if (i == 1)
		return (return_xpm(&e->lxpm, "./image/w/ww1.xpm"));
	if (i == 0)
		return (return_xpm(&e->lxpm, "./image/grass.xpm"));
	if (i == -1)
		return (return_xpm(&e->lxpm, "./image/ground.xpm"));
	if (i == -2)
		return (return_xpm(&e->lxpm, "./image/greystone.xpm"));
	if (i == -6)
		return (return_xpm(&e->lxpm, "./image/ground.xpm"));
	return (NULL);
}

void		todraw(t_e *e, t_rc rc, t_rc *fl)
{
	int y;
	t_lxpm *f;

	fl->pix.y = fl->drawstart - 2;
	fl->pix.x = rc.pix.x;
	while (++fl->pix.y < RESO_Y - 1)
	{
		fl->mult = RESO_Y / (2.0 * fl->pix.y - RESO_Y);
		fl->wallx = fl->mult / rc.walldist;
		fl->raypos.x = fl->wallx * fl->deltadist.x + (1 - fl->wallx) * rc.raypos.x;
		fl->raypos.y = fl->wallx * fl->deltadist.y + (1 - fl->wallx) * rc.raypos.y;
		f = find_text(e, fl->raypos.x, fl->raypos.y);
		if (f)
		{
			fl->tex.x = (int)(fl->raypos.x * f->x) % f->x;
			fl->tex.y = (int)(fl->raypos.y * f->x) % f->x;
			draw_texture(e->mlx, f, fl);
		}
	}
}

void		init_fl_rc(t_e *e, t_rc rc, t_rc *fl)
{
	fl->deltadist.y = rc.map.y + rc.wallx;
	fl->deltadist.x = rc.map.x + rc.wallx;
	if (rc.side == 0 && rc.raydir.x > 0)
		fl->deltadist.x = rc.map.x;
	else if (rc.side == 0 && rc.raydir.x < 0)
		fl->deltadist.x = rc.map.x + 1.0;
	else if (rc.side == 1 && rc.raydir.y > 0)
		fl->deltadist.y = rc.map.y;
	else
		fl->deltadist.y = rc.map.y + 1.0;
	if (rc.drawend < RESO_Y - 1)
	{
		fl->drawend = RESO_Y - 1;
		fl->drawstart = rc.drawend;
	}
	else
	{
		fl->drawend = 0;
		fl->drawstart = 0;
	}
}

void		draw_floor(t_e *e, t_rc rc)
{
	t_rc flrc;
	init_fl_rc(e, rc, &flrc);
	if (rc.drawend != RESO_Y - 1)
		todraw(e, rc, &flrc);
}
