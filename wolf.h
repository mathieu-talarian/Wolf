/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 16:28:27 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/25 15:37:55 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include <stdio.h>
# include <mlx.h>
# include "./libft/libft.h"
# include <math.h>

# define RESO_X 1024
# define RESO_Y 768
# define D mlx->d

typedef struct		s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

typedef struct		s_pts
{
	int				x0;
	int				x1;
	int				y0;
	int				y1;
}					t_pts;

typedef struct		s_draw
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
}					t_draw;

typedef struct	s_d
{
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		posx;
	double		posy;
	double		time;
	double		oldtime;
}				t_d;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*d_addr;
	int			sizeline;
	int			bpp;
	int			endian;
	t_d			d;
}				t_mlx;

void	put_color_to_pixel1(t_mlx *mlx, t_draw draw, t_rgb rgb);
void	verLine(t_mlx *mlx, int x, int y0, int y1, t_rgb rgb);

void		line_1(t_mlx *mlx, t_draw draw, t_rgb rgb);
void		line_2(t_mlx *mlx, t_draw draw, t_rgb rgb);

void		put_color_to_pixel(t_mlx *mlx, t_draw draw, t_rgb rgb);

void		do_it(t_mlx *mlx);

int			key_hook(int keycode, t_mlx *mlx);

void		timing(t_mlx *mlx);
#endif
