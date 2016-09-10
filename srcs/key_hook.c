/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 18:26:32 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/10 16:24:12 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	acc(char c, t_draw *draw)
{
	if (c & (1u << 0))
		E.acceleration = 3;
	else
		E.acceleration = 1;
}

void	moove(t_e *e)
{
	int n;

	n = -1;
	acc(e->c, &e->draw);
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
	rd(e);
}

int		key_release(int keycode, t_e *e)
{
	if (keycode == 13)
		e->c ^= MF;
	else if (keycode == 257)
		e->c ^= RUN;
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
	else if (keycode == 49)
		open_door(e);
	else if (keycode == 257)
		e->c |= RUN;
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
