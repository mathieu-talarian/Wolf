/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:23:28 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/26 19:15:00 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"


void	draw_texture(t_mlx *mlx, t_lxpm *sto, t_rc *rc)
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

