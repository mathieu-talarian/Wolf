/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:03:10 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/07 12:13:24 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		find_new_start2(t_line **m, t_vect *s)
{
	t_line *l;

	l = *m;
	while (l)
	{
		if (l->wall == 0)
		{
			s->x = l->x;
			s->y = l->y;
			return (1);
		}
		l = l->next;
	}
	return (0);
}

void	find_new_start(t_vect *s, t_map **m)
{
	t_map *l;

	l = *m;
	while (l)
	{
		if (find_new_start2(&l->line, s))
			return ;
		l = l->next;
	}
}

void	test_start(t_e *e)
{
	if (e->start.x == -1 && e->start.y == -1)
		find_new_start(&e->start, &e->map);
}
