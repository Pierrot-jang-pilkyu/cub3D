/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 12:13:47 by pjang             #+#    #+#             */
/*   Updated: 2023/02/28 18:04:57 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_img(t_img *img)
{
	img->img = NULL;
	img->addr = NULL;
	img->path = NULL;
	img->color = ft_calloc((128 * 128), sizeof(unsigned int));
	img->width = 128;
	img->height = 128;
	img->bits_per_pixel = 0;
	img->line_length = 0;
	img->endian = 0;
}

void	init_map(t_map *map)
{
	int	i;

	map->lst_map = NULL;
	map->maze = NULL;
	map->width = 0;
	map->height = 0;
	map->in_err = 0;
	map->tex_num = 0;
	map->tex_pos = (double)0;
	map->step = (double)0;
	map->tex[X] = 0;
	map->tex[Y] = 0;
	i = -1;
	while (++i < 3)
	{
		map->floor[i] = 0;
		map->ceil[i] = 0;
	}
	init_img(&map->texture[N]);
	init_img(&map->texture[S]);
	init_img(&map->texture[W]);
	init_img(&map->texture[E]);
}

void	init_ray(t_ray *ray)
{
	int	i;

	i = 0;
	ray->hit = 0;
	ray->side = 0;
	ray->width = 640;
	ray->height = 480;
	ray->line_height = 0;
	ray->draw_start = 0;
	ray->draw_end = 0;
	ray->wall_x = 0.0;
	ray->camera_x = (double)0;
	ray->wall_dist = (double)0;
	while (i < 2)
	{
		ray->map[i] = 0;
		ray->step[i] = 0;
		ray->pos[i] = (double)0;
		ray->dir[i] = (double)0;
		ray->plane[i] = (double)0;
		ray->ray_dir[i] = (double)0;
		ray->side_dist[i] = (double)0;
		ray->delta_dist[i] = (double)0;
		i++;
	}
}

void	init_color(t_color *color)
{
	color->ceil = 0;
	color->floor = 0;
}

int	init(t_game *game)
{
	game->fpath = NULL;
	init_map(&game->map);
	init_ray(&game->ray);
	init_img(&game->img);
	init_color(&game->color);
	init_key(&game->key);
	game->img.width = 640;
	game->img.height = 480;
	game->mlx = NULL;
	game->win = NULL;
	game->pixel = NULL;
	game->title = "cub3D_pjang";
	return (0);
}
