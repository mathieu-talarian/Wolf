/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 18:26:32 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/06 18:32:57 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
# define ABS(X) (x < 0 ? (x * -1) : x)

void	rd(t_e *e)
{
	mlx_destroy_image(e->mlx->mlx, e->mlx->img);
	e->mlx->img = mlx_new_image(e->mlx->mlx, RESO_X, RESO_Y);
	e->mlx->d_a = mlx_get_data_addr(e->mlx->img, &e->mlx->bpp, &e->mlx->sl, &e->mlx->e);
	wolf_3d(e);
	mlx_put_image_to_window(e->mlx->mlx, e->mlx->win, e->mlx->img, 0, 0);
}

void	collision(t_map *map, t_vect *pos, t_vect oldpos)
{
	printf("pos x = %f | y = %f\n", pos->x, pos->y);
	printf("pos-int x = %d | y = %d\n", (int)pos->x, (int)pos->y);
	printf("mapping = %d\n", mapping(&map, (int)pos->x,(int)pos->y));
	if (mapping(&map, (int)pos->x, (int)pos->y) != 0)
	{
		pos->x = oldpos.x;
		pos->y = oldpos.y;
	}
}

void	mod(int keycode, t_draw *draw, t_map *map)
{
	double	movespeed = 0.2;
	double	rotspeed = 0.2;
	double	olddirx = draw->d.dirx;
	double	oldplanex = draw->d.planex;
	t_vect	oldpos;
	
	oldpos.x = E.pos.x;
	oldpos.y = E.pos.y;
	printf("%d\n", keycode);
	if (keycode == 53)
		exit (0);
	if (keycode == 13)
	{
		if (mapping(&map, E.pos.x + E.dirx * movespeed, E.pos.y) == 0)
			E.pos.x += E.dirx * movespeed;
		if (mapping(&map, E.pos.x, E.pos.y + E.diry * movespeed) == 0)
			E.pos.y += E.diry * movespeed;
	}
	else if (keycode == 1)
	{
		if (mapping(&map, E.pos.x - E.dirx * movespeed, E.pos.y) == 0)
			E.pos.x -= E.dirx * movespeed;
		if (mapping(&map, E.pos.x, E.pos.y - E.diry * movespeed) == 0)
		E.pos.y -= E.diry * movespeed;
	}
	else if (keycode == 123)
	{
		E.pos.x -= E.planex * movespeed;
		E.pos.y -= E.planey * movespeed;
	}
	else if (keycode == 124)
	{
		E.pos.x += E.planex * movespeed;
		E.pos.y += E.planey * movespeed;
	}
	else if (keycode == 0)
	{
		olddirx = E.dirx;
		oldplanex = E.planex;
		E.dirx = E.dirx * cos(-rotspeed) - E.diry * sin(-rotspeed);
		E.diry = olddirx * sin(-rotspeed) + E.diry * cos(-rotspeed);
		E.planex = E.planex * cos(-rotspeed) - E.planey * sin(-rotspeed);
		E.planey = oldplanex * sin(-rotspeed) + E.planey * cos(-rotspeed);
	}
	else if (keycode == 2)
	{
		olddirx = E.dirx;
		oldplanex = E.planex;
		E.dirx = E.dirx * cos(rotspeed) - E.diry * sin(rotspeed);
		E.diry = olddirx * sin(rotspeed) + E.diry * cos(rotspeed);
		E.planex = E.planex * cos(rotspeed) - E.planey * sin(rotspeed);
		E.planey = oldplanex * sin(rotspeed) + E.planey * cos(rotspeed);
	}
}

int		key_hook(int keycode, t_e *e)
{
	printf("keycode = %d\n", keycode);
	mod(keycode, &e->draw, e->map);
	rd(e);
	return (0);
}
