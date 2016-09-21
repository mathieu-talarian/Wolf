/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 12:23:28 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/21 17:52:06 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	draw_texture(t_mlx *mlx, t_lxpm *sto, int x, int y, t_vect tex)
{
	int i;
	int j;

	i = (x * 4) + (y * mlx->sl);
	j = (tex.x * 4) + (tex.y * sto->sl);
	unsigned int b = sto->d_a[j];
	unsigned int g = sto->d_a[++j];
	unsigned int r = sto->d_a[++j];
	if (b != 0 && g != 0 && r != 0)
	{
		mlx->d_a[i] = b;
		mlx->d_a[++i] = g;
		mlx->d_a[++i] = r;
	}
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

