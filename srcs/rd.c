/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/09 15:30:42 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 20:32:07 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
#define F e->draw.d

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
	if (e->i == 0 && (int)F.pos.y == 1 && ((int)F.pos.x == 13 \
				|| (int)F.pos.x == 14))
		new_map(e);
	if (e->i == 1 && (int)F.pos.y == 32 && ((int)F.pos.x == 9 \
				|| (int)F.pos.x == 10))
		new_map2(e);
	mlx_img_to_black(e->mlx);
}
