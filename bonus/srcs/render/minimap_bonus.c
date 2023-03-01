/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 17:12:18 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 18:43:14 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	draw_pixel(t_game *game, int x, int y, unsigned int color)
{
	int				i[2];
	t_pixel			**pixel;

	pixel = game->pixel;
	i[X] = 0;
	while (i[X] < 10)
	{
		i[Y] = 0;
		while (i[Y] < 10)
		{
			*(pixel[x + i[X]][game->map.height * 10 - y + i[Y]++].color) = \
				(color & 8355771);
		}
		i[X]++;
	}
}

void	put_minimap(t_game *game, t_map *map)
{
	int				x;
	int				y;
	unsigned int	color;
	t_pixel			**pixel;

	pixel = game->pixel;
	x = 0;
	color = 0x00FFFFFF;
	while (x < map->width * 10)
	{
		y = 0;
		while (y < map->height * 10)
		{
			if (map->maze[x / 10][y / 10] == '0' \
				|| map->maze[x / 10][y / 10] == 'N' \
				|| map->maze[x / 10][y / 10] == 'S' \
				|| map->maze[x / 10][y / 10] == 'W' \
				|| map->maze[x / 10][y / 10] == 'E')
			{
				*(pixel[x][map->height * 10 - y].color) = (color & 8355771);
			}
			y++;
		}
		x++;
	}
}

void	put_player(t_game *game, t_ray *ray)
{
	int				x;
	int				y;
	unsigned int	color;

	color = 0x00FF0000;
	x = (int)(ray->pos[X] * 10);
	y = (int)(ray->pos[Y] * 10);
	draw_pixel(game, x, y, color);
}

void	draw_minimap(t_game *game)
{
	put_minimap(game, &game->map);
	put_player(game, &game->ray);
}
