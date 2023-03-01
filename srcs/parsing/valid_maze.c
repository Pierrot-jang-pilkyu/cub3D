/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_maze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 20:57:11 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 21:23:00 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	valid_bound_space(t_map *map, int x, int y)
{
	if (x == 0)
	{
		while (x < map->width -1 && map->maze[x][y] == ' ')
			x++;
	}
	if (x == map->width -1)
	{
		while (x >= 0 && map->maze[x][y] == ' ')
			x--;
	}
	if (y == 0)
	{
		while (y < map->height -1 && map->maze[x][y] == ' ')
			y++;
	}
	if (y == map->height -1)
	{
		while (y >= 0 && map->maze[x][y] == ' ')
			y--;
	}
	if (x < 0 || x >= map->width || y < 0 || y > map->height)
		return (1);
	if (map->maze[x][y] != '1')
		return (0);
	return (1);
}

int	valid_bound(t_map *map)
{
	int	x;
	int	y;

	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (x == 0 || x == map->width - 1 || y == 0 || y == map->height -1)
			{
				if (map->maze[x][y] == '1')
				{
					y++;
					continue ;
				}
				if ((map->maze[x][y] == ' ' && \
					!valid_bound_space(map, x, y)) || map->maze[x][y] == '0')
					return (0);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int	valid_in(t_map *map, int x, int y)
{
	char	**temp;

	temp = get_zero_to_c(map, 0, 0);
	if (!temp || map->in_err)
	{
		safety_dimention_free(&temp);
		return (0);
	}
	while (x < map->width - 1)
	{
		y = 1;
		while (y < map->height - 1)
		{
			if (temp[x][y] == '0')
			{
				safety_dimention_free(&temp);
				return (1);
			}
			y++;
		}
		x++;
	}
	safety_dimention_free(&temp);
	return (0);
}

int	valid_maze(t_map *map)
{
	int	err_flag;

	err_flag = !valid_bound(map);
	if (!valid_in(map, 1, 1) && err_flag)
		return (0);
	return (1);
}
