/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 20:00:18 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 20:30:31 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_mlx		*initialize_mlx(t_vect s, t_draw *draw)
{
	t_mlx *mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, RESO_X, RESO_Y, "wolf");
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_a = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->e);
	E.dirx = 1;
	E.diry = 0;
	E.time = 0;
	E.oldtime = 0;
	E.planex = 0;
	E.planey = 0.66;
	E.pos.x = s.x + 0.5;
	E.pos.y = s.y + 0.5;
	E.movespeed = 0.1;
	E.acceleration = 1;
	return (mlx);
}

void		print_xpm(t_lxpm **li)
{
	t_lxpm *l;

	l = *li;
	while (l)
	{
		printf("%s\n", l->fn);
		l = l->next;
	}
}

int			do_wolf_3d(t_e *e)
{
	moove(e);
	wolf_3d(e);
	mlx_put_image_to_window(M, W, I, 0, 0);
	return (0);
}

void		do_wolf(t_e *e, char **av)
{
	e->i = 0;
	e->c = 0;
	e->mlx = initialize_mlx(e->start, &e->draw);
	if (!(fill_xpm(&e, av)))
		exit(0);
	mlx_loop_hook(e->mlx->mlx, do_wolf_3d, e);
	mlx_hook(W, 17, 1L << 17, red_button, e);
	mlx_hook(W, 2, 1L << 0, key_press, e);
	mlx_hook(W, 3, 1L << 1, key_release, e);
	mlx_loop(e->mlx->mlx);
}
