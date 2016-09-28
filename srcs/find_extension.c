/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_extension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 15:11:25 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/28 15:17:53 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		find_extension(char *ex, char *fn)
{
	char	*chr;
	int		i;
	char	*tmp;

	tmp = NULL;
	chr = ft_strrchr(fn, '.');
	tmp = ft_strsub(fn, i + 1, ft_strlen(fn));
	if (!(ft_strcmp(ex, tmp)))
	{
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}
