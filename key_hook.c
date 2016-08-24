/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 18:26:32 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/24 18:59:51 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	rd(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, 512, 384);
	mlx->d_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->endian);
	do_it(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

int		key_hook(int keycode, t_mlx *mlx)
{
	printf("%d\n", keycode);
	if (keycode == 53)
		exit (0);
	if (keycode == 123)
	{
		mlx->dirX+=0.01;
		mlx->dirY-=0.01;
		mlx_destroy_image(mlx->mlx, mlx->img);
		rd(mlx);
	}
	if (keycode == 124)
	{
		mlx->dirX-=0.01;
		mlx->dirX+=0.01;
		mlx_destroy_image(mlx->mlx, mlx->img);
		rd(mlx);
	}
	if (keycode == 126)
	{
		mlx->dirX+=0.01;
		mlx->dirY+=0.01;
		mlx_destroy_image(mlx->mlx, mlx->img);
		rd(mlx);
	}
	if (keycode == 125)
	{
		mlx->dirX-=0.01;
		mlx->dirY-=0.01;
		mlx_destroy_image(mlx->mlx, mlx->img);
		rd(mlx);
	}
	return (0);
}
