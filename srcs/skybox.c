/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 17:35:19 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 20:52:27 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		cpy_color(t_mlx *m, t_lxpm *p, int x, int y)
{
	int j;
	int l;

	j = (x * 4) + (y * m->sl);
	l = (x * 4) + (y * p->sl);
	m->d_a[j] = p->d_a[l];
	m->d_a[++j] = p->d_a[++l];
	m->d_a[++j] = p->d_a[++l];
	m->d_a[++j] = 10;
}

void		skybox(t_e *e, t_lxpm *sb)
{
	int x;
	int y;

	x = -1;
	y = -1;
	if (!sb || e->i == 1)
	{
		sky(e);
		return ;
	}
	while (++y < RESO_Y)
	{
		x = -1;
		while (++x < RESO_X)
			cpy_color(e->mlx, sb, x, y);
	}
}

t_lxpm		*find_xpm(t_mlx *mlx, char *fn)
{
	t_lxpm *x;

	x = (t_lxpm *)malloc(sizeof(t_lxpm));
	x->img = mlx_xpm_file_to_image(mlx->mlx, fn, &x->x, &x->y);
	if (x->img == NULL)
	{
		free(x);
		return (NULL);
	}
	x->fn = ft_strdup(fn);
	x->d_a = mlx_get_data_addr(x->img, &x->bpp, &x->sl, &x->e);
	return (x);
}
