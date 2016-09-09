/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf_3d.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 15:41:06 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/08 21:02:19 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	wolf_3d(t_e *e)
{
	unsigned int	x;
	t_vect			raydir;
	t_vect			raypos;
	t_vect			sidedist;
	t_vect			deltadist;
	x = -1;
//	while (++x < RESO_X)
//	{
//		sky(e, x);
//		ground(e, x);
//	}
	x = -1;
	while (++x < RESO_X)
	{
		int y = 0;
		double cameraX = 2 * x / (double)RESO_X - 1;
		raypos.x = e->D.pos.x;
		raypos.y = e->D.pos.y;
		raydir.x = e->D.dirx + e->D.planex * cameraX;
		raydir.y = e->D.diry + e->D.planey * cameraX;

      int mapX = (int)raypos.x;
      int mapY = (int)raypos.y;
      deltadist.x = sqrt(1 + (carre(raydir.y)) / (carre(raydir.x)));
      deltadist.y = sqrt(1 + (carre(raydir.x)) / (carre(raydir.y)));
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?

      //calculate step and initial sideDist
      if (raydir.x < 0)
      {
        stepX = -1;
        sidedist.x = (raypos.x - mapX) * deltadist.x;
      }
      else
      {
        stepX = 1;
        sidedist.x = (mapX + 1.0 - raypos.x) * deltadist.x;
      }
      if (raydir.y < 0)
      {
        stepY = -1;
        sidedist.y = (raypos.y - mapY) * deltadist.y;
      }
      else
      {
        stepY = 1;
        sidedist.y = (mapY + 1.0 - raypos.y) * deltadist.y;
      }
      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sidedist.x < sidedist.y)
        {
          sidedist.x += deltadist.x;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sidedist.y += deltadist.y;
          mapY += stepY;
          side = 1;
        }
        if (mapping(&e->map, mapX, mapY) > 0) hit = 1;
      } 

      if (side == 0) perpWallDist = (mapX - raypos.x + (1 - stepX) / 2) / raydir.x;
      else           perpWallDist = (mapY - raypos.y + (1 - stepY) / 2) / raydir.y;
	  int lineHeight;
		if ((int)perpWallDist == 0)
			lineHeight = RESO_Y - 1;
		else
			lineHeight = (int)(RESO_Y / perpWallDist);
		int drawStart = -lineHeight / 2 + RESO_Y / 2;
		if(drawStart < 0)drawStart = 0;
			int drawEnd = lineHeight / 2 + RESO_Y / 2;
		if(drawEnd >= RESO_Y)drawEnd = RESO_Y - 1;
			t_hsv hsv;
		hsv.v = 1;
		if (perpWallDist > DIS_V)
			hsv.v = 0;
	else
		hsv.v = perpWallDist / - DIS_V + 1;
		if (mapping(&e->map, mapX, mapY) == 1)
			hsv.h = 0;
		if (mapping(&e->map, mapX, mapY) == 2)
			hsv.h = 120;
		if (mapping(&e->map, mapX, mapY) == 3)
			hsv.h = 240;
		if (mapping(&e->map, mapX, mapY) == 4)
			hsv.h = 60;
		if (side == 1)
			hsv.s = 0.5;
		else
			hsv.s = 1;
		wall(e, x, drawStart, drawEnd, hsv);
	}
}
