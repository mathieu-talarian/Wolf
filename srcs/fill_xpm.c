/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_xpm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:35:32 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/21 14:46:20 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	start_fill_xpm(t_mlx *mlx, t_lxpm **lxpm, char **av)
{
	int i;

	i = 2;
	while (av[i])
	{
		lstxpmadd(lxpm, lst_xpm_new(mlx, av[i]));
		i++;
	}
}

int		fill_xpm(t_e **ll, char **av)
{
	t_e *e;

	e = *ll;
	start_fill_xpm(e->mlx, &e->lxpm, av);
	return (1);
}
