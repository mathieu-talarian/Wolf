/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 14:14:07 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 21:53:59 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	sky(t_e *e)
{
	t_hsv	hsv;
	t_rgb	rgb;
	t_l		l;
	double	sw;
	double	delta;

	sw = (RESO_Y / DIS_V) / 2;
	delta = 1 / (double)((RESO_Y - sw) / 2);
	hsv.h = 0;
	hsv.s = 0;
	l.x = -1;
	while (++l.x < RESO_X)
	{
		l.y = -1;
		hsv.v = 1;
		while (++l.y < RESO_Y / 2 && hsv.v >= 0)
		{
			hsv.v -= delta;
			rgb = hsv_to_rgb(hsv);
			put_color_to_pixel(e->mlx, l, rgb);
		}
	}
}

void	ground(t_e *e)
{
	t_hsv	hsv;
	t_rgb	rgb;
	t_l		l;
	double	sw;
	double	delta;

	sw = (RESO_Y / DIS_V) / 2;
	delta = 1 / (double)((RESO_Y - sw) / 2);
	hsv.h = 0;
	hsv.s = 0;
	l.x = -1;
	while (++l.x < RESO_X)
	{
		l.y = RESO_Y - 1;
		hsv.v = 1;
		while (--l.y > RESO_Y / 2 && hsv.v >= 0)
		{
			hsv.v -= delta;
			rgb = hsv_to_rgb(hsv);
			put_color_to_pixel(e->mlx, l, rgb);
		}
	}
}
