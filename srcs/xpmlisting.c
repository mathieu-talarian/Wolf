/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpmlisting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:13:37 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/27 12:48:55 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

t_lxpm		*lst_xpm_new(t_mlx *mlx, char *fn)
{
	t_lxpm *l;

	if (!(l = (t_lxpm *)malloc(sizeof(t_lxpm))))
		return (NULL);
	if (l)
	{
		l->img = mlx_xpm_file_to_image(mlx->mlx, fn, &l->x, &l->y);
		if (l->img == NULL)
		{
			free(l);
			return (NULL);
		}
		l->fn = ft_strdup(fn);
		l->d_a = mlx_get_data_addr(l->img, &l->bpp, &l->sl, &l->e);
	}
	l->next = NULL;
	return (l);
}

void		lstxpmadd(t_lxpm **begin_list, t_lxpm *nw)
{
	t_lxpm *datas;

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
