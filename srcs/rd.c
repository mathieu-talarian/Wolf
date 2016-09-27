/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:30:42 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/27 12:42:50 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	mlx_img_to_black(t_mlx *mlx)
{
	t_l		l;
	t_rgb	r;

	r.r = 0;
	r.g = 0;
	r.b = 0;
	l.y = -1;
	while (++l.y < RESO_Y)
	{
		l.x = -1;
		while (++l.x < RESO_X)
		{
			put_color_to_pixel(mlx, l, r);
		}
	}
}

void	rd(t_e *e)
{
	mlx_img_to_black(e->mlx);
}
