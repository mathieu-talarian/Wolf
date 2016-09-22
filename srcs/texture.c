/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:23:28 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/22 19:34:18 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"


void	draw_texture(t_mlx *mlx, t_lxpm *sto, t_rc *rc, t_hsv h)
{
	t_rgb r;
	t_rgb r2;
	t_hsv h1;
	t_ivect i;

	i.x = (rc->pix.x * 4) + (rc->pix.y * mlx->sl);
	i.y = (rc->tex.x * 4) + (rc->tex.y * sto->sl);
	r.b = sto->d_a[i.y];
	r.g = sto->d_a[++i.y];
	r.r = sto->d_a[++i.y];
	h1 = rgb_to_hsv(r);
//	h1.v = h.v;
//	if (rc->side == 1)
//		h1.s /= 2;
	r2 = hsv_to_rgb(h1);
//	if (r.b != r2.b || r.g != r2.g || r.r != r2.r)
//	{
		printf("r =  %f | %f | %f\n", r.r, r.g, r.b);
		printf("r2 = %f | %f | %f\n", r2.r, r2.g, r2.b);
//		exit (0);
//	}
	mlx->d_a[i.x] = r2.b;
	mlx->d_a[++i.x] = r2.g;
	mlx->d_a[++i.x] = r2.r;
}

t_lxpm		*return_xpm(t_lxpm **p, char *fn)
{
	t_lxpm *l;
	l = *p;
	if (l)
	{
		while (l)
		{
			if ((ft_strcmp(l->fn, fn)) == 0)
				return (l);
			l = l->next;
		}
	}
	return (NULL);
}

