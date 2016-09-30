/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 19:06:29 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 20:43:05 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		fill_line_list(t_line **list, int num_line, char **tab)
{
	int		i;

	i = 0;
	while (tab[i])
	{
		line_list_add(list, new_line_list(num_line, i, tab[i]));
		i++;
	}
}

t_line		*new_line_list(int y, int x, char *nbr)
{
	t_line	*new;
	char	**tab;
	int		i;

	i = 1;
	tab = NULL;
	if (!(new = (t_line *)malloc(sizeof(t_line))))
		return (NULL);
	if (new && nbr)
	{
		new->x = x;
		new->y = y;
		new->wall = ft_atoi(nbr);
		new->next = NULL;
	}
	ft_strdel(tab);
	return (new);
}

t_map		*new_data_list(int num_line, char **tab)
{
	t_map		*new;
	int			i;

	i = 0;
	new = NULL;
	if (!(new = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	if (new)
	{
		new->num_line = num_line;
		new->line = NULL;
		fill_line_list(&new->line, num_line, tab);
		new->next = NULL;
	}
	return (new);
}

void		data_list_add(t_map **begin_list, t_map *nw)
{
	t_map *datas;

	datas = *begin_list;
	if (datas && nw)
	{
		while (datas->next)
			datas = datas->next;
		datas->next = nw;
	}
	else
	{
		if (nw)
			*begin_list = nw;
	}
}

void		line_list_add(t_line **begin_list, t_line *nw)
{
	t_line *line;

	line = *begin_list;
	if (line && nw)
	{
		while (line->next)
			line = line->next;
		line->next = nw;
	}
	else
	{
		if (nw)
			*begin_list = nw;
	}
}
