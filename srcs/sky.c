/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:14:07 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/08 21:01:53 by mmoullec         ###   ########.fr       */
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

t_rgb	hsv_to_rgb(t_hsv hsv)
{
	t_rgb rgb;
	int ti;
	double f, l, m, n;

	if (hsv.s == 0)
	{
		rgb.r = hsv.v;
		rgb.g = hsv.v;
		rgb.b = hsv.v;
		rgb.r *= 255;
		rgb.g *= 255;
		rgb.b *= 255;
		return (rgb);
	}
	ti = (int)(hsv.h / 6) % 6;
	f = (hsv.h / 60) - ti;
	l = hsv.v * (1 - hsv.s);
	m = hsv.v * (1 - f * hsv.s);
	n = hsv.v * (1 - (1 - f) * hsv.s);

   switch (ti)
    {
		case 0:
			rgb.r = hsv.v; rgb.g = n; rgb.b = l;
		break;
        case 1:
			rgb.r = m; rgb.g = hsv.v; rgb.b = l;
		break;
		case 2:
			rgb.r = l; rgb.g = hsv.v; rgb.b = n;
		break;
		case 3:
			rgb.r = l; rgb.g = m; rgb.b = hsv.v;
		break;
		case 4:
			rgb.r = n; rgb.g = l; rgb.b = hsv.v;
		break;
		default:
		rgb.r = hsv.v; rgb.g = l; rgb.b = m;
		break;
	}
		rgb.r *= 255;
		rgb.g *= 255;
		rgb.b *= 255;
	return rgb;
}

void	sky(t_e *e, int x)
{
	t_hsv hsv;
	t_rgb rgb;
	t_l l;

	double sw = (((RESO_Y / DIS_V) / 2 ));
	double delta = 1 / (double)((RESO_Y  - sw) / 2);
	hsv.h = 205;
	hsv.s = 0.47;
	l.x = x;
	l.y = -1;
	hsv.v = 1;

	while (++l.y < RESO_Y / 2 && hsv.v >= 0)
	{
		hsv.v -= delta;
		rgb = hsv_to_rgb(hsv);
		put_color_to_pixel(e->mlx, l, rgb);
	}
}

void	ground(t_e *e, int x)
{
	t_hsv hsv;
	t_rgb rgb;
	t_l l;

	double sw = (((RESO_Y / DIS_V) / 2));
	double delta = 1 / (double)((RESO_Y  - sw) / 2);
	hsv.h = 0;
	hsv.s = 0;
	l.x = x;
	l.y = RESO_Y - 1;
	hsv.v = 1;
	while (--l.y > RESO_Y / 2 && hsv.v >= 0)
	{
		hsv.v -= delta;
		rgb = hsv_to_rgb(hsv);
		put_color_to_pixel(e->mlx, l, rgb);
	}
}

void	wall(t_e *e, int x, int ds, int de, t_hsv hsv)
{
	t_rgb rgb;
	rgb = hsv_to_rgb(hsv);
	draw_line(e, x, ds, de, rgb);
}
