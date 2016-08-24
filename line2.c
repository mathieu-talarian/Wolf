/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 17:44:31 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/24 17:49:49 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		put_color_to_pixel(t_mlx *mlx, t_draw draw, t_rgb rgb)
{
	int				j;

	j = (draw.x * 4) + (draw.y * mlx->sizeline);
	mlx->d_addr[j] = rgb.r;
	mlx->d_addr[++j] = rgb.g;
	mlx->d_addr[++j] = rgb.b;
}

void		line_1(t_mlx *mlx, t_draw draw, t_rgb rgb)
{
	int i = 0;
	int cpt = 0;
	int j = 0;
	draw.cumul = draw.dx / 2;
	while (++i <= draw.dx)
	{
		draw.x += draw.xinc;
		draw.cumul += draw.dy;
		if (draw.cumul >= draw.dx)
		{
			draw.cumul -= draw.dx;
			draw.y += draw.yinc;
		}
		put_color_to_pixel(mlx, draw, rgb);
	}
}

void		line_2(t_mlx *mlx, t_draw draw, t_rgb rgb)
{
	int i = 0;
	int cpt = 0;
	int j = 0;
	draw.cumul = draw.dy / 2;
	while (++i <= draw.dy)
	{
		draw.y += draw.yinc;
		draw.cumul += draw.dx;
		if (draw.cumul >= draw.dy)
		{
			draw.cumul -= draw.dy;
			draw.x += draw.xinc;
		}
		put_color_to_pixel(mlx, draw, rgb);
	}
}


