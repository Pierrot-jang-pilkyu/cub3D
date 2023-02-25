/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:30:12 by pjang             #+#    #+#             */
/*   Updated: 2023/02/25 18:47:01 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_player_position(t_map *map, double *x, double *y)
{
	while (*x < map->width)
	{
		*y = 0;
		while (*y < map->height)
		{
			if (map->maze[(int)*x][(int)*y] == 'N' \
				|| map->maze[(int)*x][(int)*y] == 'S' \
				|| map->maze[(int)*x][(int)*y] == 'W' \
				|| map->maze[(int)*x][(int)*y] == 'E')
				return ;
			*y += 1;
		}
		*x += 1;
	}
}

void	get_dir_vector(t_map *map, t_ray *ray)
{
	if (map->maze[(int)ray->pos[X]][(int)ray->pos[Y]] == 'N')
	{
		ray->dir[Y] = 1;
		ray->plane[X] = 0.66;
	}
	if (map->maze[(int)ray->pos[X]][(int)ray->pos[Y]] == 'S')
	{
		ray->dir[Y] = -1;
		ray->plane[X] = 0.66;
	}
	if (map->maze[(int)ray->pos[X]][(int)ray->pos[Y]] == 'W')
	{
		ray->dir[X] = -1;
		ray->plane[Y] = 0.66;
	}
	if (map->maze[(int)ray->pos[X]][(int)ray->pos[Y]] == 'E')
	{
		ray->dir[X] = 1;
		ray->plane[Y] = 0.66;
	}
}

int	render(t_game *game)
{
	get_player_position(&game->map, &game->ray.pos[X], &game->ray.pos[Y]);
	get_dir_vector(&game->map, &game->ray);
	return (0);
}
