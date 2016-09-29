/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:23:28 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 21:54:03 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static void	draw_bl(t_mlx *mlx, t_rc *rc)
{
	int i;

	rc->pix.y = rc->drawstart - 1;
	while (++rc->pix.y < rc->drawend)
	{
		i = (rc->pix.x * 4) + (rc->pix.y * mlx->sl);
		mlx->d_a[i] = 0;
		mlx->d_a[++i] = 0;
		mlx->d_a[++i] = 0;
	}
}

void		textures(t_e *e, t_rc *rc)
{
	if (mapping(&e->map, rc->map.x, rc->map.y) == 5)
		comp_texture(e, rc, return_xpm(&e->lxpm, "./image/wood.xpm"));
	else if (mapping(&e->map, rc->map.x, rc->map.y) == 3)
		comp_texture(e, rc, return_xpm(&e->lxpm, "./image/stone.xpm"));
	else if (mapping(&e->map, rc->map.x, rc->map.y) == 6)
		comp_texture(e, rc, return_xpm(&e->lxpm, "./image/po.xpm"));
	else if (mapping(&e->map, rc->map.x, rc->map.y) == 7)
		draw_bl(e->mlx, rc);
	else if (mapping(&e->map, rc->map.x, rc->map.y) == 8)
		comp_texture(e, rc, return_xpm(&e->lxpm, "./image/stone.xpm"));
	else if (mapping(&e->map, rc->map.x, rc->map.y) == 9)
		comp_texture(e, rc, return_xpm(&e->lxpm, "./image/wll.xpm"));
	else
		comp_texture(e, rc, return_xpm(&e->lxpm, "aa"));
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
