/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maze.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:17:59 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 21:22:43 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	**get_matrix(t_map *map, int i, int j, char *str)
{
	char	**res;
	t_list	*temp;

	temp = ft_lstlast(map->lst_map);
	res = (char **)malloc(sizeof(char *) * (map->height + 1));
	if (!res || !temp)
		return (NULL);
	while (++i < map->height && temp)
	{
		res[i] = (char *)malloc(sizeof(char) * (map->width + 1));
		if (!res[i])
			return (NULL);
		j = 0;
		str = (char *)temp->content;
		while (j < map->width && *str)
			res[i][j++] = *(str++);
		if (j != map->width)
			while (j < map->width)
				res[i][j++] = ' ';
		res[i][j] = '\0';
		temp = temp->prev;
	}
	res[i] = NULL;
	return (res);
}

int	get_maze(t_map *map)
{
	int		x;
	int		y;
	char	**temp;

	temp = get_matrix(map, -1, 0, NULL);
	x = -1;
	map->maze = (char **)malloc(sizeof(char *) * (map->width + 1));
	if (!map->maze || !temp)
		return (1);
	while (++x < map->width)
	{
		y = -1;
		map->maze[x] = (char *)malloc(sizeof(char) * (map->height + 1));
		if (!map->maze[x])
			return (1);
		while (++y < map->height)
			map->maze[x][y] = temp[y][x];
		map->maze[x][y] = '\0';
	}
	map->maze[x] = NULL;
	safety_dimention_free(&temp);
	return (0);
}
