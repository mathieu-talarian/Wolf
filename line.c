/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 17:06:32 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/24 17:55:58 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		line_to_pixel(t_mlx *mlx, t_draw draw, t_rgb rgb)
{
	put_color_to_pixel(mlx, draw, rgb);
	if (draw.dx > draw.dy)
		line_1(mlx, draw, rgb);
	else
		line_2(mlx, draw, rgb);
}

void		ligne(t_mlx *mlx, t_pts pts, t_rgb rgb)
{
	t_draw	draw;

	draw.x = pts.x0;
	draw.y = pts.y0;
	draw.dx = pts.x1 - pts.x0;
	draw.dy = pts.y1 - pts.y0;
	draw.xinc = (draw.dx > 0) ? 1 : -1;
	draw.yinc = (draw.dy > 0) ? 1 : -1;
	draw.dx = abs(draw.dx);
	draw.dy = abs(draw.dy);
	line_to_pixel(mlx, draw, rgb);
}

void	verLine(t_mlx *mlx, int x, int y0, int y1, t_rgb rgb)
{
	t_pts pts;
	pts.x0 = x;
	pts.x1 = x;
	pts.y0 = y0;
	pts.y1 = y1;
	ligne(mlx, pts, rgb);
}
