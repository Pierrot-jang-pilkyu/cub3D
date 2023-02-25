/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_maze2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:25:09 by pjang             #+#    #+#             */
/*   Updated: 2023/02/25 14:54:34 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**copy_maze(t_map *map)
{
	int		x;
	int		y;
	char	**res;

	res = (char **)malloc(sizeof(char *) * (map->width + 1));
	if (!res)
		return (NULL);
	x = 0;
	while (x < map->width)
	{
		res[x] = (char *)malloc(sizeof(char) * (map->height + 1));
		if (!res[x])
			return (NULL);
		y = 0;
		while (y < map->height)
		{
			res[x][y] = map->maze[x][y];
			y++;
		}
		res[x][y] = '\0';
		x++;
	}
	res[x] = NULL;
	return (res);
}

void	find_player_position(char **maze, t_map *map, int *x, int *y)
{
	while (*x < map->width)
	{
		*y = 0;
		while (*y < map->height)
		{
			if (maze[*x][*y] == 'N' || maze[*x][*y] == 'S' \
				|| maze[*x][*y] == 'W' || maze[*x][*y] == 'E')
				return ;
			*y += 1;
		}
		*x += 1;
	}
}

void	change_zero(char ***maze, t_map *map, int x, int y)
{
	if (x < 0 || x >= map->width || y < 0 || y >= map->height)
		return ;
	if ((*maze)[x][y] == '1' || (*maze)[x][y] == 'C')
		return ;
	if ((*maze)[x][y] == ' ')
	{
		map->in_err = 1;
		return ;
	}
	if ((*maze)[x][y] == '0')
		(*maze)[x][y] = 'C';
	change_zero(maze, map, x, y - 1);
	change_zero(maze, map, x, y + 1);
	change_zero(maze, map, x - 1, y - 1);
	change_zero(maze, map, x - 1, y);
	change_zero(maze, map, x - 1, y + 1);
	change_zero(maze, map, x + 1, y - 1);
	change_zero(maze, map, x + 1, y);
	change_zero(maze, map, x + 1, y + 1);
}

char	**get_zero_to_c(t_map *map, int x, int y)
{
	char	**res;

	res = copy_maze(map);
	if (!res)
		return (NULL);
	find_player_position(res, map, &x, &y);
	change_zero(&res, map, x, y);
	return (res);
}

int	valid_in(t_map *map)
{
	int		x;
	int		y;
	char	**temp;

	temp = get_zero_to_c(map, 0, 0);
	if (!temp || map->in_err)
		return (0);
	x = 0;
	while (x < map->width)
	{
		y = 0;
		while (y < map->height)
		{
			if (temp[x][y] == '0')
				return (1);
			y++;
		}
		x++;
	}
	safety_dimention_free(temp);
	return (0);
}
