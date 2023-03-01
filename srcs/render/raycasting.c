/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 23:28:01 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 18:17:49 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	set_var(t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double)ray->width - 1;
	ray->ray_dir[X] = ray->dir[X] + ray->plane[X] * ray->camera_x;
	ray->ray_dir[Y] = ray->dir[Y] + ray->plane[Y] * ray->camera_x;
	ray->map[X] = (int)ray->pos[X];
	ray->map[Y] = (int)ray->pos[Y];
	if (ray->ray_dir[X] == 0)
		ray->delta_dist[X] = INFINITY;
	else
		ray->delta_dist[X] = fabs(1 / ray->ray_dir[X]);
	if (ray->ray_dir[Y] == 0)
		ray->delta_dist[Y] = INFINITY;
	else
		ray->delta_dist[Y] = fabs(1 / ray->ray_dir[Y]);
	ray->hit = 0;
}

void	calculate_step(t_ray *ray)
{
	if (ray->ray_dir[X] < 0)
	{
		ray->step[X] = -1;
		ray->side_dist[X] = (ray->pos[X] - ray->map[X]) * ray->delta_dist[X];
	}
	else
	{
		ray->step[X] = 1;
		ray->side_dist[X] = \
			(ray->map[X] + 1.0 - ray->pos[X]) * ray->delta_dist[X];
	}
	if (ray->ray_dir[Y] < 0)
	{
		ray->step[Y] = -1;
		ray->side_dist[Y] = (ray->pos[Y] - ray->map[Y]) * ray->delta_dist[Y];
	}
	else
	{
		ray->step[Y] = 1;
		ray->side_dist[Y] = \
			(ray->map[Y] + 1.0 - ray->pos[Y]) * ray->delta_dist[Y];
	}
}

void	wall_pos(t_map *map, t_ray *ray)
{
	if (ray->side == 0)
	{
		if (ray->map[X] - ray->pos[X] < 0)
			map->tex_num = W;
		else
			map->tex_num = E;
		ray->wall_x = ray->pos[Y] + ray->wall_dist * ray->ray_dir[Y];
	}
	else
	{
		if (ray->map[Y] - ray->pos[Y] < 0)
			map->tex_num = S;
		else
			map->tex_num = N;
		ray->wall_x = ray->pos[X] + ray->wall_dist * ray->ray_dir[X];
	}
	ray->wall_x -= floor(ray->wall_x);
}

void	tex_pos(t_game *game, t_map *map, t_ray *ray, int x)
{
	int				y;
	unsigned int	color;
	t_pixel			**pixel;

	pixel = game->pixel;
	wall_pos(map, ray);
	map->tex[X] = (int)(ray->wall_x * (double)map->texture[map->tex_num].width);
	if (ray->side == 0 && ray->ray_dir[X] > 0)
		map->tex[X] = map->texture[map->tex_num].width - map->tex[X] - 1;
	if (ray->side == 1 && ray->ray_dir[Y] < 0)
		map->tex[X] = map->texture[map->tex_num].width - map->tex[X] - 1;
	map->step = 1.0 * map->texture[map->tex_num].height / ray->line_height;
	map->tex_pos = \
		(ray->draw_start - ray->height / 2 + ray->line_height / 2) * map->step;
	y = ray->draw_start - 1;
	while (++y < ray->draw_end)
	{
		map->tex[Y] = (int)map->tex_pos & (128 - 1);
		map->tex_pos += map->step;
		color = map->texture[map->tex_num].color[128 * map->tex[Y] + \
			map->tex[X]];
		*(pixel[x][y].color) = color;
	}
}

void	raycasting(t_game *game)
{
	int		x;
	t_ray	*ray;

	ray = &game->ray;
	x = 0;
	while (x < ray->width)
	{
		set_var(ray, x);
		calculate_step(ray);
		dda(&game->map, ray);
		calculate_dist(ray);
		calculate_hline(ray);
		tex_pos(game, &game->map, &game->ray, x);
		x++;
	}
}
