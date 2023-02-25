/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjang <pjang@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 01:58:18 by pjang             #+#    #+#             */
/*   Updated: 2023/02/25 21:14:59 by pjang            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	put_xpm_to_img(t_game *game, t_map *map)
{
	map->texture[N].img = mlx_xpm_file_to_image(game->mlx, \
		map->texture[N].path, &map->texture[N].width, &map->texture[N].height);
	map->texture[S].img = mlx_xpm_file_to_image(game->mlx, \
		map->texture[S].path, &map->texture[S].width, &map->texture[S].height);
	map->texture[W].img = mlx_xpm_file_to_image(game->mlx, \
		map->texture[W].path, &map->texture[W].width, &map->texture[W].height);
	map->texture[E].img = mlx_xpm_file_to_image(game->mlx, \
		map->texture[E].path, &map->texture[E].width, &map->texture[E].height);
}

void	get_addr(t_map *map)
{
	map->texture[N].addr = (unsigned int *)mlx_get_data_addr(\
		map->texture[N].img, &map->texture[N].bits_per_pixel, \
		&map->texture[N].line_length, &map->texture[N].endian);
	map->texture[S].addr = (unsigned int *)mlx_get_data_addr(\
		map->texture[S].img, &map->texture[S].bits_per_pixel, \
		&map->texture[S].line_length, &map->texture[S].endian);
	map->texture[W].addr = (unsigned int *)mlx_get_data_addr(\
		map->texture[W].img, &map->texture[W].bits_per_pixel, \
		&map->texture[W].line_length, &map->texture[W].endian);
	map->texture[E].addr = (unsigned int *)mlx_get_data_addr(\
		map->texture[E].img, &map->texture[E].bits_per_pixel, \
		&map->texture[E].line_length, &map->texture[E].endian);
}

void	ft_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	unsigned int	*dst;

	dst = (unsigned int *)((char *)img->addr + \
		(img->line_length * y + img->bits_per_pixel / 8 * x));
	*dst = color;
}

void	scene_refresh(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < WIDTH)
	{
		y = 0;
		while (y < HEIGHT)
		{
			mlx_pixel_put(game->mlx, game->win, x, y, 0x00FFFFFF);
			y++;
		}
		x++;
	}
}

int	ft_mlx_img(t_game *game)
{
	scene_refresh(game);
	player_move(game);
	draw_base(game);
	raycasting(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (0);
}
