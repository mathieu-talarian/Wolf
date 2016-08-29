#include "wolf.h"
#include <math.h>
#include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>

#define mapWidth 24
#define mapHeight 24

static int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};


void	print_map_pos(int mapx, int mapy, int rx, int ry)
{
	printf("%d <=> %d\n", rx, ry);
	for (int y = 0; y < mapHeight;y++)
	{
		for (int x = 0; x < mapHeight; x++)
		{
			if (x == mapx && y == mapy)
				printf("*");
			else if (x == rx && y == ry)
				printf("v");
			else 
				printf("%d", worldMap[x][y]);
		}
		printf("\n");
	}
	printf("\n");
}

int main(void)
{
  t_mlx *mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, RESO_X, RESO_Y, "wolf");
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->endian);
	D.dir.x = 1;
	D.dir.y = 0; //initial direction vector
	D.time = 0; //time of current frame
	D.oldtime = 0; //time of previous frame
	D.plane.x = 0;
	D.plane.y = 0.66; //the 2d raycaster version of camera plane
	D.pos.x = 22;
	D.pos.y = 12;  //x and y start position




	do_it(mlx);
//	timing(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_hook(mlx->win, 2, 1L << 0, key_hook, mlx);
	mlx_do_key_autorepeaton(mlx->mlx);
	mlx_loop(mlx->mlx);
	return (0);
}

void	do_it(t_mlx *mlx)
{

	double rayDirX;
	double rayDirY;
      for(int x = 0; x < RESO_X; x++)
    {
      //calculate ray position and direction
      double cameraX = 2 * x / (double)RESO_X - 1; //x-coordinate in camera space
      double rayPosX = D.pos.x;
      double rayPosY = D.pos.y;
      rayDirX = D.dir.x + D.plane.x * cameraX;
      rayDirY = D.dir.y + D.plane.y * cameraX;

       //which box of the map we're in
      int mapX = (int)rayPosX;
      int mapY = (int)rayPosY;

      //length of ray from current position to next x or y-side
      double sideDistX;
      double sideDistY;




       //length of ray from one x or y-side to next x or y-side
      double deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX));
      double deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY));
      double perpWallDist;

      //what direction to step in x or y-direction (either +1 or -1)
      int stepX;
      int stepY;

      int hit = 0; //was there a wall hit?
      int side; //was a NS or a EW wall hit?

      //calculate step and initial sideDist
      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (rayPosX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.0 - rayPosX) * deltaDistX;
      }
      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (rayPosY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.0 - rayPosY) * deltaDistY;
      }

      //perform DDA
      while (hit == 0)
      {
        //jump to next map square, OR in x-direction, OR in y-direction
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        //Check if ray has hit a wall
        if (worldMap[mapX][mapY] > 0) hit = 1;
      } 

      //Calculate distance projected on camera direction (oblique distance will give fisheye effect!)
      if (side == 0) perpWallDist = (mapX - rayPosX + (1 - stepX) / 2) / rayDirX;
      else           perpWallDist = (mapY - rayPosY + (1 - stepY) / 2) / rayDirY;

         //Calculate height of line to draw on screen
      int lineHeight = (int)(RESO_Y / perpWallDist);

      //calculate lowest and highest pixel to fill in current stripe
      int drawStart = -lineHeight / 2 + RESO_Y / 2;
      if(drawStart < 0)drawStart = 0;
      int drawEnd = lineHeight / 2 + RESO_Y / 2;
      if(drawEnd >= RESO_Y)drawEnd = mapHeight - 1;

      //choose wall color
/*      ColorRGB color;
      switch(worldMap[mapX][mapY])
      {
        case 1:  color = RGB_Red;  break; //red
        case 2:  color = RGB_Green;  break; //green
        case 3:  color = RGB_Blue;   break; //blue
        case 4:  color = RGB_White;  break; //white
        default: color = RGB_Yellow; break; //yellow
      }

      //give x and y sides different brightness
      if (side == 1) {color = color / 2;}
*/
      //draw the pixels of the stripe as a vertical line
      t_rgb rgb;
      rgb.r = 0;
	  rgb.g = 0;
	  rgb.b = 0;
	  if (worldMap[mapX][mapY] == 1)
		  rgb.r = 255;
	  if (worldMap[mapX][mapY] == 2)
		  rgb.g = 255;
	  if (worldMap[mapX][mapY] == 3)
		  rgb.b = 255;
	  if (worldMap[mapX][mapY] == 4)
	  {
		  rgb.r = 255;
		  rgb.g = 255;
	  }
      if (side == 1)
	  {
		rgb.r = rgb.r / 2;
		rgb.g /= 2;
		rgb.b /= 2;
	  }
      verLine(mlx, x, drawStart, drawEnd, rgb);
    }

	print_map_pos((int)D.pos.x, (int)D.pos.y, (int)rayDirX, (int)rayDirY);
}
/*
void	timing(t_mlx *mlx)
{
	mlx->oldTime = mlx->time;
	mlx->time = getTicks();
	double frameTime = (mlx->time - mlx->oldTime) / 1000.0;
}
*/
/*
    //timing for input and FPS counter
    oldTime = time;
    time = getTicks();
    double frameTime = (time - oldTime) / 1000.0; //frameTime is the time this frame has taken, in seconds
    print(1.0 / frameTime); //FPS counter
    redraw();
    cls();

    //speed modifiers
    double moveSpeed = frameTime * 5.0; //the constant value is in squares/second
    double rotSpeed = frameTime * 3.0; //the constant value is in radians/second

    readKeys();
    //move forward if no wall in front of you
    if (keyDown(SDLK_UP))
    {
      if(worldMap[int(D.posx + mlx->dirX * moveSpeed)][int(D.posy)] == false) posX += dirX * moveSpeed;
      if(worldMap[int(D.posx)][int(D.posy + mlx->dirY * moveSpeed)] == false) posY += dirY * moveSpeed;
    }
    //move backwards if no wall behind you
    if (keyDown(SDLK_DOWN))
    {
      if(worldMap[int(D.posx - mlx->dirX * moveSpeed)][int(D.posy)] == false) posX -= dirX * moveSpeed;
      if(worldMap[int(D.posx)][int(D.posy - mlx->dirY * moveSpeed)] == false) posY -= dirY * moveSpeed;
    }
    //rotate to the right
    if (keyDown(SDLK_RIGHT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = mlx->dirX;
      mlx->dirX = dirX * cos(-rotSpeed) - mlx->dirY * sin(-rotSpeed);
      mlx->dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed);
      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed);
    }
    //rotate to the left
    if (keyDown(SDLK_LEFT))
    {
      //both camera direction and camera plane must be rotated
      double oldDirX = mlx->dirX;
      mlx->dirX = dirX * cos(rotSpeed) - mlx->dirY * sin(rotSpeed);
      mlx->dirY = oldDirX * sin(rotSpeed) + dirY * cos(rotSpeed);
      double oldPlaneX = planeX;
      planeX = planeX * cos(rotSpeed) - planeY * sin(rotSpeed);
      planeY = oldPlaneX * sin(rotSpeed) + planeY * cos(rotSpeed);
    }
  }
}*/
