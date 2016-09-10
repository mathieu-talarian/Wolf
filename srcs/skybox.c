/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skybox.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/10 17:35:19 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/10 20:12:47 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	cpy_color(t_mlx *m, t_xpm *p, int x, int y)
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

void	cpy_img(t_mlx *m, t_xpm *p)
{
	int x = -1;
	int y = -1;

	while (++y < RESO_Y)
	{
		x = -1;
		while (++x < RESO_X)
		{
			cpy_color(m, p, x, y);
		}
	}

}

t_xpm		*skybox(t_mlx *mlx)
{
	t_xpm *x;
	x = (t_xpm *)malloc(sizeof(t_xpm));
	x->img = mlx_xpm_file_to_image(mlx->mlx, "./sb.xpm", &x->x, &x->y);
	printf("%d %d\n", x->x, x->y);
	x->d_a = mlx_get_data_addr(x->img, &x->bpp, &x->sl, &x->e);
	return (x);
}
