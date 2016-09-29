/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rc_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 21:55:52 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 21:59:27 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	rc_wall(t_rc *rc)
{
	if (rc->side == 0)
		rc->wallx = rc->raypos.y + (double)(rc->walldist * rc->raydir.y);
	else
		rc->wallx = rc->raypos.x + (double)(rc->walldist * rc->raydir.x);
	rc->wallx -= floor(rc->wallx);
}

void	do_rc(t_e *e, t_rc rc)
{
	if (e->opt == 0)
	{
		textures(e, &rc);
		draw_floor(e, rc);
	}
	else
		notextures(e, rc);
}
