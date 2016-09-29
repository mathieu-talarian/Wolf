/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:35:32 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 21:54:02 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	start_fill_xpm(t_mlx *mlx, t_lxpm **lxpm, char **av)
{
	lstxpmadd(lxpm, lst_xpm_new(mlx, "./image/fl.xpm", -3));
	lstxpmadd(lxpm, lst_xpm_new(mlx, "./image/sb.xpm", 20));
	lstxpmadd(lxpm, lst_xpm_new(mlx, "./image/grass.xpm", -2));
	lstxpmadd(lxpm, lst_xpm_new(mlx, "./image/ground.xpm", -1));
	lstxpmadd(lxpm, lst_xpm_new(mlx, "./image/sand.xpm", 0));
	lstxpmadd(lxpm, lst_xpm_new(mlx, "./image/ww1.xpm", 1));
	lstxpmadd(lxpm, lst_xpm_new(mlx, "./image/wood.xpm", 5));
	lstxpmadd(lxpm, lst_xpm_new(mlx, "./image/po.xpm", 6));
	lstxpmadd(lxpm, lst_xpm_new(mlx, "./image/stone.xpm", 8));
	lstxpmadd(lxpm, lst_xpm_new(mlx, "./image/wll.xpm", 0));
	lstxpmadd(lxpm, lst_xpm_new(mlx, "./image/blue.xpm", 0));
}

int		fill_xpm(t_e **ll, char **av)
{
	t_e *e;

	e = *ll;
	start_fill_xpm(e->mlx, &e->lxpm, av);
	if (e->lxpm == NULL)
		e->opt = 1;
	return (1);
}
