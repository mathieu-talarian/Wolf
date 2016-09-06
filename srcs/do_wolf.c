/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 20:00:18 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/06 19:59:42 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_mlx		*initialize_mlx(t_draw *draw)
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
	E.pos.x = 12;
	E.pos.y = 12;  //x and y start position
	return (mlx);
}

void		do_wolf(t_e *e)
{
	print_map(&e->map);
	e->mlx = initialize_mlx(&e->draw);
	wolf_3d(e);
	mlx_put_image_to_window(M, W, I, 0, 0);
	mlx_hook(W, 2, 1L << 0, key_hook, e);
	mlx_loop(e->mlx->mlx);
}
