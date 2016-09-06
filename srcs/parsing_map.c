/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 18:45:54 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/06 17:47:35 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int				fill_list(int fd, char **line, t_map **map)
{
	int			i;
	int			j;
	int			k;
	char		**tab;

	k = 0;
	tab = NULL;
	j = 0;
	while ((i = get_next_line(fd, line)))
	{
		if (i == -1)
			return (-1);
		j = ft_count_words(*line, ' ', ft_char_cmp);
		if (*line == NULL)
			return (-1);
		tab = ft_strsplit(*line, ' ');
		data_list_add(map, new_data_list(j, k, tab));
//		tab_clr(&tab);
		k++;
	}
/*	if (j == 0)
		return (-1);
	ft_tabdel(&tab);*/
	return (1);
}

int				start_fill(int fd, t_map **map)
{
	char		*line;

	line = NULL;
	if ((fill_list(fd, &line, map)) < 0)
		return (0);
	return (1);
}

int		parsing_map(char *filename, t_e **ll)
{
	int		fd;
	t_e		*e;

	e = *ll;
	e->h = 0;
	e->w = 0;
	if (!(ft_open_file(filename, &fd)))
		return (usage());
	if (!(start_fill(fd, &e->map)))
		return (no_data());
	print_map(&e->map);
	if (!fill_size(&e->map, &e->w, &e->h))
		return (no_data());;
	printf("%d|%d\n", e->w, e->h);
/*	if (fdf_length(e->map) < 0)
		return (0);*/
	return (1);
}
