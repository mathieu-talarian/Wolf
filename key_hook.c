/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 18:26:32 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/25 16:36:18 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
# define ABS(X) (x < 0 ? (x * -1) : x)

void	do_print_d(t_d d)
{
	printf("dirx = %f\n", d.dir.x);
	printf("diry = %f\n", d.dir.y);
	printf("dposx = %f\n", d.pos.x);
	printf("dposy = %f\n", d.pos.y);
	printf("dplanex = %f\n", d.plane.x);
	printf("dplaney = %f\n", d.plane.y);
}

void	rd(t_mlx *mlx)
{
	do_print_d(D);
	mlx_destroy_image(mlx->mlx, mlx->img);
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->endian);
	do_it(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

int		key_hook(int keycode, t_mlx *mlx)
{
	double movespeed = 0.2;
	double rotspeed = 0.2;
	double olddirx = D.dir.x;
	double oldplanex = D.plane.x;
	
	printf("%d\n", keycode);
	if (keycode == 53)
		exit (0);
	if (keycode == 126)
	{
		D.pos.x += D.dir.x * movespeed;
		D.pos.y += D.dir.y * movespeed;
	}
	else if (keycode == 125)
	{
		D.pos.x -= D.dir.x * movespeed;
		D.pos.y -= D.dir.y * movespeed;
	}
	else if (keycode == 123)
	{
		olddirx = D.dir.x;
		oldplanex = D.plane.x;
		D.dir.x = D.dir.x * cos(-rotspeed) - D.dir.y * sin(-rotspeed);
		D.dir.y = olddirx * sin(-rotspeed) + D.dir.y * cos(-rotspeed);
		D.plane.x = D.plane.x * cos(-rotspeed) - D.plane.y * sin(-rotspeed);
		D.plane.y = oldplanex * sin(-rotspeed) + D.plane.y * cos(-rotspeed);
	}
	else if (keycode == 124)
	{
		olddirx = D.dir.x;
		oldplanex = D.plane.x;
		D.dir.x = D.dir.x * cos(rotspeed) - D.dir.y * sin(rotspeed);
		D.dir.y = olddirx * sin(rotspeed) + D.dir.y * cos(rotspeed);
		D.plane.x = D.plane.x * cos(rotspeed) - D.plane.y * sin(rotspeed);
		D.plane.y = oldplanex * sin(rotspeed) + D.plane.y * cos(rotspeed);
	}
	rd(mlx);
	return (0);
}
