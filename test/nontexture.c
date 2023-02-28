/*
Copyright (c) 2004-2021, Lode Vandevenne

All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

    * Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <math.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../mlx/mlx.h"

/*
g++ *.cpp -lSDL -O3 -W -Wall -ansi -pedantic
g++ *.cpp -lSDL
*/

//place the example code below here:

#define screenWidth 640
#define screenHeight 480
#define mapWidth 24
#define mapHeight 24

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_RELEASE 3
# define X_EVENT_DESTROY_NOTIFY 17

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ARR_L	123
# define KEY_ARR_R	124

typedef struct s_pixel
{
	double			dist;
	unsigned int	*color;
}					t_pixel;


typedef struct s_data
{
	double		posX, posY;
	double		dirX, dirY;
	double		planeX, planeY;
	int				key;
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	*addr;
	t_pixel			**buffer;
	char			*path;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}				t_data;

int worldMap[mapWidth][mapHeight]=
{
  {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
  {1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
  {1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
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

void	ft_mlx_pixel_put(t_data *data, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	dst = (unsigned int *)((char *)data->addr + \
		(data->line_length * y + data->bits_per_pixel / 8 * x));
	*dst = color;
}

void	refresh(t_data *data)
{
	int x = 0, y;
	int w = screenWidth, h = screenHeight;
	while (x < w)
	{
		y= 0;
		while (y < h)
		{
			mlx_pixel_put(data->mlx, data->win, x, y++, 0xFFFFFF);
		}
		x++;
	}
}


int keypress(int keycode, t_data *data)
{
	if (keycode == KEY_W)
			data->key = KEY_W;
	else if (keycode == KEY_S)
			data->key = KEY_S;
	else if (keycode == KEY_A)
			data->key = KEY_A;
	else if (keycode == KEY_D)
			data->key = KEY_D;
	else if (keycode == KEY_ARR_L)
			data->key = KEY_ARR_L;
	else if (keycode == KEY_ARR_R)
			data->key = KEY_ARR_R;
	else if (keycode == KEY_ESC)
			data->key = KEY_ESC;
	return (0);
}

void	player_move(t_data *data)
{
	double frameTime = 0.1;

	// speed modifiers
	double moveSpeed = frameTime * 5.0; // the constant value is in squares/second
	double rotSpeed = frameTime * 3.0;	// the constant value is in radians/second
	// move forward if no wall in front of you
	if (data->key == KEY_W)
	{
		if (worldMap[(int)(data->posX + data->dirX * moveSpeed)][(int)(data->posY)] == 0)
			data->posX += data->dirX * moveSpeed;
		if (worldMap[(int)(data->posX)][(int)(data->posY + data->dirY * moveSpeed)] == 0)
			data->posY += data->dirY * moveSpeed;
	}
	// move backwards if no wall behind you
	if (data->key == KEY_S)
	{
		if (worldMap[(int)(data->posX - data->dirX * moveSpeed)][(int)(data->posY)] == 0)
			data->posX -= data->dirX * moveSpeed;
		if (worldMap[(int)(data->posX)][(int)(data->posY - data->dirY * moveSpeed)] == 0)
			data->posY -= data->dirY * moveSpeed;
	}
	// rotate to the right
	if (data->key == KEY_D)
	{
		// both camera direction and camera plane must be rotated
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(-rotSpeed) - data->dirY * sin(-rotSpeed);
		data->dirY = oldDirX * sin(-rotSpeed) + data->dirY * cos(-rotSpeed);
		double oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(-rotSpeed) - data->planeY * sin(-rotSpeed);
		data->planeY = oldPlaneX * sin(-rotSpeed) + data->planeY * cos(-rotSpeed);
	}
	// rotate to the left
	if (data->key == KEY_A)
	{
		// both camera direction and camera plane must be rotated
		double oldDirX = data->dirX;
		data->dirX = data->dirX * cos(rotSpeed) - data->dirY * sin(rotSpeed);
		data->dirY = oldDirX * sin(rotSpeed) + data->dirY * cos(rotSpeed);
		double oldPlaneX = data->planeX;
		data->planeX = data->planeX * cos(rotSpeed) - data->planeY * sin(rotSpeed);
		data->planeY = oldPlaneX * sin(rotSpeed) + data->planeY * cos(rotSpeed);
	}
}

int	game_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

void	raycasting(t_data *data)
{
	int w = screenWidth, h = screenHeight;

	int x = 0, y;

	int ceil = 0xFFFF;
	int floor = (153 << 16) + (102 << 8) + 60;

	while (x < w)
	{
		y = 0;
		while (y < h / 2)
		{
			mlx_pixel_put(data->mlx, data->win, x, y++, ceil);
		}
		y--;
		while (y < h)
		{
			mlx_pixel_put(data->mlx, data->win, x, y++, floor);
		}
		x++;
	}

	for (x = 0; x < w; x++)
	{
		// calculate ray position and direction
		double cameraX = 2 * x / (double)w - 1; // x-coordinate in camera space
		double rayDirX = data->dirX + data->planeX * cameraX;
		double rayDirY = data->dirY + data->planeY * cameraX;
		// which box of the map we're in
		int mapX = (int)(data->posX);
		int mapY = (int)(data->posY);

		// length of ray from current position to next x or y-side
		double sideDistX;
		double sideDistY;

		// length of ray from one x or y-side to next x or y-side
		// these are derived as:
		// deltaDistX = sqrt(1 + (rayDirY * rayDirY) / (rayDirX * rayDirX))
		// deltaDistY = sqrt(1 + (rayDirX * rayDirX) / (rayDirY * rayDirY))
		// which can be simplified to abs(|rayDir| / rayDirX) and abs(|rayDir| / rayDirY)
		// where |rayDir| is the length of the vector (rayDirX, rayDirY). Its length,
		// unlike (dirX, dirY) is not 1, however this does not matter, only the
		// ratio between deltaDistX and deltaDistY matters, due to the way the DDA
		// stepping further below works. So the values can be computed as below.
		//  Division through zero is prevented, even though technically that's not
		//  needed in C++ with IEEE 754 floating point values.
		double deltaDistX = (rayDirX == 0) ? INFINITY : fabs(1 / rayDirX);
		double deltaDistY = (rayDirY == 0) ? INFINITY : fabs(1 / rayDirY);

		double perpWallDist;

		// what direction to step in x or y-direction (either +1 or -1)
		int stepX;
		int stepY;

		int hit = 0; // was there a wall hit?
		int side;		 // was a NS or a EW wall hit?
		// calculate step and initial sideDist
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (data->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - data->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (data->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - data->posY) * deltaDistY;
		}
		// perform DDA
		while (hit == 0)
		{
			// jump to next map square, either in x-direction, or in y-direction
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
			// Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0)
				hit = 1;
		}
		// Calculate distance projected on camera direction. This is the shortest distance from the point where the wall is
		// hit to the camera plane. Euclidean to center camera point would give fisheye effect!
		// This can be computed as (mapX - posX + (1 - stepX) / 2) / rayDirX for side == 0, or same formula with Y
		// for size == 1, but can be simplified to the code below thanks to how sideDist and deltaDist are computed:
		// because they were left scaled to |rayDir|. sideDist is the entire length of the ray above after the multiple
		// steps, but we subtract deltaDist once because one step more into the wall was taken above.
		if (side == 0)
			perpWallDist = (sideDistX - deltaDistX);
		else
			perpWallDist = (sideDistY - deltaDistY);

		printf("walldist : %f\n", perpWallDist);

		// Calculate height of line to draw on screen
		int lineHeight = (int)(h / perpWallDist);

		// calculate lowest and highest pixel to fill in current stripe
		int drawStart = -lineHeight / 2 + h / 2;
		if (drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + h / 2;
		if (drawEnd >= h)
			drawEnd = h - 1;
		
		// choose wall color
		unsigned int color;
		switch (worldMap[mapX][mapY])
		{
		case 1:
			color = 0x00FF0000;
			break; // red
		case 2:
			color = 0x0000FF00;
			break; // green
		case 3:
			color = 0x000000FF;
			break; // blue
		case 4:
			color = 0x00000000;
			break; // white
		default:
			color = 0x00FFFF00;
			break; // yellow
		}

		// give x and y sides different brightness
		if (side == 1)
		{
			color = color / 2;
		}

		// draw the pixels of the stripe as a vertical line
		y = drawStart;
		while (y < drawEnd)
		{
			mlx_pixel_put(data->mlx, data->win, x, y, color);
			y++;
		}
	}
}

int	render(t_data *data)
{
	refresh(data);

	player_move(data);

	raycasting(data);

	// mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int main()
{
  t_data	data;

	data.posX = 22; data.posY = 12;  //x and y start position
  data.dirX = -1; data.dirY = 0; //initial direction vector
  data.planeX = 0; data.planeY = 0.66; //the 2d raycaster version of camera plane

	data.width = screenWidth;
	data.height = screenHeight;

	char *title = "NonTexture";

  data.mlx = mlx_init();
  data.win = mlx_new_window(data.mlx, screenWidth, screenHeight, title);
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_hook(data.win, X_EVENT_KEY_PRESS, 0, &keypress, &data);
	mlx_hook(data.win, X_EVENT_DESTROY_NOTIFY, 0, &game_close, &data);
	mlx_loop(data.mlx);
}
