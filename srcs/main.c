/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 18:53:50 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 21:53:31 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	t_e		*e;
	int		opt;

	e = NULL;
	opt = 0;
	if (ac >= 3)
		return (usage());
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "-f") == 0)
			opt = 1;
		else
			return (usage());
	}
	if (!(e = (t_e *)malloc(sizeof(t_e))))
		return (0);
	e->map = NULL;
	e->lxpm = NULL;
	e->opt = opt;
	if (!parsing_map("./map/map.wolf", &e))
		return (0);
	test_start(e);
	do_wolf(e);
	return (1);
}
