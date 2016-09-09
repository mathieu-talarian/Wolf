/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:37:38 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/09 15:13:26 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void			print_line(t_line **ll)
{
	t_line *l;
	l = *ll;
	while (l)
	{
		printf(" |[x %d][y %d][%d]| ", l->x, l->y, l->wall);
		l = l->next;
	}
}

void			print_map(t_map **map)
{
	t_map *l;
	l = *map;
	while (l)
	{
		print_line(&l->line);
		l = l->next;
		printf("\n");
	}
}

int			count_w(t_line **l)
{
	t_line	*m;
	int		c;

	m = *l;
	c = 0;
	while (m)
	{
		c++;
		m = m->next;
	}
	return (c);
}

int			fill_size(t_map **m, int *w, int *h)
{
	int		cpt;
	t_map	*l;

	l = *m;
	cpt = 0;
	while (l)
	{
		*w = count_w(&l->line);
		*h += 1;
		l = l->next;
		if (cpt != 0 && cpt != *w)
			return (0);
		else
			cpt = *w;
	}
	return (1);
}
