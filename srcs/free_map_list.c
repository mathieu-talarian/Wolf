/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 16:54:52 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 20:31:56 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		free_line(t_line **bl)
{
	t_line *l;
	t_line *tmp;

	l = *bl;
	while (l)
	{
		tmp = l->next;
		free(l);
		l = NULL;
		l = tmp;
	}
	*bl = NULL;
}

void		free_map_list(t_map **bl)
{
	t_map *m;
	t_map *tmp;

	m = *bl;
	while (m)
	{
		tmp = m->next;
		free_line(&m->line);
		free(m);
		m = NULL;
		m = tmp;
	}
	*bl = NULL;
}
