/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 16:02:02 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 20:45:07 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		mapping_x(t_line **line, int x)
{
	t_line	*l;
	int		ret;

	ret = 0;
	l = *line;
	while (l)
	{
		if (l->x == x)
			return (l->wall);
		l = l->next;
	}
	return (0);
}

int		mapping(t_map **map, int x, int y)
{
	t_map	*l;

	l = *map;
	while (l)
	{
		if (l->num_line == y)
			return (mapping_x(&l->line, x));
		l = l->next;
	}
	return (0);
}
