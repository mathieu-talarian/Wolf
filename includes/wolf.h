/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 18:33:39 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/01 20:09:33 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define RESO_X 512
# define RESO_Y 384

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

typedef struct		s_line
{
	int				x;
	int				y;
	char			*wall;
	struct s_line	*next;
}					t_line;


typedef struct		s_map
{

	int				num_line;
	t_line			*line;
	struct s_map	*next;
}					t_map;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	int				sl;
	int				bpp;
	int				e;
	int				d_a;
}					t_mlx;

typedef struct		s_e
{
	t_mlx			*mlx;
	t_map			*map;
	int				h;
	int				w;
}					t_e;

/*
**parsing et remplissage map
*/
int		parsing_map(char *filename, t_e **e);

/*
**erreurs
*/
int		usage(void);
int		no_data();

/*
**listing
*/
void		line_list_add(t_line **begin_list, t_line *nw);
void		data_list_add(t_map **begin_list, t_map *nw);
t_map		*new_data_list(int count_words, int num_line, char **tab);
t_line		*new_line_list(int y, int x, char *nbr);
void		fill_line_list(t_line **list, int num_line, char **tab);
int			fill_size(t_map **m, int *w, int *h);



void			print_map(t_map **map);


void			do_wolf(t_e *e);
#endif
