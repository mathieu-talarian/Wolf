/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 20:00:18 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/09 15:38:58 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		print_datas(t_draw *draw)
{
	printf("dirx %f | diry %f\n", E.dirx, E.diry);
	printf("planex %f | planey %f\n", E.planex, E.planey);
	printf("posx %f | posy %f\n", E.pos.x, E.pos.y);
}

t_mlx		*initialize_mlx(t_vect s, t_draw *draw)
{
	t_mlx *mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, RESO_X, RESO_Y, "wolf");
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_a = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->e);
	E.dirx = 1;
	E.diry = 0; //initial direction vector
	E.time = 0; //time of current frame
	E.oldtime = 0; //time of previous frame
	E.planex = 0;
	E.planey = 0.66; //the 2d raycaster version of camera plane
	E.pos.x = s.x;
	E.pos.y = s.y;  //x and y start position
	E.movespeed = 0.1;
	return (mlx);
}

int	do_wolf_3d(t_e *e)
{
//	print_datas(&e->draw);
	moove(e);
	wolf_3d(e);
	mlx_put_image_to_window(M, W, I, 0, 0);
	return (0);
}

void		do_wolf(t_e *e)
{
	e->c = 0;
	e->mlx = initialize_mlx(e->start, &e->draw);
	int x = -1;
	mlx_loop_hook(e->mlx->mlx, do_wolf_3d, e);
	mlx_hook(W, 2, 1L << 0, key_press, e);
	mlx_hook(W, 3, 1L << 1, key_release, e);
	mlx_loop(e->mlx->mlx);
}
