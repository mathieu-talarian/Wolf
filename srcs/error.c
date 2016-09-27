/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/12 18:40:42 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/27 12:49:29 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		small_map(char *fn)
{
	ft_putstr("Map ");
	ft_putstr(fn);
	ft_putendl(" too small.");
	return (0);
}

int		no_data(void)
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
