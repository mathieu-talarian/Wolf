/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 18:26:32 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/08 21:12:52 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"
# define ABS(X) (x < 0 ? (x * -1) : x)

void	mlx_img_to_black(t_mlx *mlx)
{
	t_l l;
	t_rgb r;

	r.r = 0;
	r.g = 0;
	r.b = 0;
	l.y = -1;
	while (++l.y < RESO_Y)
	{
		l.x = -1;
		while (++l.x < RESO_X)
		{
			put_color_to_pixel(mlx, l, r);
		}
	}
}

void	rd(t_e *e)
{
	mlx_img_to_black(e->mlx);
//	wolf_3d(e);
//	mlx_put_image_to_window(e->mlx->mlx, e->mlx->win, e->mlx->img, 0, 0);
}

void	moove(t_e *e)
{
	int n;

	n = -1;
	while (++n < 8)
	{
		if (e->c & (1u << n) && n == 1)
			move_forward(&e->draw, e->map);
		else if (e->c & (1u << n) && n == 2)
			move_backward(&e->draw, e->map);
		else if (e->c & (1u << n) && n == 3)
			straf_left(&e->draw, e->map);
		else if (e->c & (1u << n) && n == 4)
			straf_right(&e->draw, e->map);
		else if (e->c & (1u << n) && n == 5)
			turn_left(&e->draw, e->map);
		else if (e->c & (1u << n) && n == 6)
			turn_right(&e->draw, e->map);
	}
	n = -1;
	while (++n < 8)
	{
		if (e->c & (1u << n))
			printf("1");
		else
			printf("0");
	}
	printf("\n");
	rd(e);
}

int		key_release(int keycode, t_e *e)
{
	if (keycode == 13)
		e->c ^= MF;
	else if (keycode == 1)
		e->c ^= MB;
	else if (keycode == 123)
		e->c ^= ML;
	else if (keycode == 124)
		e->c ^= MR;
	else if (keycode == 0)
		e->c ^= TL;
	else if (keycode == 2)
		e->c ^= TR;
	moove(e);
	return (0);
}

int		key_press(int keycode, t_e *e)
{
	if (keycode == 53)
		exit (0);
	else if (keycode == 13)
		e->c |= MF;
	else if (keycode == 1)
		e->c |= MB;
	else if (keycode == 123)
		e->c |= ML;
	else if (keycode == 124)
		e->c |= MR;
	else if (keycode == 0)
		e->c |= TL;
	else if (keycode == 2)
		e->c |= TR;
	moove(e);
	return (0);
}
