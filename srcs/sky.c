/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:14:07 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/07 21:13:21 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

typedef struct	s_calcolor
{
	double		hh;
	double		p;
	double		q;
	double		t;
	double		ff;
	long		i;
}				t_cc;

void	hsv_to_rgb(t_hsv h, t_rgb *r)
{
	t_cc	c;

	if (h.s == 0)
	{
		r->r = h.h;
		r->g = h.h;
		r->b = h.h;
	}
	c.hh = h.h;
	if (c.hh >= 360.0)
		c.hh = 0;
	c.hh /= 60;
	c.i = (long)c.hh;
	c.ff = c.hh - c.i;
	c.p = h.v * (1.0 - h.s);
	c.q = h.v * (1.0 - (h.s * c.ff));
	c.t = h.v * (1.0 - (h.s * (1.0 - c.ff)));
	switch(c.i) {
		case 0:
			r->r = h.v;
			r->g = c.t;
			r->b = c.p;
		break;
		case 1:
		r->r = c.q;
		r->g = h.v;
		r->b = c.p;
		break;
		case 2:
		r->r = c.p;
		r->g = h.v;
		r->b = c.t;
		break;
		case 3:
		r->r = c.p;
		r->g = c.q;
		r->b = h.v;
		break;
		case 4:
		r->r = c.t;
		r->g = c.p;
		r->b = h.v;
		break;
		case 5:
		default:
		r->r = h.v;
		r->g = c.p;
		r->b = c.q;
		break;
				}
}

void	sky(t_e *e, int ds, int x, int val)
{
	t_hsv hsv;
	t_rgb rgb;
	if (ds > 1)
	{
		hsv.h = 205;
		hsv.s = 47;
		hsv.v = val;
		hsv_to_rgb(hsv, &rgb);
		draw_line(e, x, 0, ds - 1, rgb);
	}
}

void	ground(t_e *e, int de, int x, int val)
{
	t_rgb rgb;
	t_hsv hsv;
	if (de < RESO_Y - 1)
	{
		hsv.h = 0;
		hsv.s = 0;
		hsv.v = val;
		hsv_to_rgb(hsv, &rgb);
		draw_line(e, x, de + 1, RESO_Y - 1, rgb);
	}
}

void	wall(t_e *e, int x, int ds, int de, t_hsv hsv)
{
	t_rgb rgb;
	hsv_to_rgb(hsv, &rgb);
	draw_line(e, x, ds, de, rgb);
}
