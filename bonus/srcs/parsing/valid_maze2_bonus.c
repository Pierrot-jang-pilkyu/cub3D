/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_maze2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 21:25:09 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 18:57:56 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

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
	if (x < 1 || x >= map->width - 1 || y < 1 || y >= map->height - 1)
	{
		if (map->maze[x][y] == '0')
			map->in_err = 1;
		return ;
	}
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
