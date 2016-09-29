/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_grb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:07:04 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 22:13:42 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_rgb	do_c2(t_hsv hsv, t_crgb c)
{
	if (c.i == 3)
	{
		c.r.r = c.p;
		c.r.g = c.q;
		c.r.b = hsv.v;
	}
	else if (c.i == 4)
	{
		c.r.r = c.t;
		c.r.g = c.p;
		c.r.b = hsv.v;
	}
	else
	{
		c.r.r = hsv.v;
		c.r.g = c.p;
		c.r.b = c.q;
	}
	return (c.r);
}

t_rgb	do_c(t_hsv hsv, t_crgb c)
{
	if (c.i == 0)
	{
		c.r.r = hsv.v;
		c.r.g = c.t;
		c.r.b = c.p;
	}
	else if (c.i == 1)
	{
		c.r.r = c.q;
		c.r.g = hsv.v;
		c.r.b = c.p;
	}
	else if (c.i == 2)
	{
		c.r.r = c.p;
		c.r.g = hsv.v;
		c.r.b = c.t;
	}
	else
		return (do_c2(hsv, c));
	return (c.r);
}

t_rgb	hsv_to_rgb(t_hsv hsv)
{
	t_crgb	c;

	if (hsv.s == 0)
	{
		c.r.r = hsv.v;
		c.r.g = hsv.v;
		c.r.b = hsv.v;
		c.r.r *= 255;
		c.r.g *= 255;
		c.r.b *= 255;
		return (c.r);
	}
	c.hh = hsv.h;
	if (c.hh >= 360)
		c.hh = 0;
	c.hh /= 60;
	c.i = (long)c.hh;
	c.ff = c.hh - c.i;
	c.p = hsv.v * (1.0 - hsv.s);
	c.q = hsv.v * (1.0 - (hsv.s * c.ff));
	c.t = hsv.v * (1.0 - (hsv.s * (1.0 - c.ff)));
	return (do_c(hsv, c));
}
