/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animated_textures.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 12:36:54 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/27 12:37:39 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		return_current_image(char **str, char *u1, char *u2)
{
	static int i = 1;
	static int in = 0;

	char *s;
	char *s2;
	s = NULL;
	s2 = NULL;
	s = ft_itoa(i);
	s2 = ft_strjoin(s, u1);
	*str = ft_strjoin(u2, s2);
	ft_strdel (&s2);
	ft_strdel(&s);
	if (i == 138)
		in = 139;
	if (i == 1)
		in = 0;
	if (in < i)
	{
		in = i;
		i++;
	}
	else
	{
		in = i;
		i--;
	}
}

