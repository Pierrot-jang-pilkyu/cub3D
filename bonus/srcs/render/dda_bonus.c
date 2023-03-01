/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:28:01 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 17:04:32 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

void	calculate_dist(t_ray *ray)
{
	if (ray->side == 0)
	{
		ray->wall_dist = (ray->side_dist[X] - ray->delta_dist[X]);
	}
	else
	{
		ray->wall_dist = (ray->side_dist[Y] - ray->delta_dist[Y]);
	}
}

void	calculate_hline(t_ray *ray)
{
	ray->line_height = (int)(ray->height / ray->wall_dist);
	ray->draw_start = -ray->line_height / 2 + ray->height / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + ray->height / 2;
	if (ray->draw_end >= ray->height)
		ray->draw_end = ray->height - 1;
}

void	dda(t_map *map, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist[X] < ray->side_dist[Y])
		{
			ray->side_dist[X] += ray->delta_dist[X];
			ray->map[X] += ray->step[X];
			ray->side = 0;
		}
		else
		{
			ray->side_dist[Y] += ray->delta_dist[Y];
			ray->map[Y] += ray->step[Y];
			ray->side = 1;
		}
		if (!(ray->map[X] >= 0 && ray->map[X] < map->width && ray->map[Y] >= 0 \
			&& ray->map[Y] < map->height))
			break ;
		if (map->maze[ray->map[X]][ray->map[Y]] == '1')
			ray->hit = 1;
	}
}
