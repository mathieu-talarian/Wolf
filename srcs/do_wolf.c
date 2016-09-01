/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 20:00:18 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/01 20:09:31 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		initialize_mlx(t_mlx **m)
{
	t_mlx *mlx;

	mlx = *m;
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, RESO_X, RESO_Y, "wolf");
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_a = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->e);
	D.dirx = 1;
	D.diry = 0; //initial direction vector
	D.time = 0; //time of current frame
	D.oldtime = 0; //time of previous frame
	D.planex = 0;
	D.planey = 0.66; //the 2d raycaster version of camera plane
	D.posx = 12;
	D.posy = 12;  //x and y start position



}

void		do_wolf(t_e *e)
{
	initialize_mlx(&e->mlx);
}
