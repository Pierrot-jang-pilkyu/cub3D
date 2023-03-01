/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 05:57:59 by pjang             #+#    #+#             */
/*   Updated: 2023/03/01 18:38:00 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d_bonus.h"

int	valid_pos(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	if (c == '0')
		return (1);
	return (0);
}

void	move_add(t_game *game, double vec[2])
{
	int		x;
	int		y;
	t_ray	*ray;
	t_map	*map;

	ray = &game->ray;
	map = &game->map;
	x = (int)floor(ray->pos[X] + vec[X]);
	y = (int)floor(ray->pos[Y] + vec[Y]);
	if (valid_pos(map->maze[x][(int)(ray->pos[Y])]))
		ray->pos[X] += vec[X];
	if (valid_pos(map->maze[(int)(ray->pos[X])][y]))
		ray->pos[Y] += vec[Y];
}

void	move_sub(t_game *game, double vec[2])
{
	int		x;
	int		y;
	t_ray	*ray;
	t_map	*map;

	ray = &game->ray;
	map = &game->map;
	x = (int)ceil(ray->pos[X] + vec[X]);
	y = (int)ceil(ray->pos[Y] + vec[Y]);
	if (valid_pos(map->maze[x][(int)(ray->pos[Y])]))
		ray->pos[X] -= vec[X];
	if (valid_pos(map->maze[(int)(ray->pos[X])][y]))
		ray->pos[Y] -= vec[Y];
}

void	move_ccw(t_game *game)
{
	double	old_dir[2];
	double	old_plane[2];
	double	time;
	double	rad;
	t_ray	*ray;

	ray = &game->ray;
	time = 0.1;
	rad = time * 3.0;
	old_dir[X] = ray->dir[X];
	ray->dir[X] = (ray->dir[X] * cos(rad) - ray->dir[Y] * sin(rad));
	ray->dir[Y] = (old_dir[X] * sin(rad) + ray->dir[Y] * cos(rad));
	old_plane[X] = ray->plane[X];
	ray->plane[X] = (ray->plane[X] * cos(rad) - ray->plane[Y] * sin(rad));
	ray->plane[Y] = (old_plane[X] * sin(rad) + ray->plane[Y] * cos(rad));
}

void	move_cw(t_game *game)
{
	double	old_dir[2];
	double	old_plane[2];
	double	time;
	double	rad;
	t_ray	*ray;

	ray = &game->ray;
	time = 0.1;
	rad = time * 3.0;
	old_dir[X] = ray->dir[X];
	ray->dir[X] = (ray->dir[X] * cos(-rad) - ray->dir[Y] * sin(-rad));
	ray->dir[Y] = (old_dir[X] * sin(-rad) + ray->dir[Y] * cos(-rad));
	old_plane[X] = ray->plane[X];
	ray->plane[X] = (ray->plane[X] * cos(-rad) - ray->plane[Y] * sin(-rad));
	ray->plane[Y] = (old_plane[X] * sin(-rad) + ray->plane[Y] * cos(-rad));
}
