/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notextures.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:59:50 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 21:50:45 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_line(t_mlx *mlx, t_rgb rgb, t_rc rc)
{
	int x;
	int y;
	int j;

	x = rc.pix.x;
	y = rc.drawstart - 1;
	while (++y < rc.drawend)
	{
		j = (x * 4) + (y * mlx->sl);
		mlx->d_a[j] = rgb.b;
		mlx->d_a[++j] = rgb.g;
		mlx->d_a[++j] = rgb.r;
	}
}

void	notextures(t_e *e, t_rc rc)
{
	t_hsv hsv;

	hsv.v = 1;
	if (rc.side == 1)
		hsv.v = 0.5;
	hsv.s = 0.5;
	if (mapping(&e->map, rc.map.x, rc.map.y) == 4)
		hsv.h = 200;
	else if (mapping(&e->map, rc.map.x, rc.map.y) == 5)
		hsv.h = 210;
	else if (mapping(&e->map, rc.map.x, rc.map.y) == 6)
		hsv.h = 120;
	else if (mapping(&e->map, rc.map.x, rc.map.y) == 7)
		hsv.h = 160;
	else if (mapping(&e->map, rc.map.x, rc.map.y) == 8)
		hsv.h = 50;
	else if (mapping(&e->map, rc.map.x, rc.map.y) == 9)
		hsv.v = 70;
	draw_line(e->mlx, hsv_to_rgb(hsv), rc);
}
