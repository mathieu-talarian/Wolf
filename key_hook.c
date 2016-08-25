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
	printf("dirx = %f\n", d.dirx);
	printf("diry = %f\n", d.diry);
	printf("dposx = %f\n", d.posx);
	printf("dposy = %f\n", d.posy);
	printf("dplanex = %f\n", d.planex);
	printf("dplaney = %f\n", d.planey);
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
	double movespeed = 0.1;
	double rotspeed = 0.3;
	double olddirx = D.dirx;
	double oldplanex = D.planex;
	
	printf("%d\n", keycode);
	if (keycode == 53)
		exit (0);
/*	if (keycode == 126)
	{
		D.posx += D.dirx * movespeed;
		D.posy += D.diry * movespeed;
	}
	else if (keycode == 125)
	{
		D.posx -= D.dirx * movespeed;
		D.posy -= D.diry * movespeed;
	}
	else if (keycode == 123)
	{
		D.posx += D.planex * movespeed;
		D.posy += D.planey * movespeed;
	}*/
/*	
	else if (keycode == 123)
	{
		olddirx = D.dirx;
		oldplanex = D.planex;
		D.dirx = D.dirx * cos(-rotspeed) - D.diry * sin(-rotspeed);
		D.diry = olddirx * sin(-rotspeed) + D.diry * cos(-rotspeed);
		D.planex = D.planex * cos(-rotspeed) - D.planey * sin(-rotspeed);
		D.planey = oldplanex * sin(-rotspeed) + D.planey * cos(-rotspeed);
	}
	else if (keycode == 124)
	{
		olddirx = D.dirx;
		oldplanex = D.planex;
		D.dirx = D.dirx * cos(rotspeed) - D.diry * sin(rotspeed);
		D.diry = olddirx * sin(rotspeed) + D.diry * cos(rotspeed);
		D.planex = D.planex * cos(rotspeed) - D.planey * sin(rotspeed);
		D.planey = oldplanex * sin(rotspeed) + D.planey * cos(rotspeed);
	}
	*/
	if (keycode == 126)
		D.dirx += 0.1;
	else if (keycode == 125)
		D.dirx -= 0.1;
	else if (keycode == 123)
		D.diry -= 0.1;
	else if (keycode == 124)
		D.diry += 0.1;
	else if (keycode == 13)
		D.posx+=1;
	else if (keycode == 1)
		D.posx-=1;
	else if (keycode == 0)
		D.posy-=1;
	else if (keycode == 2)
		D.posy+=1;
	else if (keycode == 87)
		D.planex+=0.1;
	else if (keycode == 84)
		D.planex-=0.1;
	else if (keycode == 83)
		D.planey-=0.1;
	else if (keycode == 85)
		D.planey+=0.1;
	rd(mlx);
	return (0);
}
