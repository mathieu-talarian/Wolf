/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 18:53:50 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/27 12:44:09 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		main(int ac, char **av)
{
	t_e *e;

	e = NULL;
//	if (ac != 2)
//		return (usage());
	if (!(e = (t_e *)malloc(sizeof(t_e))))
		return (0);
	e->map = NULL;
	e->lxpm = NULL;
	if (!parsing_map(av[1], &e))
		return (0);
	test_start(e);
	do_wolf(e, av);
	return (1);
}
