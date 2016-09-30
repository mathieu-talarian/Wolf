/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 17:44:31 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 20:51:42 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		put_color_to_pixel(t_mlx *mlx, t_l l, t_rgb rgb)
{
	int				j;

	j = (l.x * 4) + (l.y * mlx->sl);
	mlx->d_a[j] = rgb.b;
	mlx->d_a[++j] = rgb.g;
	mlx->d_a[++j] = rgb.r;
}

void		line_1(t_mlx *mlx, t_l l, t_rgb rgb)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	l.cumul = l.dx / 2;
	while (++i <= l.dx)
	{
		l.x += l.xinc;
		l.cumul += l.dy;
		if (l.cumul >= l.dx)
		{
			l.cumul -= l.dx;
			l.y += l.yinc;
		}
		put_color_to_pixel(mlx, l, rgb);
	}
}

void		line_2(t_mlx *mlx, t_l l, t_rgb rgb)
{
	int		i;
	int		cpt;

	i = 0;
	cpt = 0;
	l.cumul = l.dy / 2;
	while (++i <= l.dy)
	{
		l.y += l.yinc;
		l.cumul += l.dx;
		if (l.cumul >= l.dy)
		{
			l.cumul -= l.dy;
			l.x += l.xinc;
		}
		put_color_to_pixel(mlx, l, rgb);
	}
}
