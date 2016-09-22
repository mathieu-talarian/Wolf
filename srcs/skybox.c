/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 17:35:19 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/22 16:47:52 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	cpy_color(t_mlx *m, t_lxpm *p, int x, int y)
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

void	cpy_img(t_mlx *m, t_lxpm **p)
{
	int x = -1;
	int y = -1;
	t_lxpm *sb;

	sb = return_xpm(p, "./image/sb.xpm");
	if (sb)
	{
		while (++y < RESO_Y)
		{
			x = -1;
			while (++x < RESO_X)
				cpy_color(m, sb, x, y);
		}
	}
}

t_lxpm		*find_xpm(t_mlx *mlx, char *fn)
{
	t_lxpm *x;
	x = (t_lxpm *)malloc(sizeof(t_lxpm));
	x->img = mlx_xpm_file_to_image(mlx->mlx, fn, &x->x, &x->y);
	if (x->img == NULL)
	{
		free (x);
		return (NULL);
	}
	x->fn = ft_strdup(fn);
	x->d_a = mlx_get_data_addr(x->img, &x->bpp, &x->sl, &x->e);
	return (x);
}
