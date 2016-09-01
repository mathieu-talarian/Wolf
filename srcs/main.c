/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 18:53:50 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/01 20:09:32 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		no_data()
{
	ft_putendl("Map empty");
	return (0);
}

int		usage(void)
{
	ft_putendl("wolf : Usage");
	ft_putendl("./wolf map.wolf");
	return (0);
}

int		main(int ac, char **av)
{
	t_e *e;

	if (ac != 2)
		return (usage());
	if (!(e = (t_e *)malloc(sizeof(t_e))))
		return (0);
	e->map = NULL;
	if (!parsing_map(av[1], &e))
		return (0);
	do_wolf(e);
	return (1);
}
