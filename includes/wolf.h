/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 18:33:39 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/09 16:54:33 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define RESO_X 1024
# define RESO_Y 768
# define DIS_V 10

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# define E draw->d
# define D draw.d
# define M e->mlx->mlx
# define W e->mlx->win
# define I e->mlx->img
# define Y e->draw.d
# define ABS(X) (x < 0 ? (x * -1) : x)

# define MF (1u<<1)
# define MB (1u<<2)
# define ML (1u<<3)
# define MR (1u<<4)
# define TL (1u<<5)
# define TR (1u<<6)
# define G (1u<<7)
# define H (1u<<0)

typedef struct		s_vect
{
	double			x;
	double			y;
}					t_vect;

typedef struct		s_rgb
{
	double			r;
	double			g;
	double			b;
}					t_rgb;

typedef struct		s_hsv
{
	double			h;
	double			s;
	double			v;
}					t_hsv;

typedef struct		s_line
{
	int				x;
	int				y;
	int				wall;
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
	char			*d_a;
}					t_mlx;

typedef struct		s_dpts
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_dpts;

typedef struct		s_l
{
	int				dx;
	int				dy;
	int				i;
	int				xinc;
	int				yinc;
	int				cumul;
	int				x;
	int				y;
	unsigned int	col_min;
	unsigned int	col_max;
}					t_l;

typedef struct	s_d
{
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	t_vect		pos;
	double		time;
	double		oldtime;
	double		movespeed;
}				t_d;

typedef struct		s_draw
{
	t_dpts			pts;
	t_l				l;
	t_d				d;
}					t_draw;

typedef struct		s_e
{
	t_mlx			*mlx;
	t_map			*map;
	int				h;
	int				w;
	char			c;
	t_vect			start;
	t_draw			draw;
}					t_e;

/*
**parsing et remplissage map
*/
int		parsing_map(char *filename, t_e **e);
int		mapping(t_map **map, int x, int y);

/*
**erreurs
*/
int		u00sage(void);
int		no_data();
int		small_map(char *fn);

/*
**listing
*/
void		line_list_add(t_line **begin_list, t_line *nw);
void		data_list_add(t_map **begin_list, t_map *nw);
t_map		*new_data_list(int count_words, int num_line, char **tab, \
		t_vect *start);
t_line		*new_line_list(int y, int x, char *nbr, t_vect *start);
void		fill_line_list(t_line **list, int num_line, char **tab, t_vect *start);
int			fill_size(t_map **m, int *w, int *h);
void		tab_clr(char ***tab);



void			print_map(t_map **map);


void			do_wolf(t_e *e);
void			wolf_3d(t_e *e);
/*
**maths
*/
double			carre(double n);
double			cube(double n);
double			p_4(double n);


void	draw_line(t_e *e, int x, int y0, int y1, t_rgb rgb);
void	put_color_to_pixel(t_mlx *mlx, t_l l, t_rgb rgb);
void	line_1(t_mlx *mlx, t_l l, t_rgb rgb);
void	line_2(t_mlx *mlx, t_l l, t_rgb rgb);

void	wolf_3d(t_e *e);
void	rd(t_e *e);

void	test_start(t_e *e);
void	sky(t_e *e, int x);
void	ground(t_e *e, int x);
void	wall(t_e *e, int x, int ds, int de, t_hsv hsv);

int		key_press(int keycode, t_e *e);
int		key_release(int keycode, t_e *e);
int		no_event(t_e *e);

/*
**movement
*/
void	move_forward(t_draw *draw, t_map *map);
void	move_backward(t_draw *draw, t_map *map);
void	straf_left(t_draw *draw, t_map *map);
void	straf_right(t_draw *draw, t_map *map);
void	turn_left(t_draw *d, t_map *m);
void	turn_right(t_draw *d, t_map *m);
void	moove(t_e *e);

void	open_door(t_e *e);
#endif
