/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 18:33:39 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/29 22:12:54 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# define RESO_X 1024
# define RESO_Y 768
# define DIS_V 15

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>
# define E draw->d
# define D draw.d
# define M e->mlx->mlx
# define W e->mlx->win
# define I e->mlx->img
# define Y e->draw.d
# define ABS(x) ((x) < 0 ? (x * -1) : (x))

# define MF (1u<<1)
# define MB (1u<<2)
# define ML (1u<<3)
# define MR (1u<<4)
# define TL (1u<<5)
# define TR (1u<<6)
# define G (1u<<7)
# define RUN (1u<<0)


typedef struct		s_ivect
{
	int				x;
	int				y;
}					t_ivect;

typedef struct		s_vect
{
	double			x;
	double			y;
}					t_vect;

typedef struct		s_rc
{
	t_ivect			pix;
	t_vect			raydir;
	t_vect			raypos;
	t_vect			deltadist;
	t_vect			sidedist;
	t_vect			cam;
	t_vect			map;
	t_vect			tex;
	double			wallx;
	double			walldist;
	t_ivect			step;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	long double		mult;
}					t_rc;

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

typedef struct		s_chsv
{
	t_hsv			out;
	t_rgb			tmp;
	double			min;
	double			max;
	double			delta;
}					t_chsv;

typedef struct		s_crgb
{
	t_rgb			r;
	long			i;
	double			hh;
	double			p;
	double			q;
	double			t;
	double			ff;
}					t_crgb;



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
	int			acceleration;
}				t_d;

typedef struct		s_draw
{
	t_dpts			pts;
	t_l				l;
	t_d				d;
}					t_draw;

typedef struct		s_lxpm
{
	void			*img;
	char			*d_a;
	char			*fn;
	int				x;
	int				y;
	int				sl;
	int				bpp;
	int				e;
	int				ext;
	struct s_lxpm	*next;
}					t_lxpm;

typedef struct		s_e
{
	t_mlx			*mlx;
	t_lxpm			*lxpm;
	t_map			*map;
	int				h;
	int				w;
	char			c;
	int				i;
	int				opt;
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
int		usage(void);
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
void		free_map_list(t_map **map);
void		tab_clr(char ***tab);



void			print_map(t_map **map);
void			mlx_img_to_black(t_mlx *mlx);


void			do_wolf(t_e *e, char **av);
void			wolf_3d(t_e *e);
/*
**maths
*/
double			carre(double n);
double			cube(double n);
double			p_4(double n);


void	draw_line(t_mlx *mlx, t_rgb rgb, t_rc rc);
void	put_color_to_pixel(t_mlx *mlx, t_l l, t_rgb rgb);
void	line_1(t_mlx *mlx, t_l l, t_rgb rgb);
void	line_2(t_mlx *mlx, t_l l, t_rgb rgb);

void	rd(t_e *e);

void	test_start(t_e *e);
void	skybox(t_e *e, t_lxpm *sb);
void	sky(t_e *e);
void	ground(t_e *e);
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

int		red_button(t_e *e);

/*
**xpm
*/
t_lxpm		*lst_xpm_new(t_mlx *mlx, char *fn, int tx_n);
void		lstxpmadd(t_lxpm **begin_list, t_lxpm *nw);
int			fill_xpm(t_e **ll, char **av);
void	cpy_img(t_mlx *mlx, t_lxpm **x);
t_lxpm		*return_xpm(t_lxpm **p, char *fn);

void		draw_texture(t_mlx *mlx, t_lxpm *sto, t_rc *rc);
void		comp_texture(t_e *e, t_rc *rc, t_lxpm *x);

void	print_x(t_lxpm **l);

void	ray_casting(t_e *e);

t_rgb	hsv_to_rgb(t_hsv hsv);
t_hsv	rgb_to_hsv(t_rgb rgb);

void	draw_floor(t_e *e, t_rc rc);
void	textures(t_e *e, t_rc *rc);
void	*bmp_to_image(t_mlx *mlx, char *fn, int *w, int *h);

void	new_map(t_e *e);
void	new_map2(t_e *e);
int		do_wolf_3d(t_e *e);
void	notextures(t_e *e, t_rc rc);
void	rc_wall(t_rc *rc);
void	do_rc(t_e *e, t_rc rc);
#endif
