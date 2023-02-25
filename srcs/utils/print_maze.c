/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_maze.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 19:15:53 by pjang             #+#    #+#             */
/*   Updated: 2023/02/25 20:05:30 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	print_maze(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
			write(1, &map->maze[j++][i], 1);
		write(1, "\n", 1);
		i++;
	}
}

void	print_maze2(t_map *map, char **temp)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
			write(1, &temp[j++][map->height - 1 - i], 1);
		write(1, "\n", 1);
		i++;
	}
}
