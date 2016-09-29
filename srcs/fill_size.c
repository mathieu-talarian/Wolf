/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 20:27:16 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 20:28:43 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

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
