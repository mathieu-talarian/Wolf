/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:23:28 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/27 19:47:09 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		textures(t_e *e, t_rc *rc)
{
	double test;
	if (mapping(&e->map, rc->map.x, rc->map.y) == 1)
		comp_texture(e, rc, return_xpm(&e->lxpm, "./image/greystone.xpm"));
	else if (mapping(&e->map, rc->map.x, rc->map.y) == 2)
		comp_texture(e, rc, return_xpm(&e->lxpm, "./image/floor.xpm"));
}

void		draw_texture(t_mlx *mlx, t_lxpm *sto, t_rc *rc)
{
	t_ivect i;

	i.x = (rc->pix.x * 4) + (rc->pix.y * mlx->sl);
	i.y = (rc->tex.x * 4) + (rc->tex.y * sto->sl);
	mlx->d_a[i.x] = sto->d_a[i.y];
	mlx->d_a[++i.x] = sto->d_a[++i.y];
	mlx->d_a[++i.x] = sto->d_a[++i.y];
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
