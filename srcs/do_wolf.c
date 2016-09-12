/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_wolf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 20:00:18 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/12 20:32:06 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void		print_datas(t_draw *draw)
{
	printf("dirx %f | diry %f\n", E.dirx, E.diry);
	printf("planex %f | planey %f\n", E.planex, E.planey);
	printf("posx %f | posy %f\n", E.pos.x, E.pos.y);
}

t_mlx		*initialize_mlx(t_vect s, t_draw *draw)
{
	t_mlx *mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, RESO_X, RESO_Y, "wolf");
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_a = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sl, &mlx->e);
	E.dirx = 1;
	E.diry = 0;
	E.time = 0;
	E.oldtime = 0;
	E.planex = 0;
	E.planey = 0.66;
	E.pos.x = s.x;
	E.pos.y = s.y;
	E.movespeed = 0.1;
	E.acceleration = 1;
	return (mlx);
}

int		do_wolf_3d(t_e *e)
{
	moove(e);
	wolf_3d(e);
	mlx_put_image_to_window(M, W, I, 0, 0);
	return (0);
}

void		fill_xpm_list2(t_mlx *mlx, t_list **list, char *fn)
{
	t_list *l;

	l = *list;
	ft_lstadd(&l, ft_lstnew(find_xpm(mlx, fn), sizeof(t_xpm)));
}

void		fill_xpm_list1(t_mlx *mlx, t_list **list, char **av)
{
	int i = 1;
	t_list *l;
	l = *list;
	while (av[++i])
		fill_xpm_list2(mlx, &l, av[i]);
}

void		print_xd(t_xpm *xpm)
{
	printf("%s\n", xpm->fn);
}

void		test_xpm_list(t_list *l)
{
	if (l)
	{
	while (l)
	{
		printf("%zu\n", l->content_size);
//		print_xd(l->content);
		l = l->next;
	}
	}
}

void		do_wolf(t_e *e, char **av)
{
	e->c = 0;
	e->mlx = initialize_mlx(e->start, &e->draw);
	fill_xpm_list1(e->mlx, &e->list, av);
	test_xpm_list(e->list);
//	mlx_loop_hook(e->mlx->mlx, do_wolf_3d, e);
//	mlx_hook(W, 17, 1L << 17, red_button, e);
//	mlx_hook(W, 2, 1L << 0, key_press, e);
//	mlx_hook(W, 3, 1L << 1, key_release, e);
//	mlx_loop(e->mlx->mlx);
}
