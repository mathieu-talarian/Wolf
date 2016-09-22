/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hsv_to_grb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 16:07:04 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/22 19:34:27 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_rgb	hsv_to_rgb(t_hsv hsv)
{
	t_rgb rgb;
	long i;
	double hh, p, q, t, ff;

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
	hh = hsv.h;
	if (hh >= 360)
		hh = 0;
	hh /= 60;
	i = (long)hh;
	ff = hh - i;
	p = hsv.v * (1.0 - hsv.s);
	q = hsv.v * (1.0 - (hsv.s * ff));
	t = hsv.v * (1.0- (hsv.s * (1.0 - ff)));

   switch (i)
    {
		case 0:
			rgb.r = hsv.v; 
			rgb.g = t; 
			rgb.b = p;
		break;
        case 1:
			rgb.r = q; 
			rgb.g = hsv.v; 
			rgb.b = p;
		break;
		case 2:
			rgb.r = p; 
			rgb.g = hsv.v; 
			rgb.b = t;
		break;
		case 3:
			rgb.r = p; 
			rgb.g = q; 
			rgb.b = hsv.v;
		break;
		case 4:
			rgb.r = t; 
			rgb.g = p; 
			rgb.b = hsv.v;
		break;
		default:
		rgb.r = hsv.v; 
		rgb.g = p; 
		rgb.b = q;
		break;
	}
		rgb.r *= 255;
		rgb.g *= 255;
		rgb.b *= 255;
	return rgb;
}
